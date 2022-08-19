/*------------------------------- INCLUDE -------------------------------*/
#include "./Card.h"
/*--------------------------- Card ---------------------------*/
void card(void)
{
    card_holder_name();
    card_expiry_date();
    card_pan_number();
}
/*---------------------------- Get Card Name ----------------------------*/
void card_holder_name(void)
{
     u8 flag=false;
     do
     {
          printf("Please Enter Card Holder Name : ");
          gets(current_data.name);
          for(u8 i=0 ; i<(sizeof(arr_30)/sizeof(u8)) && current_data.name[i]!=0 ; i++)
          {
               if((current_data.name[i]>'@' && current_data.name[i]<'[')||(current_data.name[i]>'`' && current_data.name[i]<'{')||(current_data.name[i]==' '))  /*A-Z// //a-z// ONLY*/
               {
                    flag=false;
               }
               else
               {
                    for(u8 i=0 ; i<(sizeof(arr_30)/sizeof(u8)) ; i++)
                    {
                         current_data.name[i]=false;
                    }
                    printf("xxx  Invaild Name  xxx\n");
                    flag=true;
                    break;
               }
          }
     }while (flag);
}
/*--------------------------- Get Expiry Date ---------------------------*/
void card_expiry_date(void)
{
     u8 flag;
     while (true)
     {
          flag=false;
          printf("--------------------------------------------\n");
          printf("Please Enter Expire Date mn/yr : ");
          scanf("%[^\n]%*c", current_data.date);
          flag=(current_data.date[0]>='0'&&current_data.date[0]<='1')?(flag+1):false;
          flag=(current_data.date[1]>='0'&&current_data.date[1]<='9')?(flag+1):false;
          flag=(current_data.date[2]=='/')?(flag+1):false;
          flag=(current_data.date[3]>='0'&&current_data.date[3]<='9')?(flag+1):false;
          flag=(current_data.date[4]>='0'&&current_data.date[4]<='9')?(flag+1):false;
          flag=(current_data.date[5]==0)?(flag+1):false;
          if(flag==6)break;
          for(u8 i=0;i<7;i++)current_data.date[i]==0;
          printf("xxx  Invaild Date  xxx\n");
     }
}
/*--------------------------- Get Card PAN ---------------------------*/
void card_pan_number(void)
{
     u8 flag,count;
     arr_17 temp;
     while (true)
     {
          printf("--------------------------------------------\n");
          printf("Please Enter PAN Number : ");
          scanf("%[^\n]%*c", temp);
          flag=false;
          count=false;
          /*------------ PAN CHECK ------------*/
          /*Convert From Char To Dec*/
          for(u8 x=0 ; x<16 ; x++) 
          {
               if(temp[x])
               {
                    count++;
                    current_data.pan[x]=temp[x];
                    temp[x]-=48;
               }
          }
          /*Swap*/
          for(u8 x=0 ; x<7 ; x++)
          {
               temp[x]^=temp[14-x];
               temp[14-x]^=temp[x];
               temp[x]^=temp[14-x];
          }
          /*Multiplication By 2 if odd*/
          for(u8 x=0 ; x<15 ; x++)
          {
               temp[x]=((x%2)==0)?(temp[x]*2):temp[x];
          }
          /*Subtraction By 9 if greater*/
          for(u8 x=0 ; x<15 ; x++)
          {
               temp[x]=(temp[x]>9)?(temp[x]-9):temp[x];
          }
          /*Summation*/
          for(u8 x=0 ; x<16 ; x++)
          {
               flag+=temp[x];
          }
          /*Check*/
          if(flag%10==0 && count==16) break;
          /*------------ IF FALSE ------------*/
          else printf("xxx  Invaild PAN  xxx\n");
     }
     printf("--------------------------------------------\n");
}

