#ifndef __cg_h
#define __cg_h

#include <stdint.h>
#include "cpp_lsn.h"

#define CLKSEL_CLKDIV   0
#define CLKSEL_PLL      1

typedef struct
{
    volatile uint32_t PLLCTRL;
    volatile uint32_t PLLOFF;
    volatile uint32_t CLKDIV;
    volatile uint32_t CLKSEL;
} CgMap;

typedef struct
{
    struct {
        uint32_t nf : 13;
        uint32_t nr : 6;
        uint32_t od : 3;
        uint32_t    : 10;
    } ctrl;
    uint8_t div;
} Pll;

#define CG_M ((CgMap *)MP_CG_BASE)

int cg_pll_search(uint32_t hz, Pll* pll);
void cg_config(uint32_t hz);
uint32_t cg_get_frq(void);

#endif
