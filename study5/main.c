#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
//	����DCOΪ16MHz
	DCOCTL = CAL_DCO_1MHZ;
	BCSCTL1 = CAL_BC1_1MHZ;

//  ����SMCLK��ʱ��ԴΪDC0
	BCSCTL2 &= ~SELS;
//  SMCLK�ķ�Ƶϵ����Ϊ1
    BCSCTL2 &=~(DIVS0 | DIVS1);

//  ��λUSCI_Ax
    UCA0CTL1 |= UCSWRST;
//  ѡ��USCI_AxΪUARTģʽ
    UCA0CTL0 &= ~UCSYNC;
//  ����UARTʱ��ԴΪSMCLK
    UCA0CTL1 |= UCSSEL1;

//  ���ò�����Ϊ9600@1MHZ
    UCA0BR0=0x68;
    UCA0BR1=0x00;
    UCA0MCTL=1<<1;
//  ʹ�ܶ˿ڸ���
    P1SEL |= BIT1+BIT2;
    P1SEL2 |= BIT1+BIT2;
//  �����λλ��ʹ��UART
    UCA0CTL1 &=~UCSWRST;

    while(1){
        UCA0TXBUF=0x55;
        __delay_cycles(5000000);
    }
	return 0;
}
