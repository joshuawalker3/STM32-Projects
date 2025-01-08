/*
 * lcd_commands.h
 *
 *  Created on: Dec 22, 2024
 *  Author: joshuawalker
 */

#ifndef INC_LCD_COMMANDS_H_
#define INC_LCD_COMMANDS_H_

#define ROW_1 0
#define ROW_2 1

#define COL_1 0
#define COL_2 1
#define COL_3 2
#define COL_4 3
#define COL_5 4
#define COL_6 5
#define COL_7 6
#define COL_8 7
#define COL_9 8
#define COL_10 9
#define COL_11 10
#define COL_12 11
#define COL_13 12
#define COL_14 13
#define COL_15 14
#define COL_16 15

//commands to clear display and return home
#define CLEAR_DISPLAY 0x01
#define RET_HOME 0x02

//Entry mode set and options
#define ENTRY_MODE_SET 0x04
#define CURS_INCR 0x02
#define CURS_DECR 0x00
#define SCREEN_SHIFT_EN 0x01
#define SCREEN_SHIFT_DIS 0x00

//Display control
#define DISP_CTRL 0x08
#define DISP_ON 0x04
#define DISP_OFF 0x00
#define CURS_ON 0x02
#define CURS_OFF 0x00
#define CURS_BLINK 0x01
#define CURS_SOLID 0x00

//Cursor and Display Shift
#define CURS_DISP_SHIFT 0x10
#define SHIFT_DISP 0x08
#define SHIFT_CURS 0x00
#define SHIFT_RIGHT 0x04
#define SHIFT_LEFT 0x00

//Function Set
#define FUNCTION_SET 0x20
#define BIT_MODE_8 0x10
#define BIT_MODE_4 0x00
#define LINES_2 0x08
#define LINES_1 0x00
#define FONT_5x11 0x04
#define FONT_5x8 0x00

//Setting DDRAM and CGRAM Address
#define CGRAM_SET 0x40
#define DDRAM_SET 0x80

//bytes for LCD pin control and byte transmission
#define BIT_COMP 0xF0
#define LIGHT_HI 0x08
#define LIGHT_LO 0x00
#define EN_HI 0x04
#define EN_LO 0x00
#define RW_HI 0x02
#define RW_LO 0x00
#define RS_HI 0x01
#define RS_LO 0x00
#define PACKET_SIZE 4
#define _GET_LOWER_NIBBLE(x) (x << 4)
#define MAX_TIMEOUT 100

//for sample program
#define BS 0xFF
#define WS 0x20

#endif /* INC_LCD_COMMANDS_H_ */
