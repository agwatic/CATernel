/*
 * Saad Talaat
 * CATReloaded (C) Copyrights 2011
 * http://catreloaded.net
 */

#ifndef _CATERNEL_VIDEO_H_
#define _CATERNEL_VIDEO_H_
/* try to read the CGA/MONO documentation */
#define CGA_INDEX1	0x3D4
#define CGA_DATA1	0x3D5
#define CGA_BUFF_OFF	0xB8000
#define CGA_COLS	80
#define CGA_ROWS	25
#define CGA_SIZE	(CGA_ROWS * CGA_COLS)		
#define COLOR_DARK_GRAY	0x0700
#define COLOR_BLUE	0x0100
#define COLOR_GREEN	0x0200
#define COLOR_RED	0x0400
#define COLOR_GRAY	0x0800
#define COLOR_WHITE	0x0f00
#define BACKGROUND_GRAY	0x7000
#define BACKGROUND_BLUE	0x1000
#define BACKGROUND_GREEN	0x2000
#define BACKGROUND_RED	0x4000
#define BACKGROUND_BLINK	0x8000
#define BACKGROUND_WHITE	0xF000
//static int serial_exists;
uint16_t	cursor_position;
uint16_t	*char_buff;
/**
 * @fn void cga_init(void);
 * @brief initiates CGA.
 *
 * @details This function sets global variables to its initial values.
 * sets <b>start</b> to address of the CGA buffer.
 * and sets current character buffer to the start value. and
 * initalizes cga color attributes to none.
 *
 *
 * @fn uint16_t cga_get_pos(void);
 * @brief gets the cursor position on the screen.
 * 
 * @details The get position function gets the cursor position by reading
 * it from the data register, by indexing the cga index register.
 *
 *
 * @fn void cga_set_pos(uint16_t);
 * @param uint32_t pos the position to be set.
 * @brief sets the position to a given value on the screen map
 * 
 * @details Function behavious is similar to cga_get_pos
 *
 *
 * @fn void cga_putc(int);
 * @param int c the character to be written.
 * @brief writes a character to screen using cga.
 *
 * @details The CGA putc is relatively big function and similar somehow to
 * the printing function, here we take only one character at a time
 * and print it to screen and attribute is set to every printed char.
 * then character type is being checked and every character has its
 * own operation, for example: \n
 * Backspace:	cursor position is decremented by one. \n
 * New-Line: 	a whole line character count is added to the cursor position\n
 * After a chacter is written, screen checks if it needs to be shifted up.
 *
 *
 * @fn void cga_set_attr(uint16_t);
 * @param uint16_t c the color attribute
 * @brief sets global color attribute to a given value.
 *
 *
 * @fn void cga_clear(void);
 * @brief clears the screen.
 * 
 *
 * @fn void cga_putstr(char *);
 * @brief uses cga_putc to write a string
 */ 


void		cga_init(void);
uint16_t	cga_get_pos(void);
void		cga_set_pos(uint16_t);
void		cga_putc(int c);
void		cga_set_attr(uint16_t);
void		cga_clear(void);
void		cga_putstr(char *);

#endif
