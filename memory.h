﻿


#ifndef MEMORY_H_
#define MEMORY_H_

//*****************************************DIO register***********************************************
#define DDRA   (*(volatile unsigned char*)0x3A)
#define PINA   (*(volatile unsigned char*)0x39)
#define PORTA  (*(volatile unsigned char*)0x3B)

#define DDRB   (*(volatile unsigned char*)0x37)
#define PINB   (*(volatile unsigned char*)0x36)
#define PORTB  (*(volatile unsigned char*)0x38)

#define DDRC   (*(volatile unsigned char*)0x34)
#define PINC   (*(volatile unsigned char*)0x33)
#define PORTC  (*(volatile unsigned char*)0x35)

#define DDRD   (*(volatile unsigned char*)0x31)
#define PIND   (*(volatile unsigned char*)0x30)
#define PORTD  (*(volatile unsigned char*)0x32)
//********************************************************reg pointer*********************************//
#define PORTA_POINTER   (volatile unsigned char*)0x3b
#define PORTC_POINTER   (volatile unsigned char*)0x35
#define PORTB_POINTER   (volatile unsigned char*)0x38
#define PORTD_POINTER   (volatile unsigned char*)0x32

//*****************************************************************ADC************************************//

#define ADMUX   (*(volatile unsigned char*)0x27)
#define ADCSRA   (*(volatile unsigned char*)0x26)
#define ADCH   (*(volatile unsigned char*)0x25)
#define ADCL   (*(volatile unsigned char*)0x24)
#define ADC   (*(volatile unsigned short*)0x24)
//***********************************************EIU***********************************************//
#define  MCUCR    (*(volatile unsigned char*)0x55)
#define  MCUCSR    (*(volatile unsigned char*)0x54)
#define  GICR    (*(volatile unsigned char*)0x5B)
#define  GIFR    (*(volatile unsigned char*)0x5A)
//*******************************MCUCR bits********************************************//
#define  ISC00   0
#define  ISC01   1
#define  ISC10   2
#define  ISC11   3
//********************************MCUCSR bit****************************************//
#define  ISC2    6
//********************************GICR bits*******************************************//
 #define INT0    6
 #define INT1    7
 #define INT2    5
  
//****************************************************interrupt vector******************************************//
/* Interrupt vectors */
/* External Interrupt Request 0 */
#define INT0_vect			   __vector_1
/* External Interrupt Request 1 */
#define INT1_vect			   __vector_2
/* External Interrupt Request 2 */
#define INT2_vect			   __vector_3
/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect	   __vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect		   __vector_5
/* Timer/Counter1 Capture Event */
#define TIMER1_ICU_vect		   __vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_OCA_vect		   __vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_OCB_vect		   __vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect		   __vector_9
/* Timer/Counter0 Compare Match */
#define TIMER0_OC_vect		   __vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect		   __vector_11
/* Serial Transfer Complete */
#define SPI_STC_vect		   __vector_12
/* USART, Rx Complete */
#define UART_RX_vect		   __vector_13
/* USART Data Register Empty */
#define UART_UDRE_vect		   __vector_14
/* USART, Tx Complete */
#define UART_TX_vect		   __vector_15
/* ADC Conversion Complete */
#define ADC_vect			   __vector_16
/* EEPROM Ready */
#define EE_RDY_vect			   __vector_17
/* Analog Comparator */
#define ANA_COMP_vect		   __vector_18
/* 2-wire Serial Interface */
#define TWI_vect			   __vector_19
/* Store Program Memory Ready */
#define SPM_RDY_vect		   __vector_20

//********************************************interrupt func**************************************************//
/*interrupt functions*/
//instructions that enable or disable Global Interrupt
# define sei()   __asm__ __volatile__ ("sei" ::)
# define cli()   __asm__ __volatile__ ("cli" ::)  //cli() used to disable global interrupt
# define reti()  __asm__ __volatile__ ("reti" ::)
# define ret()   __asm__ __volatile__ ("ret" ::)

#  define ISR_NOBLOCK    __attribute__((interrupt))    // we use it instead of __attribute__ ((signal)) to open global before context switch,so an another important interrupt can cut this interrupt
#  define ISR_NAKED      __attribute__((naked))

#define ISR(vector,...)         void vector(void)__attribute__((signal))__VA_ARGS__;\
                                void vector(void)

//************************************************NVM**********************************************************//

