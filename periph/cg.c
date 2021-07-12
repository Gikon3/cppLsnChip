#include "main.h"
#include "cg.h"

int cgPllSearch(float pll_freq, CgInit* cg_param) {
    float clk;
    for(uint16_t nf = 0; nf <= 0x1FFF; ++ nf) {
        for(uint8_t nr = 0; nr <= 0x3F; ++ nr) {
            for(uint8_t od = 0; od <= 7; ++ od) {
                clk = HSE * (nf + 1) / (nr + 1) / (od + 1);
                if(clk == pll_freq) {
                    cg_param->pll_ctrl.nf = nf;
                    cg_param->pll_ctrl.nr = nr;
                    cg_param->pll_ctrl.od = od;
                    return 0;
                }
            }
        }
    }
    return -1;
}

void cgConfig(float pll_freq) {
    CgInit cg_param;
    if(cgPllSearch(pll_freq, &cg_param))
        while(1);
    uint32_t tmp;
    tmp = cg_param.pll_ctrl.nf & 0x1FFF;
    tmp |= (cg_param.pll_ctrl.nr & 0x3F) << 13;
    tmp |= (cg_param.pll_ctrl.od & 7) << 19;
    CG_M->PLLCTRL = tmp;
    CG_M->CLKSEL = CLKSEL_PLL;
}
