
/*

Beta Standard Header v1.42

(c) Copyleft 2005-2007, BSGDT beta6

*/

#if defined _beta_included
  #endinput
#endif
#define _beta_included
#pragma library beta

#include <a_samp>
#include <core>
#include <float>
#include <string>
#include <file>
#include <time>
#include <datagram>

#pragma tabsize 0

// Colors

#if !defined UNUSE_COLOR
#define BETAC_LIMEGREEN 	0x32CD32AA
#define BETAC_BLACK 		0x000000AA
#define BETAC_YELLOWS 		0xFFFF82AA
#define BETAC_ORCHID 		0xDA70D6AA
#define BETAC_FIREBRICK 	0xB22222AA
#define BETAC_GOLD 		0xFFD700AA
#define BETAC_OLIVE 		0x808000AA
#define BETAC_LIMEGREEN		0x32CD32AA
#define BETAC_GREY 		0xAFAFAFAA
#define BETAC_GREEN 		0x33AA33AA
#define BETAC_RED 		0xAA3333AA
#define BETAC_YELLOW 		0xFFFF00AA
#define BETAC_WHITE 		0xFFFFFFAA
#define BETAC_BLUE 		0x0000BBAA
#define BETAC_LIGHTBLUE 	0x33CCFFAA
#define BETAC_ORANGE 		0xFF9900AA
#define BETAC_SYSTEM 		0xF5FF9FAA
#endif

// Variable

#if !defined UNUSE_VAR
#define int new
#define long new
#define char new
#define Dim new
#define var new
#define void new
#define short new
#define auto new
#define private new
#define Global new
#define LOCAL new
#define function public
#define unsigned assert
#endif

// Virtual Basic

#if !defined UNUSE_VB
#define IF if(
#define ENDIF }
#define ELSE else
#define THEN ){

#define Select switch
#define Case case
#define CaseElse default

#define Do while
#define While (
#define Until (
#define Loop }

#define AND &&
#define OR ||
#define NOT !

#define Nothing 0

#define End }
#endif

//Other

#if !defined UNUSE_OTH
#define NULL 0
#define RELEASE 0
#define undefined 0
//#define typedef forward
#define using native
#define OTHERWISE default
#endif

// Operator

#if !defined UNUSE_OPE
#define PLUS +
#define MINUS -
#define MPC *
#define DIV /
#define MOD %
#endif

#if !defined UNUSE_FUNCTIONS

//forwards

forward BetPlayerName(playerid);
forward BetPlayerIP(playerid);
forward SendClientMessageToAdmins(color, const str[]);
forward GivePlayerMoneyToAdmins(money);
forward GivePlayerWeaponToAdmins(weaponid,ammo);
forward SetPlayerHealthToAdmins(Float:health);
forward SaveIPAdress(playerid);
forward ClearIPAdress(playerid);
forward CheckResidentRegistrationNumber_FirstNumber(input_value[]);
//forward InStr(string[],findstring[]);
forward Float:BetPlayerPosX(playerid);
forward Float:BetPlayerPosY(playerid);
forward Float:BetPlayerPosZ(playerid);
forward Float:BetVehiclePosX(Vehicleid);
forward Float:BetVehiclePosY(Vehicleid);
forward Float:BetVehiclePosZ(Vehicleid);

#define CRR_FN CheckResidentRegistrationNumber_FirstNumber

//functions

char bettempplayerip[200][200];

stock BetPlayerName(playerid) {
  new name[MAX_PLAYER_NAME];
  GetPlayerName(playerid, name, MAX_PLAYER_NAME);
  return name;
}

stock BetPlayerIP(playerid)
{
	new playeripad[32];
	GetPlayerIp(playerid, playeripad, 32);
	return playeripad;
}


function SendClientMessageToAdmins(color, const str[])
{
for (new i = 0; i < MAX_PLAYERS; i++)
{
    if (IsPlayerConnected(i)) {
        if (IsPlayerAdmin(i)) {
            SendClientMessage(i, color, str);
        }
    }
}
}

function GivePlayerMoneyToAdmins(money)
{
for (new i = 0; i < MAX_PLAYERS; i++)
{
    if (IsPlayerConnected(i)) {
        if (IsPlayerAdmin(i)) {
            GivePlayerMoney(i,money);
        }
    }
}
}

function GivePlayerWeaponToAdmins(weaponid,ammo)
{
for (new i = 0; i < MAX_PLAYERS; i++)
{
    if (IsPlayerConnected(i)) {
        if (IsPlayerAdmin(i)) {
            GivePlayerWeapon(i, weaponid, ammo);
        }
    }
}
}

function ClearIPAdress(playerid)
{
	if(IsPlayerConnected(playerid)) {
		format(bettempplayerip[playerid],200,"");
	}
}

function SetPlayerHealthToAdmins(Float:health)
{
for (new i = 0; i < MAX_PLAYERS; i++)
{
    if (IsPlayerConnected(i)) {
        if (IsPlayerAdmin(i)) {
            SetPlayerHealth(i, health);
        }
    }
}
}

function SaveIPAdress(playerid)
{
	if(IsPlayerConnected(playerid)) {
		format(bettempplayerip[playerid],200,"%s",BetPlayerIP(playerid));
	}
}

stock GetSavedIPAdress(playerid)
{
	return bettempplayerip[playerid];
}

function CheckResidentRegistrationNumber_FirstNumber(input_value[])
{
	char thenumber[128];
	format(thenumber,128,"%s",input_value);
	if(strlen(thenumber) == 6)
	{
	char y[3];
	char m[3];
	char d[3];
	strmid(y,thenumber,0,3);
	strmid(m,thenumber,2,4);
	strmid(d,thenumber,4,6);
	if(strval(y) >= 25)
	{
		if(strval(m) <= 12 AND strval(m) >= 1)
		{
			if(strval(d) <= 31 AND strval(d) >= 1)
			{
			return 1;
			}
		}
	}
	}
	return 0;
}

/*
public InStr(string[],findstring[])
{
	
}
*/

public Float:BetPlayerPosX(playerid)
{
	new Float:x;
	new Float:y;
	new Float:z;
	GetPlayerPos(playerid,x,y,z);
	return x;
}
public Float:BetPlayerPosY(playerid)
{
	new Float:x;
	new Float:y;
	new Float:z;
	GetPlayerPos(playerid,x,y,z);
	return y;
}
public Float:BetPlayerPosZ(playerid)
{
	new Float:x;
	new Float:y;
	new Float:z;
	GetPlayerPos(playerid,x,y,z);
	return z;
}

public Float:BetVehiclePosX(Vehicleid)
{
	new Float:x;
	new Float:y;
	new Float:z;
	GetVehiclePos(Vehicleid,x,y,z);
	return x;
}
public Float:BetVehiclePosY(Vehicleid)
{
	new Float:x;
	new Float:y;
	new Float:z;
	GetVehiclePos(Vehicleid,x,y,z);
	return y;
}
public Float:BetVehiclePosZ(Vehicleid)
{
	new Float:x;
	new Float:y;
	new Float:z;
	GetVehiclePos(Vehicleid,x,y,z);
	return z;
}

#endif
