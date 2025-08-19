#include "Dot_Matrix.h"
#include "stm32f1xx_hal.h"

void MAX7219_GPIO_Config(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOB_CLK_ENABLE();

    // 配置DIN
    GPIO_InitStruct.Pin = DIN_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(DIN_GPIO_PORT, &GPIO_InitStruct);

    // 配置CS
    GPIO_InitStruct.Pin = CS_GPIO_PIN;
    HAL_GPIO_Init(CS_GPIO_PORT, &GPIO_InitStruct);

    // 配置CLK
    GPIO_InitStruct.Pin = CLK_GPIO_PIN;
    HAL_GPIO_Init(CLK_GPIO_PORT, &GPIO_InitStruct);
}

void Write_Max7219_byte(uint8_t DATA) {
    uint8_t i;
    CS_0;
    for(i = 8; i >= 1; i--) {
        CLK_0;
        if(DATA & 0x80) {
            DIN_1;
        } else {
            DIN_0;
        }
        DATA <<= 1;
        CLK_1;
    }
}

void Write_Max7219(uint8_t address1, uint8_t dat1) {
    CS_0;
    Write_Max7219_byte(address1);
    Write_Max7219_byte(dat1);
    CS_1;
}

void Init_MAX7219(void) {
    Write_Max7219(0x09, 0x00);  // 禁用BCD解码
    Write_Max7219(0x0A, 0x01);  // 亮度
    Write_Max7219(0x0B, 0x07);  // 扫描8列
    Write_Max7219(0x0C, 0x01);  // 正常模式
    Write_Max7219(0x0F, 0x00);  // 关闭测试模式
}

void Show_Num(uint8_t *Num, uint8_t Long, uint16_t Time) {
    uint8_t i, j;
    for(j = 0; j < Long; j++) {
        for(i = 1; i < 9; i++) {
            Write_Max7219(i, *(Num + (i - 1) + 8 * j));
        }
        HAL_Delay(Time);  // 使用HAL库延时
    }
}
