#include <reg52.h>
sbit led = P2^0;
void TimerDelay();  //function declaration

void main(void){
	while(1){
		led=1;
		TimerDelay();
		led=0;
		TimerDelay();
	}
}


void TimerDelay ()   //function definition
{
	  int x;
    for (x=0; x<20;x++){
      TMOD=0x10; //Timer 1, mode 1(16-bit)
      TL1=0xFE;	//load TL1
      TH1 = 0xA5;  //load TH1
      TR1=1;   //turn on T1
      while (TF1==0);  //wait for TF1 to roll over
      TR1=0;   //turn off t1
      TF1 = 0;  //clear TF1
    }
	//A5FE=42494, 65536-42494=23042, now xtal/12=11.0592mhz/12= 0.9216mhz, so T=1.085us,  therefore 23042*1.085 = 25ms , 25*20ms=500ms.
}
