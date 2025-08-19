#ifndef __DOT_MATRIX_H
#define __DOT_MATRIX_H

#include "stm32f1xx_hal.h"

// 定义MAX7219引脚
#define DIN_GPIO_PORT    GPIOB
#define DIN_GPIO_PIN     GPIO_PIN_15

#define CS_GPIO_PORT     GPIOB
#define CS_GPIO_PIN      GPIO_PIN_14

#define CLK_GPIO_PORT    GPIOB
#define CLK_GPIO_PIN     GPIO_PIN_13

// 定义引脚操作宏（HAL库）
#define DIN_1    HAL_GPIO_WritePin(DIN_GPIO_PORT, DIN_GPIO_PIN, GPIO_PIN_SET)
#define DIN_0    HAL_GPIO_WritePin(DIN_GPIO_PORT, DIN_GPIO_PIN, GPIO_PIN_RESET)

#define CS_1     HAL_GPIO_WritePin(CS_GPIO_PORT, CS_GPIO_PIN, GPIO_PIN_SET)
#define CS_0     HAL_GPIO_WritePin(CS_GPIO_PORT, CS_GPIO_PIN, GPIO_PIN_RESET)

#define CLK_1    HAL_GPIO_WritePin(CLK_GPIO_PORT, CLK_GPIO_PIN, GPIO_PIN_SET)
#define CLK_0    HAL_GPIO_WritePin(CLK_GPIO_PORT, CLK_GPIO_PIN, GPIO_PIN_RESET)

void Init_MAX7219(void);
void Write_Max7219(uint8_t address1, uint8_t dat1);
void MAX7219_GPIO_Config(void);
void Show_Num(uint8_t *Num, uint8_t Long, uint16_t Time);

#endif
