#include <msp430.h> 


/**
 * main.c
 */
//��ʱ�Ӹ���ʵ��
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
//	����MCLKƵ��,��1MHZ,8MHZ,16MHZ
	DCOCTL=CALDCO_1MHZ;
	BCSCTL1=CALBC1_1MHZ;
	
	P1DIR |=BIT6;
	//  ��ʼ��led2����IO��p1.6Ϊ���
	    P1OUT &=~BIT6;
	//  ��ʼ��led2����IO��P1.6Ϊ�͵�ƽ��Led2��ʼ״̬Ϊ��
	while(1){
	    P1OUT ^=BIT6;
	    __delay_cycles(500000);
	}
	return 0;
}
