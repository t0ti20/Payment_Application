#ifndef _SERVAR_H_
#define _SERVAR_H_
/*-------------- File Guard ------------------*/
/*Include*/
#include <stdio.h>
#include <windows.h>
#include <Standard_Types.h>
#include "../1-Application/Application.h"
/*Bank Data*/
typedef struct{u8 pan[17];u8 date[6];u16 amount;}bank;
/*Functins To Use*/
void server(void);
void get_bank_data(void);
void update_account_balance();
void save_transaction();
u8 is_amount_available();
u8 is_valid_account(void);
/*-------------- File Guard ------------------*/
#endif