#include "i2c-lcd.h"
#include "lcd-commands.h"
extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;

void lcd_send_cmd_hi2c1(uint16_t addr, char cmd){
  char data_u, data_l;
	uint8_t data_t[PACKET_SIZE];
	data_u = (cmd & BIT_COMP);
	data_l = (_GET_LOWER_NIBBLE(cmd) & BIT_COMP);
	data_t[0] = data_u | LIGHT_HI | EN_HI | RW_LO | RS_LO;
	data_t[1] = data_u | LIGHT_HI | EN_LO | RW_LO | RS_LO;
	data_t[2] = data_l | LIGHT_HI | EN_HI | RW_LO | RS_LO;
	data_t[3] = data_l | LIGHT_HI | EN_LO | RW_LO | RS_LO;
	HAL_I2C_Master_Transmit(&hi2c1, addr, (uint8_t *) data_t, PACKET_SIZE, MAX_TIMEOUT);
}

void lcd_send_cmd_hi2c2(uint16_t addr, char cmd){
  char data_u, data_l;
	uint8_t data_t[PACKET_SIZE];
	data_u = (cmd & BIT_COMP);
	data_l = (_GET_LOWER_NIBBLE(cmd) & BIT_COMP);
	data_t[0] = data_u | LIGHT_HI | EN_HI | RW_LO | RS_LO;
	data_t[1] = data_u | LIGHT_HI | EN_LO | RW_LO | RS_LO;
	data_t[2] = data_l | LIGHT_HI | EN_HI | RW_LO | RS_LO;
	data_t[3] = data_l | LIGHT_HI | EN_LO | RW_LO | RS_LO;
	HAL_I2C_Master_Transmit(&hi2c2, addr, (uint8_t *) data_t, PACKET_SIZE, MAX_TIMEOUT);
}

void lcd_send_data_hi2c1(uint16_t addr, char data) {
	char data_u, data_l;
	uint8_t data_t[PACKET_SIZE];
	data_u = (data & BIT_COMP);
	data_l = (_GET_LOWER_NIBBLE(data) & BIT_COMP);
	data_t[0] = data_u | LIGHT_HI | EN_HI | RW_LO | RS_HI;
	data_t[1] = data_u | LIGHT_HI | EN_LO | RW_LO | RS_HI;
	data_t[2] = data_l | LIGHT_HI | EN_HI | RW_LO | RS_HI;
	data_t[3] = data_l | LIGHT_HI | EN_LO | RW_LO | RS_HI;
	HAL_I2C_Master_Transmit(&hi2c1, addr, (uint8_t *) data_t, PACKET_SIZE, MAX_TIMEOUT);
}

void lcd_send_data_hi2c2(uint16_t addr, char data) {
	char data_u, data_l;
	uint8_t data_t[PACKET_SIZE];
	data_u = (data & BIT_COMP);
	data_l = (_GET_LOWER_NIBBLE(data) & BIT_COMP);
	data_t[0] = data_u | LIGHT_HI | EN_HI | RW_LO | RS_HI;
	data_t[1] = data_u | LIGHT_HI | EN_LO | RW_LO | RS_HI;
	data_t[2] = data_l | LIGHT_HI | EN_HI | RW_LO | RS_HI;
	data_t[3] = data_l | LIGHT_HI | EN_LO | RW_LO | RS_HI;
	HAL_I2C_Master_Transmit(&hi2c2, addr, (uint8_t *) data_t, PACKET_SIZE, MAX_TIMEOUT);
}

void lcd_clear_hi2c1(uint16_t addr) {
	lcd_send_cmd_hi2c1(addr, CLEAR_DISPLAY);
	HAL_Delay(1);
	lcd_send_cmd_hi2c1(addr, RET_HOME);
	HAL_Delay(1);
}

void lcd_clear_hi2c2(uint16_t addr) {
	lcd_send_cmd_hi2c2(addr, CLEAR_DISPLAY);
	HAL_Delay(1);
	lcd_send_cmd_hi2c2(addr, RET_HOME);
	HAL_Delay(1);
}

