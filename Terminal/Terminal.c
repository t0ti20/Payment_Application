/*------------------------------- INCLUDE -------------------------------*/
#include "./Terminal.h"
/*--------------------------- Terminal ---------------------------*/
logic terminal(ST_cardData_t *cardData,ST_terminalData_t *termData)
{
     u8 flag;
     getTransactionDate(termData);
     flag=isCardExpired(*cardData,*termData);
     if(flag==OK_T)flag=getTransactionAmount(termData);
     if(flag==OK_T)flag=true;
     else
     {
          switch (flag)
          {
               case EXPIRED_CARD:printf("xxx  Expired Card  xxx\n");break;
               case INVALID_CARD:printf("xxx   ERROR   xxx\n");;break;
               case INVALID_AMOUNT:printf("xxx  Invaild Amount  xxx\n");break;
               case EXCEED_MAX_AMOUNT:printf("xxx  You've Reached Maximum Amount  xxx\n");break;
               default :printf("xxx  Error  xxx\n");break;
          }
          flag=false;
     }
     return flag;
}
/*--------------------------- getTransactionDate ---------------------------*/
void getTransactionDate(ST_terminalData_t *termData)
{
     u8 date[6];
     SYSTEMTIME local_time;
     GetLocalTime(&local_time);
     itoa(local_time.wDay,date,10);
     strcat(termData->transactionDate,date);
     strcat(termData->transactionDate,"/");
     itoa(local_time.wMonth,date,10);
     if(local_time.wMonth<10)strcat(termData->transactionDate,"0");
     strcat(termData->transactionDate,date);
     strcat(termData->transactionDate,"/");
     itoa(local_time.wYear,date,10);
     strcat(termData->transactionDate,date);
}
/*--------------------------- isCardExpired ---------------------------*/
EN_terminalError_t isCardExpired(ST_cardData_t cardData,ST_terminalData_t termData)
{
     u8 mn_s,yr_s,mn_c,yr_c,flag;
     mn_s=((termData.transactionDate[2]-48)*10)+(termData.transactionDate[3]-48);
     yr_s=((termData.transactionDate[7]-48)*10)+(termData.transactionDate[8]-48);
     mn_c=((cardData.cardExpirationDate[0]-48)*10)+(cardData.cardExpirationDate[1]-48);
     yr_c=((cardData.cardExpirationDate[3]-48)*10)+(cardData.cardExpirationDate[4]-48);
     if(yr_c>yr_s) flag=OK_T;
     else if (yr_c==yr_s) {flag=mn_c>=mn_s?OK_T:EXPIRED_CARD;}
     else flag=EXPIRED_CARD;
     return flag;
}
/*--------------------------- getTransactionAmount ---------------------------*/
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
     u8 flag;
     printf("--------------------------------------------\n");
     printf("Please Enter Product Price : ");
     scanf("%f",&termData->transAmount);
     flag=(termData->transAmount>0)?isBelowMaxAmount(termData):INVALID_AMOUNT;
     return flag;
}
/*--------------------------- isBelowMaxAmount ---------------------------*/
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
     return (termData->transAmount<=Maximum_Ammount)?OK_T:EXCEED_MAX_AMOUNT;
}