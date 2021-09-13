#ifndef __periph_poll_h
#define __periph_poll_h

#include <stdint.h>
#include "cpp_lsn.h"
#include "poll.h"
#include "periph_poll.h"

void periph_poll_init(void);
void periphPoll(void);
void pollSpiqf(CheckBlock *check);
void pollUart(uint8_t uart_sel, CheckBlock *check);
void pollI2cm(CheckBlock *check);
void pollSpod(CheckBlock *check);
void spiqfRead(CheckBlock *check);
void uart0Read(CheckBlock *check);
void uart1Read(CheckBlock *check);
void i2cmRead(CheckBlock *check);
void spodRead(CheckBlock *check);

#endif
