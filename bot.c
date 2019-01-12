#include <avr/io.h>
#include <util/delay.h>
int main()
{
	DDRD=0XFF;
	DDRC=0X00;
	
	while(1)
	{
		//int LS=0X00,RS=0X00;
		int LS=PINC&0b00000001;
		int RS=PINC&0b00000010;

		if(LS==0b00000000&&RS==0b00000000)	//L=black R=black
		PORTD=0b00001010;					//LF(B1)=1 LB(B2)=0 RF(B3)=1 RB(B4)=0
		
		if(LS==0b00000000&&RS==0b00000010)	//L=black R=white
		PORTD=0b00001000;					//LF(B1)=0 LB(B2)=1 RF(B3)=1 RB(B4)=0
		
		if(LS==0b000000001&&RS==0b00000000)	//L=white R=black
		PORTD=0b00000010;					//LF(B1)=1 LB(B2)=0 RF(B3)=0 RB(B4)=1
		
		if(LS==0b00000001&&RS==0b00000010)	//L=white R=white
		PORTD=0b00001010;					//LF(B1)=1 LB(B2)=0 RF(B3)=1 RB(B4)=0

	}
	return 0; 
}
