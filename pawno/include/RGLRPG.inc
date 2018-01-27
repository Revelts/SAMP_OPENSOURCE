/*  SA-MP Functions
 *
 *  (c) Copyright 2005-2011, SA-MP Team
 *
 */

#if defined _samp_included
	#endinput
#endif
#define _samp_included
#pragma library samp

#pragma tabsize 4
// Ignores warning 217 for properly indented PAWNO code
// It's tab size is 4 and often uses 4 spaces instead, PAWNCC's is 8

#include <core>
#include <float>
#include <string>
#include <file>
#include <time>
#include <datagram>
#include <a_players>
#include <a_vehicles>
#include <a_objects>
#include <a_sampdb>

// Limits and internal constants
#define MAX_PLAYER_NAME							(24)
#define MAX_PLAYERS								(500)
#define MAX_VEHICLES							(2000)
#define INVALID_PLAYER_ID						(0xFFFF)
#define INVALID_VEHICLE_ID						(0xFFFF)
#define NO_TEAM									(255)
#define MAX_OBJECTS								(1000)
#define INVALID_OBJECT_ID						(0xFFFF)
#define MAX_GANG_ZONES							(1024)
#define MAX_TEXT_DRAWS							(2048)
#define MAX_MENUS								(128)
#define MAX_3DTEXT_GLOBAL						(1024)
#define MAX_3DTEXT_PLAYER						(1024)
#define MAX_PICKUPS								(4096)
#define INVALID_MENU							(0xFF)
#define INVALID_TEXT_DRAW						(0xFFFF)
#define INVALID_GANG_ZONE						(-1)
#define INVALID_3DTEXT_ID						(0xFFFF)

// --------------------------------------------------
// Natives
// --------------------------------------------------

// Util
native print(const string[]);
native printf(const format[], {Float,_}:...);
native format(output[], len, const format[], {Float,_}:...);
native SendClientMessage(playerid, color, const message[]);
native SendClientMessageToAll(color, const message[]);
native SendPlayerMessageToPlayer(playerid, senderid, const message[]);
native SendPlayerMessageToAll(senderid, const message[]);
native SendDeathMessage(killer,killee,weapon);
native GameTextForAll(const string[],time,style);
native GameTextForPlayer(playerid,const string[],time,style);
native SetTimer(funcname[], interval, repeating);
native SetTimerEx(funcname[], interval, repeating, const format[], {Float,_}:...);
native KillTimer(timerid);
native GetTickCount();
native GetMaxPlayers();
native CallRemoteFunction(const function[], const format[], {Float,_}:...);
native CallLocalFunction(const function[], const format[], {Float,_}:...);
native Float:asin(Float:value);
native Float:acos(Float:value);
native Float:atan(Float:value);
native Float:atan2(Float:x, Float:y);

// Game
native SetGameModeText(const string[]);
native SetTeamCount(count);
native AddPlayerClass(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
native AddPlayerClassEx(teamid, modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
native AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2);
native AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay);
native AddStaticPickup(model, type, Float:X, Float:Y, Float:Z, virtualworld = 0);
native CreatePickup(model, type, Float:X, Float:Y, Float:Z, virtualworld = 0);
native DestroyPickup(pickup);
native ShowNameTags(show);
native ShowPlayerMarkers(mode);
native GameModeExit();
native SetWorldTime(hour);
native GetWeaponName(weaponid, const weapon[], len);
native EnableTirePopping(enable);
native AllowInteriorWeapons(allow);
native SetWeather(weatherid);
native SetGravity(Float:gravity);
native AllowAdminTeleport(allow);
native SetDeathDropAmount(amount);
native CreateExplosion(Float:X, Float:Y, Float:Z, type, Float:Radius);
native EnableZoneNames(enable);
native UsePlayerPedAnims();		// Will cause the players to use CJ running/walking animations
native DisableInteriorEnterExits();  // will disable all interior enter/exits in the game.
native SetNameTagDrawDistance(Float:distance); // Distance at which nametags will start rendering on the client.
native DisableNameTagLOS(); // Disables the nametag Line-Of-Sight checking
native LimitGlobalChatRadius(Float:chat_radius);
native LimitPlayerMarkerRadius(Float:marker_radius);

// Npc
native ConnectNPC(name[], script[]);
native IsPlayerNPC(playerid);

// Admin
native IsPlayerAdmin(playerid);
native Kick(playerid);
native Ban(playerid);
native BanEx(playerid, const reason[]);
native SendRconCommand(command[]);
native GetServerVarAsString(const varname[], buffer[], len);
native GetServerVarAsInt(const varname[]);
native GetServerVarAsBool(const varname[]);
native GetPlayerNetworkStats(playerid, retstr[], retstr_size);
native GetNetworkStats(retstr[], retstr_size);

// Menu
native Menu:CreateMenu(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0);
native DestroyMenu(Menu:menuid);
native AddMenuItem(Menu:menuid, column, const menutext[]);
native SetMenuColumnHeader(Menu:menuid, column, const columnheader[]);
native ShowMenuForPlayer(Menu:menuid, playerid);
native HideMenuForPlayer(Menu:menuid, playerid);
native IsValidMenu(Menu:menuid);
native DisableMenu(Menu:menuid);
native DisableMenuRow(Menu:menuid, row);
native Menu:GetPlayerMenu(playerid);

// Text Draw
native Text:TextDrawCreate(Float:x, Float:y, text[]);
native TextDrawDestroy(Text:text);
native TextDrawLetterSize(Text:text, Float:x, Float:y);
native TextDrawTextSize(Text:text, Float:x, Float:y);
native TextDrawAlignment(Text:text, alignment);
native TextDrawColor(Text:text, color);
native TextDrawUseBox(Text:text, use);
native TextDrawBoxColor(Text:text, color);
native TextDrawSetShadow(Text:text, size);
native TextDrawSetOutline(Text:text, size);
native TextDrawBackgroundColor(Text:text, color);
native TextDrawFont(Text:text, font);
native TextDrawSetProportional(Text:text, set);
native TextDrawShowForPlayer(playerid, Text:text);
native TextDrawHideForPlayer(playerid, Text:text);
native TextDrawShowForAll(Text:text);
native TextDrawHideForAll(Text:text);
native TextDrawSetString(Text:text, string[]);

