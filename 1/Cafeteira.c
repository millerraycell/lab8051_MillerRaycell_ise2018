#include<at89x52.h>
#define MOEDA P3_0
#define BOTAOCAFE P3_1
#define BOTAOCHA P3_2
#define CAFE P0_0
#define CHA P0_1
#define COPO P0_2

void delay_ms(unsigned int x)
{
	unsigned int i,j;
	for (i=0;i<x;i++)
	{
		for(j=0;j<1275;j++)
		{
		}
	}
}

void cafe()
{
	if(MOEDA == 1 & BOTAOCAFE == 1)
	{
		COPO = 0;
		CAFE = 1;
		delay_ms(15000);
		CAFE = 0;
		delay_ms(1000);
		BOTAOCAFE = 0;
		MOEDA = 0;
		delay_ms(1000);
		COPO = 1;
	}
}

void cha()
{
	if(MOEDA == 1 & BOTAOCHA == 1)
	{
		COPO = 0;
		CHA = 1;
		delay_ms(15000);
		CHA = 0;
		delay_ms(1000);
		BOTAOCHA = 0;
		delay_ms(1000);
		MOEDA = 0;
		delay_ms(1000);
		COPO = 1;
	}
}
void main()
{
	P0 = 0;
	P3 = 0;
	while(1)
	{
		cha();
		cafe();		
	}
}