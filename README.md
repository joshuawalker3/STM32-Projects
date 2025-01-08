# Projects Using STM32F103C8T6 Microcontroller

## Overview
This repository contains a collection of projects for the STM32F103C8T6 microcontroller. The projects are meant to showcase my abilities and understanding of both the hardaware and software associated with embedded programming with STM32 microcontrollers.

A general overview is provided in this REAMDE with each project directory containing a project level README that provides further detail on the project.

RTOS Skills Used
- Task creation/termination
- Semaphores
- One shot timer

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
- [SEGGER Ozone](https://www.segger.com/products/development-tools/ozone-j-link-debugger/)

## Hardware
For development of device drivers, I used a STM32F103C8T6 development board. For the development of Free RTOS applications I used a STM32F767ZI development board.

## General Software Used
Applications were written using the STM32CubeIDE environement and the automatically generated STM32 HAL was utilized.
When other software or API's are used (i.e. CSMIS-RTOS) they will be listed in the projects software section.



# Projects

## Blinky
This project blinks the USR-LED connected to pin PC13 at a frequency of 1 Hz. It is simple project using basic GPIO HAL functions.

## Crystal-LCD
This program utilizes the I2C communication protocol to print data to an LCD. It uses a custom driver for the LCD functions. 

## FreeRTOS-Blinky
This program utilizes CMSIS-RTOS to create two tasks that blink two seperate LEDs. A timer is used to create a new task and delete the previous two. 

## ADC-DMA-LED-Dimmer
This program utilizes DMA to store ADC data collected from a potentiometer to generate a PWM signal to drive a LED. Code flow is controlled by DMA interrupt and a binary semaphore.
