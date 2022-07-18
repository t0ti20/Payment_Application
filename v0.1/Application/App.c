#include "./App.h"

u32 main(void)
{
     return appStart();
}

logic appStart(void)
{
     u8 flag;
     flag=card(&cardData);
     if(flag)
     {
          flag=terminal(&cardData,&terminal_data);
          if(flag) flag=server(&cardData,&terminal_data);
     }
}
