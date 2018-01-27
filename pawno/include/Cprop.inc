/*
 *            CProp functions 1.1 
 *        (c) Copyleft 2007 by CoolGuy
 *
 * @author    : 밥먹었니 (cafe.daum.net/Coolpdt)
 * @date      : 2007/04/29
 * @update    : 2007/05/11
 * @require : dini.inc
 *
 * This file is provided as is (no warranties).
 *
 */

/**
 * 확인이 용이한 Property를 생성합니다.
 * 디버그용으로 사용하기에 좋습니다.
 *
 */

#if defined _cprop_included
  #endinput
#endif

#define _cprop_included
#pragma library cprop

#include <dini>

#define FILE_PROPERTY "Properties.txt"



public c_PropertyReset()
{
   dini_Remove(FILE_PROPERTY);
   return dini_Create(FILE_PROPERTY);
}

public c_PropertyExists(name[]) return dini_Isset(FILE_PROPERTY,name);

public c_PropertyDelete(name[]){
if(!c_PropertyExists(name)) return false;

	dini_Unset(FILE_PROPERTY,name);
return true;
}


public c_PropertySet(name[],value[])
{
   if(!fexist(FILE_PROPERTY)) dini_Create(FILE_PROPERTY);

	return dini_Set(FILE_PROPERTY,name,value);
}

public c_PropertyIntSet(name[],val)
{
	new str[11];
	valstr(str,val);
	return c_PropertySet(name,str);
}

public c_PropertyBoolSet(name[],bool:val)
{
	new input;
	if(val == false) input = 0;
	else input = 1;
		
	return c_PropertyIntSet(name,input);
}

public c_PropertyFloatSet(name[],Float:value[])
{
	new str[64];
	format(str,sizeof(str),"%f",value);
	return c_PropertySet(name,str);
}

public c_PropertyGet(name[]) {
		new value[256];
if(!c_PropertyExists(name)) return value;

value=dini_Get(FILE_PROPERTY,name);
	
   return value;
}

public c_PropertyInt(name[]) return strval(c_PropertyGet(name));

public bool:c_PropertyBool(name[]) return bool:strval(c_PropertyGet(name));

public Float:c_PropertyFloat(name[]) return floatstr(c_PropertyGet(name));

stock c_PropertyAdd(name[],value=1)
	return c_PropertyIntSet(name,c_PropertyInt(name)+value);

stock c_PropertySub(name[],value=1)
	return c_PropertyIntSet(name,c_PropertyInt(name)-value);

stock c_PropertyFloatAdd(name[],Float:value=1.000000)
	return c_PropertyFloatSet(name,floatadd(c_PropertyFloat(name),value));

stock c_PropertyFloatSub(name[],Float:value=1.000000)
return c_PropertyFloatSet(name,floatsub(c_PropertyFloat(name),value));

