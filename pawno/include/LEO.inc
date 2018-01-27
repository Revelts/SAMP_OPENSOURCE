#include <a_samp>
#include <float>
#include <time>
#include <file>
#include <utils>
#include <morphinc>
#include <veh>
#include <Dini>
#include <gameinfo>
#include <streamer>
#define TextBox         true   //텍스트박스 사용여부
#define TextTopLines    true   //텍스트 탑라인 사용여부
#define TextSideLines   false   //텍스트 사이드라인 사용여부
#define BoxColor         0xffffffff     //박스의 색
#define SideLinesColor   0xffffffff     //사이드라인의 색
#define TopLinesColor    0xffffffff     //탑라인의 색
#define CategoriesColor  "~b~"          //정보창의 색
#define MPH_KPH_Color    "~g~"          //속도계의 색
#define Public:%0(%1)  forward %0(%1); \
      public %0(%1)
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#define COLOR_YELLOW2 0xF5DEB3AA
#define COLOR_YELLOW 0xFFFF00AA
#define COLOR_PURPLE 0xC2A2DAAA
#define COLOR_ERROR 0xB4B5B7FF//회색 (에러)
#define COLOR_GREY 0xB4B5B7FF//회색 (에러)
#define COLOR_INFO 0xFFFFFFFF//하얀색 (정보)
#define COLOR_HINT 0x99FFCCAA//밝은하늘색 (힌트)
#define COLOR_SUC 0x99CCFF00//푸른색 (완료)
#define COLOR_ACT 0xC2A2DAAA//보라색 (행동)
#define COLOR_ADMIN 0xF64D69AA//밝은빨강색(관리자~~)
#define COLOR_SUN 0xF64D69FF//선모양할때(밝은빨강)//보라색 0xCE96EDFF
#define COLOR_ADMIN1 0xFF8000FF//관리자명령어 (공지사항) , (칭찬) , (차감)
#define COLOR_YELLOW3 0xFFFF00AA // 노란색 확성기 색
#define COLOR_RED 0xC94445AA // 붉은색 (경고)
#define COLOR_BLUE 0x2641FEAA // 파란색 정부군에 관한색
#define COLOR_NEWS 0xE3BC9EAA // 똥색 방송국에 관한색
#define COLOR_FADE1 0xE6E6E6E6
#define COLOR_FADE2 0xC8C8C8C8
#define COLOR_FADE3 0xAAAAAAAA
#define COLOR_FADE4 0x8C8C8C8C
#define COLOR_FADE5 0x6E6E6E6E
#define COLOR_LINE 0x99CCFF00
#define COLOR_ST 0x62B382AA
#define COLOR_SOUND 0xDB7093FF
#define COLOR_LIGHTRED 0xFF8080FF
#define Command(%1) if(strcmp(%1,cmdtext,true)==0)
#define Command2(%1,%2) if(strcmp(%1,cmdtext,true)==0||strcmp(%2,cmdtext,true)==0)
#define Command3(%1,%2,%3) if(strcmp(%1,cmdtext,true)==0||strcmp(%2,cmdtext,true)==0||strcmp(%3,cmdtext,true)==0)
#define Command4(%1,%2,%3,%4) if(strcmp(%1,cmdtext,true)==0||strcmp(%2,cmdtext,true)==0||strcmp(%3,cmdtext,true)==0||strcmp(%4,cmdtext,true)==0)
#define M_P 150
#define MAX_ZONE_NAME 38
#define SCM SendClientMessage
#define SCMToAll SendClientMessageToAll

stock IsPlayerInArea(playerid, Float:max_x, Float:min_x, Float:max_y, Float:min_y)
{
	new Float:X, Float:Y, Float:Z;
	GetPlayerPos(playerid, X, Y, Z);
	if(X <= max_x && X >= min_x && Y <= max_y && Y >= min_y) return 1;
	return 0;
}

stock RespawnVehicles()
{
	new bool:used[MAX_VEHICLES] = { false, ... };
	for(new p; p<M_P; p++)
	{
		if(IsPlayerInAnyVehicle(p))
		{
			new veh = GetPlayerVehicleID(p);
			used[veh] = true;
		}
	}
	for(new v; v<MAX_VEHICLES; v++)
	{
		if(1 <= v <=1)
		{
			used[v] = true;
		}
		if(!used[v])
		{
			SetVehicleToRespawn(v);
		}
	}
}

stock ini_GetKey( line[] )
{
new keyRes[128];
keyRes[0] = 0;
if ( strfind( line , "=" , true ) == -1 ) return keyRes;
strmid( keyRes , line , 0 , strfind( line , "=" , true ) , sizeof( keyRes) );
return keyRes;
}

stock ini_GetValue( line[] )
{
new valRes[128];
valRes[0]=0;
if ( strfind( line , "=" , true ) == -1 ) return valRes;
strmid( valRes , line , strfind( line , "=" , true )+1 , strlen( line ) , sizeof( valRes ) );
return valRes;
}

stock c_fwrite( File: handle, const string[] )
{
    for( new i = 0; i < strlen( string );  i++ ) fputchar( handle, string[i], false);
    return ;
}

stock FTF(playerid, facingtoid)//페이스 투 페이스(보는플레이어,대상)
{
	new Float:angle;
	new Float:misc = 5.0;
	new Float:x, Float:y, Float:z;
	new Float:ix, Float:iy, Float:iz;
	GetPlayerPos(facingtoid, x, y, z);
	GetPlayerPos(playerid, ix, iy, iz);
	angle = 180.0-atan2(ix-x,iy-y);
	angle += misc;
	misc *= -1;
	SetPlayerFacingAngle(playerid, angle+misc);
}

strtok(const string[], &index)
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}

	new offset = index;
	new result[64];
	while ((index < length) &&((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

stock PlayerName(playerid)
{
	new playername[MAX_PLAYER_NAME];
	GetPlayerName(playerid, playername, sizeof(playername));
	return playername;
}