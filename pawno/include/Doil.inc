/*==========================================================================*/

#include <a_samp>
#include <core>
#include <float>
#include <time>
#include <file>
#include <utils>
#include <morphinc>

/*==========================================================================*/

#define HackWeapon GetPW(playerid)==9||GetPW(playerid)==26||GetPW(playerid)==33||GetPW(playerid)==37||GetPW(playerid)==38||GetPW(playerid)==42||GetPW(playerid)==35||GetPW(playerid)==36
#define GivePW GivePlayerWeapon
#define SetPW SetPlayerWeapon
#define GetPW GetPlayerWeapon
#define AP	for(new i = 0; i < M_P; i++)//맥스플레이어 포문 간편사용
new PShotgun[M_P];
#define DIALOG_13 14000