#include <msp430.h> 


/**
 * main.c
 */
//led2闪烁实验
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1DIR |=BIT6;
//	初始化led2所在IO口p1.6为输出
	P1OUT &=~BIT6;
//	初始化led2所在IO口P1.6为低电平，Led2初始状态为灭
	P1OUT &=~BIT6;
	while(1){
	    P1OUT ^=BIT6;
//	  P1OUT=P1OUT ^ BIT6,"^"表示按位异或
//	    第一次执行语句时:x0xxxxxx ^ 01000000=x1xxxxxx,P1OUT,P1.6输出高电平,led2点亮
//	    第二次执行语句时:x1xxxxxx ^ 01000000=x0xxxxxx,P1OUT,P1.6输出低电平,led2熄灭
//	    如此循环，led2闪烁
	    __delay_cycles(500000);
//	    设计延时为500ms
	}
	return 0;
}