// Gang Zones
native GangZoneCreate(Float:minx, Float:miny, Float:maxx, Float:maxy);
native GangZoneDestroy(zone);
native GangZoneShowForPlayer(playerid, zone, color);
native GangZoneShowForAll(zone, color);
native GangZoneHideForPlayer(playerid, zone);
native GangZoneHideForAll(zone);
native GangZoneFlashForPlayer(playerid, zone, flashcolor);
native GangZoneFlashForAll(zone, flashcolor);
native GangZoneStopFlashForPlayer(playerid, zone);
native GangZoneStopFlashForAll(zone);

// Global 3D Text Labels
native Text3D:Create3DTextLabel(text[], color, Float:X, Float:Y, Float:Z, Float:DrawDistance, virtualworld, testLOS=0);
native Delete3DTextLabel(Text3D:id);
native Attach3DTextLabelToPlayer(Text3D:id, playerid, Float:OffsetX, Float:OffsetY, Float:OffsetZ);
native Attach3DTextLabelToVehicle(Text3D:id, vehicleid, Float:OffsetX, Float:OffsetY, Float:OffsetZ);
native Update3DTextLabelText(Text3D:id, color, text[]);

// Per-player 3D Text Labels
native PlayerText3D:CreatePlayer3DTextLabel(playerid, text[], color, Float:X, Float:Y, Float:Z, Float:DrawDistance, attachedplayer=INVALID_PLAYER_ID, attachedvehicle=INVALID_VEHICLE_ID, testLOS=0);
native DeletePlayer3DTextLabel(playerid, PlayerText3D:id);
native UpdatePlayer3DTextLabelText(playerid, PlayerText3D:id, color, text[]);

// Player GUI Dialog
#define DIALOG_STYLE_MSGBOX		0
#define DIALOG_STYLE_INPUT		1
#define DIALOG_STYLE_LIST		2
#define DIALOG_STYLE_PASSWORD	3

native ShowPlayerDialog(playerid, dialogid, style, caption[], info[], button1[], button2[]);

// --------------------------------------------------
// Defines
// --------------------------------------------------

// States
#define PLAYER_STATE_NONE						(0)
#define PLAYER_STATE_ONFOOT						(1)
#define PLAYER_STATE_DRIVER						(2)
#define PLAYER_STATE_PASSENGER					(3)
#define PLAYER_STATE_EXIT_VEHICLE				(4) // (used internally)
#define PLAYER_STATE_ENTER_VEHICLE_DRIVER		(5) // (used internally)
#define PLAYER_STATE_ENTER_VEHICLE_PASSENGER	(6) // (used internally)
#define PLAYER_STATE_WASTED						(7)
#define PLAYER_STATE_SPAWNED					(8)
#define PLAYER_STATE_SPECTATING					(9)

// Marker modes used by ShowPlayerMarkers()
#define PLAYER_MARKERS_MODE_OFF			(0)
#define PLAYER_MARKERS_MODE_GLOBAL		(1)
#define PLAYER_MARKERS_MODE_STREAMED	(2)

// Weapons
#define WEAPON_BRASSKNUCKLE				(1)
#define WEAPON_GOLFCLUB					(2)
#define WEAPON_NITESTICK				(3)
#define WEAPON_KNIFE					(4)
#define WEAPON_BAT						(5)
#define WEAPON_SHOVEL					(6)
#define WEAPON_POOLSTICK				(7)
#define WEAPON_KATANA					(8)
#define WEAPON_CHAINSAW					(9)
#define WEAPON_DILDO					(10)
#define WEAPON_DILDO2					(11)
#define WEAPON_VIBRATOR					(12)
#define WEAPON_VIBRATOR2				(13)
#define WEAPON_FLOWER					(14)
#define WEAPON_CANE						(15)
#define WEAPON_GRENADE					(16)
#define WEAPON_TEARGAS					(17)
#define WEAPON_MOLTOV					(18)
#define WEAPON_COLT45					(22)
#define WEAPON_SILENCED					(23)
#define WEAPON_DEAGLE					(24)
#define WEAPON_SHOTGUN					(25)
#define WEAPON_SAWEDOFF					(26)
#define WEAPON_SHOTGSPA					(27)
#define WEAPON_UZI						(28)
#define WEAPON_MP5						(29)
#define WEAPON_AK47						(30)
#define WEAPON_M4						(31)
#define WEAPON_TEC9						(32)
#define WEAPON_RIFLE					(33)
#define WEAPON_SNIPER					(34)
#define WEAPON_ROCKETLAUNCHER			(35)
#define WEAPON_HEATSEEKER				(36)
#define WEAPON_FLAMETHROWER				(37)
#define WEAPON_MINIGUN					(38)
#define WEAPON_SATCHEL					(39)
#define WEAPON_BOMB						(40)
#define WEAPON_SPRAYCAN					(41)
#define WEAPON_FIREEXTINGUISHER			(42)
#define WEAPON_CAMERA					(43)
#define WEAPON_PARACHUTE				(46)
#define WEAPON_VEHICLE					(49)
#define WEAPON_DROWN					(53)
#define WEAPON_COLLISION				(54)

// Keys
#define KEY_ACTION				(1)
#define KEY_CROUCH				(2)
#define KEY_FIRE				(4)
#define KEY_SPRINT				(8)
#define KEY_SECONDARY_ATTACK	(16)
#define KEY_JUMP				(32)
#define KEY_LOOK_RIGHT			(64)
#define KEY_HANDBRAKE			(128)
#define KEY_LOOK_LEFT			(256)
#define KEY_SUBMISSION			(512)
#define KEY_LOOK_BEHIND			(512)
#define KEY_WALK				(1024)
#define KEY_ANALOG_UP			(2048)
#define KEY_ANALOG_DOWN			(4096)
#define KEY_ANALOG_LEFT			(8192)
#define KEY_ANALOG_RIGHT		(16384)
#define KEY_YES					(65536)
#define KEY_NO					(131072)
#define KEY_CTRL_BACK			(262144)

#define KEY_UP					(-128)
#define KEY_DOWN				(128)
#define KEY_LEFT				(-128)
#define KEY_RIGHT				(128)

// --------------------------------------------------
// Forwards (Callback declarations)
// --------------------------------------------------

