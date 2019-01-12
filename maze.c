#define F_CPU 8000000UL // define cpu frequency for delay function
#include <avr/io.h>
#include <util/delay.h>
int main()
{
	DDRB=0XFF; //PORTB as output Port connected to motors
	DDRC=0X00; //PORTC Input port connected to Sensors

	while(1) // infinite loop
	{
		int LS=PINC&0b00000001;	// mask PC0 bit of Port C
		int CS=PINC&0b00000010;	// mask PC1 bit of Port C
		int RS=PINC&0b00000100;	// mask PC2 bit of Port C

		if(LS==0b00000000)		//L(C0)=black
		PORTB=0b00001100;		//LF(B1)=0 LB(B2)=1 RF(B3)=1 RB(B4)=0
		
		if(LS==0b00000001 && RS==0b00000000)		//L=white R=black
		PORTB=0b00001010;		//LF(B1)=1 LB(B2)=0 RF(B3)=0 RB(B4)=1
		
		if(LS==0b00000001 && CS==0b00000000 && RS==0b00000100)		//L=white R=white C=black
		{
			PORTB=0b00010010;	//LF(B1)=1 LB(B2)=0 RF(B3)=1 RB(B4)=0
		}
		if(LS==0b00000001 && CS==0b00000010 && RS==0b00000100)		//L=white C=white R=white
		{
			PORTB=0b00001100;	//LF(B1)=0 LB(B2)=1 RF(B3)=1 RB(B4)=0
		}
	}
}
