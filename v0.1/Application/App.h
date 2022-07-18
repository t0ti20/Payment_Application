#ifndef _APP_H_
#define _APP_H_
/*-------------- File Guard ------------------*/
/*Include*/
#include <stdio.h>
#include <Macros.h>
#include <Standard_Types.h>
#include "../Card/Card.h"
#include "../Servar/Servar.h"
#include "../Terminal/Terminal.h"
/*Global Variables*/
ST_cardData_t cardData;
ST_terminalData_t terminal_data;
/*Functins To Use*/
logic appStart(void);
/*-------------- File Guard ------------------*/
#endif