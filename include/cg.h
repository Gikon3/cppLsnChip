#ifndef __cg_h
#define __cg_h

#include <stdint.h>
#include "cpp_lsn.h"

#define CLKSEL_CLKDIV   0
#define CLKSEL_PLL      1

typedef struct __CgMap {
    volatile uint32_t PLLCTRL;
    volatile uint32_t PLLOFF;
    volatile uint32_t CLKDIV;
    volatile uint32_t CLKSEL;
} CgMap;

typedef struct __CgInit {
    struct {
        uint16_t nf;
        uint8_t nr;
        uint8_t od;
    } pll_ctrl;
} CgInit;

#define CG_M ((CgMap *)MP_CG_BASE)

int cgPllSearch(float pll_freq,  CgInit* cg_param);
void cgConfig(float pll_freq);

#endif
