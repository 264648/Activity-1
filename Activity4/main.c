/*
 */

#include <avr/io.h>
#include<util/delay.h>
void USARTInit(uint16_t ubrr_value)
{
    UBRR0L=ubrr_value;
    UBRR0H=(ubrr_value>>8)&(0x00ff);
    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);
    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

void InitADC()
{

    ADMUX=(1<<REFS0); // For Aref=AVcc;
    ADCSRA=(1<<ADEN) | (7<<ADPS0);
}
uint16_t ReadADC(uint8_t ch)
{
 //SELECT ADC CHANNEL CH MUST BE 0-7
 ADMUX&=0xf8;
 ch=ch&0b00000111;
 ADMUX|=ch;
 // Start Single conversion
 ADCSRA|=(1<<ADSC);
 //Wait for conversion to complete
 while(!(ADCSRA & (1<<ADIF)));
 //Clear ADIF by writing one to it
 ADCSRA|=(1<<ADIF);
 return(ADC);

}
int main(void)
{
InitADC();
uint16_t temp=0;
uint16_t i;
DDRB|=(1<<PB0);// SET B0=1
  DDRD&=~(1<<PD2);// CLEAR BIT
  PORTD|=(1<<PD2);// SET BIT
  DDRD&=~(1<<PD1);// CLEAR BIT
  PORTD|=(1<<PD1);// SET BIT
TCCR1A |=(1<<COM1A1)|(1<<WGM11) | (1<<WGM10);
TCCR1B|=(1<<WGM12) | (1<<CS12) | (1<<CS10);
DDRB |=1<<PB1;
    // Insert code

    while(1)
    {

        if((!(PIND&(1<<PD2))) & (!(PIND&(1<<PD1))))
        {

        PORTB|=(1<<PB0);
        temp=ReadADC(0);

        OCR1A=temp;
        if(OCR1A>=0 && OCR1A<=200){
                unsigned char d1[]="Temp:20\n";
        i=0;
        while(d1[i]!=0){
           while(!(UCSR0A & (1<<UDRE0)));
           UDR0=d1[i];
           i++;
        }
        _delay_ms(200);
        }
        else if(OCR1A>=210 && OCR1A<=500){

       unsigned char d1[]="Temp:25\n";
        i=0;
        while(d1[i]!=0){
           while(!(UCSR0A & (1<<UDRE0)));
           UDR0=d1[i];
           i++;
        }
        _delay_ms(200);
        }
        else if(OCR1A>=510 && OCR1A<=700){

        unsigned char d1[]="Temp:29\n";
        i=0;
        while(d1[i]!=0){
           while(!(UCSR0A & (1<<UDRE0)));
           UDR0=d1[i];
           i++;
        }
        _delay_ms(200);
        }
        else if(OCR1A>=710 && OCR1A<=1024){
       unsigned char d1[]="Temp:33\n";
        i=0;
        while(d1[i]!=0){
           while(!(UCSR0A & (1<<UDRE0)));
           UDR0=d1[i];
           i++;
        }
        _delay_ms(200);
        }
        }
        else{
        PORTB&=~(1<<PB0);
        _delay_ms(200);
    }
    }

    return 0;
}