forward OnGameModeInit();
forward OnGameModeExit();
forward OnFilterScriptInit();
forward OnFilterScriptExit();
forward OnPlayerConnect(playerid);
forward OnPlayerDisconnect(playerid, reason);
forward OnPlayerSpawn(playerid);
forward OnPlayerDeath(playerid, killerid, reason);
forward OnVehicleSpawn(vehicleid);
forward OnVehicleDeath(vehicleid, killerid);
forward OnPlayerText(playerid, text[]);
forward OnPlayerCommandText(playerid, cmdtext[]);
forward OnPlayerRequestClass(playerid, classid);
forward OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
forward OnPlayerExitVehicle(playerid, vehicleid);
forward OnPlayerStateChange(playerid, newstate, oldstate);
forward OnPlayerEnterCheckpoint(playerid);
forward OnPlayerLeaveCheckpoint(playerid);
forward OnPlayerEnterRaceCheckpoint(playerid);
forward OnPlayerLeaveRaceCheckpoint(playerid);
forward OnRconCommand(cmd[]);
forward OnPlayerRequestSpawn(playerid);
forward OnObjectMoved(objectid);
forward OnPlayerObjectMoved(playerid, objectid);
forward OnPlayerPickUpPickup(playerid, pickupid);
forward OnVehicleMod(playerid, vehicleid, componentid);
forward OnEnterExitModShop(playerid, enterexit, interiorid);
forward OnVehiclePaintjob(playerid, vehicleid, paintjobid);
forward OnVehicleRespray(playerid, vehicleid, color1, color2);
forward OnVehicleDamageStatusUpdate(vehicleid, playerid);
forward OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat);
forward OnPlayerSelectedMenuRow(playerid, row);
forward OnPlayerExitedMenu(playerid);
forward OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid);
forward OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
forward OnRconLoginAttempt( ip[], password[], success );
forward OnPlayerUpdate(playerid);
forward OnPlayerStreamIn(playerid, forplayerid);
forward OnPlayerStreamOut(playerid, forplayerid);
forward OnVehicleStreamIn(vehicleid, forplayerid);
forward OnVehicleStreamOut(vehicleid, forplayerid);
forward OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
forward OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid);
forward OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid);
forward OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ);

#define CLICK_SOURCE_SCOREBOARD		0
forward OnPlayerClickPlayer(playerid, clickedplayerid, source);

// --------------------------------------------------

/*
 *            Dini 1.5.1
 *       (c) Copyright 2006 by DracoBlue
 *
 * @author    : DracoBlue (http://dracoblue.com)
 * @date      : 13th May 2006
 * @update    : 3rd June 2007
 * @require   : DUtils 1.8
 *
 * This file is provided as is (no warranties).
 *
 * Feel free to use it, a little message in
 * about box is honouring thing, isn't it?
 *
 */

#if defined _dini_included
  #endinput
#endif

#define _dini_included
#pragma library dutils

#include <dutils>

stock  dini_Exists(filename[]) {
	if (fexist(filename)) return true;
	return false;
}

stock  dini_Remove(filename[]) {
	if (!fexist(filename)) return false;
	fremove(filename);
	return true;
}

stock  dini_Create(filename[]) {
	new File:fhnd;
	if (fexist(filename)) return false;
	fhnd=fopen(filename,io_write);
	fclose(fhnd);
	return true;
}

stock  dini_PRIVATE_ExtractKey(line[]) {
	new tmp[MAX_STRING];
	tmp[0]=0;
	if (strfind(line,"=",true)==-1) return tmp;
	set(tmp,strlower(ret_memcpy(line,0,strfind(line,"=",true))));
	return tmp;
}

stock  dini_PRIVATE_ExtractValue(line[]) {
    new tmp[MAX_STRING];
    tmp[0]=0;
    if (strfind(line,"=",true)==-1) {
        return tmp;
    }
    set(tmp,ret_memcpy(line,strfind(line,"=",true)+1,strlen(line)));
    return tmp;
}

stock  dini_Set(filename[],key[],value[]) {
	new File:fohnd, File:fwhnd;
	new bool:wasset=false;
	new tmpres[MAX_STRING];
	if (key[0]==0) return false; /* If we have no sign in key, it can't be set*/
	format(tmpres,sizeof(tmpres),"%s.part",filename);
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	fremove(tmpres);
	fwhnd=fopen(tmpres,io_write);
	//  if (!fwhnd) return false;
	while (fread(fohnd,tmpres)) {
		StripNewLine(tmpres);
		if ((!wasset)&&(equal(dini_PRIVATE_ExtractKey(tmpres),key,true))) {
			/* We've got what needs to be replaced! */
			format(tmpres,sizeof(tmpres),"%s=%s",key,value);
			wasset=true;
		}
		fwrite(fwhnd,tmpres);
		fwrite(fwhnd,"\r\n");
	}

	if (!wasset) {
		format(tmpres,sizeof(tmpres),"%s=%s",key,value);
		fwrite(fwhnd,tmpres);
		fwrite(fwhnd,"\r\n");
	}

	fclose(fohnd);
	fclose(fwhnd);

	format(tmpres,sizeof(tmpres),"%s.part",filename);
	if (fcopytextfile(tmpres,filename)) {
		return fremove(tmpres);
	}
	return false;
}


stock  dini_IntSet(filename[],key[],value) {
   new valuestring[MAX_STRING];
   format(valuestring,sizeof(valuestring),"%d",value);
   return dini_Set(filename,key,valuestring);
}

stock  dini_Int(filename[],key[]) {
   return strval(dini_Get(filename,key));
}

stock  dini_FloatSet(filename[],key[],Float:value) {
   new valuestring[MAX_STRING];
   format(valuestring,sizeof(valuestring),"%f",value);
   return dini_Set(filename,key,valuestring);
}

stock  Float:dini_Float(filename[],key[]) {
   return floatstr(dini_Get(filename,key));
}

stock  dini_Bool(filename[],key[]) {
   return strval(dini_Get(filename,key));
}

stock  dini_BoolSet(filename[],key[],value) {
   new valuestring[MAX_STRING];
   format(valuestring,sizeof(valuestring),"%d",value);
   return dini_Set(filename,key,valuestring);
}

stock  dini_Unset(filename[],key[]) {
	new File:fohnd, File:fwhnd;
	new tmpres[MAX_STRING];
	format(tmpres,sizeof(tmpres),"%s.part",filename);
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	fremove(tmpres);
	fwhnd=fopen(tmpres,io_write);
	//  if (!fwhnd) return false;
	while (fread(fohnd,tmpres)) {
		StripNewLine(tmpres);
		if (equal(dini_PRIVATE_ExtractKey(tmpres),key,true)) {
			/* We've got what needs to be removed! */
		} else {
			format(tmpres,sizeof(tmpres),"%s",tmpres);
			fwrite(fwhnd,tmpres);
			fwrite(fwhnd,"\r\n");
		}
	}

	fclose(fohnd);
	fclose(fwhnd);

	format(tmpres,sizeof(tmpres),"%s.part",filename);
	if (fcopytextfile(tmpres,filename)) {
		return fremove(tmpres);
	}
	return false;
}

