/*------------------------------- INCLUDE -------------------------------*/
#include "./Servar.h"
/*--------------------------- Get Bank Data ---------------------------*/
bank bank_data[50];
u8 record=0;
u8 count=0;
/*--------------------------- Get Bank Data ---------------------------*/
void get_bank_data(void)
{
     u8 read=0;
     FILE *file;
     file=fopen("./Data_Base/Bank_Data.txt","r");
     if(!file)printf("Cannot Found Bank Data Base");
     do
     {
          read=fscanf(file,"%16[^,],%5[^,],%d\n",bank_data[record].pan,bank_data[record].date,&bank_data[record].amount);
          if (read==3)record++;
          else if (read!=4 && !feof(file)) printf("File format incorrect.\n");
          else if (ferror(file)) printf("Error reading file.\n");
     }while(!feof(file));
     fclose(file);
}
/*--------------------------- Is Valid Account ---------------------------*/
u8 is_valid_account(void)
{
     u8 pan[17],date[6];
     u16 amount;
     u8 flag=false;
     while(count<record)
     {
          flag=false;
          for(u8 i=0 ; i<17 ; i++) 
          {
               if(bank_data[count].pan[i]==current_data.pan[i]) flag++;
               else break;
          }
          if(flag==17) return true;
          else count++;
     }
     printf("xxx  Can't Find Account  xxx\n");
     return false;
}
/*--------------------------- Server ---------------------------*/
u8 is_amount_available()
{
     u8 flag=false;
     if (bank_data[count].amount>=current_data.amount)
     {
          bank_data[count].amount-=current_data.amount;
          flag=true;
     }
     else printf("xxx  No Available Amount  xxx\n");
     printf("--------------------------------------------\n");
     return flag;
}
/*--------------------------- Server ---------------------------*/
void update_account_balance()
{
     FILE *file;
     file = fopen("./Data_Base/Bank_Data.txt","w");
     if(!file)printf("Cannot Write On Bank Data Base");
     else
     {
          for(u8 i=0;i<record;i++) fprintf(file,"%s,%s,%d\n",bank_data[i].pan,bank_data[i].date,bank_data[i].amount);
     }
     fclose(file);
     printf("===== Successful Transaction ====");
}
/*--------------------------- Server ---------------------------*/
void server(void)
{
     get_bank_data();
     if(is_valid_account())
     {
          if(is_amount_available())
          {
               update_account_balance();
               save_transaction();
          }
     }
}
/*--------------------------- Server ---------------------------*/
void save_transaction()
{
     SYSTEMTIME local_time;
     GetLocalTime(&local_time);
     FILE *file;
     file = fopen("./Data_Base/Transactions.txt","a");
     if(!file)printf("Cannot Write On Transactions Data Base");
     else
     {
         fprintf(file,"%d-%d-%d , %s , %d\n",local_time.wDay,local_time.wMonth,local_time.wYear,current_data.pan,current_data.amount);
     }
     fclose(file);
}