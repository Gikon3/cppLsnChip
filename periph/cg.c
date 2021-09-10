#include "main.h"
#include "cg.h"

static uint32_t frq = HSE;

int cg_pll_search(uint32_t hz, Pll* pll) {
    float clk;
    for(uint16_t nf = 0; nf <= 0x1FFF; ++ nf) {
        for(uint8_t nr = 0; nr <= 0x3F; ++ nr) {
            for(uint8_t od = 0; od <= 7; ++ od) {
                clk = HSE * (nf + 1) / (nr + 1) / (od + 1);
                if(clk == hz) {
                    pll->ctrl.nf = nf;
                    pll->ctrl.nr = nr;
                    pll->ctrl.od = od;
                    return 0;
                }
            }
        }
    }
    return -1;
}

void cg_config(uint32_t hz) {
    Pll pll;
    if(cg_pll_search(hz, &pll)) while(1);
    frq = hz;

    pll.div = 0;
    CG_M->CLKDIV = pll.div;
    CG_M->CLKSEL = CLKSEL_CLKDIV;
    CG_M->PLLOFF = 2;
    CG_M->PLLCTRL = *(uint32_t*)&pll.ctrl;
    CG_M->PLLOFF = 0;
    //const unsigned int captureTime = HSE / (pll.ctrl.nr + 1);
    //for (unsigned int i = 0; i < captureTime; ++i) CG_M->CLKSEL;
    CG_M->CLKSEL = CLKSEL_PLL;
}

uint32_t cg_get_frq()
{
    return frq;
}