stock  dini_Get(filename[],key[]) {
	new File:fohnd;
	new tmpres[MAX_STRING];
	new tmpres2[MAX_STRING];
	tmpres[0]=0;
	fohnd=fopen(filename,io_read);
	if (!fohnd) return tmpres;
	while (fread(fohnd,tmpres)) {
		StripNewLine(tmpres);
		if (equal(dini_PRIVATE_ExtractKey(tmpres),key,true)) {
			/* We've got what we need */
			tmpres2[0]=0;
			strcat(tmpres2,dini_PRIVATE_ExtractValue(tmpres));
			fclose(fohnd);
			return tmpres2;
		}
	}
	fclose(fohnd);
	return tmpres;
}


stock  dini_Isset(filename[],key[]) {
	new File:fohnd;
	new tmpres[MAX_STRING];
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	while (fread(fohnd,tmpres)) {
		StripNewLine(tmpres);
		if (equal(dini_PRIVATE_ExtractKey(tmpres),key,true)) {
			/* We've got what we need */
			fclose(fohnd);
			return true;
		}
	}
	fclose(fohnd);
	return false;
}

/*

	GAME INFOMATION HEADER v1.0
	COPYRIGHT 2008 beta6. ALL RIGHTS RESERVED.

 -- function list

native IsPoliceCar(modelid);
native IsTunableVehicle(modelid);
native IsAttackableVehicle(modelid);
native IsMotorcycle(modelid);
native IsBicycle(modelid);
native IsAirPlane(modelid);
native IsPublicTransportation(modelid);
native IsTruck(modelid);
native IsRV(modelid);
native IsShip(modelid);
*/

#if defined _ginfo_included
  #endinput
#endif
#define _ginfo_included
#pragma library ginfo

forward IsPoliceCar(modelid);
forward IsTunableVehicle(modelid);
forward IsAttackableVehicle(modelid);
forward IsMotorcycle(modelid);
forward IsBicycle(modelid);
forward IsAirPlane(modelid);
forward IsPublicTransportation(modelid);
forward IsTruck(modelid);
forward IsRV(modelid);
forward IsShip(modelid);

public IsPoliceCar(modelid)
{
	if(modelid == 596 || modelid == 597 || modelid == 598 || modelid == 599)
	{
		return 1;
	}
	else if(modelid == 601 || modelid == 427 || modelid == 523 || modelid == 528 || modelid == 490)
	{
		return 1;
	}
	return 0;
}

public IsTunableVehicle(modelid)
{
	if(modelid == 560 || modelid == 559 || modelid == 562 || modelid == 557 || modelid == 411)
	{
		return 1;
	}
	return 0;
}

public IsAttackableVehicle(modelid)
{
	if(modelid == 425 || modelid == 432 || modelid == 447 || modelid == 476 || modelid == 476 || modelid == 520)
	{
		return 1;
	}
	return 0;
}

public IsMotorcycle(modelid)
{
	if(modelid == 521 || modelid == 522 || modelid == 523 || modelid == 471 || modelid == 461 || modelid == 581)
	{
		return 1;
	}
	return 0;
}

public IsBicycle(modelid)
{
	if(modelid == 509 || modelid == 510 || modelid == 481)
	{
		return 1;
	}
	return 0;
}


public IsAirPlane(modelid)
{
	if(modelid == 593 || modelid == 520 || modelid == 519 || modelid == 513 || modelid == 511 || modelid == 476 || modelid == 460)
	{
		return 1;
	}
	return 0;
}

public IsShip(modelid)
{
	if(modelid == 472 || modelid == 493 || modelid == 595 || modelid == 473 || modelid == 484 || modelid == 430 || modelid == 452 || modelid == 476 || modelid == 453)
	{
		return 1;
	}
	else if(modelid == 446 || modelid == 454)
	{
		return 1;
	}
	return 0;
}


public IsPublicTransportation(modelid)
{
	if(modelid == 420 || modelid == 438)
	{
		return 1;
	}
	else if(modelid == 431 || modelid == 437)
	{
		return 1;
	}
	return 0;
}

public IsTruck(modelid)
{
	if(modelid == 422 || modelid == 440 || modelid == 478 || modelid == 482 || modelid == 543 || modelid == 554)
	{
	return 1;
	}
	return 0;
}

public IsRV(modelid)
{
	if(modelid==400 || modelid==418 || modelid==442 || modelid==458 || modelid==479 || modelid==482 || modelid==483 || modelid==579)
	{
	return 1;
	}
	return 0;
}

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

new pdistance = 1;
forward NameTimer();
Float:GetPointDistanceToPointExMorph(Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2)
{
new Float:x, Float:y, Float:z;
x = x1-x2;
y = y1-y2;
z = z1-z2;
return floatsqroot(x*x+y*y+z*z);
}
stock SetPDistance(dista)
{
pdistance = dista;
}
stock GetPDistance()
{
return pdistance;
}
stock EnableDistancedNameTag(delay)
{
SetTimer("NameTimer",delay,1);
}
forward NameTimer();
public NameTimer()
	{
	for(new i = 0;i < MAX_PLAYERS;i++)
 	{
 	if(IsPlayerConnected(i))
 	{
 	for(new q = 0;q < MAX_PLAYERS;q++)
 	{
	if(IsPlayerConnected(q))
	{
 	new Float:p1x;
	new Float:p1y;
	new Float:p1z;
	new Float:p2x;
	new Float:p2y;
	new Float:p2z;
	if(IsPlayerConnected(i) && IsPlayerConnected(q))
	{
	GetPlayerPos(i,p1x,p1y,p1z);
    GetPlayerPos(q,p2x,p2y,p2z);
	if(GetPointDistanceToPointExMorph(p1x,p1y,p1z,p2x,p2y,p2z) < pdistance)
		{
	    ShowPlayerNameTagForPlayer(i,q,1);
	    }
	else
		{
		ShowPlayerNameTagForPlayer(i,q,0);
		}
	}}}}}
}

