#if defined ____QINI____
/*
	Script: Quick
	LastUpdate:2012-07-24
	LastUpdate:2012-07-26
	Version: V1

	Quick INI(Read & Write) Include


--  ------ --- - -- - - ----- -- -- -- --- --- -- -- ---- ----- -- -- --- -

		                           _            _   _
				 ___ _  _    _   (_ )   __ _   ||  //
				/    |  ||   ||   ||  //    \\ ||//
		       |     |  ||   ||   ||  ||       |  |
		        \___ |  ||   ||   ||  ||       ||\\
		           | |  \\___||_ _||_ _\\___/}_||_ \\_ _ _
				   |_/ - - -- -/- -  - -- --- -- - - -- - - -
		        --------------------------------------------------
			     _ _  __
		        /  __ _ \
		        | \    \_|                    _
			    \ \__ _       _ __   _   _  (_ ) _ ___
		         \__ _  \   //    \\ \\/ _-  ||  | -  \ _||_
		         _     \ \  ||       | /  -| ||  | _ _/  ||
			    | |__ _/ /  ||       ||      ||  ||      ||  _
				\__ __  /_ _\\_ __/)/_\__ _ _||_ ||_ _ __\\_//_ _
		        --------------------------------------------------

- -- ---- -- --- --- --- --- -- --- --- -- -- -- ---- -- -- -- -- -- -- ---*/



INI_Dir(dir[]) 						폴더의 존재여부를 구별합니다.
INI_Exist(filename[]) 				파일의 존재여부를 구별합니다.
INI_Create(filename[])				파일을 생성합니다.

INI_Open(filename[], create=false)	INI 파일을 엽니다.
INI_Close(save=false)				INI 파일을 닫습니다.


INI_Write(key[],value[]) 			INI 파일에 정보를 씁니다.
INI_WriteInt(key[],value) 			ex:)INI_WriteInt("Int",1);
INI_WriteFloat(key[],Float:value) 	ex:)INI_WriteFloat("Float",3.141);

INI_WriteBool(key[],bool:value,type=0)INI 파일에 Bool형을 씁니다.
									(type 0~4)문자를 선택할수 있습니다.
									불러오는데 지장은 없습니다.
									ex:)INI_WriteBool("bool",true);


INI_Get(key[])		INI 파일에 정보를 불러옵니다.
					ex:)INI_Get("QINI");
									
INI_GetInt(key[])	ex:)new a = INI_GetInt("QINI");
INI_GetFloat(key[])	ex:)new Float:a = INI_GetFloat("QINI");
INI_GetBool(key[])	ex:)new bool:a = INI_GetBool("QINI");



//Addon
INI_Isset(key[])	키값 존재여부 확인
INI_Unset(key[])	키값을 삭제.

INI_Debug(bool:value=true)
INI_DebugWriter(content[])



/*
    native INI_Dir(dir[])
    native INI_Exist(filename[])
    native INI_Create(filename[])
	native INI_Open(filename[], create=false)
	native INI_Close(save = false)
	native INI_Write(key[], value[])
    native INI_WriteInt(key[], value)
    native INI_WriteFloat(key[], Float:value)
    native INI_WriteBool(key[], bool:value, type=0)
    native INI_Get(key[])
    native INI_GetInt(key[])
    native INI_GetFloat(key[])
    native INI_GetBool(key[])
    native INI_Isset(key[])
    native INI_Unset(key[])
	native INI_Debug(bool:value = true)
	native INI_DebugWriter(content[])
*/
#endif


#if defined _qini_included
  #endinput
#endif

#define _qini_included

#pragma library qini


#define DEFAULT_BOOL_TYPE 0

#define LIBRARY_NAME "QINI"

#define INI_MAX_VALUE_LENGTH   		128
#define INI_MAX_KEY_LENGTH    		64
#define INI_MAX_INI_LENGTH			(INI_MAX_KEY_LENGTH+INI_MAX_VALUE_LENGTH)

#define Debug_Write(%0) ClearString(debugString),format(debugString,256,%0),INI_DebugWriter(debugString)
#define Debug_Writef(%0,%1) ClearString(debugString),format(debugString,256,%0,%1),INI_DebugWriter(debugString)

#define INI_DEFAULT_DEBUG 	false
#define INI_DEBUG_FILE_NAME "/ini_debug.txt"

#define INI_MAX_FILENAME_LENGTH  	128
#define INI_MAX_LINE                500


enum INI_CACHE
{
	E_TEMP_VALUE	[INI_MAX_VALUE_LENGTH ],
	E_TEMP_KEY		[INI_MAX_KEY_LENGTH],
};
enum INI_FILE
{
	bool:E_OPEND,
	E_FILE_NAME		[INI_MAX_FILENAME_LENGTH]
};



