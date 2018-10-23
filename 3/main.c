#include <at89x52.h>
#define CAMERA1 P1_0
#define CAMERA2 P1_1
#define CAMERA3 P1_2
#define CAMERA4 P1_3
#define SALA1 P0_0
#define SALA2 P0_1
#define SALA3 P0_2
#define SALA4 P0_3
 
const 1 = 1;
const 0 = 0;
int contador = 0;

void alarme() interrupt 0{
	if(SALA1 == 1 || SALA2 == 1 || SALA3 == 1 || SALA4 == 1 ){
			P3_1 = ~P3_1;
			P3_3 = ~P3_3;
			P3_3 = ~P3_4;
			P3_5 = ~P3_5;
			P3_6 = ~P3_6;
			P3_7 = ~P3_7;
	}
}

void pauseVCR(){
	while(SALA1 == 0 && SALA2 == 0 && SALA3 == 0 && SALA4 == 0){
		CAMERA1 = 0;
		CAMERA2 = 0;
		CAMERA3 = 0;
		CAMERA4 = 0;
		contador = 0;
		if(SALA1 == 1 && SALA2 == 0 && SALA3 == 0 && SALA4 == 0){
			contador = 60;
			break;
		}
		else if(SALA1 == 0 && SALA2 == 1 && SALA3 == 0 && SALA4 == 0){
			contador = 120;
			break;
		}
		else if(SALA1 == 0 && SALA2 == 0 && SALA3 == 1 && SALA4 == 0){
			contador = 180;
			break;
		}
		else if(SALA1 == 0 && SALA2 == 0 && SALA3 == 0 && SALA4 == 1){
			contador = 220;
			break;
		}
	}
}

void caixaCheiaInterrupt() interrupt 1{
	TR0 = 0;
	TH0 = 0x3C;
	TL0 = 0xAF;
	TR0 = 1;
	
	if(contador == 60){ 
		CAMERA1 = 1;
		CAMERA2 = 0;
		CAMERA3 = 0;
		CAMERA4 = 0;
		
	}else if(contador == 120){ 
		CAMERA2 = 1;
		CAMERA1 = 0;
		CAMERA3 = 0;
		CAMERA4 = 0;
	} else if(contador == 180){
		CAMERA3 = 1;
		CAMERA1 = 0;
		CAMERA2 = 0;
		CAMERA4 = 0;
	}else if(contador == 240){
		CAMERA4 = 1;
		CAMERA1 = 0;
		CAMERA2 = 0;
		CAMERA3 = 0;
		contador = 0;
	}
	contador++;
	pauseVCR();
}

int main(){
		EA = 1;
		EX0 = 1;
		ET0 = 1;
		TMOD = 1; 
		TR0 = 1;
		P1 = 0;
		while(1)
		{
		}
}