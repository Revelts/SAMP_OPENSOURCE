/*
 *            Subadmin functions v1.6
 *       (c) Copyleft 2007 by Coolguy
 *
 * @author    : Coolguy(¹ä¸Ô¾ú´Ï)
 * (cafe.daum.net/Coolpdt)
 * @date      : 2007/04/28
 * @Last update  : 2007/09/07
 *
 * This file is provided as is (no warranties).
 *
 */
#if defined _subadmin_included
	#endinput
#endif
#define _subadmin_included
#pragma library SubAdmin

/*
USAGE
	1. Type #include <subadmin>.
	2. OnGameModeInit : Type RESET_SUBADMIN;
	3. OnPlayerDisconnect : Type UnSetPlayerSubAdmin(playerid);
Compile Options
	#define _SUBADMIN_NO_ADDITIONAL : Don't Use Additional Functions.
	
Functions List :
native IsPlayerSubAdmin(playerid);
native SetPlayerSubAdmin(playerid);
native UnSetPlayerSubAdmin(playerid);
native Num_SubAdmin();
native SubAdminMessage(COLOR,string[]);
native KickAllSubAdmin();
native SummonSubAdminToPlayer(playerid);
native SetSubAdminPos(Float:x,Float:y,Float:z,Float:Angle);
native KickExceptAdmins();
*/
//--------------------------------------------------------------------------
/* Core */
#define IsPlayerSubAdmin(%1) existproperty(0,"IsPlayerSubAdmin",(%1))
#define SetPlayerSubAdmin(%1) setproperty(0,"IsPlayerSubAdmin",(%1),"True")
#define UnSetPlayerSubAdmin(%1) deleteproperty(0,"IsPlayerSubAdmin",(%1))
#define RESET_SUBADMIN for(new z=0,q=GetMaxPlayers();z<q;z++) UnSetPlayerSubAdmin(z)

/* Additional */
#if defined _SUBADMIN_NO_ADDITIONAL
	#endinput
#endif
stock Num_SubAdmin(){
new count;
for(new i=0,j=GetMaxPlayers();i<j;i++) if(IsPlayerSubAdmin(i)) count++;
return count;
}

stock SubAdminMessage(COLOR,string[]) for(new i=0,j=GetMaxPlayers();i<j;i++) if(IsPlayerSubAdmin(i)) SendClientMessage(i,COLOR,string);

stock KickAllSubAdmin() for(new i=0,j=GetMaxPlayers();i<j;i++) if(IsPlayerSubAdmin(i)) Kick(i);

stock SummonSubAdminToPlayer(playerid){
new Float:x,Float:y,Float:z;
GetPlayerPos(playerid,x,y,z);
	for(new i=0,j=GetMaxPlayers();i<j;i++){
		if(IsPlayerSubAdmin(i)){
		SetPlayerPos(i,x,y,z);
		SetPlayerFacingAngle(i,270.0);
		}
	}
}
stock SetSubAdminPos(Float:x,Float:y,Float:z,Float:Angle){
	for(new i=0,j=GetMaxPlayers();i<j;i++){
		if(IsPlayerSubAdmin(i)) {
		SetPlayerPos(i,x,y,z);
 		SetPlayerFacingAngle(i,Angle);
		}
	}
}
stock KickExceptAdmins() for(new i=0,j=GetMaxPlayers();i<j;i++) if(!IsPlayerAdmin(i) && !IsPlayerSubAdmin(i)) Kick(i);
