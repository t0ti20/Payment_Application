#ifndef _TERMINAL_H_
#define _TERMINAL_H_
/*-------------- File Guard ------------------*/
/*Include*/
#include <stdio.h>
#include <windows.h>
#include <Standard_Types.h>
#include "../1-Application/Application.h"
/*Define*/
#define Maximum_Ammount 500
/*Functins To Use*/
u8 terminal(void);
u8 is_expired(void);
u8 get_amount(void);
/*Help Functions*/
u8 check_amount(u16 amount);
/*-------------- File Guard ------------------*/
#endif