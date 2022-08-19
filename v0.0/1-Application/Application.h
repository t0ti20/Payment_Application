#ifndef _MAIN_H_
#define _MAIN_H_
/*-------------- File Guard ------------------*/
/*Include*/
#include <stdio.h>
#include <Standard_Types.h>
#include "../2-Card/Card.h"
#include "../3-Terminal/Terminal.h"
#include "../4-Servar/Servar.h"
/*Type Defs*/
typedef enum{false,true}logic;
typedef u8 arr_30[30];
typedef u8 arr_17[17];
typedef u8 arr_6[6];
/*Current Data*/
struct process{arr_30 name;arr_17 pan;u16 amount;arr_6 date;};
extern struct process current_data;
struct process current_data;
/*Functins To Use*/
void application(void);
/*-------------- File Guard ------------------*/
#endif