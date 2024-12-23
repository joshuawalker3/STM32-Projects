#include "i2c-lcd.h"
#include "lcd-commands.h"
extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;

void lcd_send_cmd_hi2c1(uint16_t addr, char cmd){
  char data_u, data_l;
	uint8_t data_t[4];
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
	data_t[0] = data_u|0x0C;  //en=1, rs=0 -> bxxxx1100
	data_t[1] = data_u|0x08;  //en=0, rs=0 -> bxxxx1000
	data_t[2] = data_l|0x0C;  //en=1, rs=0 -> bxxxx1100
	data_t[3] = data_l|0x08;  //en=0, rs=0 -> bxxxx1000
	HAL_I2C_Master_Transmit(&hi2c1, addr, (uint8_t *) data_t, 4, 100);
}

void lcd_send_cmd_hi2c2(uint16_t addr, char cmd){
  char data_u, data_l;
	uint8_t data_t[4];
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
	data_t[0] = data_u|0x0C;  //en=1, rs=0 -> bxxxx1100
	data_t[1] = data_u|0x08;  //en=0, rs=0 -> bxxxx1000
	data_t[2] = data_l|0x0C;  //en=1, rs=0 -> bxxxx1100
	data_t[3] = data_l|0x08;  //en=0, rs=0 -> bxxxx1000
	HAL_I2C_Master_Transmit(&hi2c2, addr, (uint8_t *) data_t, 4, 100);
}

void lcd_send_data_hi2c1(uint16_t addr, char data) {
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);
	data_t[0] = data_u|0x0D;  //en=1, rs=0 -> bxxxx1101
	data_t[1] = data_u|0x09;  //en=0, rs=0 -> bxxxx1001
	data_t[2] = data_l|0x0D;  //en=1, rs=0 -> bxxxx1101
	data_t[3] = data_l|0x09;  //en=0, rs=0 -> bxxxx1001
	HAL_I2C_Master_Transmit(&hi2c1, addr, (uint8_t *) data_t, 4, 100);
}

void lcd_send_data_hi2c2(uint16_t addr, char data) {
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);
	data_t[0] = data_u|0x0D;  //en=1, rs=0 -> bxxxx1101
	data_t[1] = data_u|0x09;  //en=0, rs=0 -> bxxxx1001
	data_t[2] = data_l|0x0D;  //en=1, rs=0 -> bxxxx1101
	data_t[3] = data_l|0x09;  //en=0, rs=0 -> bxxxx1001
	HAL_I2C_Master_Transmit(&hi2c2, addr, (uint8_t *) data_t, 4, 100);
}

void lcd_clear_hi2c1(uint16_t addr) {
	lcd_send_cmd_hi2c1(addr, 0x80);
	for (int i = 0; i < 70; i++)
	{
		lcd_send_data_hi2c1(addr, ' ');
	}
}

void lcd_clear_hi2c2(uint16_t addr) {
	lcd_send_cmd_hi2c1(addr, 0x80);
	for (int i = 0; i < 70; i++)
	{
		lcd_send_data_hi2c2(addr, ' ');
	}
}

void lcd_put_cur_hi2c1(uint16_t addr, int row, int col) {
	switch (row) {
		case 0:
			col |= 0x80;
		    break;
		case 1:
		    col |= 0xC0;
		    break;
	}

	lcd_send_cmd_hi2c1(addr, col);
}

void lcd_put_cur_hi2c2(uint16_t addr, int row, int col) {
	switch (row) {
		case 0:
			col |= 0x80;
	        break;
	    case 1:
	        col |= 0xC0;
	        break;
	 }

	 lcd_send_cmd_hi2c2(addr, col);
}

void lcd_init_hi2c1(uint16_t addr) {
	HAL_Delay(50);
	lcd_send_cmd_hi2c1(addr, FUNCTION_SET|BIT_MODE_8);
	HAL_Delay(5);
	lcd_send_cmd_hi2c1(addr, FUNCTION_SET|BIT_MODE_8);
	HAL_Delay(1);
	lcd_send_cmd_hi2c1(addr, FUNCTION_SET|BIT_MODE_8);
	HAL_Delay(10);
	lcd_send_cmd_hi2c1(addr, FUNCTION_SET|BIT_MODE_4);
	HAL_Delay(10);

	lcd_send_cmd_hi2c1(addr, FUNCTION_SET|LINES_2|FONT_5x11);
	HAL_Delay(1);
	lcd_send_cmd_hi2c1(addr, DISP_CTRL|DISP_OFF|CURS_OFF|CURS_SOLID);
	HAL_Delay(1);
	lcd_send_cmd_hi2c1(addr, CLEAR_DISPLAY);
	HAL_Delay(2);
	lcd_send_cmd_hi2c1(addr, ENTRY_MODE_SET|CURS_INCR|SCREEN_SHIFT_DIS);
	HAL_Delay(1);
	lcd_send_cmd_hi2c1(addr, DISP_CTRL|DISP_ON|CURS_ON|CURS_BLINK);
}

void lcd_init_hi2c2(uint16_t addr) {
	HAL_Delay(50);
	lcd_send_cmd_hi2c2(addr, FUNCTION_SET|BIT_MODE_8);
	HAL_Delay(5);
	lcd_send_cmd_hi2c2(addr, FUNCTION_SET|BIT_MODE_8);
	HAL_Delay(1);
	lcd_send_cmd_hi2c2(addr, FUNCTION_SET|BIT_MODE_8);
	HAL_Delay(10);
	lcd_send_cmd_hi2c2(addr, FUNCTION_SET|BIT_MODE_4);
	HAL_Delay(10);

	lcd_send_cmd_hi2c2(addr, FUNCTION_SET|LINES_2|FONT_5x11);
	HAL_Delay(1);
	lcd_send_cmd_hi2c2(addr, DISP_CTRL|DISP_OFF|CURS_OFF|CURS_SOLID);
	HAL_Delay(1);
	lcd_send_cmd_hi2c2(addr, CLEAR_DISPLAY);
	HAL_Delay(2);
	lcd_send_cmd_hi2c2(addr, ENTRY_MODE_SET|CURS_INCR|SCREEN_SHIFT_DIS);
	HAL_Delay(1);
	lcd_send_cmd_hi2c2(addr, DISP_CTRL|DISP_ON|CURS_ON|CURS_BLINK);
}

void lcd_send_string_hi2c1(uint16_t addr, char *str) {
	while (*str) {
		lcd_send_data_hi2c1(addr, *str++);
	}
}

void lcd_send_string_hi2c2(uint16_t addr, char *str) {
	while (*str) {
		lcd_send_data_hi2c2(addr, *str++);
	}
}
