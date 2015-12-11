#ifndef SSD1306_H_
#define SSD1306_

#include "stm32f0xx.h"

// Pin Definitions

#define SSD1306_LCDWIDTH                  128
#define SSD1306_LCDHEIGHT                 64

// Commands
#define SSD1306_SETCONTRAST               0x81
#define SSD1306_DISPLAYALLON_RESUME       0xA4
#define SSD1306_DISPLAYALLON              0xA5
#define SSD1306_NORMALDISPLAY             0xA6
#define SSD1306_INVERTDISPLAY             0xA7
#define SSD1306_DISPLAYOFF                0xAE
#define SSD1306_DISPLAYON                 0xAF
#define SSD1306_SETDISPLAYOFFSET          0xD3
#define SSD1306_SETCOMPINS                0xDA
#define SSD1306_SETVCOMDETECT             0xDB
#define SSD1306_SETDISPLAYCLOCKDIV        0xD5
#define SSD1306_SETPRECHARGE              0xD9
#define SSD1306_SETMULTIPLEX              0xA8
#define SSD1306_SETLOWCOLUMN              0x00
#define SSD1306_SETHIGHCOLUMN             0x10
#define SSD1306_SETSTARTLINE              0x40
#define SSD1306_SETSTARTPAGE              0xB0
#define SSD1306_MEMORYMODE                0x20
#define SSD1306_COMSCANINC                0xC0
#define SSD1306_COMSCANDEC                0xC8
#define SSD1306_SEGREMAP                  0xA0
#define SSD1306_CHARGEPUMP                0x8D
#define SSD1306_EXTERNALVCC               0x1
#define SSD1306_SWITCHCAPVCC              0x2

// Initialisation/Config Prototypes
void ssd1306_init(uint8_t vccstate);
void ssd1306_refresh(void);
void ssd1306_refresh_line(uint8_t page);

void ssd1306_cs(uint8_t stat);

void ssd1306_dc(uint8_t stat);

void ssd1306_rst(uint8_t stat);

void ssd1306_mosi(uint8_t stat);

void ssd1306_sck(uint8_t stat);


void CMD(uint8_t c);
void DATA(uint8_t c);

void ssd1306_send_byte(uint8_t byte);

uint8_t put_char_small(unsigned char c, uint8_t y, uint8_t x);
void put_pixel(uint8_t on, uint8_t x, uint8_t y);
unsigned int put_char_arial16(unsigned char character, unsigned int y, unsigned int x, unsigned int color);

