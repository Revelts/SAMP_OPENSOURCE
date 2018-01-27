//include
#include a_samp.inc
//System
#define M_P 		200
#define SCM		SendClientMessage
#define SCMToAll	SendClientMessageToAll
//define
#define public:%1(%2)   forward %1(%2); public %1(%2)
#define Anim(%1)	ApplyAnimation(%1,1)
#define RESPAWN_DELAY   -1