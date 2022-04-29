// Mathew Clutter
// AVR ATMega 2560 @16MHz
// 7 segment display interfacing
// displays 4 digit number on 4 digit 7 seg display

// connect the segments to PORTA in order (segment A to pin 0, etc)
// decimal point can be connected to 5v (it is not used in this program)
// anodes on PORTC (if high, screen is active, if low, screen is off)
// C0 is leftmost display, C3 is rightmost display

#include <avr/io.h>
#include <util/delay.h>

unsigned char displayArray[10];

void writeNum(unsigned int num)
{
  if(num > 9999)
  {
    return;
  }

  int currDig;
  
  currDig = num % 10;
  num = num / 10;
  PORTC = 0x01;
  PORTA = ~displayArray[currDig];
  _delay_ms(1);

  currDig = num % 10;
  num = num / 10;
  PORTC = 0x02;
  PORTA = ~displayArray[currDig];
  _delay_ms(1);

  currDig = num % 10;
  num = num / 10;
  PORTC = 0x04;
  PORTA = ~displayArray[currDig];
  _delay_ms(1);

  currDig = num % 10;
  num = num / 10;
  PORTC = 0x08;
  PORTA = ~displayArray[currDig];
  _delay_ms(1);

  return;
}

int main()
{
  displayArray[0] = 0b00111111;
  displayArray[1] = 0b00000110;
  displayArray[2] = 0b01011011;
  displayArray[3] = 0b01001111;
  displayArray[4] = 0b01100110;
  displayArray[5] = 0b01101101;
  displayArray[6] = 0b01111101;
  displayArray[7] = 0b00000111;
  displayArray[8] = 0b01111111;
  displayArray[9] = 0b01101111;

  DDRA = 0xFF;
  PORTA = 0x00;

  DDRC = 0xFF; 
  PORTC = 0xFF;

  while(1)
  {
    writeNum(4593); // need to call the writeNum function quickly for display to work right
  }
}