void println_16(char * line, int len, int x, int y);
void println_8(char * line, int len, int x, int y);
void println_8_spacy(char * line, int len, int x, int y);
				
				static const unsigned char font[] = {
				        0x00, 0x00, 0x00, 0x00, 0x00,   
					0x3E, 0x5B, 0x4F, 0x5B, 0x3E, 	
					0x3E, 0x6B, 0x4F, 0x6B, 0x3E, 	
					0x1C, 0x3E, 0x7C, 0x3E, 0x1C, 
					0x18, 0x3C, 0x7E, 0x3C, 0x18, 
					0x1C, 0x57, 0x7D, 0x57, 0x1C, 
					0x1C, 0x5E, 0x7F, 0x5E, 0x1C, 
					0x00, 0x18, 0x3C, 0x18, 0x00, 
					0xFF, 0xE7, 0xC3, 0xE7, 0xFF, 
					0x00, 0x18, 0x24, 0x18, 0x00, 
					0xFF, 0xE7, 0xDB, 0xE7, 0xFF, 
					0x30, 0x48, 0x3A, 0x06, 0x0E, 
					0x26, 0x29, 0x79, 0x29, 0x26, 
					0x40, 0x7F, 0x05, 0x05, 0x07, 
					0x40, 0x7F, 0x05, 0x25, 0x3F, 
					0x5A, 0x3C, 0xE7, 0x3C, 0x5A, 
					0x7F, 0x3E, 0x1C, 0x1C, 0x08, 
					0x08, 0x1C, 0x1C, 0x3E, 0x7F, 
					0x14, 0x22, 0x7F, 0x22, 0x14, 
					0x5F, 0x5F, 0x00, 0x5F, 0x5F, 
					0x06, 0x09, 0x7F, 0x01, 0x7F, 
					0x00, 0x66, 0x89, 0x95, 0x6A, 
					0x60, 0x60, 0x60, 0x60, 0x60, 
					0x94, 0xA2, 0xFF, 0xA2, 0x94, 
					0x08, 0x04, 0x7E, 0x04, 0x08, 
					0x10, 0x20, 0x7E, 0x20, 0x10, 
					0x08, 0x08, 0x2A, 0x1C, 0x08, 
					0x08, 0x1C, 0x2A, 0x08, 0x08, 
					0x1E, 0x10, 0x10, 0x10, 0x10, 
					0x0C, 0x1E, 0x0C, 0x1E, 0x0C, 
					0x30, 0x38, 0x3E, 0x38, 0x30, 
					0x06, 0x0E, 0x3E, 0x0E, 0x06, 
					0x00, 0x00, 0x00, 0x00, 0x00, 
					0x00, 0x00, 0x5F, 0x00, 0x00, 
					0x00, 0x07, 0x00, 0x07, 0x00, 
					0x14, 0x7F, 0x14, 0x7F, 0x14, 
					0x24, 0x2A, 0x7F, 0x2A, 0x12, 
					0x23, 0x13, 0x08, 0x64, 0x62, 
					0x36, 0x49, 0x56, 0x20, 0x50, 
					0x00, 0x08, 0x07, 0x03, 0x00, 
					0x00, 0x1C, 0x22, 0x41, 0x00, 
					0x00, 0x41, 0x22, 0x1C, 0x00, 
					0x2A, 0x1C, 0x7F, 0x1C, 0x2A, 
					0x08, 0x08, 0x3E, 0x08, 0x08, 
					0x00, 0x80, 0x70, 0x30, 0x00, 
					0x08, 0x08, 0x08, 0x08, 0x08, 
					0x00, 0x00, 0x60, 0x60, 0x00, 
					0x20, 0x10, 0x08, 0x04, 0x02, 
					0x3E, 0x51, 0x49, 0x45, 0x3E, 
					0x00, 0x42, 0x7F, 0x40, 0x00, 
					0x72, 0x49, 0x49, 0x49, 0x46, 
					0x21, 0x41, 0x49, 0x4D, 0x33, 
					0x18, 0x14, 0x12, 0x7F, 0x10, 
					0x27, 0x45, 0x45, 0x45, 0x39, 
					0x3C, 0x4A, 0x49, 0x49, 0x31, 
					0x41, 0x21, 0x11, 0x09, 0x07, 
					0x36, 0x49, 0x49, 0x49, 0x36, 
					0x46, 0x49, 0x49, 0x29, 0x1E, 
					0x00, 0x00, 0x14, 0x00, 0x00, 
					0x00, 0x40, 0x34, 0x00, 0x00, 
					0x00, 0x08, 0x14, 0x22, 0x41, 
					0x14, 0x14, 0x14, 0x14, 0x14, 
					0x00, 0x41, 0x22, 0x14, 0x08, 
					0x02, 0x01, 0x59, 0x09, 0x06, 
					0x3E, 0x41, 0x5D, 0x59, 0x4E, 
					0x7C, 0x12, 0x11, 0x12, 0x7C, 
					0x7F, 0x49, 0x49, 0x49, 0x36, 
					0x3E, 0x41, 0x41, 0x41, 0x22, 
					0x7F, 0x41, 0x41, 0x41, 0x3E, 
					0x7F, 0x49, 0x49, 0x49, 0x41, 
					0x7F, 0x09, 0x09, 0x09, 0x01, 
					0x3E, 0x41, 0x41, 0x51, 0x73, 
					0x7F, 0x08, 0x08, 0x08, 0x7F, 
					0x00, 0x41, 0x7F, 0x41, 0x00, 
					0x20, 0x40, 0x41, 0x3F, 0x01, 
					0x7F, 0x08, 0x14, 0x22, 0x41, 
					0x7F, 0x40, 0x40, 0x40, 0x40, 
					0x7F, 0x02, 0x1C, 0x02, 0x7F, 
					0x7F, 0x04, 0x08, 0x10, 0x7F, 
					0x3E, 0x41, 0x41, 0x41, 0x3E, 
					0x7F, 0x09, 0x09, 0x09, 0x06, 
					0x3E, 0x41, 0x51, 0x21, 0x5E, 
					0x7F, 0x09, 0x19, 0x29, 0x46, 
					0x26, 0x49, 0x49, 0x49, 0x32, 
					0x03, 0x01, 0x7F, 0x01, 0x03, 
					0x3F, 0x40, 0x40, 0x40, 0x3F, 
					0x1F, 0x20, 0x40, 0x20, 0x1F, 
					0x3F, 0x40, 0x38, 0x40, 0x3F, 
					0x63, 0x14, 0x08, 0x14, 0x63, 
					0x03, 0x04, 0x78, 0x04, 0x03, 
					0x61, 0x59, 0x49, 0x4D, 0x43, 
					0x00, 0x7F, 0x41, 0x41, 0x41, 
					0x02, 0x04, 0x08, 0x10, 0x20, 
					0x00, 0x41, 0x41, 0x41, 0x7F, 
					0x04, 0x02, 0x01, 0x02, 0x04, 
					0x40, 0x40, 0x40, 0x40, 0x40, 
					0x00, 0x03, 0x07, 0x08, 0x00, 
					0x20, 0x54, 0x54, 0x78, 0x40, 
					0x7F, 0x28, 0x44, 0x44, 0x38, 
					0x38, 0x44, 0x44, 0x44, 0x28, 
					0x38, 0x44, 0x44, 0x28, 0x7F, 
					0x38, 0x54, 0x54, 0x54, 0x18, 
					0x00, 0x08, 0x7E, 0x09, 0x02, 
					0x18, 0xA4, 0xA4, 0x9C, 0x78, 
					0x7F, 0x08, 0x04, 0x04, 0x78, 
					0x00, 0x44, 0x7D, 0x40, 0x00, 
					0x20, 0x40, 0x40, 0x3D, 0x00, 
					0x7F, 0x10, 0x28, 0x44, 0x00, 
					0x00, 0x41, 0x7F, 0x40, 0x00, 
					0x7C, 0x04, 0x78, 0x04, 0x78, 
					0x7C, 0x08, 0x04, 0x04, 0x78, 
					0x38, 0x44, 0x44, 0x44, 0x38, 
					0xFC, 0x18, 0x24, 0x24, 0x18, 
					0x18, 0x24, 0x24, 0x18, 0xFC, 
					0x7C, 0x08, 0x04, 0x04, 0x08, 
					0x48, 0x54, 0x54, 0x54, 0x24, 
					0x04, 0x04, 0x3F, 0x44, 0x24, 
					0x3C, 0x40, 0x40, 0x20, 0x7C, 
					0x1C, 0x20, 0x40, 0x20, 0x1C, 
					0x3C, 0x40, 0x30, 0x40, 0x3C, 
					0x44, 0x28, 0x10, 0x28, 0x44, 
					0x4C, 0x90, 0x90, 0x90, 0x7C, 
					0x44, 0x64, 0x54, 0x4C, 0x44, 
					0x00, 0x08, 0x36, 0x41, 0x00, 
					0x00, 0x00, 0x77, 0x00, 0x00, 
					0x00, 0x41, 0x36, 0x08, 0x00, 
					0x02, 0x01, 0x02, 0x04, 0x02, 
					0x3C, 0x26, 0x23, 0x26, 0x3C, 
					0x1E, 0xA1, 0xA1, 0x61, 0x12, 
					0x3A, 0x40, 0x40, 0x20, 0x7A, 
					0x38, 0x54, 0x54, 0x55, 0x59, 
					0x21, 0x55, 0x55, 0x79, 0x41, 
					0x22, 0x54, 0x54, 0x78, 0x42, // a-umlaut
					0x21, 0x55, 0x54, 0x78, 0x40, 
					0x20, 0x54, 0x55, 0x79, 0x40, 
					0x0C, 0x1E, 0x52, 0x72, 0x12, 
					0x39, 0x55, 0x55, 0x55, 0x59, 
					0x39, 0x54, 0x54, 0x54, 0x59, 
					0x39, 0x55, 0x54, 0x54, 0x58, 
					0x00, 0x00, 0x45, 0x7C, 0x41, 
					0x00, 0x02, 0x45, 0x7D, 0x42, 
					0x00, 0x01, 0x45, 0x7C, 0x40, 
					0x7D, 0x12, 0x11, 0x12, 0x7D, // A-umlaut
					0xF0, 0x28, 0x25, 0x28, 0xF0, 
					0x7C, 0x54, 0x55, 0x45, 0x00, 
					0x20, 0x54, 0x54, 0x7C, 0x54, 
					0x7C, 0x0A, 0x09, 0x7F, 0x49, 
					0x32, 0x49, 0x49, 0x49, 0x32, 
					0x3A, 0x44, 0x44, 0x44, 0x3A, // o-umlaut
					0x32, 0x4A, 0x48, 0x48, 0x30, 
					0x3A, 0x41, 0x41, 0x21, 0x7A, 
					0x3A, 0x42, 0x40, 0x20, 0x78, 
					0x00, 0x9D, 0xA0, 0xA0, 0x7D, 
					0x3D, 0x42, 0x42, 0x42, 0x3D, // O-umlaut
					0x3D, 0x40, 0x40, 0x40, 0x3D, 
					0x3C, 0x24, 0xFF, 0x24, 0x24, 
					0x48, 0x7E, 0x49, 0x43, 0x66, 
					0x2B, 0x2F, 0xFC, 0x2F, 0x2B, 
					0xFF, 0x09, 0x29, 0xF6, 0x20, 
					0xC0, 0x88, 0x7E, 0x09, 0x03, 
					0x20, 0x54, 0x54, 0x79, 0x41, 
					0x00, 0x00, 0x44, 0x7D, 0x41, 
					0x30, 0x48, 0x48, 0x4A, 0x32, 
					0x38, 0x40, 0x40, 0x22, 0x7A, 
					0x00, 0x7A, 0x0A, 0x0A, 0x72, 
					0x7D, 0x0D, 0x19, 0x31, 0x7D, 
					0x26, 0x29, 0x29, 0x2F, 0x28, 
					0x26, 0x29, 0x29, 0x29, 0x26, 
					0x30, 0x48, 0x4D, 0x40, 0x20, 
					0x38, 0x08, 0x08, 0x08, 0x08, 
					0x08, 0x08, 0x08, 0x08, 0x38, 
					0x2F, 0x10, 0xC8, 0xAC, 0xBA, 
					0x2F, 0x10, 0x28, 0x34, 0xFA, 
					0x00, 0x00, 0x7B, 0x00, 0x00, 
					0x08, 0x14, 0x2A, 0x14, 0x22, 
					0x22, 0x14, 0x2A, 0x14, 0x08, 
					0xAA, 0x00, 0x55, 0x00, 0xAA, 
					0xAA, 0x55, 0xAA, 0x55, 0xAA, 
					0x00, 0x00, 0x00, 0xFF, 0x00, 
					0x10, 0x10, 0x10, 0xFF, 0x00, 
					0x14, 0x14, 0x14, 0xFF, 0x00, 
					0x10, 0x10, 0xFF, 0x00, 0xFF, 
					0x10, 0x10, 0xF0, 0x10, 0xF0, 
					0x14, 0x14, 0x14, 0xFC, 0x00, 
					0x14, 0x14, 0xF7, 0x00, 0xFF, 
					0x00, 0x00, 0xFF, 0x00, 0xFF, 
					0x14, 0x14, 0xF4, 0x04, 0xFC, 
					0x14, 0x14, 0x17, 0x10, 0x1F, 
					0x10, 0x10, 0x1F, 0x10, 0x1F, 
					0x14, 0x14, 0x14, 0x1F, 0x00, 
					0x10, 0x10, 0x10, 0xF0, 0x00, 
					0x00, 0x00, 0x00, 0x1F, 0x10, 
					0x10, 0x10, 0x10, 0x1F, 0x10, 
					0x10, 0x10, 0x10, 0xF0, 0x10, 
					0x00, 0x00, 0x00, 0xFF, 0x10, 
					0x10, 0x10, 0x10, 0x10, 0x10, 
					0x10, 0x10, 0x10, 0xFF, 0x10, 
					0x00, 0x00, 0x00, 0xFF, 0x14, 
					0x00, 0x00, 0xFF, 0x00, 0xFF, 
					0x00, 0x00, 0x1F, 0x10, 0x17, 
					0x00, 0x00, 0xFC, 0x04, 0xF4, 
					0x14, 0x14, 0x17, 0x10, 0x17, 
					0x14, 0x14, 0xF4, 0x04, 0xF4, 
					0x00, 0x00, 0xFF, 0x00, 0xF7, 
					0x14, 0x14, 0x14, 0x14, 0x14, 
					0x14, 0x14, 0xF7, 0x00, 0xF7, 
					0x14, 0x14, 0x14, 0x17, 0x14, 
					0x10, 0x10, 0x1F, 0x10, 0x1F, 
					0x14, 0x14, 0x14, 0xF4, 0x14, 
					0x10, 0x10, 0xF0, 0x10, 0xF0, 
					0x00, 0x00, 0x1F, 0x10, 0x1F, 
					0x00, 0x00, 0x00, 0x1F, 0x14, 
					0x00, 0x00, 0x00, 0xFC, 0x14, 
					0x00, 0x00, 0xF0, 0x10, 0xF0, 
					0x10, 0x10, 0xFF, 0x10, 0xFF, 
					0x14, 0x14, 0x14, 0xFF, 0x14, 
					0x10, 0x10, 0x10, 0x1F, 0x00, 
					0x00, 0x00, 0x00, 0xF0, 0x10, 
					0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
					0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 
					0xFF, 0xFF, 0xFF, 0x00, 0x00, 
					0x00, 0x00, 0x00, 0xFF, 0xFF, 
					0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 
					0x38, 0x44, 0x44, 0x38, 0x44, 
					0xFC, 0x4A, 0x4A, 0x4A, 0x34, // sharp-s or beta
					0x7E, 0x02, 0x02, 0x06, 0x06, 
					0x02, 0x7E, 0x02, 0x7E, 0x02, 
					0x63, 0x55, 0x49, 0x41, 0x63, 
					0x38, 0x44, 0x44, 0x3C, 0x04, 
					0x40, 0x7E, 0x20, 0x1E, 0x20, 
					0x06, 0x02, 0x7E, 0x02, 0x02, 
					0x99, 0xA5, 0xE7, 0xA5, 0x99, 
					0x1C, 0x2A, 0x49, 0x2A, 0x1C, 
					0x4C, 0x72, 0x01, 0x72, 0x4C, 
					0x30, 0x4A, 0x4D, 0x4D, 0x30, 
					0x30, 0x48, 0x78, 0x48, 0x30, 
					0xBC, 0x62, 0x5A, 0x46, 0x3D, 
					0x3E, 0x49, 0x49, 0x49, 0x00, 
					0x7E, 0x01, 0x01, 0x01, 0x7E, 
					0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 
					0x44, 0x44, 0x5F, 0x44, 0x44, 
					0x40, 0x51, 0x4A, 0x44, 0x40, 
					0x40, 0x44, 0x4A, 0x51, 0x40, 
					0x00, 0x00, 0xFF, 0x01, 0x03, 
					0xE0, 0x80, 0xFF, 0x00, 0x00, 
					0x08, 0x08, 0x6B, 0x6B, 0x08,
					0x36, 0x12, 0x36, 0x24, 0x36,
					0x06, 0x0F, 0x09, 0x0F, 0x06,
					0x00, 0x00, 0x18, 0x18, 0x00,
					0x00, 0x00, 0x10, 0x10, 0x00,
					0x30, 0x40, 0xFF, 0x01, 0x01,
					0x00, 0x1F, 0x01, 0x01, 0x1E,
					0x00, 0x19, 0x1D, 0x17, 0x12,
					0x00, 0x3C, 0x3C, 0x3C, 0x3C,
					0x00, 0x00, 0x00, 0x00, 0x00
				};



				const unsigned char arial16Width[] = {

				    // char widths
				    0x00, 0x02, 0x06, 0x07, 0x07, 0x0F, 0x0B, 0x02, 0x04, 0x04,
				    0x05, 0x08, 0x02, 0x04, 0x02, 0x04, 0x08, 0x05, 0x08, 0x08,
				    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x02, 0x02, 0x08, 0x08,
				    0x08, 0x08, 0x0F, 0x0B, 0x0A, 0x0A, 0x0A, 0x09, 0x08, 0x0A,
				    0x0A, 0x02, 0x08, 0x0A, 0x08, 0x0B, 0x0A, 0x0A, 0x09, 0x0A,
				    0x0B, 0x09, 0x0A, 0x0A, 0x0B, 0x0F, 0x09, 0x0A, 0x09, 0x04,
				    0x04, 0x04, 0x08, 0x09, 0x03, 0x08, 0x08, 0x07, 0x08, 0x07,
				    0x05, 0x08, 0x08, 0x02, 0x03, 0x07, 0x02, 0x0C, 0x08, 0x08,
				    0x08, 0x08, 0x05, 0x07, 0x05, 0x08, 0x07, 0x0D, 0x07, 0x09,
				    0x07, 0x06, 0x02, 0x06, 0x08, 0x08

				};

				const unsigned short arial16Offset[] = {

				  0x0000, 0x0002, 0x0008, 0x000f, 0x0016, 0x0025, 0x0030, 0x0032, 0x0036, 0x003a,
				  0x003f, 0x0047, 0x0049, 0x004d, 0x004f, 0x0053, 0x005b, 0x0060, 0x0068, 0x0070,
				  0x0078, 0x0080, 0x0088, 0x0090, 0x0098, 0x00a0, 0x00a2, 0x00a4, 0x00ac, 0x00b4,
				  0x00bc, 0x00c4, 0x00d3, 0x00de, 0x00e8, 0x00f2, 0x00fc, 0x0105, 0x010d, 0x0117,
				  0x0121, 0x0123, 0x012b, 0x0135, 0x013d, 0x0148, 0x0152, 0x015c, 0x0165, 0x016f,
				  0x017a, 0x0183, 0x018d, 0x0197, 0x01a2, 0x01b1, 0x01ba, 0x01c4, 0x01cd, 0x01d1,
				  0x01d5, 0x01d9, 0x01e1, 0x01ea, 0x01ed, 0x01f5, 0x01fd, 0x0204, 0x020c, 0x0213,
				  0x0218, 0x0220, 0x0228, 0x022a, 0x022d, 0x0234, 0x0236, 0x0242, 0x024a, 0x0252,
				  0x025a, 0x0262, 0x0267, 0x026e, 0x0273, 0x027b, 0x0282, 0x028f, 0x0296, 0x029f,
				  0x02a6, 0x02ac, 0x02ae, 0x02b4, 0x02bc, 0x02c4
				};

				const unsigned char arial16[] = {
				    // font data
				    0xFE, 0xFE, 0x1B, 0x1B,// 33
				    0x1E, 0x1E, 0x00, 0x00, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 34
				    0x30, 0xF0, 0xFE, 0x3E, 0xF0, 0xFE, 0x3E, 0x1F, 0x1F, 0x03, 0x1F, 0x1F, 0x03, 0x03, // 35
				    0x38, 0x7C, 0xE6, 0xFF, 0xC6, 0x8C, 0x08, 0x06, 0x0E, 0x18, 0x3F, 0x19, 0x0F, 0x07, // 36
				    0x3C, 0x7E, 0x42, 0x42, 0x7E, 0x3C, 0x80, 0xE0, 0x70, 0x1C, 0x8E, 0x82, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x10, 0x18, 0x0E, 0x07, 0x01, 0x00, 0x0F, 0x1F, 0x10, 0x10, 0x1F, 0x0F, // 37
				    0x00, 0x9C, 0xFE, 0xE6, 0xE6, 0xE6, 0x3E, 0x1C, 0x80, 0x00, 0x00, 0x07, 0x0F, 0x18, 0x18, 0x19, 0x1B, 0x0F, 0x0E, 0x0F, 0x1D, 0x08,// 38
				    0x1E, 0x1E, 0x00, 0x00, // 39
				    0xE0, 0xFC, 0x1E, 0x02, 0x0F, 0x7F, 0xF0, 0x80, // 40
				    0x02, 0x1E, 0xFC, 0xE0, 0x80, 0xF0, 0x7F, 0x0F,// 41
				    0x14, 0x14, 0x0E, 0x14, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, // 42
				    0xC0, 0xC0, 0xC0, 0xF8, 0xF8, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, // 43
				    0x00, 0x00, 0x98, 0x78, // 44
				    0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03,// 45
				    0x00, 0x00, 0x18, 0x18, // 46
				    0x00, 0xF0, 0xFE, 0x0E, 0x1C, 0x1F, 0x03, 0x00,// 47
				    0xF0, 0xFC, 0x0E, 0x06, 0x06, 0x0E, 0xFC, 0xF0, 0x03, 0x0F, 0x1C, 0x18, 0x18, 0x1C, 0x0F, 0x03, // 48
				    0x30, 0x18, 0x0C, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x1F, 0x1F,  // 49
				    0x18, 0x1C, 0x0E, 0x06, 0x86, 0xC6, 0xFC, 0x38, 0x18, 0x1C, 0x1E, 0x1B, 0x1B, 0x19, 0x18, 0x18, // 50
				    0x08, 0x0C, 0x06, 0x66, 0x66, 0xE6, 0xFE, 0x9C, 0x06, 0x0E, 0x1C, 0x18, 0x18, 0x1C, 0x0F, 0x07,  // 51
				    0x00, 0x80, 0xE0, 0x70, 0x1C, 0xFE, 0xFE, 0x00, 0x07, 0x07, 0x06, 0x06, 0x06, 0x1F, 0x1F, 0x06,  // 52
				    0xF0, 0xFE, 0x7E, 0x66, 0x66, 0xE6, 0xC6, 0x80, 0x06, 0x0E, 0x1C, 0x18, 0x18, 0x1C, 0x0F, 0x07,  // 53
				    0xF0, 0xFC, 0xCE, 0x66, 0x66, 0xE6, 0xCE, 0x8C, 0x03, 0x0F, 0x1C, 0x18, 0x18, 0x18, 0x0F, 0x07,  // 54
				    0x06, 0x06, 0x06, 0xC6, 0xF6, 0x3E, 0x0E, 0x06, 0x00, 0x00, 0x1C, 0x1F, 0x03, 0x00, 0x00, 0x00,  // 55
				    0x38, 0xFC, 0xC6, 0xC6, 0xC6, 0xC6, 0xFC, 0x38, 0x07, 0x0F, 0x18, 0x18, 0x18, 0x18, 0x0F, 0x07,  // 56
				    0x78, 0xFC, 0xCE, 0x86, 0x86, 0xCE, 0xFC, 0xF0, 0x0C, 0x1C, 0x19, 0x19, 0x19, 0x1C, 0x0F, 0x03,  // 57
				    0x30, 0x30, 0x18, 0x18,  // 58
				    0x30, 0x30, 0x98, 0x78,  // 59
				    0x80, 0xC0, 0xC0, 0x60, 0x60, 0x30, 0x30, 0x18, 0x00, 0x01, 0x01, 0x03, 0x03, 0x06, 0x06, 0x0C,  // 60
				    0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,  // 61
				    0x18, 0x30, 0x30, 0x60, 0x60, 0xC0, 0xC0, 0x80, 0x0C, 0x06, 0x06, 0x03, 0x03, 0x01, 0x01, 0x00,  // 62
				    0x18, 0x1C, 0x0E, 0x86, 0xC6, 0xE6, 0x7C, 0x38, 0x00, 0x00, 0x00, 0x1B, 0x1B, 0x00, 0x00, 0x00,  // 63
				    0xC0, 0xF0, 0x78, 0x9C, 0xEC, 0x66, 0x36, 0x36, 0x36, 0xE6, 0xF6, 0x7C, 0x1C, 0xF8, 0xE0, 0x0F, 0x3F, 0x70, 0xEF, 0xDF, 0x98, 0x98, 0x98, 0x8C, 0x9F, 0x9F, 0xD8, 0xCC, 0x67, 0x23,  // 64
				    0x00, 0x00, 0xC0, 0xF8, 0x3E, 0x06, 0x3E, 0xF8, 0xC0, 0x00, 0x00, 0x10, 0x1E, 0x0F, 0x03, 0x03, 0x03, 0x03, 0x03, 0x0F, 0x1E, 0x10,  // 65
				    0xFE, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xFE, 0xBC, 0x00, 0x1F, 0x1F, 0x18, 0x18, 0x18, 0x18, 0x18, 0x19, 0x0F, 0x07,  // 66
				    0xF0, 0xFC, 0x0C, 0x06, 0x06, 0x06, 0x06, 0x0E, 0x1C, 0x08, 0x03, 0x0F, 0x0C, 0x18, 0x18, 0x18, 0x18, 0x1C, 0x0E, 0x04,  // 67
				    0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0C, 0xFC, 0xF0, 0x1F, 0x1F, 0x18, 0x18, 0x18, 0x18, 0x18, 0x0C, 0x0F, 0x03,  // 68
				    0xFE, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x1F, 0x1F, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, // 69
				    0xFE, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x06, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 70
				    0xF0, 0xFC, 0x0C, 0x06, 0x06, 0x86, 0x86, 0x8E, 0x9C, 0x88, 0x03, 0x0F, 0x0C, 0x18, 0x18, 0x19, 0x19, 0x0D, 0x0F, 0x07,  // 71
				    0xFE, 0xFE, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xFE, 0xFE, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F,  // 72
				    0xFE, 0xFE, 0x1F, 0x1F, // 73
				    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x06, 0x0E, 0x1C, 0x18, 0x18, 0x1C, 0x0F, 0x07,  // 74
				    0xFE, 0xFE, 0x80, 0xC0, 0x60, 0xF0, 0xD8, 0x0C, 0x06, 0x02, 0x1F, 0x1F, 0x01, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x1C, 0x18,  // 75
				    0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,  // 76
				    0xFE, 0xFE, 0x1E, 0xF8, 0xC0, 0x00, 0xC0, 0xF8, 0x1E, 0xFE, 0xFE, 0x1F, 0x1F, 0x00, 0x01, 0x0F, 0x1E, 0x0F, 0x01, 0x00, 0x1F, 0x1F,  // 77
				    0xFE, 0xFE, 0x1C, 0x38, 0xE0, 0xC0, 0x00, 0x00, 0xFE, 0xFE, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0E, 0x1F, 0x1F,  // 78
				    0xF0, 0xFC, 0x0C, 0x06, 0x06, 0x06, 0x06, 0x0C, 0xFC, 0xF0, 0x03, 0x0F, 0x0C, 0x18, 0x18, 0x18, 0x18, 0x0C, 0x0F, 0x03,  // 79
				    0xFE, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xEE, 0x7C, 0x38, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 80
				    0xF0, 0xFC, 0x0C, 0x06, 0x06, 0x06, 0x06, 0x0C, 0xFC, 0xF0, 0x03, 0x0F, 0x0C, 0x18, 0x1A, 0x1E, 0x0C, 0x1C, 0x3F, 0x23,  // 81
				    0xFE, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x6E, 0x7C, 0x38, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0F, 0x1E, 0x18, 0x10,  // 82
				    0x38, 0x7C, 0x6E, 0xE6, 0xC6, 0xC6, 0xCE, 0x9C, 0x18, 0x06, 0x0E, 0x1C, 0x18, 0x18, 0x18, 0x1D, 0x0F, 0x07,  // 83
				    0x06, 0x06, 0x06, 0x06, 0xFE, 0xFE, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00,  // 84
				    0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x07, 0x0F, 0x1C, 0x18, 0x18, 0x18, 0x18, 0x1C, 0x0F, 0x07,  // 85
				    0x06, 0x1E, 0xF8, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0x1E, 0x06, 0x00, 0x00, 0x00, 0x03, 0x1F, 0x1C, 0x1F, 0x03, 0x00, 0x00, 0x00,  // 86
				    0x06, 0x3E, 0xFC, 0xC0, 0x00, 0xF0, 0xFE, 0x0E, 0xFE, 0xF0, 0x00, 0xC0, 0xF8, 0x3E, 0x06, 0x00, 0x00, 0x01, 0x1F, 0x1E, 0x1F, 0x01, 0x00, 0x01, 0x1F, 0x1E, 0x1F, 0x03, 0x00, 0x00,  // 87
				    0x06, 0x0E, 0x3C, 0xF0, 0xE0, 0xF0, 0x3C, 0x0E, 0x06, 0x18, 0x1C, 0x0F, 0x03, 0x01, 0x03, 0x0F, 0x1C, 0x18,  // 88
				    0x06, 0x0E, 0x3C, 0x70, 0xC0, 0xC0, 0x70, 0x3C, 0x0E, 0x06, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00,  // 89
				    0x00, 0x06, 0x06, 0x86, 0xE6, 0x76, 0x3E, 0x0E, 0x06, 0x18, 0x1C, 0x1F, 0x1B, 0x19, 0x18, 0x18, 0x18, 0x18,  // 90
				    0xFE, 0xFE, 0x06, 0x06, 0xFF, 0xFF, 0xC0, 0xC0,  // 91
				    0x0E, 0xFE, 0xF0, 0x00, 0x00, 0x03, 0x1F, 0x1C, // 92
				    0x06, 0x06, 0xFE, 0xFE, 0xC0, 0xC0, 0xFF, 0xFF,  // 93
				    0x40, 0x70, 0x3C, 0x0E, 0x0E, 0x3C, 0x70, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 94
				    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,  // 95
				    0x02, 0x06, 0x04, 0x00, 0x00, 0x00,  // 96
				    0x60, 0x70, 0x30, 0xB0, 0xB0, 0xF0, 0xE0, 0x00, 0x0E, 0x1F, 0x1B, 0x19, 0x19, 0x0F, 0x1F, 0x10, // 97
				    0xFE, 0xFE, 0x60, 0x30, 0x30, 0x70, 0xE0, 0xC0, 0x1F, 0x1F, 0x0C, 0x18, 0x18, 0x1C, 0x0F, 0x07, // 98
				    0xC0, 0xE0, 0x70, 0x30, 0x30, 0x70, 0x60, 0x07, 0x0F, 0x1C, 0x18, 0x18, 0x0C, 0x04,  // 99
				    0xC0, 0xE0, 0x70, 0x30, 0x30, 0x60, 0xFE, 0xFE, 0x07, 0x0F, 0x1C, 0x18, 0x18, 0x0C, 0x1F, 0x1F, // 100
				    0xC0, 0xE0, 0xB0, 0xB0, 0xB0, 0xE0, 0xC0, 0x07, 0x0F, 0x1D, 0x19, 0x19, 0x0D, 0x05,  // 101
				    0x30, 0xFC, 0xFE, 0x36, 0x36, 0x00, 0x1F, 0x1F, 0x00, 0x00,  // 102
				    0xC0, 0xE0, 0x70, 0x30, 0x30, 0x60, 0xF0, 0xF0, 0x67, 0xEF, 0xDC, 0xD8, 0xD8, 0xCC, 0xFF, 0x7F,  // 103
				    0xFE, 0xFE, 0x60, 0x30, 0x30, 0x30, 0xF0, 0xE0, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F,  // 104
				    0xF6, 0xF6, 0x1F, 0x1F,  // 105
				    0x00, 0xF6, 0xF6, 0xC0, 0xFF, 0x7F,  // 106
				    0xFE, 0xFE, 0x80, 0xC0, 0xE0, 0x30, 0x10, 0x1F, 0x1F, 0x03, 0x01, 0x07, 0x1E, 0x18,  // 107
				    0xFE, 0xFE, 0x1F, 0x1F, // 108
				    0xF0, 0xF0, 0x60, 0x30, 0x30, 0xF0, 0xE0, 0x60, 0x30, 0x30, 0xF0, 0xE0, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x1F, 0x1F,  // 109
				    0xF0, 0xF0, 0x60, 0x30, 0x30, 0x30, 0xF0, 0xE0, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F,  // 110
				    0xC0, 0xE0, 0x70, 0x30, 0x30, 0x70, 0xE0, 0xC0, 0x07, 0x0F, 0x1C, 0x18, 0x18, 0x1C, 0x0F, 0x07,  // 111
				    0xF0, 0xF0, 0x60, 0x30, 0x30, 0x70, 0xE0, 0xC0, 0xFF, 0xFF, 0x0C, 0x18, 0x18, 0x1C, 0x0F, 0x07,  // 112
				    0xC0, 0xE0, 0x70, 0x30, 0x30, 0x60, 0xF0, 0xF0, 0x07, 0x0F, 0x1C, 0x18, 0x18, 0x0C, 0xFF, 0xFF, // 113
				    0xF0, 0xF0, 0x60, 0x30, 0x30, 0x1F, 0x1F, 0x00, 0x00, 0x00, // 114
				    0xE0, 0xF0, 0xB0, 0xB0, 0x30, 0x70, 0x60, 0x0C, 0x1D, 0x19, 0x1B, 0x1B, 0x1F, 0x0E,  // 115
				    0x30, 0xFC, 0xFE, 0x30, 0x30, 0x00, 0x0F, 0x1F, 0x18, 0x18,  // 116
				    0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0, 0x0F, 0x1F, 0x18, 0x18, 0x18, 0x0C, 0x1F, 0x1F, // 117
				    0x70, 0xF0, 0x80, 0x00, 0x80, 0xF0, 0x70, 0x00, 0x03, 0x1F, 0x1C, 0x1F, 0x03, 0x00,  // 118
				    0x30, 0xF0, 0xC0, 0x00, 0x80, 0xF0, 0x70, 0xF0, 0x80, 0x00, 0xC0, 0xF0, 0x30, 0x00, 0x03, 0x1F, 0x1C, 0x1F, 0x03, 0x00, 0x03, 0x1F, 0x1C, 0x1F, 0x03, 0x00,  // 119
				    0x30, 0x70, 0xE0, 0x80, 0xE0, 0x70, 0x30, 0x18, 0x1C, 0x0F, 0x03, 0x0F, 0x1C, 0x18, // 120
				    0x30, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0xF0, 0x30, 0x00, 0xC0, 0xC7, 0xFF, 0x7C, 0x1F, 0x07, 0x00, 0x00,  // 121
				    0x30, 0x30, 0x30, 0xB0, 0xF0, 0xF0, 0x30, 0x18, 0x1E, 0x1F, 0x1B, 0x19, 0x18, 0x18,  // 122
				    0x80, 0xC0, 0xFC, 0x7E, 0x06, 0x06, 0x01, 0x03, 0x7F, 0xFE, 0xC0, 0xC0,  // 123
				    0xFE, 0xFE, 0xFF, 0xFF,  // 124
				    0x06, 0x06, 0x7E, 0xFC, 0xC0, 0x80, 0xC0, 0xC0, 0xFE, 0x7F, 0x01, 0x01, // 125
				    0x80, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0xC0, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,  // 126
				    0xFC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xFC, 0x1F, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F, // 127

				};

#endif /* SSD1306_H_ */
