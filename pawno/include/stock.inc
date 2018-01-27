/*
서버보안 인클루드
Don_Dota(우수)
오전 2:20 2010-11-13

*/

#define SCM SendClientMessage
#define SCMToAll SendClientMessageToAll
#define M_P 500
new bool:Hide[M_P];


forward Stopit(playerid);
public Stopit(playerid)
{
	SendClientMessage(playerid, 0xFFFFFFFF,"(정보) 5초가 지났습니다 차량을 출발시키십시오.");
    SetPlayerFreeze(playerid, false, 0);
	TogglePlayerControllable(playerid, 1);
}
stock c_fwrite( File: handle, const str[] )
{
 for( new c_fwval = 0; c_fwval < strlen( str );  c_fwval++ )
  fputchar( handle, str[c_fwval], false);
 return ;
}
stock RPPlayerName (playerid)
{
	new playername[MAX_PLAYER_NAME];
	if(Hide[playerid])
	{
		playername="알수없음";
	}
	else
	{
		GetPlayerName(playerid, playername, sizeof(playername));
		new PlyName1 = strfind(playername,"_", true);
		if(PlyName1 != -1)
		{
			playername[PlyName1] = ' ';
		}
	}
	return playername;
}
stock GetName(playerid)
{
	new pname[MAX_PLAYER_NAME];
	GetPlayerName(playerid, pname, sizeof(pname));
	return pname;
}
stock GetMemberName(member)
{
	new string[256];
	switch(member)
	{
	case 1: string="L.S.P.D";
	case 2: string="F.B.I";
	case 3: string="U.N";
	case 4: string="E.M.T";
	case 5: string="Locotes";
	case 6: string="Terranova Crime Famiglia";
	case 7: string="정부";
	case 8: string="M.M.C";
	case 9: string="H.N.N";
	case 10: string="LS-PCT";
	case 11: string="Moters";
	case 12: string="Crip's";
	case 13: string="Cyco Clika";
	case 14: string="Yamaguchi_Gumi";
	case 15: string="三合會";
	case 16: string="Seviles";
	case 17: string="Bloodz";
	case 18: string="종로파";
	case 19: string="Mongols Motorcycle Club";
	case 20: string="CB그룹";
	case 21: string="Comfortable Development";
	case 22: string="교도관";
	case 23: string="CIA";
	case 24: string="CAMORRA";
	default: string="없음";
	}
	return string;
}
//forwsard GetRankName(member, rank);
stock GetRankName(member, rank)
{
	new string[256];
	switch(member)
	{
	case 1:
		{
			switch(rank)
			{
			case 1: string="순경";
			case 2: string="경장";
			case 3: string="경사";
			case 4: string="경위";
			case 5: string="경감";
			case 6: string="경정";
			case 7: string="총경";
			case 8: string="경무관";
			case 9: string="치안감";
			case 10: string="치안정감";
			case 11: string="치안총감";
			default: string="-없는계급-";
			}
		}
		case 2:
		{
			switch(rank)
			{
			case 1: string="Trainee";
			case 2: string="Third Agent";
			case 3: string="Second Agent";
			case 4: string="First Agent";
			case 5: string="Special Agent";
			case 6: string="Associate Director";
			case 7: string="Deputy Director";
			case 8: string="Assistant Director";
			case 9: string="Director";
			default: string="-없는계급-";
			}
		}
	case 16:
		{
			switch(rank)
			{
			case 0: string="Girl'G";
			case 1: string="T.G";
			case 2: string="B.G";
			case 3: string="Trug";
			case 4: string="O.G";
			case 5: string="Double O.G";
			case 6: string="Triple O.G";
			case 7: string="Top O.G";
			default: string="Girl'G";
			}
		}
	case 3:
		{
			switch(rank)
			{
			case 1: string="훈련병";
			case 2: string="이등병";
			case 3: string="일등병";
			case 4: string="상병";
			case 5: string="병장";
			case 6: string="하사";
			case 7: string="중사";
			case 8: string="상사";
			case 9: string="원사";
			case 10: string="주임윈사";
			case 11: string="준위";
			case 12: string="소위";
			case 13: string="중위";
			case 14: string="대위";
			case 15: string="소령";
			case 16: string="중령";
			case 17: string="대령";
			case 18: string="준장";
			case 19: string="소장";
			case 20: string="중장";
			case 21: string="대장";
			case 22: string="국방부장관";
			default: string="훈련병";
			}
		}
	case 4:
		{
			switch(rank)
			{
			case 0: string="교육생";
			case 1: string="외부인턴";
			case 2: string="내부인턴";
			case 3: string="레지던트";
			case 4: string="펠로우";
			case 5: string="부교수";
			case 6: string="교수";
			case 7: string="관리인";
			case 8: string="병원장";
			case 9: string="의료장관";
			default: string="인턴";
			}
		}
	case 5:
		{
			switch(rank)
			{
			}
		}
	case 6:
		{
			switch(rank)
			{
			case 0: string="Outsider";
			case 1: string="Associates";
			case 2: string="Made guy";
			case 3: string="Soldaty";
			case 4: string="Caporegima";
			case 5: string="Capo";
			case 6: string="UnderBoss";
			case 7: string="Consigliere";
			case 8: string="Boss";
			case 9: string="Godfather";
			default: string="Outsider";
			}
		}
	case 7:
		{
			switch(rank)
			{
			case 0: string="시청공무원";
			case 1: string="비서";
			case 2: string="비서실장";
			case 3: string="경호원";
			case 4: string="경호실장";
			case 5: string="부서원";
			case 6: string="부서장";
			case 7: string="운전기사";
			case 8: string="시의원";
			case 9: string="부시장";
			case 10: string="시장";
			default: string="시청공무원";
			}
		}
	case 8:
		{
			switch(rank)
			{
			case 1: string="No.6";
			case 2: string="No.5";
			case 3: string="No.4";
			case 4: string="No.3";
			case 5: string="No.2";
			case 6: string="No.1";
			default: string="No.6";
			}
		}
	case 9:
		{
			switch(rank)
			{
			case 1: string="훈련생";
			case 2: string="기자";
			case 3: string="정식 기자";
			case 4: string="본부장";
			case 5: string="부국장";
			case 6: string="국장";
			default: string="훈련생";
			}
		}
	case 10:
	    {
			switch(rank)
			{
			case 1: string="훈련생";
			case 2: string="신입기사";
			case 3: string="정식기사";
			case 4: string="모범기사";
			case 5: string="버스기사";
			case 6: string="관리팀원";
			case 7: string="관리팀장";
			case 8: string="부사장";
			case 9: string="사장";
			default: string="훈련생";
			}
		}
	case 11:
		{
			switch(rank)
			{
			case 1: string="알바생";
			case 2: string="엔지니어";
			case 3: string="매니저";
			case 4: string="부사장";
			case 5: string="사장";
			default: string="알바생";
			}
		}
	case 12:
		{
			switch(rank)
			{
			case 6: string="Top O.G";
			case 5: string="Double O.G";
			case 4: string="O.G";
			case 3: string="O.T.G";
			case 2: string="T.G";
			case 1: string="B.G";
			default: string="B.G";
			}
		}
	case 13:
		{
			switch(rank)
			{
			}
		}
	case 14:
		{
			switch(rank)
			{
			case 1: string="요이지";
			case 2: string="가이진";
			case 3: string="샤테이";
			case 4: string="교다이";
			case 5: string="후쿠혼부쵸 호사";
			case 6: string="샤테이가시라";
			case 7: string="소혼부쵸";
			case 8: string="와카가시라 호사";
			case 9: string="후쿠혼부쵸";
			case 10: string="사이코센세";
			case 11: string="와카가시라";
			case 12: string="카이케이";
			case 13: string="쿠미쵸";
			default: string="고붕";
			}
		}
	case 15:
		{
			switch(rank)
			{
			case 1: string="남등롱";
			case 2: string="사구자";
			case 3: string="초혜";
			case 4: string="백지선";
			case 5: string="홍곤";
			case 6: string="선봉";
			case 7: string="향주";
			case 8:string="부산주";
			case 9:string="용두";
			default: string="-없는계급-";
			}
		}
	case 17:
		{
			switch(rank)
			{
			case 6: string="Top O.G";
			case 5: string="R.Hand";
			case 4: string="L.Hand";
			case 3: string="O.G";
			case 2: string="B.G";
			case 1: string="Crew";
			default: string="Crew";
			}
		}
	case 18:
		{
			switch(rank)
			{
			case 0: string="신참";
			case 1: string="외부인";
			case 2: string="양아치";
			case 3: string="준조직원";
			case 4: string="조직원";
			case 5: string="행동대장";
			case 6: string="실장";
			case 7: string="지부장";
			case 8: string="부두목";
			case 9: string="두목";
			case 10: string="원로";
			default: string="외부인";
			}
		}
	case 19:
		{
			switch(rank)
			{
			case 1: string="Prospect";
			case 2: string="Mongol";
			case 3: string="Veteran";
			case 4: string="Sergant at Arms";
			case 5: string="Road Captain";
			case 6: string="Treasurer";
			case 7: string="Houston-President";
			case 8: string="President";
			default: string="Prospect";
			}
		}
	case 20:
		{
			switch(rank)
			{
			case 0: string="총알받이";
			case 1: string="신참";
			case 2: string="돌격부";
			case 3: string="특수부";
			case 4: string="저격부";
			case 5: string="엘리트";
			case 6: string="엘리트";
			}
		}
	case 21:
		{
			switch(rank)
			{
			case 1: string="도급직원";
			case 2: string="CD직원";
			case 3: string="관리감독";
			case 4: string="비서";
			case 5: string="CD사장";
			default: string="훈련생";
			}
		}
	case 22:
		{
			switch(rank)
			{
			case 1: string="교사시보";
			case 2: string="교도";
			case 3: string="교사";
			case 4: string="교위";
			case 5: string="교감";
			case 6: string="교정관";
			case 7: string="교정감";
			case 8: string="교정부이사관";
			case 9: string="교정이사관";
			default: string="-없는계급-";
			}
		}
	case 23:
		{
			switch(rank)
			{
			case 1: string="Trainee";
			case 2: string="Third Class";
			case 3: string="Second Class";
			case 4: string="First Class";
			case 5: string="Special Agent";
			case 6: string="Associate Director";
			case 7: string="Deputy Director";
			case 8: string="Assistant Director";
			case 9: string="Director";
			default: string="-없는계급-";
			}
		}
	case 24:
		{
			switch(rank)
			{
			case 0: string="Outsider";
			case 1: string="Associates";
			case 2: string="Made guy";
			case 3: string="Soldaty";
			case 4: string="Caporegima";
			case 5: string="Capo";
			case 6: string="UnderBoss";
			case 7: string="Consigliere";
			case 8: string="Boss";
			case 9: string="Godfather";
			default: string="Outsider";
			}
		}
	default: string="없음";
	}
	return string;
}
stock HostLeader(playerid)
{
	new playersip[20];
	GetPlayerIp(playerid,playersip,sizeof(playersip));
	if(strcmp(playersip, "127.0.0.1", true) == 0)
	{
	    return 1;
	}
	return 0;
}
stock FactionAdmin(playerid)
{
	new name[20];
	GetPlayerName(playerid, name, sizeof(name));
	if(strcmp(name, "Pablo_Albino", true) == 0||strcmp(name, "Albanos_Washington", true) == 0)
	{
	    return 1;
	}
	return 0;
}
stock SuperAdmin(playerid)
{
	new name[20];
	GetPlayerName(playerid, name, sizeof(name));
	if(strcmp(name, "Pablo_Albino", true) == 0||strcmp(name, "Santino_Valenti", true) == 0)
	{
	    return 1;
	}
	return 0;
}
stock gc(playerid)
{
	new name[20];
	GetPlayerName(playerid, name, sizeof(name));
	if(strcmp(name, "Maurice_Mcdonald", true) == 0)
	{
	    return 1;
	}
	return 0;
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