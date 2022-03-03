#include <msp430.h> 


/**
 * main.c
 */
//点亮一个led
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= BIT0;  //P1DIR,BIT0做一个按位或运算后，赋给P1DIR
//	P1,P1.0~P1.7
//	P2,P2.0~P2.7
//	PxDIR 00000000 0->输入（低电平）,1->输出（高电平）,00000001,10000001
//	位置从0开始，哪一位位置上有0或者1即代表该端口是低电平或高电平，x代表无效（例如：10000000 p1.7）
//	PxOUT P1.7->1,P1.0->0,P1OUT,1xxxxxx0   //PxOUT输出端口，
//	PxIN P1.6 P1IN x1xxxxxx x0xxxxxx    //PxIN输入端口
	P1OUT |=BIT0;
	while(1)
	{

	}
	return 0;
}
