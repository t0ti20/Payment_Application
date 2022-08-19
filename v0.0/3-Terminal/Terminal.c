/*------------------------------- INCLUDE -------------------------------*/
#include "./Terminal.h"
/*--------------------------- Terminal ---------------------------*/
u8 terminal(void)
{    
     return (is_expired()?get_amount():false);
}
/*--------------------------- Is Expired ---------------------------*/
u8 is_expired(void)
{
     SYSTEMTIME local_time;
     GetLocalTime(&local_time);
     u8 flag=true;
     s8 mn,yr;
     while(flag)
     {
          mn=((current_data.date[0]-48)*10)+(current_data.date[1]-48)-local_time.wMonth;
          yr=((current_data.date[3]-48)*10)+(current_data.date[4]-48)-(local_time.wYear-2000);
          if(yr>0)flag=true;
          else if(yr<0)flag=false;
          else 
          {
               flag=(mn>0)?true:false;
          }
          if(flag)  return true;
          printf("xxx  Expired Card  xxx\n");
          return false;
     }
}
/*--------------------------- Get Amount ---------------------------*/
u8 get_amount(void)
{
     printf("Please Enter Product Price : ");
     scanf("%d",&current_data.amount);
     if(check_amount(current_data.amount)) return true;
     else
     {
          printf("xxx  You've Reached Maximum Amount  xxx\n");
          return false;
     }
}
/*--------------------------- Check Amount ---------------------------*/
u8 check_amount(u16 amount)
{
     return (amount<Maximum_Ammount)?true:false;
}