new vNames[][] = {
   "Landstalker",
   "Bravura",
   "Buffalo",
   "Linerunner",
   "Pereniel",
   "Sentinel",
   "Dumper",
   "Firetruck",
   "Trashmaster",
   "Stretch",
   "Manana",
   "Infernus",
   "Voodoo",
   "Pony",
   "Mule",
   "Cheetah",
   "Ambulance",
   "Leviathan",
   "Moonbeam",
   "Esperanto",
   "Taxi",
   "Washington",
   "Bobcat",
   "Mr Whoopee",
   "BF Injection",
   "Hunter",
   "Premier",
   "Enforcer",
   "Securicar",
   "Banshee",
   "Predator",
   "Bus",
   "Rhino",
   "Barracks",
   "Hotknife",
   "Trailer",
   "Previon",
   "Coach",
   "Cabbie",
   "Stallion",
   "Rumpo",
   "RC Bandit",
   "Romero",
   "Packer",
   "Monster Truck",
   "Admiral",
   "Squalo",
   "Seasparrow",
   "Pizzaboy",
   "Tram",
   "Trailer",
   "Turismo",
   "Speeder",
   "Reefer",
   "Tropic",
   "Flatbed",
   "Yankee",
   "Caddy",
   "Solair",
   "Berkley's RC Van",
   "Skimmer",
   "PCJ-600",
   "Faggio",
   "Freeway",
   "RC Baron",
   "RC Raider",
   "Glendale",
   "Oceanic",
   "Sanchez",
   "Sparrow",
   "Patriot",
   "Quad",
   "Coastguard",
   "Dinghy",
   "Hermes",
   "Sabre",
   "Rustler",
   "ZR-350",
   "Walton",
   "Regina",
   "Comet",
   "BMX",
   "Burrito",
   "Camper",
   "Marquis",
   "Baggage",
   "Dozer",
   "Maverick",
   "News Chopper",
   "Rancher",
   "FBI Rancher",
   "Virgo",
   "Greenwood",
   "Jetmax",
   "Hotring",
   "Sandking",
   "Blista Compact",
   "Police Maverick",
   "Boxville",
   "Benson",
   "Mesa",
   "RC Goblin",
   "Hotring Racer",
   "Hotring Racer",
   "Bloodring Banger",
   "Rancher",
   "Super GT",
   "Elegant",
   "Journey",
   "Bike",
   "Mountain Bike",
   "Beagle",
   "Cropdust",
   "Stunt",
   "Tanker",
   "RoadTrain",
   "Nebula",
   "Majestic",
   "Buccaneer",
   "Shamal",
   "Hydra",
   "FCR-900",
   "NRG-500",
   "HPV1000",
   "Cement Truck",
   "Tow Truck",
   "Fortune",
   "Cadrona",
   "FBI Truck",
   "Willard",
   "Forklift",
   "Tractor",
   "Combine",
   "Feltzer",
   "Remington",
   "Slamvan",
   "Blade",
   "Freight",
   "Streak",
   "Vortex",
   "Vincent",
   "Bullet",
   "Clover",
   "Sadler",
   "Firetruck",
   "Hustler",
   "Intruder",
   "Primo",
   "Cargobob",
   "Tampa",
   "Sunrise",
   "Merit",
   "Utility",
   "Nevada",
   "Yosemite",
   "Windsor",
   "Monster Truck",
   "Monster Truck",
   "Uranus",
   "Jester",
   "Sultan",
   "Stratum",
   "Elegy",
   "Raindance",
   "RC Tiger",
   "Flash",
   "Tahoma",
   "Savanna",
   "Bandito",
   "Freight",
   "Trailer",
   "Kart",
   "Mower",
   "Duneride",
   "Sweeper",
   "Broadway",
   "Tornado",
   "AT-400",
   "DFT-30",
   "Huntley",
   "Stafford",
   "BF-400",
   "Newsvan",
   "Tug",
   "Trailer",
   "Emperor",
   "Wayfarer",
   "Euros",
   "Hotdog",
   "Club",
   "Trailer",
   "Trailer",
   "Andromada",
   "Dodo",
   "RC Cam",
   "Launch",
   "LSPD",
   "SFPD",
   "LVPD",
   "Police Ranger",
   "Picador",
   "S.W.A.T. Van",
   "Alpha",
   "Phoenix",
   "Glendale",
   "Sadler",
   "Luggage Trailer",
   "Luggage Trailer",
   "Stair Trailer",
   "Boxville",
   "Farm Plow",
   "Utility Trailer"
};

stock GetVehicleName(vehicleid)
{
  new vehname[128];
  format(vehname, sizeof(vehname), "%s",vNames[GetVehicleModel(vehicleid)-400]);
  return vehname;
}

