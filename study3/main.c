#include <msp430.h> 


/**
 * main.c
 */
//��������led2
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    P1DIR |=BIT6;
//  ��ʼ��led2����IO��p1.6Ϊ���
    P1OUT &=~BIT6;
//  ��ʼ��led2����IO��P1.6Ϊ�͵�ƽ��Led2��ʼ״̬Ϊ��
    P1OUT &=~BIT6;

    P1REN |=BIT3;
    P1OUT |=BIT3;
//  ʹ��P1.3�ڵ���������
    while(1){

    if(P1IN & BIT3){   //���p1.3��Ϊ�ߵ�ƽ������û���£���ִ��Ϩ��led2�����䣬�������ִ��else�����������£�
        P1OUT &=~BIT6;//Ϩ��led2
    }
    else{
        P1OUT |=BIT6;//����led2
    }

    }
	return 0;
}
