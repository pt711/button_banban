/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PE2_INPUT_Pin GPIO_PIN_2
#define PE2_INPUT_GPIO_Port GPIOE
#define PE3_INPUT_Pin GPIO_PIN_3
#define PE3_INPUT_GPIO_Port GPIOE
#define LCD_DISP_EN_Pin GPIO_PIN_4
#define LCD_DISP_EN_GPIO_Port GPIOE
#define TP_IRQ_Pin GPIO_PIN_5
#define TP_IRQ_GPIO_Port GPIOE
#define TP_IRQ_EXTI_IRQn EXTI5_IRQn
#define LCD_BL_CTRL_Pin GPIO_PIN_6
#define LCD_BL_CTRL_GPIO_Port GPIOE
#define USER_BUTTON_Pin GPIO_PIN_13
#define USER_BUTTON_GPIO_Port GPIOC
#define PF2_INPUT_Pin GPIO_PIN_2
#define PF2_INPUT_GPIO_Port GPIOF
#define VSYNC_FREQ_Pin GPIO_PIN_0
#define VSYNC_FREQ_GPIO_Port GPIOC
#define PA2_INPUT_Pin GPIO_PIN_2
#define PA2_INPUT_GPIO_Port GPIOA
#define PA3_INPUT_Pin GPIO_PIN_3
#define PA3_INPUT_GPIO_Port GPIOA
#define PB0_INPUT_Pin GPIO_PIN_0
#define PB0_INPUT_GPIO_Port GPIOB
#define PB11_INPUT_Pin GPIO_PIN_11
#define PB11_INPUT_GPIO_Port GPIOB
#define PB15_INPUT_Pin GPIO_PIN_15
#define PB15_INPUT_GPIO_Port GPIOB
#define PA8_INPUT_Pin GPIO_PIN_8
#define PA8_INPUT_GPIO_Port GPIOA
#define RENDER_TIME_Pin GPIO_PIN_10
#define RENDER_TIME_GPIO_Port GPIOC
#define FRAME_RATE_Pin GPIO_PIN_11
#define FRAME_RATE_GPIO_Port GPIOC
#define MCU_ACTIVE_Pin GPIO_PIN_12
#define MCU_ACTIVE_GPIO_Port GPIOC
#define USER_LD2_RED_Pin GPIO_PIN_2
#define USER_LD2_RED_GPIO_Port GPIOD
#define USER_LD3_GREEN_Pin GPIO_PIN_4
#define USER_LD3_GREEN_GPIO_Port GPIOD
#define PD7_INPUT_Pin GPIO_PIN_7
#define PD7_INPUT_GPIO_Port GPIOD
#define PG9_INPUT_Pin GPIO_PIN_9
#define PG9_INPUT_GPIO_Port GPIOG
#define PG10_INPUT_Pin GPIO_PIN_10
#define PG10_INPUT_GPIO_Port GPIOG
#define PG12_INPUT_Pin GPIO_PIN_12
#define PG12_INPUT_GPIO_Port GPIOG
#define PG15_INPUT_Pin GPIO_PIN_15
#define PG15_INPUT_GPIO_Port GPIOG
#define PB5_INPUT_Pin GPIO_PIN_5
#define PB5_INPUT_GPIO_Port GPIOB
#define PB6_INPUT_Pin GPIO_PIN_6
#define PB6_INPUT_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
