#include "main.h"
#include "gpio.h"

void gpioConf() {
    GPIO_M->DIR = 0;
    GPIO_M->ALT = 0;
    GPIO_M->EVEN = 0;
    GPIO_M->EDGE = 0;
    GPIO_M->EVMASK = GPIO_EVMASK_DIS;
}
