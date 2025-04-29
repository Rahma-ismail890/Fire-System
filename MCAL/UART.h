/*
 * UART.h
 *
 * Created: 10/23/2023 8:32:03 AM
 *  Author: user
 */ 


#ifndef UART_H_
#define UART_H_
void UART_Init(void);

void UART_senddata(u8 data);

u8 UART_recivedata_busywait(void);
bool UART_recivedata_periodiccheck(u8*data);
void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);
void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);
void UART_RX_setCallBack(void(*localFptr)(void));
void UART_TX_setCallBack(void(*localFptr)(void));
void UART_SendNoBlock(u8 data);
u8  UART_ReceiveNoBlock(void);
#endif /* UART_H_ */