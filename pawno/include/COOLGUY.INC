/**
 *            Coolguy's functions v3.4
 *       (c) Copyright 2007-2008 CoolGuy
 *
 * @author    :  ¹ä¸Ô¾ú´Ï (cafe.daum.net/Coolpdt)
 * @date      : 2007/03/20
 * @Last update  : 2008/01/25
 * @require :
 *
 * This file is provided as is (no warranties).
 * 
 *
-*---------------------------------------------------------------------------------------------------------------------
USAGE
	1. Type Some compile options if you need.
	2. Type #include <coolguy> last of your includes.

Compile Options
	#define _COOLGUY_NO_COLOR : Don't Use CoolGuy's Color Collection.
	#define _COOLGUY_NO_BITS : Don't Use Bit Compression Support.(Used Automatically)
	#define _COOLGUY_NO_ENCRYPT : Don't Use Encryption Support.
	#define _COOLGUY_NO_INI : Don't Use INI Support.
	#define _COOLGUY_NO_FILE : Don't Use File Support.
	#define _COOLGUY_NO_PLAYER : Don't Use Game & Player Support.
	#define _COOLGUY_NO_MATH : Don't Use Number & Calc Support.

Feature
	INI with Full-Annotation Support.
 	ex) 
		# Skips whole line.
		[header] //Some Comment
		key=0//Some Comment
	Powerful String/Player Support.
	Encryption & Calculation Support.


Special Thanks To  
	 Y_LESS(thx very much, i copied some his YSI interface)
	
Version History
	- v2.9(07/09/11) :
		Previous Release.
	- v3.0(08/01/12) :
		Added "Crash()" Function.
		Fixed _COOLGUY_NO_SUBADMIN error.
		Removed Useless & Unavailable Functions.
		Fixed Various Functions.
		Rearranged all functions clear.
	- v3.1
		Added Some Colors.
		Added "PlayerArmour()" Function.
	- v3.2
		Fixed "StopSoundForPlayer()" Function.
		Added "PlayerIP()" Function.
		Added "Kill()" Function.
	- v3.3
		Added "CharPos()" Function.
		Added "strfloat()" Function.
		Added "intfloat()" Function.
		Removed Useless Functions.
		Optimized "IsPartOfName()" Function.
		Don't require any includes anymore.
	- v3.4
		Added "PlayerAngle()" Function.
		Removed dependance with SUBADMIN.
		Optimized "Crash()" Function. 
		Removed "InsertChar()" Function.
		Removed "isString()" Function.
		Fixed "multicat()" Function.
		Revived "FixChars()" Function.
		Added many of 'string.inc' Functions.

Functions List :

native __ARGUMENT__();
	native
native GetArgString(arg,dest[]);
	native
native __CONVERT__();
	native
native RetStr(val);
native hexstr(string[]);
native HexToInt(string[]);
native IntToHex(number);
native strfloat(Float:value);
native intfloat(Float:val,bool:round=false);
	native
native __STRINGHANDLE__();
	native
native isHangulExists(const strings[]);
native left(source[],len);
native right(source[], len);
native join(string1[],string2[]);
native medium(source[],start,end);
native SwapChar(source[],n1,n2);
native multicat({Float,_}:...);
native stringslice(const string[],stringindex,separator=' ');
native StripNL(str[]);
native ReplaceChar(object,toreplace,source[]);
native Unpack(str[]);
native sscanf(string[],format[],separator=' ', {Float,_}:...);
native IsStringServerVar(const string[]);
native parsecommand(cmdtext[], cmd[], text[], parcount = false);
native CharPos(string[],character,index=1);
native c_strlen(string[]);
native c_chrfind(string[],char,pos);
native c_strfind(string[],substr[],ignorecase=false,pos=0);
native c_strcat(string1[],string2[],maxlength=sizeof string1);
native c_strmid(dest[],source[],start,end,maxlength=sizeof dest);
native bool:c_strins(string[],substr[],pos,maxlength=sizeof string);
native bool:c_strdel(string[], start, end);
native FixChars(string[]);
	native
native __FILECONTROL__();
	native
native freset(file[]);
native fcreate(filename[]);
native fdeleteline(filename[],line[]);
native fsize(filename[]);
	native
native __GAME&PLAYER__();
	native
native PlayerName(playerid);
native Float:PlayerHealth(playerid);
native Float:PlayerArmour(playerid);
native PlayerIP(playerid);
native IsPartOfName(partofname[],playerid);
native GetClossetPlayerID(partofname[]);
native SendClientMessageExceptPlayer(id,COLOR,const text[]);
native wiper(...);
native wiperToAll();
native Eraser(lines,...);
native EraserToAll(lines);
native SendAdminMessage(COLOR,text[]);
native c_SetPlayerWorldBounds(playerid,Float:x_max,Float:x_min,Float:y_max,Float:y_min);
native GetPlayerWorldBounds(playerid,&Float:x_max,&Float:x_min,&Float:y_max,&Float:y_min);
native ResetPlayerWorldBounds(playerid);
native Num_Players();
native ToggleBlipVisibilty(playerid, bool:visible);
native AddCircleOfStaticVehicles(vehicleid, Float:X, Float:Y, Float:Z,Float:radius, num_of_vehicles, color1, color2);
native SetPlayersPosInCircle(Float:X, Float:Y, Float:Z, Float:radius);
native SetObjectToFaceCords(objectid, Float:x1,Float:y1,Float:z1);
native AllowAllTeleport(allow);
native SetVehiclePosEx(vehicleid, Float:x, Float:y, Float:z);
native ResetPlayerWeapon(playerid,weaponid);
native IsValidWeaponId(weaponid);
native FlashPlayerWantedLevel(playerid, times);
native IsValidVehicleMod(componentid);
native AddVehicleComponentEx(vehicleid, ...);
native RemoveVehicleComponentEx(vehicleid, ...);
native IsPlayerInInvalidNosVehicle(playerid,vehicleid);
native PlaySoundForPlayer(playerid,soundid);
native PlaySoundForAll(soundid);
native StopSoundForPlayer(playerid);
native StopSoundForAll();
native GetWeaponType(weaponid);
native Float:GetPlayerDistanceToPoint(playerid,{Float,_}:...);
native Float:GetDistanceBetweenPlayers(playerid,playerid2);
native IsPlayerInArea(playerid,Float:x1,Float:x2,Float:y1,Float:y2);
native IsPlayerInCube(playerid,Float:x1,Float:x2,Float:y1,Float:y2,Float:z1,Float:z2);
native IsPlayerInCircle(playerid,Float:X,Float:Y,Float:Radius);
native IsPlayerInSphere(playerid,Float:X,Float:Y,Float:Z,Float:Radius);
native Kill(playerid);
native Float:PlayerAngle(playerid);
	native
native __ENCRYPTION__();
	native
native coolguy_hash(buf[]);
native coolguy_strhash(str[]);
native coolguy_checksum(buffer[],mod = 65521);
native bernstein(s[]);
native xencrypt(string[],enc[]);
native xdecrypt(string[],enc[]);
native encrypt(string[]);
native RMB1(buf[]);
native SHA1(const string[]);
native MD5(const string[]);
	native
native __INI__();
	native
native c_iniIntSet(file[],header[],key[],value);
native c_iniInt(file[],header[],key[]);
native c_iniSet(file[],header[],key[],value[]);
native c_iniGet(file[],header[],key[]);
native Float:c_iniFloat(file[],header[],key[]);
native c_iniFloatSet(file[],header[],key[],Float:value);
native bool:c_iniBool(file[],header[],key[]);
native c_iniBoolSet(file[],header[],key[],bool:value);
native c_iniUnSet(file[],header[],key[]);
native c_iniIsSet(file[],header[],key[]);
native c_iniIsHeader(file[],header[]);
native c_iniAdd(file[],header[],key[],value=1);
native c_iniSub(file[],header[],key[],value=1);
native c_iniFloatAdd(file[],header[],key[],Float:value=1.000000);
native c_iniFloatSub(file[],header[],key[],Float:value=1.000000);
	native
native __BITCOMPRESSION__();
	native
native ceildiv(dividend,devisor);
native Bit_Bits(num);
native Bit_GetBit(Bit:array[],slot);
native Bit_Get(Bit:array[], slot, size = sizeof (array));
native Bit_Let(Bit:array[],slot);
native Bit_Vet(Bit:array[],slot);
native Bit_Set(Bit:array[], slot, set, size = sizeof (array));
native Bit_SetAll(Bit:array[], set, size = sizeof (array));
native Bit_GetCount(Bit:array[], size = sizeof (array));
native Bit_Reverse(Bit:array[],slot);
native Bit_ReverseAll(Bit:array[],num = -1);
	native
native __CALCULATION__();
	native
native minrand(min,max);
native TwoWayRand(value);
native Float:floatrand(Float:max,depth=6);
native Float:MinFloatrand(Float:min,Float:max);
native Float:TwoWayFloatrand(Float:max);
	native
native __ETC__();
	native
native Beep();
native Wait(time);
native Swap(&n1,&n2);
native Crash();

----------------------------------------------------------------------------------------------------------------------*/
#if defined _coolguy_included
  #endinput
