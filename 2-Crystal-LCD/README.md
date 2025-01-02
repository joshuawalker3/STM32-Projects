# Crystal-LCD
## Introduction
This project prints two lines of text to a 1602-LCD via I2C communication Protocol.

The process begins by initializing the internal clock and clock for the pins used for the I2C bus. I2C bus hi2c1 is then initialized. Finally, the display is initialized in accordance with the [manual](https://cdn-shop.adafruit.com/datasheets/TC1602A-01T.pdf). UPon completion of initialization, two strings are printed to the LCD, one string per line.

To accommodate the I2C interface for the LCD, each byte of data is sent 4 bits at a time. This requires bit manipulation in the lcd_send_cmd_hi2cx and lcd_send_data_hi2cx functions.

To compile and flash the program to the chip, I used the 'Run' option in STM32CubeIDE. To connect the board to the computer I used an ST-Link/V2.

## Custom Driver
For this project I wrote a custom driver for the LCD (i2c-lcd.h). The functions and a brief description of their use are described below. The hi2c1 and or hi2c2 bus must be initialized before calling these functions.

void lcd_init_hi2c1(uint16_t addr)\
	- Initializes the LCD at address on i2c bus hi2c1

void lcd_init_hi2c2(uint16_t addr)\
	- Initializes the LCD at address on i2c bus hi2c2

void lcd_send_cmd_hi2c1(uint16_t addr, char cmd)\
	- Send command to the LCD at address on i2c bus hi2c1. Commands are defined in lcd-commands.h

void lcd_send_cmd_hi2c2(uint16_t addr, char cmd)\
	- Send command to the LCD at address on i2c bus hi2c2. Commands are defined in lcd-commands.h

void lcd_send_data_hi2c1(uint16_t addr, char data)\
	- Send data to the LCD at address addr on i2c bus hi2c1

void lcd_send_data_hi2c2(uint16_t addr, char data)\
	- Send data to the LCD at address addr on i2c bus hi2c2

void lcd_send_string_hi2c1(uint16_t addr, char \*str)\
	- Send string to the LCD at address addr on i2c bus hi2c1 

void lcd_send_string_hi2c2(uint16_t addr, char \*str)\
	- Send string to the LCD at address addr on i2c bus hi2c2

void lcd_put_cur_hi2c1(uint16_t addr, int row, int col)\
	- Move cursor to specified row, range [0, 1], and column, range [0, 15], for LCD at address on hi2c1 bus

void lcd_put_cur_hi2c2(uint16_t addr, int row, int col)\
	- Move cursor to specified row, range [0, 1], and column, range [0, 15], for LCD at address on hi2c2 bus

void lcd_clear_hi2c1(uint16_t addr)\
	- Clear display for LCD at address on hi2c1 bus

void lcd_clear_hi2c2(uint16_t addr)\
	- Clear display for LCD at address on hi2c1 bus

## Communication
Since the I2C backpack interacts with the LCD in 4-bit interface, commands and data must be sent one nibble at a time. The initaial byte to be sent is first split into two bytes where the most significant nibble is either the upper or lower four bits of the original byte.

To send the bytes, the en pin must be set to high then to low for both of the two bytes created above.

The byte received by the LCD is determined to be either a command (clearing the screen, returning the cursor home, etc.) or data (character to be printed) by whether the rs pin is set to high. If the rs pin is low, the byte is treated as a cammand. If the rs pin is high, the byte is treated as data. 

To complete all this, an array of 4 bytes is created. The first byte in the array contains the upper half of the initial byte to be sent, the en pin bit set to high, and the status of the rs pin depending on if the initial byte to be sent is a command or data. The second byte is the same as the first except the en pin bit is set to low. Bytes three and four follow the same process but for the byte containing the lower half of the initial bit to be sent.

## Other Tools
Saleae Logic 2 logic analyzer and associated software used to verify correct bytes being sent.

## Project Setup
Below is the pin connections I used.

| LCD | STM32F103C8T6 |
| --- | ------------- |
| GND | GND |
| VCC | 5V |
| SDA | PB7 |
| SCL | PB6 |

| Logic Analyzer | STM32F103C8T6 |
| --- | ------------- |
| D0 In | PB7 |
| D0 GND | GND |
| D1 In | PB6 |
| D1 GND | GND |

A 4K7 ohm pull-up resistor is installed between both the SDA and SCL buses and 5V.

## I2C Setup
- Address length = 7-bit
- Default settings for all other options

## Schematic

Schematic: ![Schematic](../Images/2-Crystal-LCD/Schematic.svg)

## Images

Setup: ![Project Setup](../Images/2-Crystal-LCD/setup.jpeg)

Initial Initialization Command: ![Initialization](../Images/2-Crystal-LCD/First-Init-Cmd.png)

Sending 'L' Character: ![Send Data](../Images/2-Crystal-LCD/Send-L-Character.png)