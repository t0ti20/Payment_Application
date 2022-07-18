/*------------------------------- INCLUDE -------------------------------*/
#include "./Servar.h"
/*--------------------------- Get Bank Data ---------------------------*/
ST_accountsDB_t accountsDB[50];
u8 record=zero;
u8 count=zero;
logic server(ST_cardData_t *cardData,ST_terminalData_t *termData)
{
     u8 flag;
     loadAccountData();
     flag=isValidAccount(cardData);
     if(flag==OK_S)
     {
          flag=isAmountAvailable(termData);
          if(flag==OK_S)
          {
               flag=saveTransaction(cardData,termData);
               if(flag==OK_S){flag=updateAcount();}
          }
     }
     switch (flag)
          {
               case OK_S:printf("===== Successful Transaction ====\n");flag=true;break;
               case SAVING_FAILED:printf("xxx  Error While Saving  xxx\n");break;
               case ERROR_UPDATE_ACCOUNT:printf("xxx   Error Updating Account   xxx\n");break;
               case LOW_BALANCE:printf("xxx  No Available Amount  xxx\n");break;
               case ACCOUNT_NOT_FOUND:printf("xxx  Can't Find Account  xxx\n");break;
               default :printf("xxx  Error  xxx\n");break;
          }
     return flag==true?true:false;
}
/*--------------------------- saveTransaction ---------------------------*/
EN_serverError_t updateAcount(void)
{
     u8 flag=ERROR_UPDATE_ACCOUNT;
     FILE *file;
     printf("%f\n",accountsDB[count].amount);
     file = fopen("./Data_Base/Bank_Data.txt","w");
     if(!file)printf("Cannot Write On Bank Data Base");
     else
     {
          for(u8 i=0;i<record;i++) fprintf(file,"%s,%s,%f\n",accountsDB[i].pan,accountsDB[i].date,accountsDB[i].amount);
          flag=OK_S;
     }
     fclose(file);
     return flag;
}
/*--------------------------- saveTransaction ---------------------------*/
EN_serverError_t saveTransaction(ST_cardData_t *cardData,ST_terminalData_t *transData)
{
     u8 flag=SAVING_FAILED;
     FILE *file;
     file = fopen("./Data_Base/Transactions.txt","a");
     if(!file)printf("Cannot Write On Transactions Data Base");
     else
     {
         fprintf(file,"Date :%s , Amount:%f , Account Number:%s\n",transData->transactionDate,transData->transAmount,cardData->primaryAccountNumber);
         flag=OK_S;
     }
     fclose(file);
     return flag;
}
/*--------------------------- isAmountAvailable ---------------------------*/
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData)
{
     u8 flag=LOW_BALANCE;
     if (accountsDB[count].amount>=termData->transAmount)
     {
          accountsDB[count].amount-=termData->transAmount;
          flag=OK_S;
     }
     return flag;
}
/*--------------------------- isValidAccount ---------------------------*/
EN_serverError_t isValidAccount(ST_cardData_t *cardData)
{
     u8 flag;
     while(count<record)
     {
          flag=zero;
          for(u8 i=0 ; i<17 ; i++) 
          {
               if(accountsDB[count].pan[i]==cardData->primaryAccountNumber[i]) flag++;
               else break;
          }
          if(flag==17) {flag=OK_S;break;}
          else flag=ACCOUNT_NOT_FOUND;
          count++;
     }
     return flag;
}
/*--------------------------- loadAccountData ---------------------------*/
logic loadAccountData(void)
{
     u8 read=0;
     FILE *file;
     file=fopen("./Data_Base/Bank_Data.txt","r");
     if(!file)printf("xxx Cannot Found Bank Data Base xxx");
     do
     {
          read=fscanf(file,"%16[^,],%5[^,],%f\n",accountsDB[record].pan,accountsDB[record].date,&accountsDB[record].amount);
          if (read==3)record++;
          else if (read!=4 && !feof(file)) printf("File format incorrect.\n");
          else if (ferror(file)) printf("Error reading file.\n");
     }while(!feof(file));
     fclose(file);
}