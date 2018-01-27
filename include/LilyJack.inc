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
/*
    SA-MP Streamer Plugin v2.6
    Copyright ?2012 Incognito

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

// Definitions

#define STREAMER_TYPE_OBJECT (0)
#define STREAMER_TYPE_PICKUP (1)
#define STREAMER_TYPE_CP (2)
#define STREAMER_TYPE_RACE_CP (3)
#define STREAMER_TYPE_MAP_ICON (4)
#define STREAMER_TYPE_3D_TEXT_LABEL (5)
#define STREAMER_TYPE_AREA (6)

#define STREAMER_AREA_TYPE_CIRCLE (0)
#define STREAMER_AREA_TYPE_RECTANGLE (1)
#define STREAMER_AREA_TYPE_SPHERE (2)
#define STREAMER_AREA_TYPE_CUBE (3)
#define STREAMER_AREA_TYPE_POLYGON (4)

#define STREAMER_OBJECT_TYPE_GLOBAL (0)
#define STREAMER_OBJECT_TYPE_PLAYER (1)
#define STREAMER_OBJECT_TYPE_DYNAMIC (2)

#if !defined FLOAT_INFINITY
    #define FLOAT_INFINITY (Float:0x7F800000)
#endif

// Include File Version

public Streamer_IncludeFileVersion = 0x26002;

#pragma unused Streamer_IncludeFileVersion

// Enumerator

enum
{
	E_STREAMER_ATTACHED_OBJECT,
	E_STREAMER_ATTACHED_PLAYER,
	E_STREAMER_ATTACHED_VEHICLE,
	E_STREAMER_COLOR,
	E_STREAMER_DRAW_DISTANCE,
	E_STREAMER_EXTRA_ID,
	E_STREAMER_INTERIOR_ID,
	E_STREAMER_MAX_X,
	E_STREAMER_MAX_Y,
	E_STREAMER_MAX_Z,
	E_STREAMER_MIN_X,
	E_STREAMER_MIN_Y,
	E_STREAMER_MIN_Z,
	E_STREAMER_MODEL_ID,
	E_STREAMER_MOVE_R_X,
	E_STREAMER_MOVE_R_Y,
	E_STREAMER_MOVE_R_Z,
	E_STREAMER_MOVE_SPEED,
	E_STREAMER_MOVE_X,
	E_STREAMER_MOVE_Y,
	E_STREAMER_MOVE_Z,
	E_STREAMER_NEXT_X,
	E_STREAMER_NEXT_Y,
	E_STREAMER_NEXT_Z,
	E_STREAMER_PLAYER_ID,
	E_STREAMER_R_X,
	E_STREAMER_R_Y,
	E_STREAMER_R_Z,
	E_STREAMER_SIZE,
	E_STREAMER_STREAM_DISTANCE,
	E_STREAMER_STYLE,
	E_STREAMER_TEST_LOS,
	E_STREAMER_TYPE,
	E_STREAMER_WORLD_ID,
	E_STREAMER_X,
	E_STREAMER_Y,
	E_STREAMER_Z
}

// Setting Natives

native Streamer_TickRate(rate);
native Streamer_MaxItems(type, items);
native Streamer_VisibleItems(type, items);
native Streamer_CellDistance(Float:distance);
native Streamer_CellSize(Float:size);

// Update Natives

native Streamer_ProcessActiveItems();
native Streamer_ToggleIdleUpdate(playerid, toggle);
native Streamer_Update(playerid);
native Streamer_UpdateEx(playerid, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1);

// Data Manipulation Natives

native Streamer_GetFloatData(type, {Text3D,_}:id, data, &Float:result);
native Streamer_SetFloatData(type, {Text3D,_}:id, data, Float:value);
native Streamer_GetIntData(type, {Text3D,_}:id, data);
native Streamer_SetIntData(type, {Text3D,_}:id, data, value);
native Streamer_GetArrayData(type, {Text3D,_}:id, data, dest[], maxlength = sizeof dest);
native Streamer_SetArrayData(type, {Text3D,_}:id, data, const src[], maxlength = sizeof src);
native Streamer_IsInArrayData(type, {Text3D,_}:id, data, value);
native Streamer_AppendArrayData(type, {Text3D,_}:id, data, value);
native Streamer_RemoveArrayData(type, {Text3D,_}:id, data, value);
native Streamer_GetUpperBound(type);

// Miscellaneous Natives

native Streamer_GetDistanceToItem(Float:x, Float:y, Float:z, type, {Text3D,_}:id, &Float:distance);
native Streamer_IsItemVisible(playerid, type, {Text3D,_}:id);
native Streamer_DestroyAllVisibleItems(playerid, type);
native Streamer_CountVisibleItems(playerid, type);

// Object Natives

native CreateDynamicObject(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = 300.0);
native DestroyDynamicObject(objectid);
native IsValidDynamicObject(objectid);
native SetDynamicObjectPos(objectid, Float:x, Float:y, Float:z);
native GetDynamicObjectPos(objectid, &Float:x, &Float:y, &Float:z);
native SetDynamicObjectRot(objectid, Float:rx, Float:ry, Float:rz);
native GetDynamicObjectRot(objectid, &Float:rx, &Float:ry, &Float:rz);
native MoveDynamicObject(objectid, Float:x, Float:y, Float:z, Float:speed, Float:rx = -1000.0, Float:ry = -1000.0, Float:rz = -1000.0);
native StopDynamicObject(objectid);
native IsDynamicObjectMoving(objectid);
native DestroyAllDynamicObjects();
native CountDynamicObjects();

// Pickup Natives

native CreateDynamicPickup(modelid, type, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = 100.0);
native DestroyDynamicPickup(pickupid);
native IsValidDynamicPickup(pickupid);
native DestroyAllDynamicPickups();
native CountDynamicPickups();

// Checkpoint Natives

native CreateDynamicCP(Float:x, Float:y, Float:z, Float:size, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = 100.0);
native DestroyDynamicCP(checkpointid);
native IsValidDynamicCP(checkpointid);
native TogglePlayerDynamicCP(playerid, checkpointid, toggle);
native TogglePlayerAllDynamicCPs(playerid, toggle);
native IsPlayerInDynamicCP(playerid, checkpointid);
native GetPlayerVisibleDynamicCP(playerid);
native DestroyAllDynamicCPs();
native CountDynamicCPs();

// Race Checkpoint Natives

native CreateDynamicRaceCP(type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = 100.0);
native DestroyDynamicRaceCP(checkpointid);
native IsValidDynamicRaceCP(checkpointid);
native TogglePlayerDynamicRaceCP(playerid, checkpointid, toggle);
native TogglePlayerAllDynamicRaceCPs(playerid, toggle);
native IsPlayerInDynamicRaceCP(playerid, checkpointid);
native GetPlayerVisibleDynamicRaceCP(playerid);
native DestroyAllDynamicRaceCPs();
native CountDynamicRaceCPs();

// Map Icon Natives

native CreateDynamicMapIcon(Float:x, Float:y, Float:z, type, color, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = 100.0);
native DestroyDynamicMapIcon(iconid);
native IsValidDynamicMapIcon(iconid);
native DestroyAllDynamicMapIcons();
native CountDynamicMapIcons();

// 3D Text Label Natives

native Text3D:CreateDynamic3DTextLabel(const text[], color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testlos = 0, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = 100.0);
native DestroyDynamic3DTextLabel(Text3D:id);
native IsValidDynamic3DTextLabel(Text3D:id);
native GetDynamic3DTextLabelText(Text3D:id, text[], maxlength = sizeof text);
native UpdateDynamic3DTextLabelText(Text3D:id, color, const text[]);
native DestroyAllDynamic3DTextLabels();
native CountDynamic3DTextLabels();

// Area Natives

native CreateDynamicCircle(Float:x, Float:y, Float:size, worldid = -1, interiorid = -1, playerid = -1);
native CreateDynamicRectangle(Float:minx, Float:miny, Float:maxx, Float:maxy, worldid = -1, interiorid = -1, playerid = -1);
native CreateDynamicSphere(Float:x, Float:y, Float:z, Float:size, worldid = -1, interiorid = -1, playerid = -1);
native CreateDynamicCube(Float:minx, Float:miny, Float:minz, Float:maxx, Float:maxy, Float:maxz, worldid = -1, interiorid = -1, playerid = -1);
native CreateDynamicPolygon(Float:points[], Float:minz = -FLOAT_INFINITY, Float:maxz = FLOAT_INFINITY, maxpoints = sizeof points, worldid = -1, interiorid = -1, playerid = -1);
native DestroyDynamicArea(areaid);
native IsValidDynamicArea(areaid);
native TogglePlayerDynamicArea(playerid, areaid, toggle);
native TogglePlayerAllDynamicAreas(playerid, toggle);
native IsPlayerInDynamicArea(playerid, areaid);
native IsPlayerInAnyDynamicArea(playerid);
native IsPointInDynamicArea(areaid, Float:x, Float:y, Float:z);
native IsPointInAnyDynamicArea(Float:x, Float:y, Float:z);
native AttachDynamicAreaToObject(areaid, objectid, type = STREAMER_OBJECT_TYPE_DYNAMIC, playerid = INVALID_PLAYER_ID);
native AttachDynamicAreaToPlayer(areaid, playerid);
native AttachDynamicAreaToVehicle(areaid, vehicleid);
native DestroyAllDynamicAreas();
native CountDynamicAreas();

// Extended Natives

native CreateDynamicObjectEx(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, Float:drawdistance = 0.0, Float:streamdistance = 200.0, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native CreateDynamicPickupEx(modelid, type, Float:x, Float:y, Float:z, Float:streamdistance = 100.0, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native CreateDynamicCPEx(Float:x, Float:y, Float:z, Float:size, Float:streamdistance = 100.0, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native CreateDynamicRaceCPEx(type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size, Float:streamdistance = 100.0, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native CreateDynamicMapIconEx(Float:x, Float:y, Float:z, type, color, style = MAPICON_LOCAL, Float:streamdistance = 100.0, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native Text3D:CreateDynamic3DTextLabelEx(const text[], color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testlos = 0, Float:streamdistance = 100.0, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native CreateDynamicCircleEx(Float:x, Float:y, Float:size, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native CreateDynamicRectangleEx(Float:minx, Float:miny, Float:maxx, Float:maxy, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native CreateDynamicSphereEx(Float:x, Float:y, Float:z, Float:size, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native CreateDynamicCubeEx(Float:minx, Float:miny, Float:minz, Float:maxx, Float:maxy, Float:maxz, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native CreateDynamicPolygonEx(Float:points[], Float:minz = -FLOAT_INFINITY, Float:maxz = FLOAT_INFINITY, maxpoints = sizeof points, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);

// Internal Natives

native Streamer_CallbackHook(callback, ...);

// Callbacks

forward OnDynamicObjectMoved(objectid);
forward OnPlayerPickUpDynamicPickup(playerid, pickupid);
forward OnPlayerEnterDynamicCP(playerid, checkpointid);
forward OnPlayerLeaveDynamicCP(playerid, checkpointid);
forward OnPlayerEnterDynamicRaceCP(playerid, checkpointid);
forward OnPlayerLeaveDynamicRaceCP(playerid, checkpointid);
forward OnPlayerEnterDynamicArea(playerid, areaid);
forward OnPlayerLeaveDynamicArea(playerid, areaid);

// Callback Hook Section

#define STREAMER_OPC (0)
#define STREAMER_OPDC (1)
#define STREAMER_OPPP (2)
#define STREAMER_OPEC (3)
#define STREAMER_OPLC (4)
#define STREAMER_OPERC (5)
#define STREAMER_OPLRC (6)

static bool:Streamer_g_OPC = false;
static bool:Streamer_g_OPDC = false;
static bool:Streamer_g_OPPP = false;
static bool:Streamer_g_OPEC = false;
static bool:Streamer_g_OPLC = false;
static bool:Streamer_g_OPERC = false;
static bool:Streamer_g_OPLRC = false;

public OnFilterScriptInit()
{
	Streamer_g_OPC = funcidx("Streamer_OnPlayerConnect") != -1;
	Streamer_g_OPDC = funcidx("Streamer_OnPlayerDisconnect") != -1;
	Streamer_g_OPPP = funcidx("Streamer_OnPlayerPickUpPickup") != -1;
	Streamer_g_OPEC = funcidx("Streamer_OnPlayerEnterCP") != -1;
	Streamer_g_OPLC = funcidx("Streamer_OnPlayerLeaveCP") != -1;
	Streamer_g_OPERC = funcidx("Streamer_OnPlayerEnterRaceCP") != -1;
	Streamer_g_OPLRC = funcidx("Streamer_OnPlayerLeaveRaceCP") != -1;
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

forward Streamer_OnFilterScriptInit();

public OnGameModeInit()
{
	Streamer_g_OPC = funcidx("Streamer_OnPlayerConnect") != -1;
	Streamer_g_OPDC = funcidx("Streamer_OnPlayerDisconnect") != -1;
	Streamer_g_OPPP = funcidx("Streamer_OnPlayerPickUpPickup") != -1;
	Streamer_g_OPEC = funcidx("Streamer_OnPlayerEnterCP") != -1;
	Streamer_g_OPLC = funcidx("Streamer_OnPlayerLeaveCP") != -1;
	Streamer_g_OPERC = funcidx("Streamer_OnPlayerEnterRaceCP") != -1;
	Streamer_g_OPLRC = funcidx("Streamer_OnPlayerLeaveRaceCP") != -1;
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

forward Streamer_OnGameModeInit();

public OnPlayerConnect(playerid)
{
	if (!IsPlayerNPC(playerid))
	{
		Streamer_CallbackHook(STREAMER_OPC, playerid);
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

forward Streamer_OnPlayerConnect(playerid);

public OnPlayerDisconnect(playerid, reason)
{
	if (!IsPlayerNPC(playerid))
	{
		Streamer_CallbackHook(STREAMER_OPDC, playerid, reason);
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

forward Streamer_OnPlayerDisconnect(playerid, reason);

public OnPlayerPickUpPickup(playerid, pickupid)
{
	if (!IsPlayerNPC(playerid))
	{
		Streamer_CallbackHook(STREAMER_OPPP, playerid, pickupid);
	}
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

forward Streamer_OnPlayerPickUpPickup(playerid, pickupid);

public OnPlayerEnterCheckpoint(playerid)
{
	if (!IsPlayerNPC(playerid))
	{
		Streamer_CallbackHook(STREAMER_OPEC, playerid);
	}
	if (Streamer_g_OPEC)
	{
		return CallLocalFunction("Streamer_OnPlayerEnterCP", "d", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerEnterCheckpoint
	#undef OnPlayerEnterCheckpoint
#else
	#define _ALS_OnPlayerEnterCheckpoint
#endif
#define OnPlayerEnterCheckpoint Streamer_OnPlayerEnterCP

forward Streamer_OnPlayerEnterCP(playerid);

public OnPlayerLeaveCheckpoint(playerid)
{
	if (!IsPlayerNPC(playerid))
	{
		Streamer_CallbackHook(STREAMER_OPLC, playerid);
	}
	if (Streamer_g_OPLC)
	{
		return CallLocalFunction("Streamer_OnPlayerLeaveCP", "d", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerLeaveCheckpoint
	#undef OnPlayerLeaveCheckpoint
#else
	#define _ALS_OnPlayerLeaveCheckpoint
#endif
#define OnPlayerLeaveCheckpoint Streamer_OnPlayerLeaveCP

forward Streamer_OnPlayerLeaveCP(playerid);

public OnPlayerEnterRaceCheckpoint(playerid)
{
	if (!IsPlayerNPC(playerid))
	{
		Streamer_CallbackHook(STREAMER_OPERC, playerid);
	}
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

forward Streamer_OnPlayerEnterRaceCP(playerid);

public OnPlayerLeaveRaceCheckpoint(playerid)
{
	if (!IsPlayerNPC(playerid))
	{
		Streamer_CallbackHook(STREAMER_OPLRC, playerid);
	}
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

forward Streamer_OnPlayerLeaveRaceCP(playerid);

/*
 *            Dini 1.6
 *       (c) Copyright 2006-2008 by DracoBlue
 *
 * @author    : DracoBlue (http://dracoblue.com)
 * @date      : 13th May 2006
 * @update    : 16th Sep 2008
 *
 * This file is provided as is (no warranties).
 *
 * It's released under the terms of MIT.
 *
 * Feel free to use it, a little message in
 * about box is honouring thing, isn't it?
 *
 */

