#include <a_samp>
#include <Dini>
#include <streamer>
#include <audio>
//#include <OEVD>
#include <mysql>
#include <a_http>
//#include <AntiCheatPlugin>
//#include <djson>

#define TIMER_TIME 300

new VehicleUpdateTimer[MAX_VEHICLES];

forward OnVehicleUpdate(vehicleid);
forward OnVehicleDestroy(vehicleid);

forward VPRPG_CreateVehicle(vehicletype, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay);

public VPRPG_CreateVehicle(vehicletype, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay)
{
	new vehicleid = CreateVehicle(vehicletype, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay);
	if(vehicleid)
		VehicleUpdateTimer[vehicleid] = SetTimerEx("OnVehicleUpdate", TIMER_TIME, true, "i", vehicleid);
	return vehicleid;
}

#define CreateVehicle VPRPG_CreateVehicle

forward VPRPG_AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2);

public VPRPG_AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2)
{
	new vehicleid = AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2);
	if(vehicleid)
		VehicleUpdateTimer[vehicleid] = SetTimerEx("OnVehicleUpdate", TIMER_TIME, true, "i", vehicleid);
	return vehicleid;
}

#define AddStaticVehicle VPRPG_AddStaticVehicle

forward VPRPG_AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay);

public VPRPG_AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay)
{
	new vehicleid = AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay);
	if(vehicleid)
		VehicleUpdateTimer[vehicleid] = SetTimerEx("OnVehicleUpdate", TIMER_TIME, true, "i", vehicleid);
	return vehicleid;
}

#define AddStaticVehicleEx VPRPG_AddStaticVehicleEx

forward VPRPG_DestroyVehicle(vehicleid);

public VPRPG_DestroyVehicle(vehicleid)
{
	new re = DestroyVehicle(vehicleid);
	if(VehicleUpdateTimer[vehicleid])
	{
		KillTimer(VehicleUpdateTimer[vehicleid]);
		VehicleUpdateTimer[vehicleid] = 0;
		OnVehicleDestroy(vehicleid);
	}
	return re;
}

#define DestroyVehicle VPRPG_DestroyVehicle

IsNumeric(const string[])
{
	for (new i = 0, j = strlen(string); i < j; i++)
	{
		if (string[i] > '9' || string[i] < '0') return 0;
	}
	return 1;
}

ReturnUser(text[], playerid = INVALID_PLAYER_ID)
{
	new pos = 0;
	while (text[pos] < 0x21) // Strip out leading spaces
	{
		if (text[pos] == 0) return INVALID_PLAYER_ID; // No passed text
		pos++;
	}
	new userid = INVALID_PLAYER_ID;
	if (IsNumeric(text[pos])) // Check whole passed string
	{
		// If they have a numeric name you have a problem (although names are checked on id failure)
		userid = strval(text[pos]);
		if (userid >=0 && userid < MAX_PLAYERS)
		{
			if(!IsPlayerConnected(userid))
			{
				/*if (playerid != INVALID_PLAYER_ID)
				{
					SendClientMessage(playerid, 0xFF0000AA, "User not connected");
				}*/
				userid = INVALID_PLAYER_ID;
			}
			else
			{
				return userid; // A player was found
			}
		}
		/*else
		{
			if (playerid != INVALID_PLAYER_ID)
			{
				SendClientMessage(playerid, 0xFF0000AA, "Invalid user ID");
			}
			userid = INVALID_PLAYER_ID;
		}
		return userid;*/
		// Removed for fallthrough code
	}
	// They entered [part of] a name or the id search failed (check names just incase)
	new len = strlen(text[pos]);
	new count = 0;
	new name[MAX_PLAYER_NAME];
	for (new i = 0; i < MAX_PLAYERS; i++)
	{
		if (IsPlayerConnected(i))
		{
			GetPlayerName(i, name, sizeof (name));
			if (strcmp(name, text[pos], true, len) == 0) // Check segment of name
			{
				if (len == strlen(name)) // Exact match
				{
					return i; // Return the exact player on an exact match
					// Otherwise if there are two players:
					// Me and MeYou any time you entered Me it would find both
					// And never be able to return just Me's id
				}
				else // Partial match
				{
					count++;
					userid = i;
				}
			}
		}
	}
	if (count != 1)
	{
		if (playerid != INVALID_PLAYER_ID)
		{
			if (count)
			{
				SendClientMessage(playerid, 0xFF0000AA, "Multiple users found, please narrow earch");
			}
			else
			{
				SendClientMessage(playerid, 0xFF0000AA, "No matching user found");
			}
		}
		userid = INVALID_PLAYER_ID;
	}
	return userid; // INVALID_USER_ID for bad return
}