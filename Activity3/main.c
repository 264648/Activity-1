/*
 */

#include <avr/io.h>
#include<util/delay.h>
 void InitADC()
 {
     ADMUX=(1<<REFS0);
     ADCSRA=(1<<ADEN)|(7<<ADPS0);
 }
 uint16_t ReadADC(uint8_t ch)
 {
     ADMUX&=0xf8;
     ch=ch&0b00000111;
     ADMUX|=ch;
     ADCSRA|=(1<<ADSC);
     while(!(ADCSRA&(1<<ADIF)));
     ADCSRA|=1<<ADIF;
     return(ADC);
 }
 int main(void)
 {
     InitADC();
     uint16_t temp=0;
     DDRB|=(1<<PB0);
     DDRD&=~(1<<PD2);
     PORTD|=(1<<PD2);
      DDRD&=~(1<<PD1);
     PORTD|=(1<<PD1);
     TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01);
     TCCR0B|=(1<<CS01)|(1<<CS00);
     DDRD|=1<<PD6;
     while(1)
     {
         if((!(PIND&(1<<PD2))) & (!(PIND&(1<<PD1))))
         {

                 PORTB|=(1<<PB0);
                 temp=ReadADC(0);
                 OCR0A=temp;
                 _delay_ms(200);
             }
             else{
                PORTB&=~(1<<PB0);
                _delay_ms(200);
             }
         }
     return 0;
 }