#endif
#define _coolguy_included
#pragma library CoolGuy
//==========================================================
// Defines
//==========================================================
/* Dependencies */
#if defined _YSI_included
	#define _COOLGUY_NO_BITS
#endif
#if defined _enini_included
	#define _COOLGUY_NO_INI
#endif




#if defined MAX_STRING
	#undef MAX_STRING
#endif
#define MAX_STRING 512

#define PI 3.14159265

#if !defined _COOLGUY_NO_PLAYER
/* GetWeaponType */
#define WTYPE_MELEE 							1
#define WTYPE_PROJECTILE 						2
#define WTYPE_PISTOL 							3
#define WTYPE_SHOTGUN 							4
#define WTYPE_MACHINEGUN 						5
#define WTYPE_ASSAULT 							6
#define WTYPE_RIFLE 							7
#define WTYPE_HEAVY 							8
#define WTYPE_SPECIAL 							9
#endif

/* Colors */
#if !defined _COOLGUY_NO_COLOR
#define COLOR_RED 								0xFF000096
#define COLOR_DARKRED 							0xA6000096
#define COLOR_ORANGE          					0xFF9900AA
#define COLOR_ORANGERED							0xFF4500AA
#define COLOR_SALMON 							0xFA8072AA
#define COLOR_MAGENTA							0xFF00FFFF
#define COLOR_MEDIUMMAGENTA						0x8B008BAA
#define COLOR_CRIMSON							0xDC143CAA
#define COLOR_CORAL								0xFF7F50AA
#define COLOR_PINK								0xFFC0CBAA
#define COLOR_TOMATO							0xFF6347AA
#define COLOR_VIOLET							0xEE82EEFF
#define COLOR_GREEN 							0x33AA33AA
#define COLOR_DARKGREEN 						0x00800096
#define COLOR_LIME								0x10F441AA
#define COLOR_LAWNGREEN							0x7CFC00AA
#define COLOR_LIMEGREEN							0x32CD32AA
#define COLOR_SEAGREEN							0x20B2AAAA
#define COLOR_SEAGREEN2							0x2E8B57AA
#define COLOR_SPRINGGREEN						0x00FF7FAA
#define COLOR_YELLOWGREEN						0x9ACD32AA
#define COLOR_LIGHTGREEN 						0xCBFEA9AA
#define COLOR_CHARTREUSE						0x7FFF00AA
#define COLOR_BLUE								0x6FA7FB96
#define COLOR_RBLUE							 	0x4169FFAA
#define COLOR_MIDNIGHTBLUE						0x191970AA
#define COLOR_DARKBLUE 							0x0000A896
#define COLOR_LIGHTBLUE      					0x33CCFFAA
#define COLOR_FLBLUE							0x6495EDAA
#define COLOR_POLICEBLUE      					0x3F63CCAA
#define COLOR_NAVY								0x000080AA
#define COLOR_AQUA								0xF0F8FFAA
#define COLOR_MEDIUMAQUA						0x83BFBFAA
#define COLOR_CYAN 								0x00FFFFAA
#define COLOR_INDIGO							0x4B00B0AA
#define COLOR_SYSTEM 							0xEFEFF7AA
#define COLOR_YELLOW      	 				    0xFFFF00AA
#define COLOR_GREENYELLOW						0xADFF2FAA
#define COLOR_TAXIYELLOW      					0xF0E68CAA
#define COLOR_IVORY								0xFFFF82AA
#define COLOR_GOLD								0xE3B92496
#define COLOR_BROWN							 	0xC1762B96
#define COLOR_DARKBROWN 						0x80400096
#define COLOR_BISQUE							0xFFE4C4AA
#define COLOR_MAROON							0x800000AA
#define COLOR_THISTLE							0xD8BFD8FF
#define COLOR_WHITE							 	0xFFFFFF96
#define COLOR_SILVER							0xD2D2D296
#define COLOR_GRAY 								0x80808096
#define COLOR_GREY 								0xAFAFAFAA
#define COLOR_BLACK								0x00000096

#endif

