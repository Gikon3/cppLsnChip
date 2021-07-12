#ifndef __i2cm_h
#define __i2cm_h

#include <stdint.h>
#include "cpp_lsn.h"

typedef struct __I2cmMap {
    volatile uint32_t PRESC;
    volatile uint32_t ADDRSL;
    volatile uint32_t POINTSL;
    volatile uint32_t CONF;
    volatile uint32_t TXD;
    volatile uint32_t RXD;
    volatile uint32_t RUN;
    volatile uint32_t TXED;
    volatile uint32_t RXRD;
    volatile uint32_t BUSY;
    volatile uint32_t FL;
    volatile uint32_t RDY;
    volatile uint32_t ADDRSCAN;
    volatile uint32_t SCANEN;
    volatile uint32_t SCANFL;
    volatile uint32_t EOSMSK;
} I2cmMap;

#define I2CM_M ((I2cmMap *)MP_I2CM_BASE)

#endif
