#include<at89x52.h>
#define PRODUTOS P2_0
#define CAIXA P2_1

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

void atendeTimer() interrupt 0
{
	PRODUTOS = 0;
	CAIXA = 1;
	delay_ms(8000);
}

void main()
{
	EA = 1;
	EX0 = 1;
	IT0 = 1;
	P2 = 0;
	while(1)
	{
		CAIXA = 0;
		PRODUTOS = 1;		
	}
}