/*------------------------------- INCLUDE -------------------------------*/
#include "./Card.h"
/*--------------------------- Card ---------------------------*/
logic card(ST_cardData_t *cardData)
{
     u8 flag=WRONG_NAME;
     if (getCardHolderName(cardData)==OK_C)
     {
          flag=getCardExpiryDate(cardData);
          flag=(flag==OK_C)?getCardPAN(cardData):flag;
     }
     if (flag!=OK_C)
     {
          switch (flag)
          {
               case WRONG_NAME:printf("xxx  Invaild Name  xxx\n");break;
               case WRONG_EXP_DATE:printf("xxx  Invaild Date  xxx\n");;break;
               case WRONG_PAN:printf("xxx  Invaild PAN  xxx\n");break;
               default :printf("xxx  Error  xxx\n");break;
          }
          flag=false;
     }
     else flag=true;
     return flag;
}
/*---------------------------- getCardHolderName ----------------------------*/
EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
     u8 flag=zero;
     printf("--------------------------------------------\n");
     printf("Please Enter Card Holder Name : ");
     gets(cardData->cardHolderName);
     for(u8 counter=zero;counter<(sizeof(cardData->cardHolderName)/sizeof(cardData->cardHolderName[0]));counter++)
          flag=cardData->cardHolderName[counter]?(flag+1):flag;
     if(flag>19&&flag<24)flag=OK_C;
     else flag=WRONG_NAME;
     return flag;
}
/*--------------------------- getCardExpiryDate ---------------------------*/
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
     u8 flag=zero;
     printf("--------------------------------------------\n");
     printf("Please Enter Expire Date mn/yr : ");
     scanf("%[^\n]%*c", cardData->cardExpirationDate);
     flag=(cardData->cardExpirationDate[0]>='0' && cardData->cardExpirationDate[0]<='1')?(flag+1):false;
     flag=(cardData->cardExpirationDate[1]>='0' && cardData->cardExpirationDate[1]<='9')?(flag+1):false;
     flag=(cardData->cardExpirationDate[2]=='/')?(flag+1):false;
     flag=(cardData->cardExpirationDate[3]>='0' && cardData->cardExpirationDate[3]<='9')?(flag+1):false;
     flag=(cardData->cardExpirationDate[4]>='0' && cardData->cardExpirationDate[4]<='9')?(flag+1):false;
     flag=(cardData->cardExpirationDate[5]==0)?(flag+1):false;
     if(flag==six)flag=OK_C;
     else flag=WRONG_EXP_DATE;
     return flag;
}
/*--------------------------- getCardPAN ---------------------------*/
EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
     u8 flag=zero;
     printf("--------------------------------------------\n");
     printf("Please Enter PAN Number : ");
     scanf("%[^\n]%*c", cardData->primaryAccountNumber);
     for(u8 counter=zero;counter<(sizeof(cardData->primaryAccountNumber)/sizeof(cardData->primaryAccountNumber[0]));counter++)
     {
          if (cardData->primaryAccountNumber[counter]>='0' && cardData->primaryAccountNumber[counter]<='9')
               flag=cardData->primaryAccountNumber[counter]?(flag+1):flag;
          else break;
     }
     if(flag>15 && flag<20) flag=PANCheck(cardData);
     else flag=WRONG_PAN;
     return flag;
}
/*--------------------------- getCardPAN ---------------------------*/
EN_cardError_t PANCheck(ST_cardData_t *cardData)
{
     u8 temp_pan[20],flag=false;
     /*Convert From Char To Dec*/
     for(u8 count=0 ; count<16 ; count++)
          temp_pan[count]=cardData->primaryAccountNumber[count]-48;
     /*Swap*/
     for(u8 count=0 ; count<7 ; count++)
     {
          temp_pan[count]^=temp_pan[14-count];
          temp_pan[14-count]^=temp_pan[count];
          temp_pan[count]^=temp_pan[14-count];
     }
     /*Multiplication By 2 if odd*/
     for(u8 count=0 ; count<15 ; count++)
          temp_pan[count]=((count%2)==0)?(temp_pan[count]*2):temp_pan[count];
     /*Subtraction By 9 if greater*/
     for(u8 count=0 ; count<15 ; count++)
          temp_pan[count]=(temp_pan[count]>9)?(temp_pan[count]-9):temp_pan[count];
     /*Summation*/
     for(u8 count=0 ; count<16 ; count++)
          flag+=temp_pan[count];
     /*Check*/
     if(flag%10==0) flag=OK_C;
     else flag=WRONG_PAN;
     return flag;
}