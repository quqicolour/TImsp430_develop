#include <msp430.h> 


/**
 * main.c
 */
//led2��˸ʵ��
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1DIR |=BIT6;
//	��ʼ��led2����IO��p1.6Ϊ���
	P1OUT &=~BIT6;
//	��ʼ��led2����IO��P1.6Ϊ�͵�ƽ��Led2��ʼ״̬Ϊ��
	P1OUT &=~BIT6;
	while(1){
	    P1OUT ^=BIT6;
//	  P1OUT=P1OUT ^ BIT6,"^"��ʾ��λ���
//	    ��һ��ִ�����ʱ:x0xxxxxx ^ 01000000=x1xxxxxx,P1OUT,P1.6����ߵ�ƽ,led2����
//	    �ڶ���ִ�����ʱ:x1xxxxxx ^ 01000000=x0xxxxxx,P1OUT,P1.6����͵�ƽ,led2Ϩ��
//	    ���ѭ����led2��˸
	    __delay_cycles(500000);
//	    �����ʱΪ500ms
	}
	return 0;
}
