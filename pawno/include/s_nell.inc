#include <dini>
#include <utils>
#include <core>
#include <float>
#include <time>
#include <file>

#define M_P 50
#define HackKey newkeys==132||newkeys==129||newkeys==4||newkeys==36||newkeys==12||newkeys==160||newkeys==136||newkeys==1028||newkeys==1152||newkeys==1156||newkeys==5||newkeys==129||newkeys==1029||newkeys==1153||newkeys==37||newkeys==151||newkeys==1060||newkeys==1184||newkeys==137||newkeys==13
#define HackWeapon GetPW(playerid)>=2&&GetPW(playerid)<=15||GetPW(playerid)>=22&&GetPW(playerid)<=33||GetPW(playerid)>=37&&GetPW(playerid)<=38||GetPW(playerid)==42||GetPW(playerid)==46
#define GivePW GivePlayerWeapon
#define SetPW SetPlayerWeapon
#define GetPW GetPlayerWeapon
#define SCM SendClientMessage
#define SCMToAll SendClientMessageToAll
#define AllPlayers new i=0; i<M_P; i++
#define Freeze TogglePlayerControllable
#define HackResonKick reason==2||reason==3||reason==4||reason==5||reason==6||reason==7||reason==8||reason==9||reason==10||reason==11||reason==12||reason==13||reason==14||reason==15||reason==22||reason==23||reason==24||reason==25||reason==26||reason==27||reason==28||reason==29||reason==30||reason==31||reason==32||reason==41||reason==42||reason==43||reason==46
#define HackResonBan reason==16||reason==17||reason==18||reason==33||reason==34||reason==35||reason==36||reason==37||reason==38||reason==39||reason==40||reason==42||reason==44||reason==45
#define HackWeaponTime GetPW(i)>=2&&GetPW(i)<=15||GetPW(i)>=22&&GetPW(i)<=33||GetPW(i)>=37&&GetPW(i)<=38||GetPW(i)==42||GetPW(i)==46
#define PlayerHack GetPW(playerid)>=2&&GetPW(playerid)<=15||GetPW(playerid)>=22&&GetPW(playerid)<=33||GetPW(playerid)>=37&&GetPW(playerid)<=38||GetPW(playerid)==42||GetPW(playerid)==46
#define PlayerHack GetPW(playerid)>=1&&GetPW(playerid)<=50


/*forward Freeze(playerid);
forward UnFreeze(playerid);

new PlayerFreeze[MAX_PLAYERS];

public Freeze(playerid);
{
PlayerFreeze[playerid] = 0; //변수를 끕니다
TogglePlayerControllable(playerid, 1); //플레이어를 녹입니다
return 1;
}

public UnFreeze(playerid);
{
PlayerFreeze[playerid] = 1;
TogglePlayerControllable(playerid, 0);
return 1;
}*/

//오전 12:39 2010-05-10