stock static bool:INIDebug = INI_DEFAULT_DEBUG;
new debugString[256];

stock static gFile	[INI_FILE];
stock static gCache	[INI_MAX_LINE][INI_CACHE];


stock static const BoolName[6][2][9] =
{
	{"False","True"},
	{"Disabled","Enabled"},
	{"No","Yes"},
	{"Off","On"},
	{"아니오","예"},
	{"0","1"}
};



stock GetBoolName(value,type)
{
	return BoolName[type<sizeof BoolName?type:0][value==0?0:1];
}
stock ClearString(szString[])
	szString[0] = '\0';
	
stock INI_WriteChar(File:fhnd,szChar[])
{
	for(new i=0,l=strlen(szChar); i<l; i++)
	fputchar(fhnd,szChar[i],false);
}

stock INI_DeleteLine(szString[])
{
	szString[strlen(szString)-
	strfind(szString,"\r")?strfind(szString,"\r"):
	strfind(szString,"\n")?strfind(szString,"\n"):0] = EOS;
}
stock bool:INI_Dir(dir[])
{
	new szString[128];
	format(szString,sizeof szString,"%s/abcdefghijklmnopqrstuvw.xyz",dir);
	new File:fwhnd=fopen(szString,io_readwrite);

	if(fwhnd)
	{
	    fclose(fwhnd);
	    fremove(szString);
		return true;
	}
	else return false;
}
stock INI_Exist(filename[])
	return fexist(filename);

stock INI_Create(filename[])
{
	new File:fhnd = fopen(filename,io_write);
	fclose(fhnd);
}

stock INI_Debug(bool:value=true)
{
	INI_Exist(INI_DEBUG_FILE_NAME)||INI_Create(INI_DEBUG_FILE_NAME);
	new ymd[3],string[128];
	getdate(ymd[0],ymd[1],ymd[2]);

    INIDebug=value;

	format(string,sizeof string,"%d년 %d월 %d일 "#LIBRARY_NAME" 디버그 실행시작합니다."
	,ymd[0],ymd[1],ymd[2]);

	INI_DebugWriter(string);
 	return ;
}

stock INI_DebugWriter(content[])
{
	if(INIDebug)
	{
		INI_Exist(INI_DEBUG_FILE_NAME)||INI_Create(INI_DEBUG_FILE_NAME);

		new
			File:fwhnd=fopen(INI_DEBUG_FILE_NAME,io_append)
			,hms[3],timeString[40];

		gettime(hms[0],hms[1],hms[2]);

		format(timeString,sizeof timeString,"[%d:%d:%d] "
		,hms[0],hms[1],hms[2]);

		for(new i=0,l=strlen(timeString); i<l; i++)
			fputchar(fwhnd,timeString[i],false);

		for(new i=0,l=strlen(content); i<l; i++)
			fputchar(fwhnd,content[i],false);

		static const cString[4] = "\r\n";
		for(new i=0,l=strlen(cString); i<l; i++)
			fputchar(fwhnd,cString[i],false);


		fclose(fwhnd);
	}
	return ;
}

