/*
In setup:
  DDRD = 0x00;    //0b00000000
  PORTD = 0xF0;   //0b11110000
  DDRB = 0x20;    //0b00100000
*/

#include "key_matrix.h"

int pressed_button()
{
    DDRD = R1;            //setting row1 as output
    _delay_us(10);        //switch debouncing
    switch(PIND & 0xF0)   //finding 0 on columns
    {
      case C1: return 1;
      case C2: return 2;
      case C3: return 3;
      case C4: return 4;           
    }
    
    DDRD = R2;            //setting row2 as output
    _delay_us(10);        //switch debouncing
    switch(PIND & 0xF0)   //finding 0 on columns
    {
      case C1: return 5;
      case C2: return 6;
      case C3: return 7;
      case C4: return 8;           
    }
    
    DDRD = R3;            //setting row3 as output
    _delay_us(10);        //switch debouncing
    switch(PIND & 0xF0)   //finding 0 on columns
    {
      case C1: return 9;
      case C2: return 10;
      case C3: return 11;
      case C4: return 12;           
    }

    DDRD = R4;            //setting row4 as output
    _delay_us(10);        //switch debouncing
    switch(PIND & 0xF0)   //finding 0 on columns
    {
      case C1: return 13;
      case C2: return 14;
      case C3: return 15;
      case C4: return 16;           
    }
    return 0;
}

int chosen_button()
{
  int button = pressed_button();
  while(pressed_button() == button){}
  _delay_ms(20);
  return button;
}