#define   EEARH               (*(volatile unsigned char*)0x3F)
#define   EEARL               (*(volatile unsigned char*)0x3E)
#define   EEDR                (*(volatile unsigned char*)0x3D)
#define   EECR                (*(volatile unsigned char*)0x3C)
#define   EERE          0
#define   EEWE          1
#define   EEMWE         2
#define   EERIE         3



 /*********************************************timer***************************************************/
 /* Timer 0 */
 #define TCNT0   (*(volatile unsigned char*)0x52)
 #define TCCR0   (*(volatile unsigned char*)0x53)
 /* TCCR0 */
 #define FOC0    7
 #define WGM00   6
 #define COM01   5
 #define COM00   4
 #define WGM01   3
 #define CS02    2
 #define CS01    1
 #define CS00    0

 #define TWCR    (*(volatile unsigned char*)0x56)
 #define SPMCR   (*(volatile unsigned char*)0x57)
 #define TIFR    (*(volatile unsigned char*)0x58)
 #define TIMSK   (*(volatile unsigned char*)0x59)
 /* TIMSK */
 #define OCIE2   7
 #define TOIE2   6
 #define TICIE1  5
 #define OCIE1A  4
 #define OCIE1B  3
 #define TOIE1   2
 #define OCIE0   1
 #define TOIE0   0

 #define OCR0    (*(volatile unsigned char*)0x5C)
 /****************************************************************************************************/

 /*TIMER 1*/


 #define ICR1         (*(volatile unsigned short*)0x46)
 #define ICR1L     (*(volatile unsigned char*)0x46)
 #define ICR1H     (*(volatile unsigned char*)0x47)
 #define OCR1B     (*(volatile unsigned short*)0x48)
 #define OCR1BL    (*(volatile unsigned char*)0x48)
 #define OCR1BH       (*(volatile unsigned char*)0x49)
 #define OCR1A     (*(volatile unsigned short*)0x4A)
 #define OCR1AL    (*(volatile unsigned char*)0x4A)
 #define OCR1AH      (*(volatile unsigned char*)0x4B)
 #define TCNT1       (*(volatile unsigned short*)0x4C)
 #define TCNT1L    (*(volatile unsigned char*)0x4C)
 #define TCNT1H    (*(volatile unsigned char*)0x4D)
 #define TCCR1B       (*(volatile unsigned char*)0x4E)
 #define TCCR1A        (*(volatile unsigned char*)0x4F)

 #define SFIOR       (*(volatile unsigned char*)0x50)

 #define OSCCAL       (*(volatile unsigned char*)0x51)
 /******************************************************************************/
 /* Timer 2 */

 #define OCR2     (*(volatile unsigned char*)0x43)
 #define TCNT2    (*(volatile unsigned char*)0x44)
 #define TCCR2    (*(volatile unsigned char*)0x45)




 /* TCCR2 */
 #define FOC2    7
 #define WGM20   6
 #define COM21   5
 #define COM20   4
 #define WGM21   3
 #define CS22    2
 #define CS21    1
 #define CS20    0

 /* ASSR */
 /* bits 7-4 reserved */
 #define AS2     3
 #define TCN2UB  2
 #define OCR2UB  1
 #define TCR2UB  0

 /* TCCR1A */
 #define COM1A1  7
 #define COM1A0  6
 #define COM1B1  5
 #define COM1B0  4
 #define FOC1A   3
 #define FOC1B   2
 #define WGM11   1
 #define WGM10   0

 /* TCCR1B */
 #define ICNC1   7
 #define ICES1   6
 /* bit 5 reserved */
 #define WGM13   4
 #define WGM12   3
 #define CS12    2
 #define CS11    1
 #define CS10    0

 /* WDTCR */
 #define WDTCR    (*(volatile unsigned char*)0x41)
 /* bits 7-5 reserved */
 #define WDTOE   4
 #define WDE     3
 #define WDP2    2
 #define WDP1    1
 #define WDP0    0
 
 
 
 //************************************************UART**********************************************//
 /* USART Baud Rate Register High */
 #define  UBRRL          (*(volatile unsigned char*)0x29)
 
 /* USART Control and Status Register B */
 #define  UCSRB          (*(volatile unsigned char*)0x2A)
#define    RXCIE        7
#define    TXCIE        6
#define    UDRIE        5
#define    RXEN         4
#define    TXEN         3
#define    UCSZ         2
#define    UCSZ2        2
#define    RXB8         1
#define    TXB8         0
 
 /* USART Control and Status Register A */
 #define UCSRA    (*(volatile unsigned char*)0x2B)

 #define    RXC          7
 #define    TXC          6
 #define    UDRE         5
 #define    FE           4
 #define    DOR          3
 #define    UPE          2
 #define    U2X          1
 #define    MPCM         0
 
 /* USART I/O Data Register */
 #define UDR       (*(volatile unsigned char*)0x2C)
 /* USART Register C */
 #define    URSEL        7
 #define    UMSEL        6
 #define    UPM1         5
 #define    UPM0         4
 #define    USBS         3
 #define    UCSZ1        2
 #define    UCSZ0        1
 #define    UCPOL        0

//************************************************function******************************************//
/*void set_bit(char*reg, char bit)
{
	*reg=*reg|(0x01<<bit);
}

void clear_bit(char*reg, char bit)
{
	*reg=*reg&~(0x01<<bit);
}


char read_bit(char reg, char bit)
{
	char read=(reg>>bit)&0x01;
	return read;
}*/
#endif /* MEMORY_H_ */