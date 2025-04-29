#include "memory.h"
#include "stand_type.h"
#include "utilt.h"
#include "UART.h"

static void (*RXI_Fptr) (void)=NULLPTR;
static void (*TXI_Fptr) (void)=NULLPTR;

void UART_Init(void)
{
	//baud rate =9600
	UBRRL=51;
	// frame
	//8bit 1stop bit  no parity
	
	//enable rx and tx
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);

}

void UART_senddata(u8 data)
{
	while(!READ_BIT(UCSRA,UDRE));
	UDR=data;
}

u8 UART_recivedata_busywait(void)
{
	while(!READ_BIT(UCSRA,RXC));
	return UDR; 
}

bool UART_recivedata_periodiccheck(u8*data)
{
	if(READ_BIT(UCSRA,RXC))
	{
		*data=UDR;
		return true;
	}
	return false;
}

void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
}
void UART_RX_InterruptDisable(void)
{
		CLER_BIT(UCSRB,RXCIE);

}
void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB,TXCIE);
}
void UART_TX_InterruptDisable(void)
{
	CLER_BIT(UCSRB,TXCIE);

}
void UART_RX_setCallBack(void(*localFptr)(void))
{
	RXI_Fptr=localFptr;
}
void UART_TX_setCallBack(void(*localFptr)(void))
{
	TXI_Fptr=localFptr;
	
}
	
ISR(UART_RX_vect)	
{
	if(RXI_Fptr!=NULLPTR)
	{
		RXI_Fptr();
	}
}
ISR(UART_TX_vect)
{
	if(TXI_Fptr!=NULLPTR)
	{
		TXI_Fptr();
	}
}

void UART_SendNoBlock(u8 data)
{
	UDR=data;
}
u8  UART_ReceiveNoBlock(void)
{
	return UDR;
}
