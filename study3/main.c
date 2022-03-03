#include <msp430.h> 


/**
 * main.c
 */
//按键控制led2
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    P1DIR |=BIT6;
//  初始化led2所在IO口p1.6为输出
    P1OUT &=~BIT6;
//  初始化led2所在IO口P1.6为低电平，Led2初始状态为灭
    P1OUT &=~BIT6;

    P1REN |=BIT3;
    P1OUT |=BIT3;
//  使能P1.3口的上拉电阻
    while(1){

    if(P1IN & BIT3){   //如果p1.3口为高电平（按键没按下），执行熄灭led2这个语句，否则就是执行else（按键被按下）
        P1OUT &=~BIT6;//熄灭led2
    }
    else{
        P1OUT |=BIT6;//电亮led2
    }

    }
	return 0;
}
