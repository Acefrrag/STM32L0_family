/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ll_driver.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;
uint16_t	devaddr = 0x28;
/* USER CODE BEGIN PV */
HAL_StatusTypeDef status = HAL_OK;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  const uint16_t devaddr=0x0028;
  uint16_t c = 4;
  uint8_t data = 0;
  uint16_t size = 1;
  char stringa[24];
  stringa[0] = 'C';
  stringa[1] = 'i';
  stringa[2] = 'a';
  stringa[3] = 'o';
  stringa[4] = ' ';
  stringa[5] = 'N';
  stringa[6] = 'i';
  stringa[7] = 'c';
  stringa[8] = 'o';
  stringa[9] = ' ';
  stringa[10] = 'a';
  stringa[11] = ' ';
  stringa[12] = 'c';
  stringa[13] = 'o';
  stringa[14] = 's';
  stringa[15] = 'a';
  stringa[16] = ' ';
  stringa[17] = 'l';
  stringa[18] = 'a';
  stringa[19] = 'v';
  stringa[20] = 'o';
  stringa[21] = 'r';
  stringa[22] = 'i';
  stringa[23] = '?';
  //* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
	  if (c > 4) {
		  break;
	  }
	  //call write function
	  //Set Maximum Brightness Backlight
	  HAL_Delay(1000);
	  //Clear Screen
	  data = 0xFE;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  data = 0x51;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,100);
	  //Turn OFF Screen
	  data = 0xFE;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  data = 0x42;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,100);
	  //Underline Cursor OFF
	  data = 0xFE;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  data = 0x48;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,100);
	  HAL_Delay(1000);
	  data = 0xFE;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  data = 0x53;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  data = 0x01;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  HAL_Delay(1000);
	  //Turn Screen ON
	  data = 0xFE;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  data = 0x41;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,100);
	  //UnderLine Cursor ON
	  data = 0xFE;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  data = 0x47;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,100);
	  HAL_Delay(1000);
	  //Set Maximum Brightness Backlight
	  data = 0xFE;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  data = 0x53;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  data = 0x08;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  for(int i=0;i<16;i++)
	  {
		  data = (uint8_t)(stringa[i]);
		  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  }
	  //New Line
	 /*data = 0xFE;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  data = 0x45;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  data = 0x40;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  */
	  for(int i=16;i<24;i++)
	  {
		  data = (uint8_t)(stringa[i]);
		  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
	  }
	  /*data = 0x41;
	  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr,&data,size,100);
	  */
	  if (status == HAL_OK)
	  {
		  /*data = (uint8_t)(c+0x30);
		  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
		  */
		  HAL_Delay(1000);
		  while(1){
			  HAL_Delay(300);
			//Move Display by one place
			  data = 0xFE;
			  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
			  data = 0x55;
			  status = HAL_I2C_Master_Transmit(&hi2c1,devaddr<<1,&data,size,1000);
		  }
		  break;
	  }
	  else
	  {
		  c += 1;
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
	if (status == HAL_OK)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_8;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0xC000096F;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

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

#ifdef  USE_FULL_ASSERT
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
