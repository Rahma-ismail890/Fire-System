
//*****************************************************macros****************************************//
#ifndef UTILT_H_
#define UTILT_H_

#define SET_BIT(reg,bit)   (reg=reg|(0x01<<bit))
#define CLER_BIT(reg,bit)   (reg=reg&(~(0x01<<bit)))
#define READ_BIT(reg,bit)    ((reg>>bit)&0x01)
#define WRITE_BIT(reg,bit,value)   (reg=(reg&~(1<<bit))|(value<<bit))
#define TOGL_BIT(reg,bit)      (reg=reg^(0x01<<bit))



#endif /* UTILT_H_ */