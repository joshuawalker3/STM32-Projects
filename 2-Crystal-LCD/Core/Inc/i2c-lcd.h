#include "main.h"

void lcd_init_hi2c1(uint16_t addr);   // initialize lcd

void lcd_init_hi2c2(uint16_t addr);

void lcd_send_cmd_hi2c1(uint16_t addr, char cmd);  // send command to the lcd

void lcd_send_cmd_hi2c2(uint16_t addr, char cmd);

void lcd_send_data_hi2c1(uint16_t addr, char data);  // send data to the lcd

void lcd_send_data_hi2c2(uint16_t addr, char data);

void lcd_send_string_hi2c1(uint16_t addr, char *str);  // send string to the lcd

void lcd_send_string_hi2c2(uint16_t addr, char *str);

void lcd_put_cur_hi2c1(uint16_t addr, int row, int col);  // put cursor at the entered position row (0 or 1), col (0-15);

void lcd_put_cur_hi2c2(uint16_t addr, int row, int col);

void lcd_clear_hi2c1(uint16_t addr);

void lcd_clear_hi2c2(uint16_t addr);

void lcd_sample_hi2c1(uint16_t addr);

void lcd_sample_hi2c2(uint16_t addr);
