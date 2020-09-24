#include <reg51.h>
sbit counter=P3^5;
sbit mybit = P1^2; 
void T1M1Delay(void);
void main(void){
  counter=1;
  TMOD=0x60;
  TH1= 0xF5;
  while (1) {
   do {
      TR1=1;
      P2=TL1;
      }
   while (TF1==0);
		if(TF1 == 1)
		{
      mybit = ~mybit;
			T1M1Delay();
			TF1 = 0;
    } 			
   TR1=0;
   TF1=0;
 }
}
void T1M1Delay(void)
{
	    TMOD = 0x10;
      TH1 = 0xFC;    
			TL1 = 0x67; 	
			TR1 = 1;
			while (TF0==0);
			TR1 = 0;
			TF1 = 0; 
}