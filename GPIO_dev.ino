#define DDRB   (*(volatile unsigned char*)0x24)
#define PORTB  (*(volatile unsigned char*)0x25)
#define TCCR1A (*(volatile unsigned char*)0x80)
#define TCCR1B (*(volatile unsigned char*)0x81)
#define TCNT1L (*(volatile unsigned char*)0x84)
#define TCNT1H (*(volatile unsigned char*)0x85)
#define TIFR1  (*(volatile unsigned char*)0x36)

void timer1_delay_500ms()
{
    TCCR1B = 0x00;
    TCNT1H = 0xE1;
    TCNT1L = 0x6C;
    TCCR1B |= (1<<2) | (1<<0);
    while(!(TIFR1 & (1<<0)));
    TIFR1 |= (1<<0);
}

void setup()
{
    DDRB |= (1<<5);
}

void loop()
{
    PORTB ^= (1<<5);
    timer1_delay_500ms();
}