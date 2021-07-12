#include "main.h"
#include "rc.h"

#define REC1    (1 << 0)
#define TRAN1   (1 << 1)
#define REC2    (1 << 0)
#define TRAN2   (1 << 1)

#define I2CM    (1 << 0)
#define UART0   (1 << 4)
#define UART1   (1 << 5)
#define SPIQF   (1 << 6)
#define SPIM4   (1 << 7)
#define SPIM1   (1 << 8)
#define EMI     (1 << 9)
#define PWM     (1 << 10)

void rc_ctrl(Periph periph, PerReset reset)
{
    switch (periph) {
        case perRec1:
            if (reset == rstUnreset) RC_M->RECTRAN1 = RC_M->RECTRAN1 | REC1;
            else RC_M->RECTRAN1 = RC_M->RECTRAN1 & ~REC1;
            break;
        case perTran1:
            if (reset == rstUnreset) RC_M->RECTRAN1 = RC_M->RECTRAN1 | TRAN1;
            else RC_M->RECTRAN1 = RC_M->RECTRAN1 & ~TRAN1;
            break;
        case perRec2:
            if (reset == rstUnreset) RC_M->RECTRAN2 = RC_M->RECTRAN2 | REC2;
            else RC_M->RECTRAN2 = RC_M->RECTRAN2 & ~REC2;
            break;
        case perTran2:
            if (reset == rstUnreset) RC_M->RECTRAN2 = RC_M->RECTRAN2 | TRAN2;
            else RC_M->RECTRAN2 = RC_M->RECTRAN2 & ~TRAN2;
            break;
        case perI2cm:
            if (reset == rstUnreset) RC_M->PERIPH = RC_M->PERIPH | I2CM;
            else RC_M->PERIPH = RC_M->PERIPH & ~I2CM;
            break;
        case perUart0:
            if (reset == rstUnreset) RC_M->PERIPH = RC_M->PERIPH | UART0;
            else RC_M->PERIPH = RC_M->PERIPH & ~UART0;
            break;
        case perUart1:
            if (reset == rstUnreset) RC_M->PERIPH = RC_M->PERIPH | UART1;
            else RC_M->PERIPH = RC_M->PERIPH & ~UART1;
            break;
        case perSpiqf:
            if (reset == rstUnreset) RC_M->PERIPH = RC_M->PERIPH | SPIQF;
            else RC_M->PERIPH = RC_M->PERIPH & ~SPIQF;
            break;
        case perSpim4:
            if (reset == rstUnreset) RC_M->PERIPH = RC_M->PERIPH | SPIM4;
            else RC_M->PERIPH = RC_M->PERIPH & ~SPIM4;
            break;
        case perSpim1:
            if (reset == rstUnreset) RC_M->PERIPH = RC_M->PERIPH | SPIM1;
            else RC_M->PERIPH = RC_M->PERIPH & ~SPIM1;
            break;
        case perEmi:
            if (reset == rstUnreset) RC_M->PERIPH = RC_M->PERIPH | EMI;
            else RC_M->PERIPH = RC_M->PERIPH & ~EMI;
            break;
        case perPwm:
            if (reset == rstUnreset) RC_M->PERIPH = RC_M->PERIPH | PWM;
            else RC_M->PERIPH = RC_M->PERIPH & ~PWM;
            break;
        case perGpsp:
            if (reset == rstUnreset) RC_M->GPSP = 1;
            else RC_M->GPSP = 0;
            break;
        case perSpod:
            if (reset == rstUnreset) RC_M->SPOD = 1;
            else RC_M->SPOD = 0;
            break;
    }
}

void wdt_set_per(uint16_t period)
{
    RC_M->WDTPER = period;
}

uint16_t wdt_get_per()
{
    return (uint16_t)RC_M->WDTPER;
}

void wdt_reload()
{
    RC_M->WDTRELOAD = 1;
}
