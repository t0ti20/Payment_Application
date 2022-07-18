#ifndef _CARD_H_
#define _CARD_H_
/*-------------- File Guard ------------------*/
/*Include*/
#include <stdio.h>
#include <Standard_Types.h>
#include <Macros.h>
/*Type Defs*/
typedef struct ST_cardData_t {u8 cardHolderName[25];u8 primaryAccountNumber[20];u8 cardExpirationDate[6];}ST_cardData_t;
typedef enum EN_cardError_t{OK_C,WRONG_NAME,WRONG_EXP_DATE,WRONG_PAN}EN_cardError_t;
extern ST_cardData_t cardData;
/*Functins*/
logic card(ST_cardData_t *cardData);
EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);
EN_cardError_t PANCheck(ST_cardData_t *cardData);
/*-------------- File Guard ------------------*/
#endif