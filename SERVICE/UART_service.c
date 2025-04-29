#include "stand_type.h"
#include "UART.h"
#include "UART_service.h"



void UART_send_str(str8 str)
{
	u16 i=0;
	for(;str[i];i++)
	{
		UART_senddata(str[i]);
	}
	UART_senddata('#');
}

void UART_recive_str(u8*str)
{
	u16 i=0;
	str[i]=UART_recivedata_busywait();
	for(;str[i]!='#';)
	{
		i++;
		str[i]=UART_recivedata_busywait();
		
	}
	str[i]=0;
}

void UART_Send_num(u32 num)
{
	UART_senddata((u8)(num));
	UART_senddata((u8)(num>>8));
	UART_senddata((u8)(num>>16));
	UART_senddata((u8)(num>>24));
/* u8*p=&num;
 UART_senddata(p[0]);
 UART_senddata(p[1]);
 UART_senddata(p[2]);
 UART_senddata(p[3]);*/

}

u32 UART_Recive_num(void)
{
	u8 b1=UART_recivedata_busywait();
	u8 b2=UART_recivedata_busywait();
	u8 b3=UART_recivedata_busywait();
	u8 b4=UART_recivedata_busywait();
	u32 num=((u32)b1)|((u32)b2<<8)|((u32)b3<<16)|((u32)b4<<24);
	return num;
	/*
	u32 num=0;
	u8*p=&num;
	p[0]=UART_recivedata_busywait();
	p[1]=UART_recivedata_busywait();
	p[2]=UART_recivedata_busywait();
	p[3]=UART_recivedata_busywait();
	return num;*/
}

endian_type check_endian (void)
{
	u32 num=1;
	u8*p=&num;
	if(*p==1)
	{
		return LITTIE;
	}
	else
	{
		return BIG;
	}
}
u32 endian_convert_u32 (u32 num)
{
	u8*p=&num;
	u8 temp;
	temp=p[0];
	p[0]=p[3];
	p[3]=temp;
	temp=p[1];
	p[1]=p[2];
	p[2]=temp;
	return num;
	//or
	//return num>>24|num<<24|num<<8&0x00ff0000|num>>8&0x0000ff00;
}

void UART_send_str_checksum(str8 str)
{
	u8 length;
	u16 checksum=0;
	for(length=0;str[length];length++);
	UART_senddata(length);
	for(length=0;str[length];length++)
	{
		UART_senddata(str[length]);
		checksum=checksum+str[length];
    }
     
	UART_senddata((u8)checksum);
	UART_senddata((u8)checksum>>8);
}

frame_type UART_recive_str_checksum(str8 str)
{
	u8 length=UART_recivedata_busywait();
	u8 b1,b2,i;
	u16 checksum,sum=0;
	for(i=0;i<length;i++)
	{
		str[i]=UART_recivedata_busywait();
		sum=sum+str[i];
	}
	str[i]=0;
	b1=UART_recivedata_busywait();
	b2=UART_recivedata_busywait();
	checksum=(u16)b1|(u16)b2<<8;
	if(checksum==sum)
	{
		return correct_frame;
	}
	else
	{
		return frame_error;
	}
}
static u8 parity_value(u16 data)
{
	u8 parity=parity_type;
	u8 bit;
	for(u8 i=0;i<16;i++)
	{
	   	bit=data>>i&1;
		if(bit)
		{
			parity =parity^bit;
		}
	}
	return parity;
}
u16 UART_Frame(u16 data)
{
	u16 frame;
	u8 parity;
	frame =data<<1;
	if(no_parity==0)
	{
		parity=parity_value(data);
		frame=frame|parity<<(dataLength+1);
		if(stopBit==2)
		{
			frame=frame|0x11<<(dataLength+2);
		}
		else if(stopBit==1)
		{
			frame=frame|0x1<<(dataLength+2);
		}
	}
	else
	{
		if(stopBit==2)
		{
			frame=frame|0x11<<(dataLength+1);
		}
		else if(stopBit==1)
		{
			frame=frame|0x1<<(dataLength+1);
		}
	}
	return frame;
}

u8*pointer;
void Tx_func(void)
{
	static u8 i=1;
	if(pointer[i]!=0)
	{
			UART_senddata(pointer[i]);
			i++;
	}
 else
 {
	 i=1;
 }
}

void UART_SendStrSynch(u8*str)
{
	UART_TX_setCallBack(Tx_func);
	UART_TX_InterruptEnable();
	pointer=str;
	UART_senddata(str[0]);
}

