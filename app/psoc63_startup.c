#include <stdint.h>

#define SRAM_START 0x08000000U
#define SRAM_SIZE (288U * 1024U)
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))

#define STACK_START SRAM_END

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);

void Reset_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVCall_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ0_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ1_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ2_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ3_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ4_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ5_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ6_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ7_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ8_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ9_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ10_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ11_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ12_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ13_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ14_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ15_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ16_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ17_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ18_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ19_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ20_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ21_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ22_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ23_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ24_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ25_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ26_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ27_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ28_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ29_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ30_Handler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ31_Handler(void) __attribute__((weak, alias("Default_Handler")));

uint32_t vectors[] __attribute__((section(".isr_vector"))) = {
    STACK_START,
    (uint32_t)Reset_Handler,
    (uint32_t)NMI_Handler,
    (uint32_t)HardFault_Handler,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)SVCall_Handler,
    (uint32_t)0,
    (uint32_t)0,
    (uint32_t)PendSV_Handler,
    (uint32_t)SysTick_Handler,
    (uint32_t)IRQ0_Handler,
    (uint32_t)IRQ1_Handler,
    (uint32_t)IRQ2_Handler,
    (uint32_t)IRQ3_Handler,
    (uint32_t)IRQ4_Handler,
    (uint32_t)IRQ5_Handler,
    (uint32_t)IRQ6_Handler,
    (uint32_t)IRQ7_Handler,
    (uint32_t)IRQ8_Handler,
    (uint32_t)IRQ9_Handler,
    (uint32_t)IRQ10_Handler,
    (uint32_t)IRQ11_Handler,
    (uint32_t)IRQ12_Handler,
    (uint32_t)IRQ13_Handler,
    (uint32_t)IRQ14_Handler,
    (uint32_t)IRQ15_Handler,
    (uint32_t)IRQ16_Handler,
    (uint32_t)IRQ17_Handler,
    (uint32_t)IRQ18_Handler,
    (uint32_t)IRQ19_Handler,
    (uint32_t)IRQ20_Handler,
    (uint32_t)IRQ21_Handler,
    (uint32_t)IRQ22_Handler,
    (uint32_t)IRQ23_Handler,
    (uint32_t)IRQ24_Handler,
    (uint32_t)IRQ25_Handler,
    (uint32_t)IRQ26_Handler,
    (uint32_t)IRQ27_Handler,
    (uint32_t)IRQ28_Handler,
    (uint32_t)IRQ29_Handler,
    (uint32_t)IRQ30_Handler,
    (uint32_t)IRQ31_Handler,
};

void Default_Handler(void) {
  while (1)
    ;
}

void Reset_handler(void) {

  uint8_t *pSrc = (uint8_t *)&_etext; // text
  uint8_t *pDst = (uint8_t *)&_sdata; // sram

  uint32_t size = &_edata - &_sdata;
  for (uint32_t i = 0; i < size; i++) {
    *pDst++ = *pSrc++;
  }

  pDst = (uint8_t *)&_sbss;

  size = &_ebss - &_sbss;
  for (uint32_t i = 0; i < size; i++) {
    *pDst++ = 0;
  }

  main();
}
