/*
 * UART_service.h
 *
 * Created: 10/23/2023 1:02:40 PM
 *  Author: user
 */ 


#ifndef UART_SERVICE_H_
#define UART_SERVICE_H_

#define dataLength    9
#define no_parity     1             //0 parity
#define stopBit       1               //1   or   2
#define  parity_type      0    //0  even     1    	odd

typedef enum
{
   LITTIE,
   BIG	
	}endian_type;
typedef enum
{
	frame_error,
	correct_frame
	}frame_type;
void UART_send_str(str8 str);
void UART_recive_str(u8*str);
void UART_Send_num(u32 num);
u32 UART_Recive_num(void);
endian_type check_endian (void);
u32 endian_convert_u32 (u32 num);
void UART_send_str_checksum(str8 str);
frame_type UART_recive_str_checksum(str8 str);
u16 UART_Frame(u16 data);
#endif /* UART_SERVICE_H_ */