#if defined _dini_included
  #endinput
#endif

#define _dini_included
#pragma library dini

#if defined MAX_STRING
#define DINI_MAX_STRING MAX_STRING
#else
#define DINI_MAX_STRING 255
#endif

stock dini_Exists(filename[]) {
	return fexist(filename);
}

stock dini_Remove(filename[]) {
	return fremove(filename);
}

stock dini_Create(filename[]) {
	if (fexist(filename)) return false;
	new File:fhnd;
	fhnd=fopen(filename,io_write);
	if (fhnd) {
		fclose(fhnd);
		return true;
	}
	return false;
}

stock dini_Set(filename[],key[],value[]) {
	// If we have no key, it can't be set
	// we also have no chance to set the value, if all together is bigger then the max string
	new key_length = strlen(key);
	new value_length = strlen(value);
	if (key_length==0 || key_length+value_length+2>DINI_MAX_STRING) return false;
	
	new File:fohnd, File:fwhnd;
	new tmpres[DINI_MAX_STRING];
	new bool:wasset=false;
	
	// Let's remove the old *.part file if there was one.
	format(tmpres,sizeof(tmpres),"%s.part",filename);
	fremove(tmpres);
	
	// We'll open the source file.
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	
	fwhnd=fopen(tmpres,io_write);
	if (!fwhnd) {
		// we can't open the second file for writing, so .. let's close the open one and exit.
		fclose(fohnd);
		return false;
	}
	
	while (fread(fohnd,tmpres)) {
		if (
			!wasset
			&& tmpres[key_length]=='='
			&& !strcmp(tmpres, key, true, key_length)	
		) {
				// We've got what needs to be replaced!
				format(tmpres,sizeof(tmpres),"%s=%s",key,value);
				wasset=true;
		} else {
			DINI_StripNewLine(tmpres);
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
	if (DINI_fcopytextfile(tmpres,filename)) {
		return fremove(tmpres);
	}
	return false;
}


stock dini_IntSet(filename[],key[],value) {
   new valuestring[DINI_MAX_STRING];
   format(valuestring,DINI_MAX_STRING,"%d",value);
   return dini_Set(filename,key,valuestring);
}

stock dini_Int(filename[],key[]) {
   return strval(dini_Get(filename,key));
}

stock dini_FloatSet(filename[],key[],Float:value) {
   new valuestring[DINI_MAX_STRING];
   format(valuestring,DINI_MAX_STRING,"%f",value);
   return dini_Set(filename,key,valuestring);
}

stock Float:dini_Float(filename[],key[]) {
   return floatstr(dini_Get(filename,key));
}

stock dini_Bool(filename[],key[]) {
   return strval(dini_Get(filename,key));
}

stock dini_BoolSet(filename[],key[],value) {
	if (value) {
		return dini_Set(filename,key,"1");
	}
	return dini_Set(filename,key,"0");
}

stock dini_Unset(filename[],key[]) {
	// If we have no key, it can't be set
	// we also have no chance to unset the key, if all together is bigger then the max string
	new key_length = strlen(key);
	if (key_length==0 || key_length+2>DINI_MAX_STRING) return false;
	
	new File:fohnd, File:fwhnd;
	new tmpres[DINI_MAX_STRING];
	
	// Let's remove the old *.part file if there was one.
	format(tmpres,DINI_MAX_STRING,"%s.part",filename);
	fremove(tmpres);
	
	// We'll open the source file.
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	
	fwhnd=fopen(tmpres,io_write);
	if (!fwhnd) {
		// we can't open the second file for writing, so .. let's close the open one and exit.
		fclose(fohnd);
		return false;
	}
	
	while (fread(fohnd,tmpres)) {
		if (
			tmpres[key_length]=='='
			&& !strcmp(tmpres, key, true, key_length)	
		) {
				// We've got what needs to be removed!
		} else {
			DINI_StripNewLine(tmpres);
			fwrite(fwhnd,tmpres);
			fwrite(fwhnd,"\r\n");
		}
	}
	
	fclose(fohnd);
	fclose(fwhnd);

	format(tmpres,DINI_MAX_STRING,"%s.part",filename);
	if (DINI_fcopytextfile(tmpres,filename)) {
		return fremove(tmpres);
	}
	return false;
}

stock dini_Get(filename[],key[]) {
	new tmpres[DINI_MAX_STRING];
	
	new key_length = strlen(key);
	if (key_length==0 || key_length+2>DINI_MAX_STRING) return tmpres;
	
	new File:fohnd;
	fohnd=fopen(filename,io_read);
	if (!fohnd) return tmpres;
	
	while (fread(fohnd,tmpres)) {
		if (
			tmpres[key_length]=='='
			&& !strcmp(tmpres, key, true, key_length)	
		) {
			/* We've got what we need */
			DINI_StripNewLine(tmpres);
			strmid(tmpres, tmpres, key_length + 1, strlen(tmpres), DINI_MAX_STRING);
			fclose(fohnd);
			return tmpres;
		}
	}
	fclose(fohnd);
	return tmpres;
}


stock dini_Isset(filename[],key[]) {
	new key_length = strlen(key);
	if (key_length==0 || key_length+2>DINI_MAX_STRING) return false;
	
	new File:fohnd;
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	
	new tmpres[DINI_MAX_STRING];
	while (fread(fohnd,tmpres)) {
		if (
				tmpres[key_length]=='='
			&&  !strcmp(tmpres, key, true, key_length)	
		) {
			// We've got what we need
			fclose(fohnd);
			return true;
		}
	}
	fclose(fohnd);
	return false;
}



stock DINI_StripNewLine(string[]) {
	new len = strlen(string);
	if (string[0]==0) return ;
	if ((string[len - 1] == '\n') || (string[len - 1] == '\r')) {
		string[len - 1] = 0;
		if (string[0]==0) return ;
		if ((string[len - 2] == '\n') || (string[len - 2] == '\r')) string[len - 2] = 0;
	}
}

stock DINI_fcopytextfile(oldname[],newname[]) {
	new File:ohnd,File:nhnd;
	if (!fexist(oldname)) return false;
	ohnd=fopen(oldname,io_read);
	if (!ohnd) return false;
	nhnd=fopen(newname,io_write);
	if (!nhnd) {
		fclose(ohnd);
		return false;
	}
	new tmpres[DINI_MAX_STRING];
	while (fread(ohnd,tmpres)) {
		DINI_StripNewLine(tmpres);
		format(tmpres,sizeof(tmpres),"%s\r\n",tmpres);
		fwrite(nhnd,tmpres);
	}
	fclose(ohnd);
	fclose(nhnd);
	return true;
}
 /*  SA-MP threaded HTTP/1.0 client for pawn
 *
 *  (c) Copyright 2010, SA-MP Team
 *
 */

// HTTP requests
#define HTTP_GET						1
#define HTTP_POST						2
#define HTTP_HEAD						3

// HTTP error response codes
// These codes compliment ordinary HTTP response codes returned in 'response_code'
// (10x) (20x OK) (30x Moved) (40x Unauthorised) (50x Server Error)  
#define HTTP_ERROR_BAD_HOST				1
#define HTTP_ERROR_NO_SOCKET			2
#define HTTP_ERROR_CANT_CONNECT			3
#define HTTP_ERROR_CANT_WRITE			4
#define HTTP_ERROR_CONTENT_TOO_BIG		5
#define HTTP_ERROR_MALFORMED_RESPONSE	6

native HTTP(index, type, url[], data[], callback[]);

// example HTTP callback: public MyHttpResponse(index, response_code, data[]) { ... }
/*
_____________________________________________________

Namo Server Header SINI
_____________________________________________________

Description:
	INI Write,Read

_____________________________________________________
Function:

    INI_Exist(filename[])
	INI_Open(filename[])
	INI_Close()
	INI_Write(section[],key[],value[])
	INI_WriteInt(section[],key[],value[])
	INI_WriteFloat(section[],key[],value[])
	INI_Read(key[],bool:seek=true)
	
_____________________________________________________

Example:

	main()
	{
		INI_Open("Test.txt",Read);
		printf("ServerName:%s",INI_Read("ServerName"));
		INI_Close();
	}

______________________________________________________
Version 0.2

______________________________________________________




*/
#if defined _SINI_included
	#endinput
#endif

#define _SINI_included
#pragma library SINI

#define MAX_FUNC_NAME 200


#if !defined DEBUG
	#define DEBUG 0
#endif



#define INI_ReadInt(%0) strval(INI_Read(%0))
#define INI_ReadFloat(%0) floatstr(INI_Read(%0))

#if !defined MAX_STRING
	#define MAX_STRING 255
#endif

new
	File:g_hIniFile,
	bool:g_bOpend = false,
	e_fmode:g_efmode;
	
enum
	e_fmode{ Read , Write };

stock INI_Exist(filename[])
{
	if(fexist(filename)) return 1;
	else return 0;
}
stock INI_Open(filename[],e_fmode:fmode)
{
	if(fexist(filename) || fmode==Write)
	{
		if(g_bOpend) fclose(g_hIniFile);
		g_hIniFile=fopen(filename,(fmode==Read)?io_read:io_write);
		g_efmode=fmode;
		g_bOpend=true;
	}
	return 1;
}
stock INI_Close()
{
	if(g_bOpend==true )
	{
		g_bOpend=false;
		fclose(g_hIniFile);
	}
}
stock INI_WriteFloat(key[],Float:value)
{
	new szBuf[MAX_STRING];
	format(szBuf,sizeof szBuf,"%f",value);
	return INI_Write(key,szBuf);
}
stock INI_WriteInt(key[],value)
{
	new szBuf[MAX_STRING];
	format(szBuf,sizeof szBuf,"%d",value);
	return INI_Write(key,szBuf);
}

stock INI_Write(key[],value[])
{
	new
		szBuf[MAX_STRING];
	
    if(!g_bOpend||g_efmode!=Write) return 0;

	format(szBuf,sizeof szBuf,"%s=%s",key,value);
	for(new i=0,l=strlen(key)+strlen(value)+1; i<l; i++)
	{
	    fputchar(g_hIniFile,szBuf[i],false);
	}
	fwrite(g_hIniFile,"\r\n");
	return 1;
}

stock INI_Read(key[],bool:seek=true)
{
    if(!g_bOpend||g_efmode!=Read) goto turn;

	
	new
		szReadBuf[MAX_STRING],
		sResult[MAX_STRING];

	if(seek)fseek(g_hIniFile);
	while(fread(g_hIniFile,szReadBuf) )
	{
		szReadBuf[(strfind(szReadBuf,"\n")!=-1)?strfind(szReadBuf,"\n")-1:
		(strfind(szReadBuf,"\r")!=-1)?strfind(szReadBuf,"\r")-1:strlen(szReadBuf)]=EOS;
	    if(strcmp(szReadBuf,key,false,strlen(key))==0 &&strfind(szReadBuf,"=")!=-1  &&strlen(key)==strfind(szReadBuf,"="))
	    {
	        strmid(sResult,szReadBuf,strfind(szReadBuf,"=")+1,strlen(szReadBuf),255);
			return sResult;
		}
	}
	turn:return sResult;
}

/*
 * Copyright (C) 2012 Incognito
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Definitions

#define GLOBAL_VARTYPE_NONE (0)
#define GLOBAL_VARTYPE_INT (1)
#define GLOBAL_VARTYPE_STRING (2)
#define GLOBAL_VARTYPE_FLOAT (3)

// Natives

native SetGVarInt(const name[], value, id = 0);
native GetGVarInt(const name[], id = 0);
native SetGVarString(const name[], const value[], id = 0);
native GetGVarString(const name[], dest[], maxlength = sizeof dest, id = 0);
native SetGVarFloat(const name[], Float:value, id = 0);
native Float:GetGVarFloat(const name[], id = 0);
native DeleteGVar(const name[], id = 0);
native GetGVarsUpperIndex(id = 0);
native GetGVarNameAtIndex(index, dest[], maxlength = sizeof dest, id = 0);
native GetGVarType(const name[], id = 0);
/*
	Çª¸¥¹Ù
*/

#if defined _puni_included
  #endinput
#endif

#define _puni_included
#pragma library dini

#if defined MAX_STRING
#define PUNI_MAX_STRING MAX_STRING
#else
#define PUNI_MAX_STRING 255
#endif

write(File:handle,const string[])
	for(new i=0; i<strlen(string); i++)
		fputchar(handle,string[i],false);

stock puni_Write(filename[], const string[])
{
	new File:handle;
	handle = fopen(filename, io_readwrite);
	write(handle, string);
	write(handle, "\r\n");
	fclose(handle);
}

stock puni_Exists(filename[]) {
	return fexist(filename);
}

stock puni_Remove(filename[]) {
	return fremove(filename);
}

stock puni_Create(filename[]) {
	if (fexist(filename)) return false;
	new File:fhnd;
	fhnd=fopen(filename,io_write);
	if (fhnd) {
		fclose(fhnd);
		return true;
	}
	return false;
}

stock puni_Set(filename[],key[],value[]) {
	// If we have no key, it can't be set
	// we also have no chance to set the value, if all together is bigger then the max string
	new key_length = strlen(key);
	new value_length = strlen(value);
	if (key_length==0 || key_length+value_length+2>PUNI_MAX_STRING) return false;
	
	new File:fohnd, File:fwhnd;
	new tmpres[PUNI_MAX_STRING];
	new bool:wasset=false;
	
	// Let's remove the old *.part file if there was one.
	format(tmpres,sizeof(tmpres),"%s.part",filename);
	fremove(tmpres);
	
	// We'll open the source file.
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	
	fwhnd=fopen(tmpres,io_write);
	if (!fwhnd) {
		// we can't open the second file for writing, so .. let's close the open one and exit.
		fclose(fohnd);
		return false;
	}
	
	while (fread(fohnd,tmpres)) {
		if (
			!wasset
			&& tmpres[key_length]=='='
			&& !strcmp(tmpres, key, true, key_length)	
		) {
				// We've got what needs to be replaced!
				format(tmpres,sizeof(tmpres),"%s=%s",key,value);
				wasset=true;
		} else {
			PUNI_StripNewLine(tmpres);
		}
		write(fwhnd,tmpres);
		write(fwhnd,"\r\n");
	}

	if (!wasset) {
		format(tmpres,sizeof(tmpres),"%s=%s",key,value);
		write(fwhnd,tmpres);
		write(fwhnd,"\r\n");
	}

	fclose(fohnd);
	fclose(fwhnd);

	format(tmpres,sizeof(tmpres),"%s.part",filename);
	if (PUNI_fcopytextfile(tmpres,filename)) {
		return fremove(tmpres);
	}
	return false;
}


stock puni_IntSet(filename[],key[],value) {
   new valuestring[PUNI_MAX_STRING];
   format(valuestring,PUNI_MAX_STRING,"%d",value);
   return puni_Set(filename,key,valuestring);
}

stock puni_Int(filename[],key[]) {
   return strval(puni_Get(filename,key));
}

stock puni_FloatSet(filename[],key[],Float:value) {
   new valuestring[PUNI_MAX_STRING];
   format(valuestring,PUNI_MAX_STRING,"%f",value);
   return puni_Set(filename,key,valuestring);
}

stock Float:puni_Float(filename[],key[]) {
   return floatstr(puni_Get(filename,key));
}

stock puni_Bool(filename[],key[]) {
   return strval(puni_Get(filename,key));
}

stock puni_BoolSet(filename[],key[],value) {
	if (value) {
		return puni_Set(filename,key,"1");
	}
	return puni_Set(filename,key,"0");
}

stock puni_Unset(filename[],key[]) {
	// If we have no key, it can't be set
	// we also have no chance to unset the key, if all together is bigger then the max string
	new key_length = strlen(key);
	if (key_length==0 || key_length+2>PUNI_MAX_STRING) return false;
	
	new File:fohnd, File:fwhnd;
	new tmpres[PUNI_MAX_STRING];
	
	// Let's remove the old *.part file if there was one.
	format(tmpres,PUNI_MAX_STRING,"%s.part",filename);
	fremove(tmpres);
	
	// We'll open the source file.
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	
	fwhnd=fopen(tmpres,io_write);
	if (!fwhnd) {
		// we can't open the second file for writing, so .. let's close the open one and exit.
		fclose(fohnd);
		return false;
	}
	
	while (fread(fohnd,tmpres)) {
		if (
			tmpres[key_length]=='='
			&& !strcmp(tmpres, key, true, key_length)	
		) {
				// We've got what needs to be removed!
		} else {
			PUNI_StripNewLine(tmpres);
			write(fwhnd,tmpres);
			write(fwhnd,"\r\n");
		}
	}
	
	fclose(fohnd);
	fclose(fwhnd);

	format(tmpres,PUNI_MAX_STRING,"%s.part",filename);
	if (PUNI_fcopytextfile(tmpres,filename)) {
		return fremove(tmpres);
	}
	return false;
}

stock puni_Get(filename[],key[]) {
	new tmpres[PUNI_MAX_STRING];
	
	new key_length = strlen(key);
	if (key_length==0 || key_length+2>PUNI_MAX_STRING) return tmpres;
	
	new File:fohnd;
	fohnd=fopen(filename,io_read);
	if (!fohnd) return tmpres;
	
	while (fread(fohnd,tmpres)) {
		if (
			tmpres[key_length]=='='
			&& !strcmp(tmpres, key, true, key_length)	
		) {
			/* We've got what we need */
			PUNI_StripNewLine(tmpres);
			strmid(tmpres, tmpres, key_length + 1, strlen(tmpres), PUNI_MAX_STRING);
			fclose(fohnd);
			return tmpres;
		}
	}
	fclose(fohnd);
	return tmpres;
}


stock puni_Isset(filename[],key[]) {
	new key_length = strlen(key);
	if (key_length==0 || key_length+2>PUNI_MAX_STRING) return false;
	
	new File:fohnd;
	fohnd=fopen(filename,io_read);
	if (!fohnd) return false;
	
	new tmpres[PUNI_MAX_STRING];
	while (fread(fohnd,tmpres)) {
		if (
				tmpres[key_length]=='='
			&&  !strcmp(tmpres, key, true, key_length)	
		) {
			// We've got what we need
			fclose(fohnd);
			return true;
		}
	}
	fclose(fohnd);
	return false;
}



stock PUNI_StripNewLine(string[]) {
	new len = strlen(string);
	if (string[0]==0) return ;
	if ((string[len - 1] == '\n') || (string[len - 1] == '\r')) {
		string[len - 1] = 0;
		if (string[0]==0) return ;
		if ((string[len - 2] == '\n') || (string[len - 2] == '\r')) string[len - 2] = 0;
	}
}

stock PUNI_fcopytextfile(oldname[],newname[]) {
	new File:ohnd,File:nhnd;
	if (!fexist(oldname)) return false;
	ohnd=fopen(oldname,io_read);
	if (!ohnd) return false;
	nhnd=fopen(newname,io_write);
	if (!nhnd) {
		fclose(ohnd);
		return false;
	}
	new tmpres[PUNI_MAX_STRING];
	while (fread(ohnd,tmpres)) {
		PUNI_StripNewLine(tmpres);
		format(tmpres,sizeof(tmpres),"%s\r\n",tmpres);
		write(nhnd,tmpres);
	}
	fclose(ohnd);
	fclose(nhnd);
	return true;
}





