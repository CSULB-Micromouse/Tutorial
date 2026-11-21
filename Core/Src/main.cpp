/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "cmsis_os2.h"
#include "stm32f4xx_hal_gpio.h"
#include "FreeRTOS.h"
#include "stm32f4xx_hal_tim.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include <cstdint>
#include "adc.h"
#include "PLL.h"
#include "i2c.h"
#include "i2c1.h"
#include "spi.h"
#include "uart.h"
#include "timer(program breaks without this).h"
#include "motor_driver.h"


/* Private function prototypes -----------------------------------------------*/
void StartDefaultTask(void *argument);


/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_ADC1_Init();
  MX_I2C1_Init();
  MX_SPI3_Init();
  MX_USART6_UART_Init();

  /* USER CODE BEGIN 2 */
  BaseType_t result = xTaskCreate(
      StartDefaultTask,
      "defaultTask",
      512,
      NULL,
      2,
      NULL
  );

  if (result != pdPASS) {
    Error_Handler();
  }

  /* Init scheduler */
  vTaskStartScheduler();

  //Code should never reach here
  /* Infinite loop */
  while (1)
  {
  }
}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* Infinite loop */

  while(1)
  {

  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
