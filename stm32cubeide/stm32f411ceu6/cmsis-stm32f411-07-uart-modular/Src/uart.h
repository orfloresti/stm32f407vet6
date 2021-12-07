#ifndef UART__H__
#define UART__H__

#include <stdint.h>
#include "stm32f4xx.h"

void uar2_tx_init(void);
void uart2_write(int ch);

#endif
