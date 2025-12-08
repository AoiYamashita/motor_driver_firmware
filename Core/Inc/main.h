/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32f3xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define encoderA_Pin GPIO_PIN_3
#define encoderA_GPIO_Port GPIOA
#define encoderA_EXTI_IRQn EXTI3_IRQn
#define encoderB_Pin GPIO_PIN_4
#define encoderB_GPIO_Port GPIOA
#define encoderB_EXTI_IRQn EXTI4_IRQn
#define encoderZ_Pin GPIO_PIN_5
#define encoderZ_GPIO_Port GPIOA
#define encoderZ_EXTI_IRQn EXTI9_5_IRQn
#define phase_Pin GPIO_PIN_0
#define phase_GPIO_Port GPIOB
#define sr_Pin GPIO_PIN_1
#define sr_GPIO_Port GPIOB
#define pwmH_Pin GPIO_PIN_8
#define pwmH_GPIO_Port GPIOA
#define pwmL_Pin GPIO_PIN_9
#define pwmL_GPIO_Port GPIOA
#define Button_Pin GPIO_PIN_4
#define Button_GPIO_Port GPIOB
#define LED_Pin GPIO_PIN_5
#define LED_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
