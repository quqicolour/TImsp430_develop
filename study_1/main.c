#include <msp430.h> 


/**
 * main.c
 */
//����һ��led
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= BIT0;  //P1DIR,BIT0��һ����λ������󣬸���P1DIR
//	P1,P1.0~P1.7
//	P2,P2.0~P2.7
//	PxDIR 00000000 0->���루�͵�ƽ��,1->������ߵ�ƽ��,00000001,10000001
//	λ�ô�0��ʼ����һλλ������0����1������ö˿��ǵ͵�ƽ��ߵ�ƽ��x������Ч�����磺10000000 p1.7��
//	PxOUT P1.7->1,P1.0->0,P1OUT,1xxxxxx0   //PxOUT����˿ڣ�
//	PxIN P1.6 P1IN x1xxxxxx x0xxxxxx    //PxIN����˿�
	P1OUT |=BIT0;
	while(1)
	{

	}
	return 0;
}
