#include<avr/io.h>
#include<avr/interrupt.h>



ISR (TIMER1_OVF_vect)    // Timer1 ISR
{
  PORTB = PORTB^0x20; 
  TCNT1 = 49911;   // for 1 sec at 16 MHz
}

int main()
{
  DDRB = 0x20;     //Configure the PORTB as output
  
  TCNT1 = 49911;   // for 1 sec at 16 MHz 

  TCCR1A = 0x00;
  TCCR1B = (1<<CS10) | (1<<CS12);;  // Timer mode with 1024 prescaler
  TIMSK1 = (1 << TOIE1) ;   // Enable timer1 overflow interrupt(TOIE1)
  sei();        // Enable global interrupts by setting global interrupt enable bit in SREG
  
  while(1)
  {
    

  }
}