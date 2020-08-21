#include<Arduino.h>
#include "key_matrix.h"
#define sbi(port, pin) (port) |= _BV(pin)
#define cbi(port, pin) (port) &= ~_BV(pin)
#define tbi(port, pin) (port) ^= _BV(pin)


void setup()
{
  DDRD = 0x00;    //0b00000000 input
  PORTD = 0xF0;   //0b11110000 high impedance and PULL-UP
  DDRB = 0x20;    //0b00100000 output on PB5 (LED)
}

int main()
{
  init();
  setup();
  int button;
  while(1)
  {
    button = chosen_button();
    for(int i = 0; i < button; i++)
    {
      sbi(PORTB, PB5);
      _delay_ms(500);
      cbi(PORTB, PB5);
      _delay_ms(500);
    }
  }
}
