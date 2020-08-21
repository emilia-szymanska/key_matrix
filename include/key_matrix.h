#ifndef KEY_MATRIX_H
#define KEY_MATRIX_H
/*
In setup:
    DDRD = 0x00;    //0b00000000
    PORTD = 0xF0;   //0b11110000
*/

#include<Arduino.h>
#define R1 0x01     //to change rows from input to output
#define R2 0x02
#define R3 0x04
#define R4 0x08
#define C1 0xE0     //to read data from specific pins
#define C2 0xD0
#define C3 0xB0
#define C4 0x70


int pressed_button();

int chosen_button();

#endif