void lcd_put_cur_hi2c1(uint16_t addr, int row, int col) {
	switch (row) {
		case ROW_1:
			col |= 0x80;
		    break;
		case ROW_2:
		    col |= 0xC0;
		    break;
	}

	lcd_send_cmd_hi2c1(addr, col);
}

void lcd_put_cur_hi2c2(uint16_t addr, int row, int col) {
	switch (row) {
		case ROW_1:
			col |= 0x80;
	        break;
	    case ROW_2:
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

void lcd_sample_hi2c1(uint16_t addr) {
	lcd_put_cur_hi2c1(addr, ROW_1, COL_1);
	lcd_send_string_hi2c1(addr, "This is a");
	lcd_put_cur_hi2c1(addr, ROW_2, COL_1);
	lcd_send_string_hi2c1(addr, "Sample of text!");
	HAL_Delay(1000);

	lcd_clear_hi2c1(addr);

	for (int i = 0; i < 10; i++) {
		for (int i = COL_1; i <= COL_16; i++) {
			if (i % 2) {
				lcd_send_data_hi2c1(addr, BS);
			}
			else {
				lcd_send_data_hi2c1(addr, WS);
			}
		}

		lcd_put_cur_hi2c1(addr, ROW_2, COL_1);

		for (int i = COL_1; i <= COL_16; i++) {
			if (i % 2) {
				lcd_send_data_hi2c1(addr, WS);
			}
			else {
				lcd_send_data_hi2c1(addr, BS);
			}
		}

		HAL_Delay(500);

		lcd_clear_hi2c1(addr);

		for (int i = COL_1; i <= COL_16; i++) {
			if (i % 2) {
				lcd_send_data_hi2c1(addr, WS);
			}
			else {
				lcd_send_data_hi2c1(addr, BS);
			}
		}

		lcd_put_cur_hi2c1(addr, ROW_2, COL_1);

		for (int i = COL_1; i <= COL_16; i++) {
			if (i % 2) {
				lcd_send_data_hi2c1(addr, BS);
			}
			else {
				lcd_send_data_hi2c1(addr, WS);
			}
		}

		HAL_Delay(500);

		lcd_clear_hi2c1(addr);
	}
}

void lcd_sample_hi2c2(uint16_t addr) {
	lcd_put_cur_hi2c2(addr, ROW_1, COL_1);
	lcd_send_string_hi2c2(addr, "This is a");
	lcd_put_cur_hi2c2(addr, ROW_2, COL_1);
	lcd_send_string_hi2c2(addr, "Sample of text!");
	HAL_Delay(1000);

	lcd_clear_hi2c2(addr);

	for (int i = COL_1; i <= COL_16; i++) {
		if (i % 2) {
			lcd_send_data_hi2c2(addr, BS);
		}
		else {
			lcd_send_data_hi2c2(addr, WS);
		}
	}

	lcd_put_cur_hi2c1(addr, ROW_2, COL_1);

	for (int i = COL_1; i <= COL_16; i++) {
		if (i % 2) {
			lcd_send_data_hi2c2(addr, WS);
		}
		else {
			lcd_send_data_hi2c2(addr, BS);
		}
	}

	HAL_Delay(500);

	lcd_clear_hi2c2(addr);

	for (int i = COL_1; i <= COL_16; i++) {
		if (i % 2) {
			lcd_send_data_hi2c2(addr, WS);
		}
		else {
			lcd_send_data_hi2c2(addr, BS);
		}
	}

	lcd_put_cur_hi2c1(addr, ROW_2, COL_1);

	for (int i = COL_1; i <= COL_16; i++) {
		if (i % 2) {
			lcd_send_data_hi2c2(addr, BS);
		}
		else {
			lcd_send_data_hi2c2(addr, WS);
		}
	}

	HAL_Delay(500);

	lcd_clear_hi2c2(addr);
}
