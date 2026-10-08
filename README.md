# FTServo-stm32HAL

STM32 HAL library for FEETECH bus servos (SCSCL / SMS_STS / HLS series).

## 中文说明

1. stm32CubeMx版本6.1.2  
2. 使用前先使用stm32CubeMx重生成HAL库  
3. 实例默认使用stm32f103(stm32f1.ioc)/stm32f407(stm32f4.ioc)两个芯片型号，可根据实际重配置stm32CubeMx  
4. 舵机控制默认使用usart2（引脚默认）波特率1M，可根据实际重配置stm32CubeMx  
5. 重配置舵机控制串口需要修改\Core\Src\main.c中的ftUart_Send\ftUart_Read函数  
6. 实例默认使用usart1（引脚默认）进行串口重定向，用于信息打印输出，默认波特率115200，可根据实际重配置stm32CubeMx与\Core\Src\main.c中的fputc函数  
7. Example.doc为实例使用参考文档  
8. ftBus_Delay为总线帧间延时接口，时间要求大于10us（可用FT_BUS_DELAY_US调整），当前实现基于DWT周期计数器，需要Cortex-M3/M4/M7内核  
9. examples目录下同一时刻只编译一个示例文件：每个示例都定义了自己的setup/examples函数（由main函数调用）；除examples\Ping.c外默认都不参与Keil编译，需要哪个就启用哪个

## English

1. Built with STM32CubeMX 6.1.2.
2. Regenerate the HAL library with STM32CubeMX before the first build.
3. Examples target STM32F103 (`stm32f1.ioc`) and STM32F407 (`stm32f4.ioc`); reconfigure them in STM32CubeMX if needed.
4. Servo control uses USART2 on its default pins at 1 Mbps; reconfigure it in STM32CubeMX if needed.
5. When the servo UART is re-bound, update `ftUart_Send()` / `ftUart_Read()` in `\Core\Src\main.c`.
6. USART1 is used for `printf` redirection (115200 bps by default); reconfigure it in STM32CubeMX and update `fputc()` in `\Core\Src\main.c` if needed.
7. See `Example.doc` for example usage.
8. `ftBus_Delay()` in `\Core\Src\main.c` is the inter-frame bus delay (must be longer than 10 us, adjustable via `FT_BUS_DELAY_US`); the provided implementation uses the DWT cycle counter, so it requires a Cortex-M3/M4/M7 core.
9. Only one file under `examples/` may be compiled at a time: every example defines its own `setup()` / `examples()` called from `main()`. All of them except `examples/Ping.c` are excluded from the Keil build by default — enable the one you need.
