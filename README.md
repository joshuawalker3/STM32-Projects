# Projects Using STM32F103C8T6 Microcontroller

## Overview
This repository contains a collection of projects for the STM32F103C8T6 microcontroller. The projects are meant to showcase my abilities and understanding of both the hardaware and software associated with embedded programming with STM32 microcontrollers.

RTOS Skills Used
- Task creation/termination
- Semaphores

Signal Types Used
- GPIO
- PWM
- ADC

Communication Protocols Used
- I2C

Interprocess Communication Methods Used
- DMA

Tools used
- [ST-Link/V2](https://www.st.com/en/development-tools/st-link-v2.html#sample-buy)
- [Oscilloscope](http://www.hanmatek.cn/en/index.php?s=/Show/index/cid/14/id/39.html)
- [Logic Analyzer](https://www.saleae.com/products/saleae-logic-8)

Software used
- [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
- [Saleae Logic 2](https://www.saleae.com/pages/downloads)
- [Kicad](https://www.kicad.org/) (for schematics)

## General Software Used
Applications were written using the STM32CubeIDE environement and the automatically generated STM32 HAL was utilized.
When other software or API's are used (i.e. CSMIS-RTOS) they will be listed in the projects software section.

## General Hardware Used
Each project is built for the STM32F103C8T6 microcontroller mounted on a "blue pill". When other hardware and tools
are used (i.e. oscilloscope) they will in the projects hardware section. 

## Default Timer Configurations
Unless otherwise specified, this section contains the default hardware timer configuration used.

- HSE = Crystal/Ceramic Resonator
- Input Frequency = 8 MHz
- PLL Src Mux = HSE
- System Clk Mux = PLLCLK
- HCLK = 72 MHz

# Projects

## Blinky
This project blinks the USR-LED connected to pin PC13 at a frequency of 1 Hz. It is simple project using basic GPIO HAL functions.

## Crystal-LCD
This program utilizes the I2C communication protocol to print data to an LCD. It uses a custom driver for the LCD functions. 

## FreeRTOS-Blinky
This program utilizes CMSIS-RTOS to create three tasks that blink three seperate LEDs. Two of the tasks are deleted in the third task.

## adc-dma-led-dimmer
### Overview
This project takes analog data from a potentiometer then generates a corresponding PWM signal to dim an LED. The analog data is converted to a digital value and these values are stored in a buffer. When the buffer is full, an interrupt is generated which releases a semaphore. The LED control task acquires this semaphore and processes the buffer via DMA. The values in the buffer are used to update the CCR to change the duty cycle of the PWM signal used to drive the LED.

### CMSIS-RTOS Settings
- All default settings

### TIM Settings
- Prescaler = 72 - 1 (subtract 1 since register adds 1)
- ARR = 256 - 1
- Resulting frequency is 3.906 kHz
- All other values default 

### Software
Saleae Logic 2 software used.

### Hardware
Logic analyzer used to verify response. Oscilloscope used for quick debugging of PWM signals.

### Schematic

Schematic: ![Schematic](Images/adc-dma-led-dimmer/Schematic.svg)

### Images
Below are images of the project setup and response verification.

Setup: ![Project Setup](Images/adc-dma-led-dimmer/setup.jpeg)

Response Verification. PWM Signal and Analog signal are channels 0 and 1 respectively: ![Response Verification](Images/adc-dma-led-dimmer/Response-Verification.png)

PWM Signal Verification. PWM Signal and Analog signal are channels 0 and 1 respectively: ![PWM Signal Verification](Images/adc-dma-led-dimmer/Accuracy-Verification.png)