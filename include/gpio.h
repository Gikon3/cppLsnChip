#ifndef __gpio_h
#define __gpio_h

#include <stdint.h>
#include "cpp_lsn.h"

typedef struct
{
    volatile uint32_t DIR;
    volatile uint32_t ALT;
    volatile uint32_t OUT1;
    volatile uint32_t OUT0;
    volatile uint32_t INP;
    volatile uint32_t EVEN;
    volatile uint32_t EDGE;
    volatile uint32_t EVSTAT;
    volatile uint32_t EVMASK;
} GpioMap;

#define GPIO_M ((GpioMap *)MP_GPIO_BASE)

#define GPIO_EVMASK_DIS 0
#define GPIO_EVMASK_EN  1

void gpio_config(void);

#endif
