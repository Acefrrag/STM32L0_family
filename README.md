# STM32L0_family
Repository Containing my sample project for STM32 family L0 MCU from ST Microelectronics

# Tests
1. Tested 8MHz external clock. It comes from the ST-Link mcu, which is driven by its external oscillator.

# Observations

1. The setting of the registers to specify the input frequency of the external oscillator seems to be incorrect. More investigation needs to be done,
	but it seems the HAL does not setup the input frequency correctly. This is because the toggling period of the LED based on the system tick is doubled.

2. After configuring PINA8 as RCC_MCO (Master Clock Output) wired to the external input clock of 8MHz, no waveform has been detected on the oscilloscope.
	Also in this case it's either the HAL that setup incorrectly the MCO functionality or I am not setting up the environment correctly.
