#include <msp430.h> 


/**
 * main.c
 */
//主时钟更改实验
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
//	设置MCLK频率,有1MHZ,8MHZ,16MHZ
	DCOCTL=CALDCO_1MHZ;
	BCSCTL1=CALBC1_1MHZ;
	
	P1DIR |=BIT6;
	//  初始化led2所在IO口p1.6为输出
	    P1OUT &=~BIT6;
	//  初始化led2所在IO口P1.6为低电平，Led2初始状态为灭
	while(1){
	    P1OUT ^=BIT6;
	    __delay_cycles(500000);
	}
	return 0;
}
