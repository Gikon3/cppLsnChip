#ifndef __rc_h
#define __rc_h

#include <stdint.h>
#include "cpp_lsn.h"
#include "periph.h"

#define RC_PERIPH_I2CM  (1 << 0)
#define RC_PERIPH_UART0 (1 << 4)
#define RC_PERIPH_UART1 (1 << 5)
#define RC_PERIPH_SPIQF (1 << 6)
#define RC_PERIPH_SPIM4 (1 << 7)
#define RC_PERIPH_SPIM1 (1 << 8)
#define RC_PERIPH_EMI   (1 << 9)
#define RC_PERIPH_PWM   (1 << 10)

typedef struct __RcMap {
    volatile uint32_t RECTRAN1;
    volatile uint32_t RECTRAN2;
    volatile uint32_t PERIPH;
    volatile uint32_t WDTPER;
    volatile uint32_t WDTRELOAD;
    volatile uint32_t GPSP;
    volatile uint32_t SPOD;
} RcMap;

#define RC_M ((RcMap *)MP_RC_BASE)

typedef enum __PerReset
{
    rstReset,
    rstUnreset
} PerReset;

void rc_ctrl(Periph periph, PerReset reset);
void wdt_set_per(uint16_t period);
uint16_t wdt_get_per(void);
void wdt_reload(void);

#endif
