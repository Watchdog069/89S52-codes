#include <reg52.h>
sbit led = P2^0;
void TimerDelay(int x,int no);

void main(void){
	while(1){
		led=1;
		TimerDelay(20,0);
		led=0;
		TimerDelay(5,0);
	}
}


void TimerDelay (int i,int no)
{
	int x;
	switch (no)
	{
		case 1:
			for (x=0; x<i;x++){
				TMOD=0x10; //Timer 1, mode 1(16-bit)
				TL1=0xFE;	//load TL1
				TH1 = 0xA5;  //load TH1
				TR1=1;   //turn on T1
				while (TF1==0);  //wait for TF1 to roll over
				TR1=0;   //turn off t1
				TF1 = 0;  //clear TF1
			}
			break;
			
		case 0:	
			for (x=0; x<i;x++){
				TMOD=0x01; //Timer 0, mode 1(16-bit)
				TL0=0xFE;	//load TL0
				TH0=0xA5;  //load TH0
				TR0=1;   //turn on T0
				while (TF0==0);  //wait for TF0 to roll over
				TR0=0;   //turn off t0
				TF0=0;  //clear TF0
			}
			break;
	}
	//A5FE=42494, 65536-42494=23042, now xtal/12=11.0592mhz/12= 0.9216mhz, so T=1.085us,  therefore 23042*1.085 = 25ms
}
