#ifndef _TERMINAL_H_
#define _TERMINAL_H_
/*-------------- File Guard ------------------*/
/*Include*/
#include <stdio.h>
#include <windows.h>
#include <Standard_Types.h>
#include <Macros.h>
#include "../Card/Card.h"
/*Define*/
#define Maximum_Ammount 500
/*Structures*/
typedef struct ST_terminalData_t{f32 transAmount;u8 transactionDate[11];}ST_terminalData_t;
typedef enum EN_terminalError_t{OK_T,EXPIRED_CARD,INVALID_CARD,INVALID_AMOUNT,EXCEED_MAX_AMOUNT}EN_terminalError_t;
extern ST_terminalData_t terminal_data;
/*Functins To Use*/
void getTransactionDate(ST_terminalData_t *termData);
logic terminal(ST_cardData_t *cardData,ST_terminalData_t *termData);
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData);
EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);
/*-------------- File Guard ------------------*/
#endif