stock INI_Open(filename[], bool:create=false)
{

	if (!strlen(filename)) return false;
	if(create==true)
	{
		if(!INI_Exist(filename))
		INI_Create(filename);
	}
	else
	{
	    if(!INI_Exist(filename))
	    return false;
	}
	if (gFile[E_OPEND])
	{
		if (strcmp(gFile[E_FILE_NAME], filename, true)==0)
			return true;
		else INI_Close(false);
	}

	new File: frhnd;
	frhnd = fopen(filename, io_readwrite);
	if(frhnd)
	{
		gFile[E_OPEND] = true;
	    strmid(gFile[E_FILE_NAME],filename,0,strlen(filename),INI_MAX_FILENAME_LENGTH);

		INIDebug&&Debug_Writef("INI_Open(%s) INI 파일 %s을 열었습니다.",filename,filename);

		new
			szTemp[256],
			spec,
			i=0;

	    while((i < INI_MAX_LINE) && fread(frhnd,szTemp))
	    {
	        INI_DeleteLine(szTemp);
			spec=strfind(szTemp,"=");
			if(szTemp[0] == '!' || spec==-1)
			{
				if(szTemp[0] == '!')
				{
			        strmid(gCache[i][E_TEMP_VALUE],szTemp,0,strlen(szTemp),INI_MAX_VALUE_LENGTH);
				}
			    else
			    {
			        gCache[i][E_TEMP_VALUE][0] = '!';
			        strmid(gCache[i][E_TEMP_VALUE][1],szTemp,0,strlen(szTemp),INI_MAX_VALUE_LENGTH);
			    }
			}
			else
			{
				strmid(gCache[i][E_TEMP_KEY],szTemp,0,spec,INI_MAX_KEY_LENGTH);
				strmid(gCache[i][E_TEMP_VALUE],szTemp,spec+1,strlen(szTemp),INI_MAX_VALUE_LENGTH);
			}
			i++;
	    }
	    INIDebug&&Debug_Writef("INI_Open(%s) 정보들을 임시변수에 저장하였습니다.",filename);
	    fclose(frhnd);
	}
	return true;
}
stock INI_Close(bool:save=false)
{
	save&&INI_Save();
	INIDebug&&Debug_Writef("INI_Close(%s) 파일 %s을 닫습니다.",GetBoolName(_:save,0),gFile[E_FILE_NAME] );

	for(new i=0; i<INI_MAX_LINE; i++)
	{
	    gCache[i][E_TEMP_KEY][0] = EOS;
	    gCache[i][E_TEMP_VALUE][0] = EOS;
	}
	gFile[E_FILE_NAME][0] = EOS;
	gFile[E_OPEND] = false;
}
stock INI_Save()
{
	if(!gFile[E_OPEND] || !strlen(gFile[E_FILE_NAME]))
	{
	    INIDebug&&Debug_Write("오류:INI_Save() INI_Open 을 실행하지 않앗거나 파일이름 잘못됨.");
	    return ;
	}
	if(gFile[E_OPEND])
	{
		new
		//gFile[E_FILE_NAME]
			File:fwhnd = fopen(gFile[E_FILE_NAME],io_write);

		if(fwhnd)
		{
		    new
				szString[INI_MAX_INI_LENGTH],
				i=0;

			while(i < INI_MAX_LINE  && gCache[i][E_TEMP_VALUE][0]  )
			{
			    if(gCache[i][E_TEMP_VALUE][0] == '!' ||
				strlen(gCache[i][E_TEMP_VALUE]) ||
				strlen(gCache[i][E_TEMP_KEY]))
			    {
			        if(gCache[i][E_TEMP_VALUE][0] != '!')
			        {
       					format(szString,sizeof szString,"%s=%s\r\n",gCache[i][E_TEMP_KEY],gCache[i][E_TEMP_VALUE]);
      					INI_WriteChar(fwhnd,szString);
					}
					else
					{
       					format(szString,sizeof szString,"%s\r\n",gCache[i][E_TEMP_VALUE]);
						INI_WriteChar(fwhnd,szString);
					}
				}
				i++;
			}
			fclose(fwhnd);
			INIDebug&&Debug_Writef("INI_Save() 파일 %s 저장을 성공하였습니다.",gFile[E_FILE_NAME]);
		}
	}
}
stock bool:INI_Isset(key[])
{
	if(!gFile[E_OPEND] || !strlen(gFile[E_FILE_NAME])
	||!strlen(key))
	{
		INIDebug&&Debug_Writef("오류:INI_Isset(%s) INI_Open 을 실행하지 않앗거나 키값지정이 안되있거나 파일이름이 잘못됨.",key);
	    return false;
	}
	if(gFile[E_OPEND])
	{
	    new
			i=0;
		while(gCache[i][E_TEMP_VALUE][0]||gCache[i][E_TEMP_KEY][0])
		{
		    if(strcmp(key,gCache[i][E_TEMP_KEY],false,INI_MAX_KEY_LENGTH) == 0
			&&strlen(gCache[i][E_TEMP_KEY])
			&&strlen(gCache[i][E_TEMP_KEY])==strlen(key))
		    {
				return true;
		    }
		    i++;
		}
	}
	return false;
}
stock INI_Unset(key[])
{
	if(!gFile[E_OPEND] || !strlen(gFile[E_FILE_NAME])
	||!strlen(key))
	{
		INIDebug&&Debug_Writef("오류:INI_Unset(%s) INI_Open 을 실행하지 않앗거나 키값지정이 안되있거나 파일이름이 잘못됨.",key);
	    return false;
	}
	if(gFile[E_OPEND])
	{
	    new
			i=0;
		while(gCache[i][E_TEMP_VALUE][0]||gCache[i][E_TEMP_KEY][0])
		{
		    if(strcmp(key,gCache[i][E_TEMP_KEY],false,INI_MAX_KEY_LENGTH) == 0
			&&strlen(gCache[i][E_TEMP_KEY])
			&&strlen(gCache[i][E_TEMP_KEY])==strlen(key))
		    {
				for(new j=i; j<INI_MAX_LINE-1; j++)
				{
				    strmid(gCache[j][E_TEMP_KEY],gCache[j+1][E_TEMP_KEY],0,strlen(gCache[j+1][E_TEMP_KEY]),INI_MAX_KEY_LENGTH);
				    strmid(gCache[j][E_TEMP_VALUE],gCache[j+1][E_TEMP_VALUE],0,strlen(gCache[j+1][E_TEMP_VALUE]),INI_MAX_VALUE_LENGTH);
				}
				break;
		    }
		    i++;
		}
	}
	return true;
}
stock INI_Write(key[],value[])
{
	if(!gFile[E_OPEND] || !strlen(gFile[E_FILE_NAME])
	||!strlen(key)||!strlen(value))
	{
	    INIDebug&&Debug_Writef("오류:INI_Write(\"%s\",\"%s\"): INI_Open 을 실행하지 않앗거나 키값지정,정보값지정이 안되있거나 파일이름이 잘못됨.",key,value);
	    return false;
	}
	if(gFile[E_OPEND])
	{
	    new
			bool:checking=false,
			i=0;

		while(gCache[i][E_TEMP_VALUE][0]||gCache[i][E_TEMP_KEY][0])
		{
		    if(strcmp(key,gCache[i][E_TEMP_KEY],false,INI_MAX_KEY_LENGTH) == 0
				&&strlen(gCache[i][E_TEMP_KEY]))
		    {
		        strmid(gCache[i][E_TEMP_VALUE],value,0,strlen(value),INI_MAX_VALUE_LENGTH);
                checking=true;
				break;
			}
			i++;
		}
		if(!checking && i<INI_MAX_LINE)
		{
			strmid(gCache[i][E_TEMP_KEY],key,0,strlen(key),INI_MAX_KEY_LENGTH);
			strmid(gCache[i][E_TEMP_VALUE],value,0,strlen(value),INI_MAX_VALUE_LENGTH);
  }

	}
	return true;
}
stock INI_WriteInt(key[],value)
{
	new szString[21];
	format(szString,21,"%d",value);
	return INI_Write(key,szString);
}
stock INI_WriteFloat(key[],Float:value)
{
	new szString[21];
	format(szString,21,"%f",value);
	return INI_Write(key,szString);
}
stock INI_WriteBool(key[],value,type=DEFAULT_BOOL_TYPE)
{
	new szString[12];

	format(szString,21,"%s",
	GetBoolName(value,type));
	return INI_Write(key,szString);
}
stock INI_Get(key[])
{
	new szString[INI_MAX_VALUE_LENGTH];
	if(!gFile[E_OPEND] || !strlen(gFile[E_FILE_NAME])
	||!strlen(key))
	{
    	return szString;
	}
	if(gFile[E_OPEND])
	{
	    new
			i=0;
		while(gCache[i][E_TEMP_VALUE][0]||gCache[i][E_TEMP_KEY][0])
		{
		    if(strcmp(key,gCache[i][E_TEMP_KEY],false,INI_MAX_KEY_LENGTH) == 0
			&&strlen(gCache[i][E_TEMP_KEY])
			&&strlen(gCache[i][E_TEMP_KEY])==strlen(key))
		    {
		        strmid(szString,gCache[i][E_TEMP_VALUE],0,strlen(gCache[i][E_TEMP_VALUE]),INI_MAX_VALUE_LENGTH);

				break;
		    }
		    i++;
		}
	}
	return szString;
}
stock INI_GetBoolType(key[])
{
	new Get[12];
	strmid(Get,INI_Get(key),0,12,12);
	if(!strlen(Get) && !INI_Isset(key))
	{
		return DEFAULT_BOOL_TYPE;
	}

	new
	    x = DEFAULT_BOOL_TYPE;
	    
	for(new i=0; i<sizeof BoolName; i++)
	{
	    for(new j=0; j<2; j++)
	    {
            if(!strcmp(Get,BoolName[i][j],true))
            {
                x=i;
            }
	    }
	}
	
	return x;


}
stock bool:INI_GetBool(key[])
{
	new Get[12];
	strmid(Get,INI_Get(key),0,12,12);
	if(!strlen(Get)) return false;

	if(
		!strcmp(Get,"true",true)||
		!strcmp(Get,"Enabled",true)||
		!strcmp(Get,"yes",true)||
		!strcmp(Get,"on",true)||
		!strcmp(Get,"예",true)||
		!strcmp(Get,"1",true))
		return true;
	else return false;
}
stock INI_GetInt(key[])
{
	return strval(INI_Get(key));
}
stock Float:INI_GetFloat(key[])
{
	return floatstr(INI_Get(key));
}