new bool:FALSE=false,bool:TRUE=true;
#pragma unused TRUE,FALSE
// Main Functions
//==========================================================
// Argument
//==========================================================
#define GetArgString(%1,%2) do{ for(new x=0;x<sizeof(%2);x++){ %2[x]=getarg(%1,x); if(getarg(%1,x)=='\0') break; } } while(FALSE)
//==========================================================
// Convert
//==========================================================
stock RetStr(val){
	new str[13];
	format(str,13,"%d",val);
	return str;
}
//==========================================================
stock hexstr(string[])
{
	new
		ret,
		val,
		i;
	if (string[0] == '0' && (string[1] == 'x' || string[1] == 'X')) i = 2;
	while (string[i])
	{
		ret <<= 4;
		val = string[i++] - '0';
		if (val > 0x09) val -= 0x07;
		if (val > 0x0F) val -= 0x20;
		if (val < 0x01) continue;
		if (val < 0x10) ret += val;
	}
	return ret;
}
//==========================================================
#if !defined _dutils_included
stock HexToInt(string[]) {
	if (string[0]==0) return 0;
	new i;
	new cur=1;
	new res=0;
	for (i=strlen(string);i>0;i--) {
		if (string[i-1]<58) res=res+cur*(string[i-1]-48); else res=res+cur*(string[i-1]-65+10);
		cur=cur*16;
	}
	return res;
}
//==========================================================
stock IntToHex(number)
{
	new m=1;
	new depth=0;
	while (number>=m) {
		m = m*16;
		depth++;
	}
	depth--;
	new str[MAX_STRING];
	for (new i = depth; i >= 0; i--)
	{
		str[i] = ( number & 0x0F) + 0x30; // + (tmp > 9 ? 0x07 : 0x00)
		str[i] += (str[i] > '9') ? 0x07 : 0x00;
		number >>= 4;
	}
	str[8] = '\0';
	return str;
}
//==========================================================
stock strfloat(Float:value){
	new str[64];
	format(str,sizeof(str),"%f",value);
	return str;
}
//==========================================================
stock intfloat(Float:val,bool:round=false)
{
	new str[32], Float:value=val;
	if(round) floatround(value);
	format(str,sizeof(str),"%.0f",value);
	return strval(str);
}
#endif
//==========================================================
// String Handling
//==========================================================
stock isHangulExists(const strings[])
{
    for(new i;i<strlen(strings);i++)
    {
        if(strings[i]<32 || strings[i]>126)
        {
    		if(strings[i]=='\0' || strings[i]=='\n') return 0;
            return 1;
        }
    }
	return 0;
}
//==========================================================
stock left(source[],len){
	new retstr[MAX_STRING];
	strmid(retstr,source,0,len);
	return retstr;
}
//==========================================================
stock right(source[], len){
	new retstr[MAX_STRING],srclen = strlen(source);
	strmid(retstr,source,srclen - len,srclen);
	return retstr;
}
//==========================================================
stock join(string1[],string2[]){
	new tmp[MAX_STRING];
	format(tmp,sizeof(tmp),"%s%s",string1,string2);
	return tmp;
}
//==========================================================
stock medium(source[],start,end)
{
	new retstr[MAX_STRING];
	strmid(retstr,source,start,end);
	return retstr;
}
//==========================================================
stock SwapChar(source[],n1,n2){
	new temp=source[n1];
	source[n1] = source[n2];
	source[n2]=temp;
}
//==========================================================
stock multicat({Float,_}:...){
	new retstr[MAX_STRING];
	for(new i=0,j=numargs();i<j;i++){
		new semistr[MAX_STRING];
		GetArgString(i,semistr);
		c_strcat(retstr,semistr);
	}
	return retstr;
}
//==========================================================
stock stringslice(const string[],stringindex,separator=' ')
{
    new stringstart;
    new stringnum;
    new stringlength;
    new result[25];

    for(stringnum=0;stringnum<=stringindex && stringlength<=strlen(string);++stringnum)
    {
        if(stringnum>0)stringlength++;
        stringstart=stringlength;
        while(stringlength<=strlen(string) && string[stringlength]!=separator && string[stringlength]!=EOS)
        {
                stringlength++;
        }
    }

    stringnum=0;
    stringlength=stringlength-stringstart;
    while(stringnum<=stringlength && stringnum<=sizeof(result))
    {
        result[stringnum]=string[stringnum+stringstart];
        stringnum++;
    }
    
    result[stringlength]=EOS;
    return result;
}
//==========================================================
stock StripNL(str[])
{
	new l = strlen(str);
	while (l-- && str[l] <= ' ') str[l] = 0;
}
//==========================================================
stock ReplaceChar(object,toreplace,source[]) for (new i = 0;i<strlen(source);i++) if (source[i] == object) source[i] = toreplace;
//==========================================================
stock Unpack(str[]){
	new result[MAX_STRING];
	strunpack(result,str);
	return result;
}
//==========================================================
stock sscanf(string[],format[],separator=' ', {Float,_}:...)
{
	new	formatPos, stringPos, paramPos = 3, paramCount = numargs();
	while (paramPos < paramCount && string[stringPos])
	{
		switch (format[formatPos])
		{
			case '\0': break;
			case 'i', 'd': setarg(paramPos, 0, strval(string[stringPos]));
			case 'c': setarg(paramPos, 0, string[stringPos]);
			case 'f': setarg(paramPos, 0, _:floatstr(string[stringPos]));
			case 's':
			{
				new	i;
				if(format[formatPos + 1] != '\0') while (string[stringPos] != separator && string[stringPos] != '\0') setarg(paramPos, i++, string[stringPos++]);
				else while (string[stringPos] != '\0') setarg(paramPos, i++, string[stringPos++]);
				setarg(paramPos, i, '\0');
			}
			default: goto skip;
		}
		while (string[stringPos] && string[stringPos] != separator) stringPos++;
		while (string[stringPos] == separator) stringPos++;
		paramPos++;
		skip:
		formatPos++;
	}
	return format[formatPos] ? 0 : 1;
}
//==========================================================
stock IsStringServerVar(const string[])
{
   new vars[39][14] = {
   {"announce"},{"anticheat"},{"bind"},{"filterscripts"},
   {"gamemode0"},{"gamemode1"},{"gamemode2"},{"gamemode3"},
   {"gamemode4"},{"gamemode5"},{"gamemode6"},{"gamemode7"},
   {"gamemode8"},{"gamemode9"},{"gamemode10"},{"gamemode11"},
   {"gamemode12"},{"gamemode13"},{"gamemode14"},{"gamemode15"},
   {"gamemodetext"},{"gravity"},{"hostname"},{"instagib"},
   {"lanmode"},{"mapname"},{"maxplayers"},{"nosing"},
   {"myriad"},{"output"},{"plugins"},{"password"},
   {"port"},{"query"},{"rcon_password"},
   {"timestamp"},{"weburl"},{"weather"},{"worldtime"}};
   for (new x=0; x<sizeof(vars); x++){
       if (strcmp(string, vars[x], true, strlen(string)) == 0) return 1;
   }
   return 0;
}
//==========================================================
stock parsecommand(cmdtext[], cmd[], text[], parcount = false)
{
	new index = 0, length;
	length = strlen(cmdtext);
	while ((index < length) && (cmdtext[index] != ' '))
	{
		index++;
	}
	if (index == length)
	{
		strcat(cmd, cmdtext, MAX_STRING);
		text[0] = EOS;
		return 0;
	}
	else
	{
	    strmid(cmd, cmdtext, 0, index, MAX_STRING);
	    cmd[index] = EOS;
	    strmid(text, cmdtext, index + 1, length, MAX_STRING);
		text[length] = EOS;
		if (parcount)
		{
		    index = 0;
			new pars = 0;
			length = strlen(text);
			while (index < length)
			{
				if ((text[index] != ' ') && ((index == 0) || ((index > 0) && (text[index - 1] == ' '))))
				{
				    pars++;
				}
				index++;
			}
			return pars;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
//==========================================================
stock CharPos(string[],character,index=1)
{
	new curidx;
	for(new i=0;i<strlen(string);i++){
		if(string[i]==character) curidx++;
		if(curidx==index) return i;
	}
	return -1;
}

//==========================================================
stock c_strlen(string[],len=sizeof string)
{
	for(new i=0;i<len;i++)	if(string[i] == '\0' || string[i] == '\n') return i;
	return 0;
}
//==========================================================
stock c_chrfind(string[],character,pos=0)
{
	for(new i=pos,j=strlen(string);i<j;i++) if(string[i]==character) return i;
	return -1;
}
//==========================================================
stock c_strfind(string[],substr[],ignorecase=false,pos=0)
{
	new
		i=pos, //current pointer
		j=0, //substr pointer
		ptr=-1, //substr pos
		len=strlen(substr),
		maxlen=strlen(string);
	while(i < maxlen)
	{
		if((ignorecase? (tolower(string[i]) == tolower(substr[j])):(string[i] == substr[j])))
		{
			j++;
			if(j == len)
			{
				ptr=i-(len-1);
				break;
			}
		} else j=0;
		i++;
	}
	return ptr;
}
//==========================================================
stock c_strcat(string[],substr[],maxlength=sizeof string)
{
	new
		i=strlen(string),
		ptr=strlen(string),
		catlen=strlen(substr);
	while((i < i+catlen) && (i < maxlength))
	{
		string[i]=substr[i-ptr];
		i++;
	}
	if (i < maxlength) string[i]=EOS;
}
//==========================================================
stock c_strmid(dest[],source[],start,end,maxlength=sizeof dest)
{
	new i=start;
	while( (i <= end) && (i < maxlength) ) dest[i-start]=source[i++];
	if (i < maxlength) dest[i]=EOS;
}
//==========================================================
stock bool:c_strins(string[],substr[],pos,maxlength=sizeof string)
{
	new
		i=pos,
		len=strlen(substr),
		strrest[MAX_STRING];
	strmid(strrest,string,pos,strlen(string));
	while( (i-pos < len) && (i < maxlength) ){
		string[i]=substr[i-pos];
		i++;
	}
	if (i < maxlength) string[i]=EOS;
	c_strcat(string,strrest,maxlength);
	return (i+(strlen(string)-pos) < maxlength)? (true):(false);
}
//==========================================================
stock bool:c_strdel(string[], start, end, maxlength=sizeof string)
{
	new
		strrest[MAX_STRING],
		checkval=strlen(string)-(end-start+1);
	strmid(strrest,string,end+1,strlen(string));
	string[start]=EOS;
	c_strcat(string,strrest,maxlength);
	return (strlen(string)==checkval)? (true):(false);
}
//==========================================================
stock FixChars(string[]) for (new i=0;i<strlen(string);i++) if (string[i] < 0) string[i] += 256;

//==========================================================
// File Control
//==========================================================
#if !defined _COOLGUY_NO_FILE
stock freset(file[]){
	if(fexist(file)) fremove(file);
	return fcreate(file);
}
//==========================================================
stock fcreate(filename[]){
	if(fexist(filename)) return false;
	new File:fhandle = fopen(filename,io_write);
	if(!fhandle) return false;
	fclose(fhandle);
	return true;
}
//==========================================================
stock fdeleteline(filename[],line[]){
	if(!fexist(filename)) return false;
	frename(filename,join(filename,".tmp"));
	new File:fh1 = fopen(filename,io_write),File:fh2 = fopen(join(filename,".tmp"),io_read);
	if(!fh1 || !fh2) return false;
	new temp[MAX_STRING];
	while(fread(fh2,temp)){
		StripNL(temp);
		if(strlen(temp)==strlen(line) && !strcmp(temp,line,false)) fwrite(fh1,join(temp,"\r\n"));
	}
	fclose(fh1);
	fclose(fh2);
	fremove(join(filename,".tmp"));
	return true;
}
//==========================================================
stock fsize(filename[]){
	new size[10];
    new File:file = fopen(filename,io_append);
    new Float:flen = flength(file)/1048576.0;
    if(flen < 1.0){
    	flen *= 1024;
    	format(size,sizeof(size),"%.f KB",flen);
    }
    else format(size,sizeof(size),"%.2f MB",flen);
    fclose(file);
    return size;
}
#endif
//==========================================================
// Game & Player Control
//==========================================================
#if !defined _COOLGUY_NO_PLAYER
stock PlayerName(playerid) {
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid,name,MAX_PLAYER_NAME);
	return name;
}
//==========================================================
stock Float:PlayerHealth(playerid){
	new Float:thehealth;
	GetPlayerHealth(playerid,thehealth);
	return thehealth;
}
//==========================================================
stock Float:PlayerArmour(playerid){
	new Float:thearmour;
	GetPlayerArmour(playerid,thearmour);
	return thearmour;
}
//==========================================================
stock PlayerIP(playerid){
	new str[16];
	GetPlayerIp(playerid,str,16);
	return str;
}
//==========================================================
#define IsPartOfName(%1,%2) strcmp(%1,PlayerName(%2),true,strlen(%1))
//==========================================================
stock GetClossetPlayerID(partofname[]) {
	if(!strlen(partofname)) return INVALID_PLAYER_ID;
	for(new i=0,j=GetMaxPlayers();i<j;i++) if(IsPlayerConnected(i) && IsPartOfName(partofname,i)==0) return i;
	return INVALID_PLAYER_ID;
}
//==========================================================
stock SendClientMessageExceptPlayer(id,COLOR,const text[]) for(new playerid=0,total=GetMaxPlayers();playerid<total;playerid++) if(IsPlayerConnected(playerid) && playerid != id) SendClientMessage(playerid,COLOR,text);
//==========================================================
stock wiper(...) for(new playerid=0, total=numargs();playerid<total;playerid++) for(new i=0;i<MAX_CHATLINES;i++) SendClientMessage(getarg(playerid),0xAFAFAFAA,"\n");
//==========================================================
stock wiperToAll() for(new i=0;i<MAX_CHATLINES;i++) SendClientMessageToAll(0xAFAFAFAA,"\n");
//==========================================================
stock Eraser(lines,...)	for(new i=1,j=numargs();i<j;i++) for(new a=0;a < lines;a++) SendClientMessage(getarg(i),0xAFAFAFAA,"\n");
//==========================================================
stock EraserToAll(lines) for(new a=0;a < lines;a++) SendClientMessageToAll(0xAFAFAFAA, "\n");
//==========================================================
#if !defined _subadmin_included
stock SendAdminMessage(COLOR,text[]) for(new playerid=0,total=GetMaxPlayers();playerid<total;playerid++) if(IsPlayerAdmin(playerid)) SendClientMessage(playerid,COLOR,text);
#endif
//==========================================================
stock c_SetPlayerWorldBounds(playerid,Float:x_max,Float:x_min,Float:y_max,Float:y_min){
	SetPlayerWorldBounds(playerid,x_max,x_min,y_max,y_min);
	setproperty(playerid,"WorldBounds",0,strfloat(x_max));
	setproperty(playerid,"WorldBounds",1,strfloat(x_min));
	setproperty(playerid,"WorldBounds",2,strfloat(y_max));
	setproperty(playerid,"WorldBounds",3,strfloat(y_min));
}
//==========================================================
stock GetPlayerWorldBounds(playerid,&Float:x_max,&Float:x_min,&Float:y_max,&Float:y_min){
	new str[32];
	getproperty(playerid,"WorldBounds",0,str);
	strunpack(str,str);
	x_max=floatstr(str);
	getproperty(playerid,"WorldBounds",1,str);
	strunpack(str,str);
	x_min=floatstr(str);
	getproperty(playerid,"WorldBounds",2,str);
	strunpack(str,str);
	y_max=floatstr(str);
	getproperty(playerid,"WorldBounds",3,str);
	strunpack(str,str);
	y_min=floatstr(str);
}
//==========================================================
stock ResetPlayerWorldBounds(playerid) c_SetPlayerWorldBounds(playerid,20000.0, -20000.0, 20000.0, -20000.0);
//==========================================================
stock Num_Players(){
 	new activeplayers=0;
	for(new i=0,j=GetMaxPlayers();i<j;i++) if(IsPlayerConnected(i)) activeplayers++;
	return activeplayers;
}
//==========================================================
stock ToggleBlipVisibilty(playerid, bool:visible) SetPlayerColor(playerid,(visible? (GetPlayerColor(playerid) & 0xFFFFFF00):(GetPlayerColor(playerid) | 0x000000FF)));
//==========================================================
stock AddCircleOfStaticVehicles(vehicleid, Float:X, Float:Y, Float:Z, Float:radius, num_of_vehicles, color1, color2) {
	new i,
	Float: radAngle,
	Float: xCoord,
	Float: yCoord;

	for(i=0; i<num_of_vehicles; i++) {
		radAngle = floatdiv(floatmul(i,PI), floatdiv(num_of_vehicles, 2));
		xCoord = floatmul(floatcos(radAngle), radius);
		yCoord = floatmul(floatsin(radAngle), radius);
		AddStaticVehicle( vehicleid,
		floatadd(xCoord, (X)),
		floatadd(yCoord, (Y)),
		Z,
		floatadd(floatmul(radAngle, 60), 90),
		color1,
		color2);
	}

	return 1;
}
//==========================================================
stock SetPlayersPosInCircle(Float:X, Float:Y, Float:Z, Float:radius){
	new i,
	Float: radAngle,
	Float: xCoord,
	Float: yCoord,
	players_num,
	bool:playerAlreadySet[100] = {false,...};

	for(i=0; i<100; i++)
	if(IsPlayerConnected(i))
	players_num++;

	for(i=0; i<players_num; i++) {
	    radAngle = floatdiv(floatmul(i,PI), floatdiv(players_num, 2));
	    xCoord = floatmul(floatcos(radAngle), radius);
	    yCoord = floatmul(floatsin(radAngle), radius);

		for(i=0; i<100; i++) if(IsPlayerConnected(i) && !playerAlreadySet[i]){
		    playerAlreadySet[i] = true;
		    SetPlayerPos(i,floatadd(xCoord, (X)),floatadd(yCoord, (Y)),	Z);
			SetPlayerFacingAngle(i, floatadd(floatmul(radAngle, 60), 90));
			break;
		}
	}
	return 1;
}
//==========================================================
stock SetObjectToFaceCords(objectid, Float:x1,Float:y1,Float:z1)
{
//   SetObjectToFaceCords() By LucifeR   //
//                LucifeR@vgames.co.il   //

// setting the objects cords
new Float:x2,Float:y2,Float:z2;
GetObjectPos(objectid, x2,y2,z2);

// setting the distance values
new Float:DX = floatabs(x2-x1);
new Float:DY = floatabs(y2-y1);
new Float:DZ = floatabs(z2-z1);

// defining the angles and setting them to 0
    new Float:yaw = 0;
    new Float:pitch = 0;

    // check that there isnt any 0 in one of the distances,
// if there is any  use the given parameters:
if(DY == 0 || DX == 0)
{
    if(DY == 0 && DX > 0) {
yaw = 0;
pitch = 0; }
else if(DY == 0 && DX < 0) {
yaw = 180;
pitch = 180; }
else if(DY > 0 && DX == 0)  {
yaw = 90;
pitch = 90; }
else if(DY < 0 && DX == 0) {
yaw = 270;
pitch = 270; }
else if(DY == 0 && DX == 0) {
yaw = 0;
pitch = 0; }
}

// calculating the angale using atan
else // non of the distances is 0.
{
    // calculatin the angles
yaw = atan(DX/DY);
pitch = atan(floatsqroot(DX*DX + DZ*DZ) / DY);

// there are three quarters in a circle, now i will
// check wich circle this is and change the angles
// according to it.
if(x1 > x2 && y1 <= y2) {
    yaw = yaw + 90;
pitch = pitch - 45; }
        else if(x1 <= x2 && y1 < y2) {
    yaw = 90 - yaw;
pitch = pitch - 45; }
        else if(x1 < x2 && y1 >= y2) {
    yaw = yaw - 90;
pitch = pitch - 45; }
        else if(x1 >= x2 && y1 > y2) {
    yaw = 270 - yaw;
pitch = pitch + 315; }

// the pitch could be only in two quarters, lets see wich one:
        if(z1 < z2)
    pitch = 360-pitch;
}

// setting the object rotation (should be twice cuz of lame GTA rotation system)
SetObjectRot(objectid, 0, 0, yaw);
SetObjectRot(objectid, 0, pitch, yaw);
}
//==========================================================
stock AllowAllTeleport(allow)
{
    for(new i; i < MAX_PLAYERS) if(IsPlayerConnected(i)) AllowPlayerTeleport(i, allow);
    return true;
}
//==========================================================
stock SetVehiclePosEx( vehicleid, Float:x, Float:y, Float:z )
{
	SetVehiclePos(vehicleid,x, y, z);
	switch(GetVehicleModel(vehicleid))
	{
		case 509, 581, 481, 462, 521, 463, 510, 522, 461, 448, 468, 586:
		{
		    new Max_Players = GetMaxPlayers();
		    for( new i = 0; i < Max_Players; i++ ){
		        if( IsPlayerConnected(i) && IsPlayerInVehicle( i, vehicleid )){
		            new Player_State =  GetPlayerState(i);
		            SetPlayerPos(i, 0.0, 0.0, 0.0 );
		            if( Player_State == PLAYER_STATE_DRIVER ){
			   			PutPlayerInVehicle( i, vehicleid, 0 );
					} else {
						PutPlayerInVehicle( i, vehicleid, 1 );
					}
				}
			}
		}
	}
}
//==========================================================
stock ResetPlayerWeapon(playerid,weaponid)
{
	for( new i = 0; i < 13; i ++ ){
		new wp,wpa;
		GetPlayerWeaponData(playerid,i,wp,wpa);
		if (wp==weaponid) {
			GivePlayerWeapon(playerid,weaponid,0-wpa);
			return wpa;
		}
	}
}
//==========================================================
stock IsValidWeaponId(weaponid)	return ((weaponid == 19|| weaponid == 20|| weaponid == 21 ||weaponid > 46 || weaponid < 0)? (0):(1));
//==========================================================
stock FlashPlayerWantedLevel(playerid, times)
{
	static flash;
	new level = GetPlayerWantedLevel(playerid);
	if(times)
	{
	    if(!flash)
	    {
	        flash=1;
	        SetPlayerWantedLevel(playerid, 0);
	    }
	    else {
	        flash=0;
	        SetPlayerWantedLevel(playerid, level);
	    }
	    SetTimerEx("FlashPlayerWantedLevel", 500, 0, "ii", playerid, times-1);
	}
	else
	{
	    SetPlayerWantedLevel(playerid, level);
	}
}
//==========================================================
stock IsValidVehicleMod(componentid) return ((componentid < 1000 || componentid > 1193)? (0):(1));
//==========================================================
stock AddVehicleComponentEx(vehicleid, ...) {
	new arg = 1, n = numargs(), componentid;
	while(arg < n) {
		componentid = getarg(arg);
		if(IsValidVehicleMod(componentid)) {
			AddVehicleComponent(vehicleid, componentid);
			// Add any paired components
			switch(componentid) {
				case 1143: AddVehicleComponent(vehicleid, 1142);
				case 1145: AddVehicleComponent(vehicleid, 1144);
				case 1108: AddVehicleComponent(vehicleid, 1107);
				case 1042: AddVehicleComponent(vehicleid, 1099);
				case 1036: AddVehicleComponent(vehicleid, 1040);
				case 1039: AddVehicleComponent(vehicleid, 1041);
				case 1047: AddVehicleComponent(vehicleid, 1051);
				case 1048: AddVehicleComponent(vehicleid, 1052);
				case 1069: AddVehicleComponent(vehicleid, 1071);
				case 1070: AddVehicleComponent(vehicleid, 1072);
				case 1122: AddVehicleComponent(vehicleid, 1101);
				case 1106: AddVehicleComponent(vehicleid, 1124);
				case 1133: AddVehicleComponent(vehicleid, 1102);
				case 1118: AddVehicleComponent(vehicleid, 1120);
				case 1119: AddVehicleComponent(vehicleid, 1121);
				case 1056: AddVehicleComponent(vehicleid, 1062);
				case 1057: AddVehicleComponent(vehicleid, 1063);
				case 1026: AddVehicleComponent(vehicleid, 1027);
				case 1031: AddVehicleComponent(vehicleid, 1030);
				case 1134: AddVehicleComponent(vehicleid, 1137);
				case 1090: AddVehicleComponent(vehicleid, 1094);
				case 1093: AddVehicleComponent(vehicleid, 1095);
				case 1007: AddVehicleComponent(vehicleid, 1017);
			}
		}
		arg++;
	}
}
//==========================================================
stock RemoveVehicleComponentEx(vehicleid, ...) {
	new arg = 1, n = numargs(), componentid;
	while(arg < n) {
		componentid = getarg(arg);
		if(IsValidVehicleMod(componentid)) {
			RemoveVehicleComponent(vehicleid, componentid);
			// Remove any paired components
			switch(componentid) {
				case 1143: RemoveVehicleComponent(vehicleid, 1142);
				case 1145: RemoveVehicleComponent(vehicleid, 1144);
				case 1108: RemoveVehicleComponent(vehicleid, 1107);
				case 1042: RemoveVehicleComponent(vehicleid, 1099);
				case 1036: RemoveVehicleComponent(vehicleid, 1040);
				case 1039: RemoveVehicleComponent(vehicleid, 1041);
				case 1047: RemoveVehicleComponent(vehicleid, 1051);
				case 1048: RemoveVehicleComponent(vehicleid, 1052);
				case 1069: RemoveVehicleComponent(vehicleid, 1071);
				case 1070: RemoveVehicleComponent(vehicleid, 1072);
				case 1122: RemoveVehicleComponent(vehicleid, 1101);
				case 1106: RemoveVehicleComponent(vehicleid, 1124);
				case 1133: RemoveVehicleComponent(vehicleid, 1102);
				case 1118: RemoveVehicleComponent(vehicleid, 1120);
				case 1119: RemoveVehicleComponent(vehicleid, 1121);
				case 1056: RemoveVehicleComponent(vehicleid, 1062);
				case 1057: RemoveVehicleComponent(vehicleid, 1063);
				case 1026: RemoveVehicleComponent(vehicleid, 1027);
				case 1031: RemoveVehicleComponent(vehicleid, 1030);
				case 1134: RemoveVehicleComponent(vehicleid, 1137);
				case 1090: RemoveVehicleComponent(vehicleid, 1094);
				case 1093: RemoveVehicleComponent(vehicleid, 1095);
				case 1007: RemoveVehicleComponent(vehicleid, 1017);
			}
		}
		arg++;
	}
}
//==========================================================
stock IsPlayerInInvalidNosVehicle(playerid,vehicleid)
{
    #define MAX_INVALID_NOS_VEHICLES 29

    new InvalidNosVehicles[MAX_INVALID_NOS_VEHICLES] =
    {
581,523,462,521,463,522,461,448,468,586,
509,481,510,472,473,493,595,484,430,453,
452,446,454,590,569,537,538,570,449
    };

    vehicleid = GetPlayerVehicleID(playerid);

    if(IsPlayerInVehicle(playerid,vehicleid))
    {
for(new i = 0; i < MAX_INVALID_NOS_VEHICLES; i++)
{
    if(GetVehicleModel(vehicleid) == InvalidNosVehicles[i])
    {
        return true;
    }
}
    }
    return false;
}
//==========================================================
stock PlaySoundForPlayer(playerid,soundid){
	new Float:pos[3];
	GetPlayerPos(playerid,pos[0],pos[1],pos[2]);
	PlayerPlaySound(playerid,soundid,pos[0],pos[1],pos[2]);
}
//==========================================================
stock PlaySoundForAll(soundid) for(new i=0,j=GetMaxPlayers();i<j;i++) if(IsPlayerConnected(i)) PlaySoundForPlayer(i,soundid);
//==========================================================
#define StopSoundForPlayer(%1) PlayerPlaySound(%1,1184,0.0,0.0,0.0)
//==========================================================
stock StopSoundForAll() for(new i=0,j=GetMaxPlayers();i<j;i++) if(IsPlayerConnected(i)) StopSoundForPlayer(i);
//==========================================================
stock GetWeaponType(weaponid){
	switch(weaponid){
		case 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15: return WTYPE_MELEE;
		case 16,17,18,19,20,21: return WTYPE_PROJECTILE;
		case 22,23,24: return WTYPE_PISTOL;
		case 25,26,27: return WTYPE_SHOTGUN;
		case 28,32: return WTYPE_MACHINEGUN;
		case 29,30,31: return WTYPE_ASSAULT;
		case 33,34: return WTYPE_RIFLE;
		case 35,36,37,38,39,40: return WTYPE_HEAVY;
		case 41,42,43,44,45,46,47: return WTYPE_SPECIAL;
	}
	return 0;
}
//==========================================================
stock Float:GetPlayerDistanceToPoint(playerid,{Float,_}:...){
	new num = numargs(),Float:pos[3];
	GetPlayerPos(playerid,pos[0],pos[1],pos[2]);
	if(num == 3) return floatsqroot(floatpower(floatabs(floatsub(pos[0],Float:getarg(1))),2)+floatpower(floatabs(floatsub(pos[1],Float:getarg(2))),2));
	else if(num == 4) return floatsqroot(floatpower(floatabs(floatsub(pos[0],Float:getarg(1))),2)+floatpower(floatabs(floatsub(pos[1],Float:getarg(2))),2)+floatpower(floatabs(floatsub(pos[2],Float:getarg(3))),2));
	return -1.0;
}
//==========================================================
stock Float:GetDistanceBetweenPlayers(playerid,playerid2){
	new Float:pos[3];
	GetPlayerPos(playerid,pos[0],pos[1],pos[2]);
	return GetPlayerDistanceToPoint(playerid2,pos[0],pos[1],pos[2]);
}
//==========================================================
stock IsPlayerInArea(playerid,Float:x1,Float:x2,Float:y1,Float:y2){
	new Float:pos[3];
	GetPlayerPos(playerid,pos[0],pos[1],pos[2]);
	if(pos[0]>=x1 && pos[0]<=x2 && pos[1]>=y1 && pos[1]<=y2) return 1;
	return 0;
}
//==========================================================
stock IsPlayerInCube(playerid,Float:x1,Float:x2,Float:y1,Float:y2,Float:z1,Float:z2){
	new Float:pos[3];
	GetPlayerPos(playerid,pos[0],pos[1],pos[2]);
	if(x1<pos[0] && x2>pos[0] && y1<pos[1] && y2>pos[1] && z1<pos[2] && z2>pos[2]) return 1;
	return 0;
}
//==========================================================
stock IsPlayerInCircle(playerid,Float:X,Float:Y,Float:Radius) return (GetPlayerDistanceToPoint(playerid,X,Y)<Radius? (1):(0));
//==========================================================
stock IsPlayerInSphere(playerid,Float:X,Float:Y,Float:Z,Float:Radius) return (GetPlayerDistanceToPoint(playerid,X,Y,Z)<Radius? (1):(0));
//==========================================================
#define Kill(%1) SetPlayerHealth(%1,-999)
//==========================================================
stock Float:PlayerAngle(playerid){
	new Float:Angle;
	GetPlayerFacingAngle(playerid,Angle);
	return Angle;
}
#endif
//==========================================================
// Encrypting
//==========================================================
#if !defined _COOLGUY_NO_ENCRYPT
stock coolguy_hash(buf[])
{
    new length=strlen(buf);
    new s1 = 1;
    new s2 = 0;
    new n;
    for (n=0; n<length; n++)
    {
       s1 = (s1 + buf[n]) % 65521;
       s2 = (s2 + s1)     % 65521;
    }
    
    return (s2 << 16) + s1;
}
//==========================================================
stock coolguy_strhash(str[])
{
   new strtemp[MAX_STRING];
   strtemp[0]=0;
   valstr(strtemp,coolguy_hash(str));
   return strtemp;
}
//==========================================================
stock coolguy_checksum(buffer[],mod = 65521){
	new a = 0,b = 1,c = 2,d = 3;
    for(new i=0,j=strlen(buffer);i<j;i++){
        a = ((a + buffer[i]) % mod);
        b = ((a + b)	     % mod);
        c = ((a + b + c)     % mod);
        d = ((a + b + c + d) % mod);
    }
    return ((d << 16) + (a + b + c));
}
//==========================================================
stock bernstein(s[]){new h=-1,i,j;while((j=s[i++]))h=h*33+j;return h;}
//==========================================================
stock xencrypt(string[],enc[]) for(new len = strlen(string), enclen = strlen(enc), i = 0, j = 0; i < len; i++, j++, j %= enclen) string[i] += enc[j];
//==========================================================
stock xdecrypt(string[],enc[]) for(new len = strlen(string), enclen = strlen(enc), i = 0, j = 0; i < len; i++, j++, j %= enclen) string[i] -= enc[j];
//==========================================================
stock encrypt(string[])//no stringlength checking
{
	static key[] = "Put your key here, remember to escape \", \' and \\, like so.";
	// The more different characters there are in here, the better the code

	static size = sizeof(key) - 1;
	// Theres a slight bug, you don't want to count the end \0

	new retval[64];
	// Passwords limited to 48 chars (64 - 16 for rounding)

	new j, k, sum, tmp[] = {0, 0};
	// Initialise the variables

	j = strlen(string);
	sum = j;
	// Get the length of the source string

	k = ((j >> 4) + 1) << 4;
	// Round up to the nearest 16 (trust me, it does)

	for (new i = 0; i < k; i++)
	{
		if (i < j)
		{
			tmp[0] = string[i];
			// Get the next character
		}
		else
		{
			tmp[0] = ' ';
			// Add the padding
		}

		sum = ((sum + strfind(key, tmp) + 1) % size);
		// Add the new position to the running total and limit
		// it to the size of the array (thus carrying character
		// data over to the next)

		retval[i] = key[sum];
		// Add the new character to the running array.
	}
	return retval;
}
//==========================================================
stock RMB1(buf[]){
	new length=strlen(buf);
	new a;
	new s1 = 2;
	new s2 = 3;
   	new s3 = 5;
   	new s4 = 7;
   	new s5 = 9;
   	new s6 = 11;
   	new s7 = 13;
   	new s8 = 17;
   	new s9 = 7919;
   	new s10 = 7907;
   	new s11 = 7901;
   	new s12 = 7883;
   	new s13 = 7879;
   	new s14 = 7877;
   	new s15 = 7873;
   	new s16 = 7867;
   	for (a=0; a<length; a++){
        s1 = (s1 + buf[a]) * 65521;
        s2 = (s2 / s1 + buf[a]) * 65521;
        s3 = (s3 * s2 / s1 + buf[a]) * 65521;
        s4 = (s4 + s3 - s2 * s1 / buf[a]) * 65521;
        s5 = (s5 / s4 + s3 - s2 * s1 / buf[a]) * 65521;
        s6 = (s6 * s5 / s4 + s3 - s2 * s1 / buf[a]) * 65521;
        s7 = (s7 - s6 * s5 / s4 + s3 - s2 * s1 / buf[a]) * 65521;
        s8 = (s8 + s7 - s6 * s5 / s4 + s3 - s2 * s1 / buf[a]) * 65521;
        s9 = (s9 / s8 + s7 - s6 * s5 / s4 + s3 - s2 * s1 / buf[a]) * 65521;
        s10 = (s10 * s9 / s8 + s7 - s6 * s5 / s4 + s3 - s2 * s1 / buf[a]) * 65521;
        s11 = (s11 - s10 * s9 / s8 + s7 - s6 * s5 / s4 + s3 - s2 * s1 / buf[a]) * 65521;
        s12 = (s12 + s11 - s10 * s9 / s8 + s7 - s6 * s5 / s4 + s3 - s2 * s1 / buf[a]) * 65521;
        s13 = (s13 / s12 + s11 - s10 * s9 / s8 + s7 - s6 * s5 / s4 + s3 - s2 * s1 / buf[a]) * 65521;
        s14 = (s14 * s13 / s12 + s11 - s10 * s9 / s8 + s7 - s6 * s5 / s4 + s3 - s2 * s1 / buf[a]) * 65521;
        s15 = (s15 - s14 * s13 / s12 + s11 - s10 * s9 / s8 + s7 - s6 * s5 / s4 + s3 - s2 * s1 / buf[a]) * 65521;
        s16 = (s16 + s15 - s14 * s13 / s12 + s11 - s10 * s9 / s8 + s7 - s6 * s5 / s4 + s3 - s2 * s1 / buf[a]) * 65521;
    }
    return (s16 << 128) * s1 * s2 * s3 * s4 * s5 * s6 * s7 + s8 + s9 + s10 + s11 + s12 + s13 + s14 + s15 + s16;
}
//==========================================================
stock SHA1(const string[]){
	new hashtmp[MAX_STRING],len = strlen(string),digest[MAX_STRING];
	format(hashtmp,sizeof(hashtmp),"%s",string);
	hashtmp[len >> 5] |= 0x80 << (24 - len % 32);
	hashtmp[((len + 64 >> 9) << 4) + 15] = len;
	new w[80], a =  1732584193, b = -271733879, c = -1732584194, d =  271733878, e = -1009589776;
	for(new i=0;i<len;i+=16){
		new olda = a, oldb = b, oldc = c, oldd = d, olde = e;
		for(new j=0;j<80;j++){
			if(j < 16) w[j] = hashtmp[i+j];
			else w[j] = Roll(w[j-3] ^ w[j-8] ^ w[j-14] ^ w[j-16], 1);
			new t = Add(Add(Roll(a, 5), SHA1FT(j, b, c, d)),Add(Add(e, w[j]), SHA1KT(j)));
			e = d;
			d = c;
			c = Roll(b, 30);
			b = a;
			a = t;
		}
		a = Add(a, olda);
   		b = Add(b, oldb);
   		c = Add(c, oldc);
    	d = Add(d, oldd);
    	e = Add(e, olde);
	}
	format(digest,sizeof(digest),"%s%s%s%s%s",IntToHex(a),IntToHex(b),IntToHex(c),IntToHex(d),IntToHex(e));
	return digest;
}
//==========================================================
stock Roll(num,cnt) return (num << cnt) | (num >>> (32-cnt));
//==========================================================
stock Add(x,y){
	new lsw = (x & 0xFFFF) + (y & 0xFFFF);
	new msw = (x >> 16) + (y >> 16) + (lsw >> 16);
	return (msw << 16) | (lsw & 0xFFFF);
}
//==========================================================
stock SHA1FT(t,b,c,d){
	if(t < 20) return (b & c) | ((~b) & d);
	if(t < 40) return b ^ c ^ d;
	if(t < 60) return (b & c) | (b & d) | (c & d);
	return b ^ c ^ d;
}
//==========================================================
stock SHA1KT(t) return (t < 20) ? 1518500249 : (t < 40) ? 1859775393 : (t < 60) ? -1894007588 : -899497514;
//==========================================================
stock MD5(const string[]){
	new len = strlen(string);
	new x[MAX_STRING];
	format(x,sizeof(x),"%s",string);
	x[len >> 5] |= 0x80 << (len % 32);
	x[((len + 64 >> 9) << 4) + 14] = len;
	new a =  1732584193;
	new b = -271733879;
	new c = -1732584194;
	new d =  271733878;
	for(new i=0;i<len;i+=16){
		new olda = a;
		new oldb = b;
		new oldc = c;
		new oldd = d;
		a = MD5FF(a, b, c, d, x[i+ 0], 7 , -680876936);
		d = MD5FF(d, a, b, c, x[i+ 1], 12, -389564586);
  		c = MD5FF(c, d, a, b, x[i+ 2], 17,  606105819);
    	b = MD5FF(b, c, d, a, x[i+ 3], 22, -1044525330);
    	a = MD5FF(a, b, c, d, x[i+ 4], 7 , -176418897);
    	d = MD5FF(d, a, b, c, x[i+ 5], 12,  1200080426);
    	c = MD5FF(c, d, a, b, x[i+ 6], 17, -1473231341);
    	b = MD5FF(b, c, d, a, x[i+ 7], 22, -45705983);
    	a = MD5FF(a, b, c, d, x[i+ 8], 7 ,  1770035416);
    	d = MD5FF(d, a, b, c, x[i+ 9], 12, -1958414417);
    	c = MD5FF(c, d, a, b, x[i+10], 17, -42063);
    	b = MD5FF(b, c, d, a, x[i+11], 22, -1990404162);
    	a = MD5FF(a, b, c, d, x[i+12], 7 ,  1804603682);
    	d = MD5FF(d, a, b, c, x[i+13], 12, -40341101);
    	c = MD5FF(c, d, a, b, x[i+14], 17, -1502002290);
    	b = MD5FF(b, c, d, a, x[i+15], 22,  1236535329);
    	a = MD5GG(a, b, c, d, x[i+ 1], 5 , -165796510);
    	d = MD5GG(d, a, b, c, x[i+ 6], 9 , -1069501632);
    	c = MD5GG(c, d, a, b, x[i+11], 14,  643717713);
    	b = MD5GG(b, c, d, a, x[i+ 0], 20, -373897302);
    	a = MD5GG(a, b, c, d, x[i+ 5], 5 , -701558691);
    	d = MD5GG(d, a, b, c, x[i+10], 9 ,  38016083);
    	c = MD5GG(c, d, a, b, x[i+15], 14, -660478335);
    	b = MD5GG(b, c, d, a, x[i+ 4], 20, -405537848);
   		a = MD5GG(a, b, c, d, x[i+ 9], 5 ,  568446438);
    	d = MD5GG(d, a, b, c, x[i+14], 9 , -1019803690);
    	c = MD5GG(c, d, a, b, x[i+ 3], 14, -187363961);
    	b = MD5GG(b, c, d, a, x[i+ 8], 20,  1163531501);
    	a = MD5GG(a, b, c, d, x[i+13], 5 , -1444681467);
    	d = MD5GG(d, a, b, c, x[i+ 2], 9 , -51403784);
    	c = MD5GG(c, d, a, b, x[i+ 7], 14,  1735328473);
    	b = MD5GG(b, c, d, a, x[i+12], 20, -1926607734);
    	a = MD5HH(a, b, c, d, x[i+ 5], 4 , -378558);
    	d = MD5HH(d, a, b, c, x[i+ 8], 11, -2022574463);
    	c = MD5HH(c, d, a, b, x[i+11], 16,  1839030562);
    	b = MD5HH(b, c, d, a, x[i+14], 23, -35309556);
    	a = MD5HH(a, b, c, d, x[i+ 1], 4 , -1530992060);
    	d = MD5HH(d, a, b, c, x[i+ 4], 11,  1272893353);
    	c = MD5HH(c, d, a, b, x[i+ 7], 16, -155497632);
    	b = MD5HH(b, c, d, a, x[i+10], 23, -1094730640);
    	a = MD5HH(a, b, c, d, x[i+13], 4 ,  681279174);
    	d = MD5HH(d, a, b, c, x[i+ 0], 11, -358537222);
    	c = MD5HH(c, d, a, b, x[i+ 3], 16, -722521979);
   		b = MD5HH(b, c, d, a, x[i+ 6], 23,  76029189);
    	a = MD5HH(a, b, c, d, x[i+ 9], 4 , -640364487);
    	d = MD5HH(d, a, b, c, x[i+12], 11, -421815835);
    	c = MD5HH(c, d, a, b, x[i+15], 16,  530742520);
    	b = MD5HH(b, c, d, a, x[i+ 2], 23, -995338651);
    	a = MD5II(a, b, c, d, x[i+ 0], 6 , -198630844);
    	d = MD5II(d, a, b, c, x[i+ 7], 10,  1126891415);
    	c = MD5II(c, d, a, b, x[i+14], 15, -1416354905);
    	b = MD5II(b, c, d, a, x[i+ 5], 21, -57434055);
    	a = MD5II(a, b, c, d, x[i+12], 6 ,  1700485571);
    	d = MD5II(d, a, b, c, x[i+ 3], 10, -1894986606);
    	c = MD5II(c, d, a, b, x[i+10], 15, -1051523);
    	b = MD5II(b, c, d, a, x[i+ 1], 21, -2054922799);
    	a = MD5II(a, b, c, d, x[i+ 8], 6 ,  1873313359);
    	d = MD5II(d, a, b, c, x[i+15], 10, -30611744);
    	c = MD5II(c, d, a, b, x[i+ 6], 15, -1560198380);
    	b = MD5II(b, c, d, a, x[i+13], 21,  1309151649);
    	a = MD5II(a, b, c, d, x[i+ 4], 6 , -145523070);
    	d = MD5II(d, a, b, c, x[i+11], 10, -1120210379);
    	c = MD5II(c, d, a, b, x[i+ 2], 15,  718787259);
    	b = MD5II(b, c, d, a, x[i+ 9], 21, -343485551);
    	a = Add(a, olda);
    	b = Add(b, oldb);
    	c = Add(c, oldc);
    	d = Add(d, oldd);
    }
    new digest[MAX_STRING];
    format(digest,sizeof(digest),"%s%s%s%s",IntToHex(a),IntToHex(b),IntToHex(c),IntToHex(d));
    return digest;
}
//==========================================================
stock MD5FF(a,b,c,d,x,s,t) return MD5CMN((b & c) | ((~b) & d),a,b,x,s,t);
//==========================================================
stock MD5CMN(q,a,b,x,s,t) return Add(Roll(Add(Add(a,q),Add(x,t)),s),b);
//==========================================================
stock MD5GG(a,b,c,d,x,s,t) return MD5CMN((b & d) | (c & (~d)),a,b,x,s,t);
//==========================================================
stock MD5HH(a,b,c,d,x,s,t) return MD5CMN(b^c^d,a,b,x,s,t);
//==========================================================
stock MD5II(a, b, c, d, x, s, t) return MD5CMN(c ^ (b | (~d)), a, b, x, s, t);
#endif
//==========================================================
// INI
//==========================================================
#if !defined _COOLGUY_NO_INI

stock c_iniIntSet(file[],header[],key[],value) return c_iniSet(file,header,key,RetStr(value));
//==========================================================
stock c_iniInt(file[],header[],key[]) return strval(c_iniGet(file,header,key));
//==========================================================
stock c_iniSet(file[],header[],key[],value[]){
	frename(file,join(file,".tmp"));
	new File:fohnd = fopen(join(file,".tmp"),io_read),File:fwhnd = fopen(file,io_write);
	if(!fwhnd) return false;
	new temp[MAX_STRING],bool:inheader=false,bool:infile=false,len=strlen(header);
	while(fread(fohnd,temp)){
		if(temp[0]=='#'){format(temp,MAX_STRING,"%s",temp); fwrite(fwhnd,temp); continue;}
		StripNL(temp);
		if(inheader){
			if(temp[0] == '['){
				inheader=false;
		   		if(!infile){
					format(temp,MAX_STRING,"%s=%s\r\n%s",key,value,temp);
		   			infile=true;
				}
				fwrite(fwhnd,join(temp,"\r\n"));
				continue;
			}
			new p = strfind(temp,"=");
			if(p > 0 && strcmp(temp,key,false,p)==0){
				new p2= strfind(temp,"//");
				format(temp,MAX_STRING,"%s=%s%s",key,value,(p2==-1? (""):(right(temp,strlen(temp)-p2))));
				infile = true;
			}
		} else if(temp[0] == '[' && strcmp(header,temp,false,len)==0) inheader = true;
		fwrite(fwhnd,join(temp,"\r\n"));
	}
	
	if(!infile){
		if(!inheader){
			format(temp,MAX_STRING,"\r\n%s\r\n",header);
			fwrite(fwhnd,temp);
		}
		format(temp,MAX_STRING,"%s=%s\r\n",key,value);
		fwrite(fwhnd,temp);
	}
	fclose(fwhnd);
	fclose(fohnd);
	fremove(join(file,".tmp"));
	return true;
}
//==========================================================
stock c_iniGet(file[],header[],key[]){
	new result[MAX_STRING];
	new File:fhandle = fopen(file,io_read);
	if(!fhandle) return result;
	new temp[MAX_STRING],bool:inheader,len=strlen(header);
	while(fread(fhandle,temp)){
		StripNL(temp);
		if(temp[0]=='#' || !temp[0]) continue;
		if(inheader){
			if(temp[0] == '[') break;
			new p = strfind(temp,"=");
			if(p > 0 && strcmp(temp,key,false,p)==0) {
				new p2=strfind(temp,"//");
				strmid(result,temp,p+1,(p2==-1? (strlen(temp)):(p2)));
				StripNL(result);
				break;
			}
		} else if(temp[0] == '[' && strcmp(header,temp,false,len)==0) inheader = true;
	}
	fclose(fhandle);
	return result;
}
//==========================================================
stock Float:c_iniFloat(file[],header[],key[]) return floatstr(c_iniGet(file,header,key));
//==========================================================
stock c_iniFloatSet(file[],header[],key[],Float:value) return c_iniSet(file,header,key,strfloat(value));
//==========================================================
stock bool:c_iniBool(file[],header[],key[]) return bool:strval(c_iniGet(file,header,key));
//==========================================================
stock c_iniBoolSet(file[],header[],key[],bool:value) return c_iniSet(file,header,key,RetStr(value));
//==========================================================
stock c_iniUnSet(file[],header[],key[]){
	frename(file,join(file,".tmp"));
	new File:fwhnd = fopen(file,io_write),File:fohnd = fopen(join(file,".tmp"),io_read);
	if(!fwhnd || !fohnd) return false;
	new temp[MAX_STRING],bool:inheader,bool:dontwrite,len=strlen(header);
	while(fread(fohnd,temp)){
		if(temp[0]=='#'){format(temp,MAX_STRING,"%s",temp); fwrite(fwhnd,temp); continue;}
		StripNL(temp);
		if(inheader) {
		if(temp[0] == '['){ inheader = false; fwrite(fwhnd,join(temp,"\r\n")); continue;}
	 		new p = strfind(temp,"=");
			if(p > 0 && strcmp(temp,key,false,p)==0) dontwrite = true;
		} else if(temp[0] == '[' && strcmp(header,temp,false,len)==0) inheader = true;
		if(!dontwrite) fwrite(fwhnd,join(temp,"\r\n"));
		dontwrite=false;
	}
	fclose(fwhnd);
	fclose(fohnd);
	fremove(join(file,".tmp"));
	return true;
}
//==========================================================
stock c_iniIsSet(file[],header[],key[]){
	new File:fhandle = fopen(file,io_read);
	if(!fhandle) return false;
	new temp[MAX_STRING],bool:inheader,bool:isset,len=strlen(header);
	while(fread(fhandle,temp)){
		StripNL(temp);
		if(temp[0]=='#' || !temp[0]) continue;
		if(inheader){
			if(temp[0] == '[') break;
			new p = strfind(temp,"=");
			if(p > 0 && strcmp(temp,key,false,p)==0){ isset = true; break; }
		} else if(temp[0] == '[' && strcmp(header,temp,false,key)==0) inheader = true;
	}
	fclose(fhandle);
	return isset;
}
//==========================================================
stock c_iniIsHeader(file[],header[]){
	new File:fhandle = fopen(file,io_read);
	if(!fhandle) return false;
	new bool:isheader, temp[MAX_STRING], len=strlen(header);
	while(fread(fhandle,temp)){
		StripNL(temp);
		if(temp[0]=='#' || !temp[0]) continue;
		if(temp[0] == '[' && strcmp(header,temp,false,len)==0){isheader = true; break;}
	}
	fclose(fhandle);
	return isheader;
}
//==========================================================
stock c_iniAdd(file[],header[],key[],value=1) return c_iniIntSet(file,header,key,c_iniInt(file,header,key) + value);
//==========================================================
stock c_iniSub(file[],header[],key[],value=1) return c_iniIntSet(file,header,key,c_iniInt(file,header,key) - value);
//==========================================================
stock c_iniFloatAdd(file[],header[],key[],Float:value=1.000000) return c_iniFloatSet(file,header,key,floatadd(c_iniFloat(file,header,key),value));
//==========================================================
stock c_iniFloatSub(file[],header[],key[],Float:value=1.000000)	return c_iniFloatSet(file,header,key,floatsub(c_iniFloat(file,header,key),value));
//==========================================================
#endif
//==========================================================
// Compression
//==========================================================
#if !defined _COOLGUY_NO_BITS

#define MAX_BPLAYERS Bit_Bits(MAX_PLAYERS)
//==========================================================
#define ceildiv(%1,%2) ((((%1)+(%2))-1) / (%2))
//==========================================================
#define Bit_Bits(%1) ceildiv((%1), cellbits)
//==========================================================
#define Bit_GetBit(%1,%2) ((%1[(%2) / cellbits]) & Bit:(1 << ((%2) % cellbits)))
//==========================================================
stock Bit_Get(Bit:array[], slot, size = sizeof (array))
{
	if (slot / cellbits >= size) return 0;
	return (Bit_GetBit(array, slot) ? (1) : (0));
}
//==========================================================
#define Bit_Let(%1,%2) %1[(%2) / cellbits] |= Bit:(1 << ((%2) % cellbits))
//==========================================================
#define Bit_Vet(%1,%2) %1[(%2) / cellbits] &= Bit:~(1 << ((%2) % cellbits))
//==========================================================
stock Bit_Set(Bit:array[], slot, set, size = sizeof (array))
{
	if (slot / cellbits >= size) return;
	if (set) Bit_Let(array, slot);
	else Bit_Vet(array, slot);
}
//==========================================================
stock Bit_SetAll(Bit:array[], set, size = sizeof (array))
{
	new
		Bit:val = (set) ? (Bit:0xFFFFFFFF) : (Bit:0);
	for (new i = 0; i < size; i++) array[i] = val;
}
//==========================================================
stock Bit_GetCount(Bit:array[], size = sizeof (array))
{
	new
		count;
	for (new i = 0; i < size; i++) for (new j = 1; j; j <<= 1) if (array[i] & Bit:j) count++;
	return count;
}
//==========================================================
#define Bit_Reverse(%1,%2) %1[(%2) / cellbits] = (Bit_GetBit(%1,%2)? (%1[(%2) / cellbits] & Bit:~(1 << ((%2) % cellbits))):(%1[(%2) / cellbits] | Bit:(1 << ((%2) % cellbits))))
//==========================================================
stock Bit_ReverseAll(Bit:array[],num = -1)
{
	new max=(num==-1? (sizeof(array)*cellbits):(num));
	if(num/cellbits >= sizeof(array)) return;
	for (new i = 0; i < max; i++) Bit_Reverse(array,i);
}
#endif
//==========================================================
// Number & Calc
//==========================================================
#if !defined _COOLGUY_NO_MATH
stock minrand(min,max) return random(max - min) + min;
//==========================================================
stock TwoWayRand(value)	return random(value * 2 + 1) - value;
//==========================================================
stock Float:floatrand(Float:max,depth=6){
	new floatdepth=1, i=depth;
	while(i){floatdepth*=10; --i;}
	return floatdiv(float(random(max*floatdepth)) / float(floatdepth));
}
//==========================================================
stock Float:MinFloatrand(Float:min,Float:max) return floatrand(max - min) + min;
//==========================================================
stock Float:TwoWayFloatrand(Float:max) return floatrand(max * float(2) + float(1)) - max;
//==========================================================
#endif
//==========================================================
// ETC
//==========================================================
#define Beep() print("\a")
//==========================================================
stock Wait(time){
	new stamp = tickcount();
	while(tickcount() - stamp < time){}
}
//==========================================================
stock Swap(&n1,&n2){
	new temp=n1;
	n1=n2;
	n2=temp;
}
//==========================================================
#define Crash() new File:crashnd; while(TRUE) fread(crashnd,"")
//==========================================================
// Wasted & Developing in progress
//==========================================================
/* 
stock c_strcmp(string1[],string2[],bool:ignorecase=false,length=cellmax){
	new str1[MAX_STRING],str2[MAX_STRING];
	strmid(str1,string1,0,length);
	strmid(str2,string2,0,length);
	if(strlen(str1)==strlen(str2) && strfind(str1,str2,ignorecase)==0) return 1;
	return 0;
}
stock equalC(string1[],string2[],bool:ignorecase=false,length=cellmax){
	new str1[MAX_STRING],str2[MAX_STRING];
	str1=ret_memcpy(string1,0,length);
	str2=ret_memcpy(string2,0,length);
	if(strlen(str1) != strlen(str2)) return 0;
	if(ignorecase){strlower(str1); strlower(str2);}
	return (bernstein(str1)==bernstein(str2)? (1):(0));
}
stock HangulToEOS(strings[]) for(new i;i<strlen(strings);i++) if(strings[i]<32 || strings[i]>126) strings[i]=EOS;
*/
