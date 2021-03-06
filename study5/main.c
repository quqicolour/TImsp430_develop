#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
//	配置DCO为16MHz
	DCOCTL = CAL_DCO_1MHZ;
	BCSCTL1 = CAL_BC1_1MHZ;

//  配置SMCLK的时钟源为DC0
	BCSCTL2 &= ~SELS;
//  SMCLK的分频系数置为1
    BCSCTL2 &=~(DIVS0 | DIVS1);

//  复位USCI_Ax
    UCA0CTL1 |= UCSWRST;
//  选择USCI_Ax为UART模式
    UCA0CTL0 &= ~UCSYNC;
//  配置UART时钟源为SMCLK
    UCA0CTL1 |= UCSSEL1;

//  配置波特率为9600@1MHZ
    UCA0BR0=0x68;
    UCA0BR1=0x00;
    UCA0MCTL=1<<1;
//  使能端口复用
    P1SEL |= BIT1+BIT2;
    P1SEL2 |= BIT1+BIT2;
//  清除复位位，使能UART
    UCA0CTL1 &=~UCSWRST;

    while(1){
        UCA0TXBUF=0x55;
        __delay_cycles(5000000);
    }
	return 0;
}
