/* 제작 - Bruce 
 Carry 전용
BlackScreen 되돌릴때 SetCameraBehindPlayer 함수*/

#include <core>
#include <float>
#include <time>
#include <Dini>
#include <file>
#include <utils>
#include <morphinc>
#include <bitcompress>
//====================
new Text:BloodScreen;
//====================
forward Motocycle(modelid);
forward BlackScreen(playerid);
//====================
public Motocycle(modelid)
{
	if(modelid == 521 || modelid == 522 || modelid == 523 || modelid == 471 || modelid == 461 || modelid == 581)
	{
		return 1;
	}
	return 0;
}

public BlackScreen(playerid)
{
 SetPlayerPos(playerid, 0, 0, 1000);
 SetPlayerCameraLookAt(playerid,-1037.9821,36.4963,-82.0382);
 SetPlayerCameraPos(playerid,-1037.9821,36.4963,-82.0382);
 return 1;
}
