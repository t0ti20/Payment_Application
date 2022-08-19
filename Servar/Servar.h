#ifndef _SERVAR_H_
#define _SERVAR_H_
/*-------------- File Guard ------------------*/
/*Include*/
#include <stdio.h>
#include <windows.h>
#include "../Standard_Types.h"
#include "../Card/Card.h"
#include "../Terminal/Terminal.h"
/*Bank Data*/
typedef struct ST_accountsDB_t{u8 flag;u8 pan[20];u8 date[6];f32 amount;}ST_accountsDB_t;
typedef enum EN_serverError_t{OK_S,SAVING_FAILED,ERROR_UPDATE_ACCOUNT,ACCOUNT_NOT_FOUND,LOW_BALANCE}EN_serverError_t ;
/*Functins To Use*/
logic server(ST_cardData_t *cardData,ST_terminalData_t *termData);
logic loadAccountData(void);
EN_serverError_t isValidAccount(ST_cardData_t *cardData);
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData);
EN_serverError_t saveTransaction(ST_cardData_t *cardData,ST_terminalData_t *transData);
EN_serverError_t updateAcount(void);
/*-------------- File Guard ------------------*/
#endif