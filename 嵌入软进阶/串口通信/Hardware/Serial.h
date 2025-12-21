#ifndef __SERIAL_H
#define __SERIAL_H

void Serial_Init(void);
uint8_t Serial_GetRxFlag(void);
uint8_t Serial_GetRxData(void);
void Serial_SendByte(uint8_t Byte);

#endif
