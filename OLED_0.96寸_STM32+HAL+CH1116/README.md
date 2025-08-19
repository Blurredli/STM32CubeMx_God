# 作者: keysking

---

## 使用方法

| 本库适配CH1116/SH1106等系列芯片.			 ```备注 : 取模有网站,请看末尾```

### 0. 工程配置

示例工程默认使用的是STM32F103C8T6的I2C1. 如有其他I2C或SPI需求, 仅需修改`oled.h`中的Send函数即可完成移植.

### 1. 引入

#### CubeIDE

将本库的`oled.c`, `font.c`文件放入到Src文件夹, 将`oled.h`, `font.h`文件放入Inc文件夹.

### 2. 使用

1. STM32初始化IIC完成后调用`OLED_Init()`初始化OLED. 注意STM32启动比OLED上电快, 可等待20ms再初始化OLED
2. 调用`OLED_NewFrame()`开始绘制新的一帧
3. 调用`OLED_DrawXXX()`系列函数绘制图形到显存 调用`OLED_Printxxx()`系列函数绘制文本到显存
4. 调用`OLED_ShowFrame()`将显存内容显示到OLED

```c
OLED_Init();

while(1){
    OLED_NewFrame();
    OLED_PrintString(i, i, "波特律动hello", &font16x16, OLED_COLOR_NORMAL);
    OLED_ShowFrame();
    HAL_Delay(100);
}
```

---

> 摘录自网站对应驱动说明方法
>
> > [[波特律动_取模助手以及教程地址](https://led.baud-dance.com/)](取模助手and驱动库and说明)
> > 原网址有很多驱动,可以看看
> >
> > <img src="assets/image-20250819183512555.png" alt="image-20250819183512555" style="zoom:50%;" />
