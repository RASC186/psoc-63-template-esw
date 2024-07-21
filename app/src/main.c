#include "cybsp.h"
#include "cyhal.h"

#include "cy_gpio.h"

#if defined(CY_USING_HAL)
#include "cyhal_hwmgr.h"
#endif /* defined (CY_USING_HAL) */

#if defined(CY_USING_HAL_LITE)
#include "cyhal_hw_types.h"
#endif /* defined (CY_USING_HAL_LITE) */

#define CYBSP_LED3_PORT GPIO_PRT6
#define CYBSP_USER_LED1_PORT CYBSP_LED3_PORT
#define CYBSP_USER_LED_PORT CYBSP_LED3_PORT
#define CYBSP_LED3_PORT_NUM 6U
#define CYBSP_USER_LED1_PORT_NUM CYBSP_LED3_PORT_NUM
#define CYBSP_USER_LED_PORT_NUM CYBSP_LED3_PORT_NUM
#define CYBSP_LED3_PIN 3U
#define CYBSP_USER_LED1_PIN CYBSP_LED3_PIN
#define CYBSP_USER_LED_PIN CYBSP_LED3_PIN
#define CYBSP_LED3_NUM 3U
#define CYBSP_USER_LED1_NUM CYBSP_LED3_NUM
#define CYBSP_USER_LED_NUM CYBSP_LED3_NUM
#define CYBSP_LED3_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define CYBSP_USER_LED1_DRIVEMODE CYBSP_LED3_DRIVEMODE
#define CYBSP_USER_LED_DRIVEMODE CYBSP_LED3_DRIVEMODE
#define CYBSP_LED3_INIT_DRIVESTATE 0
#define CYBSP_USER_LED1_INIT_DRIVESTATE CYBSP_LED3_INIT_DRIVESTATE
#define CYBSP_USER_LED_INIT_DRIVESTATE CYBSP_LED3_INIT_DRIVESTATE
#ifndef ioss_0_port_6_pin_3_HSIOM
#define ioss_0_port_6_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define CYBSP_LED3_HSIOM ioss_0_port_6_pin_3_HSIOM
#define CYBSP_USER_LED1_HSIOM CYBSP_LED3_HSIOM
#define CYBSP_USER_LED_HSIOM CYBSP_LED3_HSIOM
#define CYBSP_LED3_IRQ ioss_interrupts_gpio_6_IRQn
#define CYBSP_USER_LED1_IRQ CYBSP_LED3_IRQ
#define CYBSP_USER_LED_IRQ CYBSP_LED3_IRQ

#if defined(CY_USING_HAL)
#define CYBSP_LED3_HAL_PORT_PIN P6_3
#define CYBSP_USER_LED1_HAL_PORT_PIN CYBSP_LED3_HAL_PORT_PIN
#define CYBSP_USER_LED_HAL_PORT_PIN CYBSP_LED3_HAL_PORT_PIN
#define CYBSP_LED3 P6_3
#define CYBSP_USER_LED1 CYBSP_LED3
#define CYBSP_USER_LED CYBSP_LED3
#define CYBSP_LED3_HAL_IRQ CYHAL_GPIO_IRQ_NONE
#define CYBSP_USER_LED1_HAL_IRQ CYBSP_LED3_HAL_IRQ
#define CYBSP_USER_LED_HAL_IRQ CYBSP_LED3_HAL_IRQ
#define CYBSP_LED3_HAL_DIR CYHAL_GPIO_DIR_OUTPUT
#define CYBSP_USER_LED1_HAL_DIR CYBSP_LED3_HAL_DIR
#define CYBSP_USER_LED_HAL_DIR CYBSP_LED3_HAL_DIR
#define CYBSP_LED3_HAL_DRIVEMODE CYHAL_GPIO_DRIVE_STRONG
#define CYBSP_USER_LED1_HAL_DRIVEMODE CYBSP_LED3_HAL_DRIVEMODE
#define CYBSP_USER_LED_HAL_DRIVEMODE CYBSP_LED3_HAL_DRIVEMODE
#endif /* defined (CY_USING_HAL) */

const cy_stc_gpio_pin_config_t CYBSP_LED3_config = {
    .outVal = 0,
    .driveMode = CY_GPIO_DM_STRONG_IN_OFF,
    .hsiom = CYBSP_LED3_HSIOM,
    .intEdge = CY_GPIO_INTR_DISABLE,
    .intMask = 0UL,
    .vtrip = CY_GPIO_VTRIP_CMOS,
    .slewRate = CY_GPIO_SLEW_FAST,
    .driveSel = CY_GPIO_DRIVE_1_2,
    .vregEn = 0UL,
    .ibufMode = 0UL,
    .vtripSel = 0UL,
    .vrefSel = 0UL,
    .vohSel = 0UL,
};

#define CYBSP_USER_LED1_config CYBSP_LED3_config
#define CYBSP_USER_LED_config CYBSP_LED3_config

#if defined(CY_USING_HAL)
const cyhal_resource_inst_t CYBSP_LED3_obj = {
    .type = CYHAL_RSC_GPIO,
    .block_num = CYBSP_LED3_PORT_NUM,
    .channel_num = CYBSP_LED3_PIN,
};
#define CYBSP_USER_LED1_obj CYBSP_LED3_obj
#define CYBSP_USER_LED_obj CYBSP_LED3_obj
#endif /* defined (CY_USING_HAL) */

int main(void) {
  cy_rslt_t result;

  /* Initialize the device and board peripherals */
  result = cybsp_init();

  /* Board init failed. Stop program execution */
  if (result != CY_RSLT_SUCCESS) {
    CY_ASSERT(0);
  }

  Cy_GPIO_Pin_Init(CYBSP_LED3_PORT, CYBSP_LED3_PIN, &CYBSP_LED3_config);

  /* Enable global interrupts */
  __enable_irq();

  for (;;) {
    Cy_GPIO_Write(CYBSP_LED3_PORT, CYBSP_LED3_PIN, 0);
    Cy_SysLib_Delay(500);
    Cy_GPIO_Write(CYBSP_LED3_PORT, CYBSP_LED3_PIN, 1);
    Cy_SysLib_Delay(500);
  }
}
