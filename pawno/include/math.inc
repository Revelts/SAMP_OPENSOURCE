/*
 Beta Standard Math v1.0 BETA
 Copyleft 2007 BSGDT beta6
*/

#if defined _math_included
  #endinput
#endif

#define _math_included
#pragma library math

//this functions is included in a_samp.inc
//native Float:asin(Float:value); 
//native Float:acos(Float:value);
//native Float:atan(Float:value);
//native Float:atan2(Float:value,Float:value2);

native Float:rnd();
native Float:atof(const str[]);
native Float:ceil(Float:value);
native Float:cos(Float:value);
native Float:cosh(Float:value);
native Float:exp(Float:value);
native Float:fabs(Float:value);
native Float:floor(Float:value);
native Float:fmod(Float:value,Float:value2);
native Float:frexp(Float:value,value2);
native Float:ldexp(Float:value,value2);
native abs(value);