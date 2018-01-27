////////////////////////////////////////////////////////////////////////////////
//

//
//////////////////////////////////////////////////////////////////////////////////

enum {

        // Anti Bug Cars
        PLAYER_SURF_VEHICLE,
        PLAYER_CAR_TELEPORT,
        PLAYER_STATE_HACK,
}


new     Float: g_ucPos[4],
        Float:g_diferencasAngle[MAX_VEHICLES],
        vehVelocity[MAX_VEHICLES],
        bool: vehRespawn[MAX_VEHICLES],
        bool: pOPC,
        bool: pOPSC,
        bool: pOUVU;

forward OnPlayerHacking(playerid, hackid);

#define SERVER_SIDE_DELAY   (0002)


#define pFunction%0(%1) %0(%1); public%0(%1)
#define Hook%0(%1)  stock%0_pB(%1)

// ---------------------------------------------
//  Nesta parte aparecem funcoes hookeadas
//  Elas sao essenciais para ter controle server-side detalhado
//  Essencial para qualquer anti-hack. Controle minucioso
//  Para o funcionamento disto precisa do filterscript
//      Hookei apenas as mais importantes callbacks nativas da sa:mp.
//      Daria muito trabalho "hookear" todas
// ---------------------------------------------



Hook PutPlayerInVehicle(playerid,vehicleid, seatid) {
        return SetPVarInt(playerid, #registerState, (gettime() - SERVER_SIDE_DELAY)), PutPlayerInVehicle(playerid, vehicleid, seatid);
}

Hook SetVehicleVelocity(vehicleid, Float: pX, Float: pY, Float: pZ) {
        return vehVelocity[vehicleid] = gettime(), SetVehicleVelocity(vehicleid, pX, pY, pZ);
}

Hook SetVehiclePos(vehicleid, Float: pX, Float: pY, Float: pZ) {

        for( new i = GetMaxPlayers() - 1; i > -1;  --i ) {
                if( GetPlayerVehicleID(i) == vehicleid ) {
                        SetPVarInt(i, #tPosSet, gettime());
                        break;
                }
        }

        return SetVehiclePos(vehicleid, pX, pY, pZ);
}

Hook SetVehicleToRespawn(vehicleid) {
        return vehRespawn[vehicleid] = true, SetVehicleToRespawn(vehicleid);
}


#if !defined varGet
#define varGet(%0)      getproperty(0,%0)
#endif

#if !defined varSet
#define varSet(%0,%1) setproperty(0, %0, %1)
#endif

public OnGameModeInit() {
        pOPC = funcidx(#ExOnPlayerConnect) != -1;

 
    
        pOPSC = funcidx(#ExOnPlayerStateChange) != -1;
        pOUVU = funcidx(#ExOnUnoccupiedVehicleUpdate) != -1;
        return CallLocalFunction(#ExOnGameModeInit, #);
}

#if defined _ALS_OnGameModeInit
        #undef OnGameModeInit
#else
        #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit ExOnGameModeInit
forward ExOnGameModeInit();

public OnPlayerConnect(playerid) {
        CallLocalFunction("registrarJogador_pB", "i", playerid);
        return (pOPC ? CallLocalFunction("ExOnPlayerConnect", "i", playerid) : 1);
}

#if defined _ALS_OnPlayerConnect
        #undef OnPlayerConnect
#else
        #define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect ExOnPlayerConnect
forward ExOnPlayerConnect(playerid);



public OnPlayerStateChange(playerid, newstate, oldstate) {

        /*--------------------------------------------------
        *
        *  Anti State Hack
        *   Usando OnPlayerStateChange com gettime
        *   A precisao deste sistema fica em torno de 95%
        *
        -------------------------------------------------*/

        if(newstate == PLAYER_STATE_DRIVER) {
                if((gettime() - GetPVarInt(playerid, #registerState)) < 2 && (gettime() - GetPVarInt(playerid, #tPosSet)) > 3) {
                        CallLocalFunction("OnPlayerHacking", "ii", playerid, PLAYER_STATE_HACK);
                }
                SetPVarInt(playerid, #registerState, gettime());
        }
        SetPVarInt(playerid, #spiderCar, 0);
        return (pOPSC ? CallLocalFunction("ExOnPlayerStateChange", "idi", playerid, newstate, oldstate) : 1);
}

#if defined _ALS_OnPlayerStateChange
        #undef OnPlayerStateChange
#else
        #define _ALS_OnPlayerStateChange
#endif

#define OnPlayerStateChange ExOnPlayerStateChange
forward ExOnPlayerStateChange(playerid, newstate, oldstate);

public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat) {

        /*--------------------------------------------------
        *
        *  Anti Surfer Vehicle
        *   Usando OnUnoccupiedVehicleUpdate com gettime e outros
        *   A precisao deste sistema fica em torno de 85%
        *
        -------------------------------------------------*/

        GetVehiclePos(vehicleid, g_ucPos[0], g_ucPos[1], g_ucPos[2]);

        if(IsPlayerInRangeOfPoint(playerid, 1.0, g_ucPos[0], g_ucPos[1], g_ucPos[2])) {
                GetVehicleZAngle(vehicleid, g_ucPos[3]);
                if(g_diferencasAngle[vehicleid] != g_ucPos[3]) {
                        if(!IsPlayerInAnyVehicle(playerid)) {
                                GetPlayerPos(vehicleid, g_ucPos[1], g_ucPos[1], g_ucPos[3]);
                                if(g_ucPos[3] > g_ucPos[2]) {
                                        SetPVarInt(playerid, #registrosUAF, GetPVarInt(playerid, #registrosUAF) +1);
                                        if(GetPVarInt(playerid, #registrosUAF) > 40) {
                                                CallLocalFunction("OnPlayerHacking", "ii", playerid, PLAYER_SURF_VEHICLE);
                                        }
                                }
                        }
                }
                g_diferencasAngle[vehicleid] = g_ucPos[3];
                return true;
        }

        /*--------------------------------------------------
        *
        *  Anti Teleport Vehicle
        *   Usando OnUnoccupiedVehicleUpdate com gettime e outros
        *   A precisao deste sistema fica em torno de 85%
        *
        -------------------------------------------------*/

        else if(!IsPlayerInRangeOfPoint(playerid, 40.0, g_ucPos[0], g_ucPos[1], g_ucPos[2])) {
                if(!IsPlayerInAnyVehicle(playerid) && (gettime() - GetPVarInt(playerid, #tPosSet) > 3) && !vehRespawn[vehicleid]) {
                        CallLocalFunction("OnPlayerHacking", "ii", playerid, PLAYER_CAR_TELEPORT);
                } else if(vehRespawn[vehicleid]) vehRespawn[vehicleid] = false;
        }
        return (pOUVU ? CallLocalFunction("ExOnUnoccupiedVehicleUpdate", "idi", vehicleid, playerid, passenger_seat) : 1);
}

#if defined _ALS_OnUnoccupiedVehicleUpdate
        #undef OnUnoccupiedVehicleUpdate
#else
        #define _ALS_OnUnoccupiedVehicleUpdate
#endif

#define OnUnoccupiedVehicleUpdate ExOnUnoccupiedVehicleUpdate
forward ExOnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat);


//#define PutPlayerInVehicle                      PutPlayerInVehicle_pB

//#define SetVehiclePos                           SetVehiclePos_pB

#define SetVehicleVelocity                      SetVehicleVelocity_pB
#define SetVehicleToRespawn                     SetVehicleToRespawn_pB

forward OnPlayerHacking(playerid, hackid);