/*
    SA-MP Streamer Plugin v2.3.8
    Copyright ?2010 Incognito

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#if defined _streamer_included
	#endinput
#endif
#define _streamer_included
#pragma library streamer

// Definitions

#define STREAMER_TYPE_OBJECT (0)
#define STREAMER_TYPE_PICKUP (1)
#define STREAMER_TYPE_CP (2)
#define STREAMER_TYPE_RACE_CP (3)
#define STREAMER_TYPE_MAP_ICON (4)
#define STREAMER_TYPE_3D_TEXT_LABEL (5)
#define STREAMER_TYPE_AREA (6)

// Enumerator

enum
{
	E_STREAMER_ATTACHED_PLAYER,
	E_STREAMER_ATTACHED_VEHICLE,
	E_STREAMER_COLOR,
	E_STREAMER_DISTANCE,
	E_STREAMER_DRAW_DISTANCE,
	E_STREAMER_EXTRA_ID,
	E_STREAMER_INTERIOR_ID,
	E_STREAMER_MARKER_TYPE,
	E_STREAMER_MAX_X,
	E_STREAMER_MAX_Y,
	E_STREAMER_MAX_Z,
	E_STREAMER_MIN_X,
	E_STREAMER_MIN_Y,
	E_STREAMER_MIN_Z,
	E_STREAMER_MODEL_ID,
	E_STREAMER_NEXT_X,
	E_STREAMER_NEXT_Y,
	E_STREAMER_NEXT_Z,
	E_STREAMER_PLAYER_ID,
	E_STREAMER_R_X,
	E_STREAMER_R_Y,
	E_STREAMER_R_Z,
	E_STREAMER_SIZE,
	E_STREAMER_TEST_LOS,
	E_STREAMER_TYPE,
	E_STREAMER_WORLD_ID,
	E_STREAMER_X,
	E_STREAMER_Y,
	E_STREAMER_Z
}

// Natives (Settings)

native Streamer_TickRate(rate);
native Streamer_MaxItems(type, items);
native Streamer_VisibleItems(type, items);

// Natives (Updates)

native Streamer_Update(playerid);
native Streamer_UpdateEx(playerid, Float:x, Float:y, Float:z);

// Natives (Data Manipulation)

native Streamer_GetFloatData(type, {Text3D,_}:id, data, &Float:result);
native Streamer_GetIntData(type, {Text3D,_}:id, data);
native Streamer_SetFloatData(type, {Text3D,_}:id, data, Float:value);
native Streamer_SetIntData(type, {Text3D,_}:id, data, value);
native Streamer_GetUpperBound(type);

// Natives (Miscellaneous)

native Streamer_IsItemVisible(playerid, type, {Text3D,_}:id);
native Streamer_DestroyAllVisibleItems(playerid, type);
native Streamer_CountVisibleItems(playerid, type);

// Natives (Objects)

native CreateDynamicObject(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 200.0);
native DestroyDynamicObject(objectid);
native IsValidDynamicObject(objectid);
native SetDynamicObjectPos(objectid, Float:x, Float:y, Float:z);
native GetDynamicObjectPos(objectid, &Float:x, &Float:y, &Float:z);
native SetDynamicObjectRot(objectid, Float:rx, Float:ry, Float:rz);
native GetDynamicObjectRot(objectid, &Float:rx, &Float:ry, &Float:rz);
native MoveDynamicObject(objectid, Float:x, Float:y, Float:z, Float:speed);
native StopDynamicObject(objectid);
native DestroyAllDynamicObjects();
native CountDynamicObjects();

// Natives (Pickups)

native CreateDynamicPickup(modelid, type, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 100.0);
native DestroyDynamicPickup(pickupid);
native IsValidDynamicPickup(pickupid);
native DestroyAllDynamicPickups();
native CountDynamicPickups();

// Natives (Checkpoints)

native CreateDynamicCP(Float:x, Float:y, Float:z, Float:size, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 100.0);
native DestroyDynamicCP(checkpointid);
native IsValidDynamicCP(checkpointid);
native TogglePlayerDynamicCP(playerid, checkpointid, toggle);
native TogglePlayerAllDynamicCPs(playerid, toggle);
native IsPlayerInDynamicCP(playerid, checkpointid);
native DestroyAllDynamicCPs();
native CountDynamicCPs();

// Natives (Race Checkpoints)

native CreateDynamicRaceCP(type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 100.0);
native DestroyDynamicRaceCP(checkpointid);
native IsValidDynamicRaceCP(checkpointid);
native TogglePlayerDynamicRaceCP(playerid, checkpointid, toggle);
native TogglePlayerAllDynamicRaceCPs(playerid, toggle);
native IsPlayerInDynamicRaceCP(playerid, checkpointid);
native DestroyAllDynamicRaceCPs();
native CountDynamicRaceCPs();

// Natives (Map Icons)

native CreateDynamicMapIcon(Float:x, Float:y, Float:z, markertype, color, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 100.0);
native DestroyDynamicMapIcon(iconid);
native IsValidDynamicMapIcon(iconid);
native DestroyAllDynamicMapIcons();
native CountDynamicMapIcons();

// Natives (3D Text Labels)

native Text3D:CreateDynamic3DTextLabel(const text[], color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testlos = 0, worldid = -1, interiorid = -1, playerid = -1, Float:distance = 100.0);
native DestroyDynamic3DTextLabel(Text3D:id);
native IsValidDynamic3DTextLabel(Text3D:id);
native UpdateDynamic3DTextLabelText(Text3D:id, color, const text[]);
native DestroyAllDynamic3DTextLabels();
native CountDynamic3DTextLabels();

// Natives (Areas)

native CreateDynamicCircle(Float:x, Float:y, Float:size, worldid = -1, interiorid = -1, playerid = -1);
native CreateDynamicRectangle(Float:minx, Float:miny, Float:maxx, Float:maxy, worldid = -1, interiorid = -1, playerid = -1);
native CreateDynamicSphere(Float:x, Float:y, Float:z, Float:size, worldid = -1, interiorid = -1, playerid = -1);
native CreateDynamicCube(Float:minx, Float:miny, Float:minz, Float:maxx, Float:maxy, Float:maxz, worldid = -1, interiorid = -1, playerid = -1);
native DestroyDynamicArea(areaid);
native IsValidDynamicArea(areaid);
native TogglePlayerDynamicArea(playerid, areaid, toggle);
native TogglePlayerAllDynamicAreas(playerid, toggle);
native IsPlayerInDynamicArea(playerid, areaid);
native DestroyAllDynamicAreas();
native CountDynamicAreas();

// Natives (Internals)

native Streamer_AddPlayer(playerid);
native Streamer_RemovePlayer(playerid);
native Streamer_VerifyPickup(playerid, pickupid);
native Streamer_VerifyCheckpoint(playerid, type, status);
native Streamer_RegisterInterface();

// Callbacks

forward OnDynamicObjectMoved(objectid);
forward OnPlayerPickUpDynamicPickup(playerid, pickupid);
forward OnPlayerEnterDynamicCP(playerid, checkpointid);
forward OnPlayerLeaveDynamicCP(playerid, checkpointid);
forward OnPlayerEnterDynamicRaceCP(playerid, checkpointid);
forward OnPlayerLeaveDynamicRaceCP(playerid, checkpointid);
forward OnPlayerEnterDynamicArea(playerid, areaid);
forward OnPlayerLeaveDynamicArea(playerid, areaid);

// Automatic Setup System

static
	bool:Streamer_g_OPC = false,
	bool:Streamer_g_OPDC = false,
	bool:Streamer_g_OPPP = false,
	bool:Streamer_g_OPEC = false,
	bool:Streamer_g_OPLC = false,
	bool:Streamer_g_OPERC = false,
	bool:Streamer_g_OPLRC = false,
	bool:Streamer_g_RI = false;

public
	OnFilterScriptInit()
{
	if (!Streamer_g_RI)
	{
		Streamer_g_OPC = funcidx("Streamer_OnPlayerConnect") != -1;
		Streamer_g_OPDC = funcidx("Streamer_OnPlayerDisconnect") != -1;
		Streamer_g_OPPP = funcidx("Streamer_OnPlayerPickUpPickup") != -1;
		Streamer_g_OPEC = funcidx("Streamer_OnPlayerEnterCP") != -1;
		Streamer_g_OPLC = funcidx("Streamer_OnPlayerLeaveCP") != -1;
		Streamer_g_OPERC = funcidx("Streamer_OnPlayerEnterRaceCP") != -1;
		Streamer_g_OPLRC = funcidx("Streamer_OnPlayerLeaveRaceCP") != -1;
		Streamer_g_RI = true;
		Streamer_RegisterInterface();
	}
	if (funcidx("Streamer_OnFilterScriptInit") != -1)
	{
		return CallLocalFunction("Streamer_OnFilterScriptInit", "");
	}
	return 1;
}

#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit Streamer_OnFilterScriptInit

forward
	Streamer_OnFilterScriptInit();

public
	OnGameModeInit()
{
	if (!Streamer_g_RI)
	{
		Streamer_g_OPC = funcidx("Streamer_OnPlayerConnect") != -1;
		Streamer_g_OPDC = funcidx("Streamer_OnPlayerDisconnect") != -1;
		Streamer_g_OPPP = funcidx("Streamer_OnPlayerPickUpPickup") != -1;
		Streamer_g_OPEC = funcidx("Streamer_OnPlayerEnterCP") != -1;
		Streamer_g_OPLC = funcidx("Streamer_OnPlayerLeaveCP") != -1;
		Streamer_g_OPERC = funcidx("Streamer_OnPlayerEnterRaceCP") != -1;
		Streamer_g_OPLRC = funcidx("Streamer_OnPlayerLeaveRaceCP") != -1;
		Streamer_g_RI = true;
		Streamer_RegisterInterface();
	}
	if (funcidx("Streamer_OnGameModeInit") != -1)
	{
		return CallLocalFunction("Streamer_OnGameModeInit", "");
	}
	return 1;
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit Streamer_OnGameModeInit

forward
	Streamer_OnGameModeInit();

public
	OnPlayerConnect(playerid)
{
	if (!IsPlayerNPC(playerid))
	{
		Streamer_AddPlayer(playerid);
	}
	if (Streamer_g_OPC)
	{
		return CallLocalFunction("Streamer_OnPlayerConnect", "d", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect Streamer_OnPlayerConnect

forward
	Streamer_OnPlayerConnect(playerid);

public
	OnPlayerDisconnect(playerid, reason)
{
	if (!IsPlayerNPC(playerid))
	{
		Streamer_RemovePlayer(playerid);
	}
	if (Streamer_g_OPDC)
	{
		return CallLocalFunction("Streamer_OnPlayerDisconnect", "dd", playerid, reason);
	}
	return 1;
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect Streamer_OnPlayerDisconnect

forward
	Streamer_OnPlayerDisconnect(playerid, reason);

public
	OnPlayerPickUpPickup(playerid, pickupid)
{
	Streamer_VerifyPickup(playerid, pickupid);
	if (Streamer_g_OPPP)
	{
		return CallLocalFunction("Streamer_OnPlayerPickUpPickup", "dd", playerid, pickupid);
	}
	return 1;
}

#if defined _ALS_OnPlayerPickUpPickup
	#undef OnPlayerPickUpPickup
#else
	#define _ALS_OnPlayerPickUpPickup
#endif
#define OnPlayerPickUpPickup Streamer_OnPlayerPickUpPickup

forward
	Streamer_OnPlayerPickUpPickup(playerid, pickupid);

public
	OnPlayerEnterCheckpoint(playerid)
{
	Streamer_VerifyCheckpoint(playerid, STREAMER_TYPE_CP, 0);
	if (Streamer_g_OPEC)
	{
		return CallLocalFunction("Streamer_OnPlayerEnterCP", "d", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerEnterCP
	#undef OnPlayerEnterCheckpoint
#else
	#define _ALS_OnPlayerEnterCP
#endif
#define OnPlayerEnterCheckpoint Streamer_OnPlayerEnterCP

forward
	Streamer_OnPlayerEnterCP(playerid);

public
	OnPlayerLeaveCheckpoint(playerid)
{
	Streamer_VerifyCheckpoint(playerid, STREAMER_TYPE_CP, 1);
	if (Streamer_g_OPLC)
	{
		return CallLocalFunction("Streamer_OnPlayerLeaveCP", "d", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerLeaveCP
	#undef OnPlayerLeaveCheckpoint
#else
	#define _ALS_OnPlayerLeaveCP
#endif
#define OnPlayerLeaveCheckpoint Streamer_OnPlayerLeaveCP

forward
	Streamer_OnPlayerLeaveCP(playerid);

public
	OnPlayerEnterRaceCheckpoint(playerid)
{
	Streamer_VerifyCheckpoint(playerid, STREAMER_TYPE_RACE_CP, 0);
	if (Streamer_g_OPERC)
	{
		return CallLocalFunction("Streamer_OnPlayerEnterRaceCP", "d", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerEnterRaceCP
	#undef OnPlayerEnterRaceCheckpoint
#else
	#define _ALS_OnPlayerEnterRaceCP
#endif
#define OnPlayerEnterRaceCheckpoint Streamer_OnPlayerEnterRaceCP

forward
	Streamer_OnPlayerEnterRaceCP(playerid);

public
	OnPlayerLeaveRaceCheckpoint(playerid)
{
	Streamer_VerifyCheckpoint(playerid, STREAMER_TYPE_RACE_CP, 1);
	if (Streamer_g_OPLRC)
	{
		return CallLocalFunction("Streamer_OnPlayerLeaveRaceCP", "d", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerLeaveRaceCP
	#undef OnPlayerLeaveRaceCheckpoint
#else
	#define _ALS_OnPlayerLeaveRaceCP
#endif
#define OnPlayerLeaveRaceCheckpoint Streamer_OnPlayerLeaveRaceCP

forward
	Streamer_OnPlayerLeaveRaceCP(playerid);

// PAWN Invoke Section

forward
	Streamer_PublicFunction();

public
	Streamer_PublicFunction()
{
	new
		Float:value;
	CreatePickup(0, 0, 0.0, 0.0, 0.0, 0);
	CreatePlayer3DTextLabel(0, "", 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0);
	CreatePlayerObject(0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	DeletePlayer3DTextLabel(0, PlayerText3D:0);
	DestroyPickup(0);
	DestroyPlayerObject(0, 0);
	DisablePlayerCheckpoint(0);
	DisablePlayerRaceCheckpoint(0);
	GetPlayerInterior(0);
	GetPlayerPos(0, value, value, value);
	GetPlayerState(0);
	GetPlayerVirtualWorld(0);
	GetVehiclePos(0, value, value, value);
	MovePlayerObject(0, 0, 0.0, 0.0, 0.0, 0.0);
	RemovePlayerMapIcon(0, 0);
	SetPlayerCheckpoint(0, 0.0, 0.0, 0.0, 0.0);
	SetPlayerMapIcon(0, 0, 0.0, 0.0, 0.0, 0, 0);
	SetPlayerObjectPos(0, 0, 0.0, 0.0, 0.0);
	SetPlayerObjectRot(0, 0, 0.0, 0.0, 0.0);
	SetPlayerRaceCheckpoint(0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	StopPlayerObject(0, 0);
	UpdatePlayer3DTextLabelText(0, PlayerText3D:0, 0, "");
	return 1;
}


/*
    SA-MP Audio Plugin v0.5
    Copyright ?2011 Incognito

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <a_samp>

// Main Natives

native Audio_CreateTCPServer(port);
native Audio_DestroyTCPServer();
native Audio_SetPack(const name[], bool:transferable = true, bool:automated = true);
native Audio_IsClientConnected(playerid);
native Audio_SendMessage(playerid, const message[]);
native Audio_TransferPack(playerid);

// Sequence Natives

native Audio_CreateSequence();
native Audio_DestroySequence(sequenceid);
native Audio_AddToSequence(sequenceid, audioid);
native Audio_RemoveFromSequence(sequenceid, audioid);

// Audio Natives

native Audio_Play(playerid, audioid, bool:pause = false, bool:loop = false, bool:downmix = false);
native Audio_PlayStreamed(playerid, const url[], bool:pause = false, bool:loop = false, bool:downmix = false);
native Audio_PlaySequence(playerid, sequenceid, bool:pause = false, bool:loop = false, bool:downmix = false);
native Audio_Pause(playerid, handleid);
native Audio_Resume(playerid, handleid);
native Audio_Stop(playerid, handleid);
native Audio_Restart(playerid, handleid);
native Audio_GetPosition(playerid, handleid, const callback[] = "Audio_OnGetPosition");
native Audio_SetPosition(playerid, handleid, seconds);
native Audio_SetVolume(playerid, handleid, volume);
native Audio_SetFX(playerid, handleid, type);
native Audio_RemoveFX(playerid, handleid, type);
native Audio_Set3DPosition(playerid, handleid, Float:x, Float:y, Float:z, Float:distance);
native Audio_Remove3DPosition(playerid, handleid);

// Radio Station Natives

native Audio_SetRadioStation(playerid, station);
native Audio_StopRadio(playerid);

// Internal Natives

native Audio_AddPlayer(playerid, const ip[], const name[]);
native Audio_RenamePlayer(playerid, const name[]);
native Audio_RemovePlayer(playerid);

// Main Callbacks

forward Audio_OnClientConnect(playerid);
forward Audio_OnClientDisconnect(playerid);
forward Audio_OnTransferFile(playerid, file[], current, total, result);
forward Audio_OnPlay(playerid, handleid);
forward Audio_OnStop(playerid, handleid);
forward Audio_OnTrackChange(playerid, handleid, track[]);
forward Audio_OnRadioStationChange(playerid, station);

// Custom Callbacks

forward Audio_OnGetPosition(playerid, handleid, seconds);

// Callback Hook Section

static bool:Audio_g_CTS = false;
static bool:Audio_g_OPC = false;
static bool:Audio_g_OPDC = false;

public OnFilterScriptInit()
{
	if (!Audio_g_CTS)
	{
		Audio_g_CTS = true;
		Audio_g_OPC = (funcidx("Audio_OnPlayerConnect") != -1);
		Audio_g_OPDC = (funcidx("Audio_OnPlayerDisconnect") != -1);
		Audio_CreateTCPServer(GetServerVarAsInt("port"));
	}
	if (funcidx("Audio_OnFilterScriptInit") != -1)
	{
		return CallLocalFunction("Audio_OnFilterScriptInit", "");
	}
	return 1;
}

#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit Audio_OnFilterScriptInit

forward Audio_OnFilterScriptInit();

public OnGameModeInit()
{
	if (!Audio_g_CTS)
	{
		Audio_g_CTS = true;
		Audio_g_OPC = (funcidx("Audio_OnPlayerConnect") != -1);
		Audio_g_OPDC = (funcidx("Audio_OnPlayerDisconnect") != -1);
		Audio_CreateTCPServer(GetServerVarAsInt("port"));
	}
	if (funcidx("Audio_OnGameModeInit") != -1)
	{
		return CallLocalFunction("Audio_OnGameModeInit", "");
	}
	return 1;
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit Audio_OnGameModeInit

forward Audio_OnGameModeInit();

public OnPlayerConnect(playerid)
{
	if (!IsPlayerNPC(playerid))
	{
		new ip[16], name[MAX_PLAYER_NAME];
		GetPlayerIp(playerid, ip, sizeof(ip));
		GetPlayerName(playerid, name, sizeof(name));
		Audio_AddPlayer(playerid, ip, name);
	}
	if (Audio_g_OPC)
	{
		return CallLocalFunction("Audio_OnPlayerConnect", "d", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect Audio_OnPlayerConnect

forward Audio_OnPlayerConnect(playerid);

public OnPlayerDisconnect(playerid, reason)
{
	if (!IsPlayerNPC(playerid))
	{
		Audio_RemovePlayer(playerid);
	}
	if (Audio_g_OPDC)
	{
		return CallLocalFunction("Audio_OnPlayerDisconnect", "dd", playerid, reason);
	}
	return 1;
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect Audio_OnPlayerDisconnect

forward Audio_OnPlayerDisconnect(playerid, reason);

// Native Hook Section

stock Audio_SetPlayerName(playerid, name[])
{
	new value = SetPlayerName(playerid, name);
	if (value > 0)
	{
		Audio_RenamePlayer(playerid, name);
	}
	return value;
}
#if defined _ALS_SetPlayerName
	#undef SetPlayerName
#else
	#define _ALS_SetPlayerName
#endif
#define SetPlayerName Audio_SetPlayerName
