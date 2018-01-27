/*

	GAME INFOMATION HEADER v1.0
	COPYRIGHT 2008 beta6. ALL RIGHTS RESERVED.

 -- function list

native IsPoliceCar(modelid);
native IsTunableVehicle(modelid);
native IsAttackableVehicle(modelid);
native IsMotorcycle(modelid);
native IsBicycle(modelid);
native IsAirPlane(modelid);
native IsPublicTransportation(modelid);
native IsTruck(modelid);
native IsRV(modelid);
native IsShip(modelid);
*/

#if defined _ginfo_included
  #endinput
#endif
#define _ginfo_included
#pragma library ginfo

forward IsPoliceCar(modelid);
forward IsTunableVehicle(modelid);
forward IsAttackableVehicle(modelid);
forward IsMotorcycle(modelid);
forward IsBicycle(modelid);
forward IsAirPlane(modelid);
forward IsPublicTransportation(modelid);
forward IsTruck(modelid);
forward IsRV(modelid);
forward IsShip(modelid);

public IsPoliceCar(modelid)
{
	if(modelid == 596 || modelid == 597 || modelid == 598 || modelid == 599)
	{
		return 1;
	}
	else if(modelid == 601 || modelid == 427 || modelid == 523 || modelid == 528 || modelid == 490)
	{
		return 1;
	}
	return 0;
}

public IsTunableVehicle(modelid)
{
	if(modelid == 560 || modelid == 559 || modelid == 562 || modelid == 557 || modelid == 411)
	{
		return 1;
	}
	return 0;
}

public IsAttackableVehicle(modelid)
{
	if(modelid == 425 || modelid == 432 || modelid == 447 || modelid == 476 || modelid == 476 || modelid == 520)
	{
		return 1;
	}
	return 0;
}

public IsMotorcycle(modelid)
{
	if(modelid == 521 || modelid == 522 || modelid == 523 || modelid == 471 || modelid == 461 || modelid == 581)
	{
		return 1;
	}
	return 0;
}

public IsBicycle(modelid)
{
	if(modelid == 509 || modelid == 510 || modelid == 481)
	{
		return 1;
	}
	return 0;
}


public IsAirPlane(modelid)
{
	if(modelid == 593 || modelid == 520 || modelid == 519 || modelid == 513 || modelid == 511 || modelid == 476 || modelid == 460)
	{
		return 1;
	}
	return 0;
}

public IsShip(modelid)
{
	if(modelid == 472 || modelid == 493 || modelid == 595 || modelid == 473 || modelid == 484 || modelid == 430 || modelid == 452 || modelid == 476 || modelid == 453)
	{
		return 1;
	}
	else if(modelid == 446 || modelid == 454)
	{
		return 1;
	}
	return 0;
}


public IsPublicTransportation(modelid)
{
	if(modelid == 420 || modelid == 438)
	{
		return 1;
	}
	else if(modelid == 431 || modelid == 437)
	{
		return 1;
	}
	return 0;
}

public IsTruck(modelid)
{
	if(modelid == 422 || modelid == 440 || modelid == 478 || modelid == 482 || modelid == 543 || modelid == 554)
	{
	return 1;
	}
	return 0;
}

public IsRV(modelid)
{
	if(modelid==400 || modelid==418 || modelid==442 || modelid==458 || modelid==479 || modelid==482 || modelid==483 || modelid==579)
	{
	return 1;
	}
	return 0;
}
