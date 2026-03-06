#define UDR0   (*(volatile unsigned char*)0xC6)
#define UCSR0A (*(volatile unsigned char*)0xC0)
#define UCSR0B (*(volatile unsigned char*)0xC1)
#define UCSR0C (*(volatile unsigned char*)0xC2)

#define UBRR0L (*(volatile unsigned char*)0xC4)
#define UBRR0H (*(volatile unsigned char*)0xC5)

#define TCCR1A (*(volatile unsigned char*)0x80)
#define TCCR1B (*(volatile unsigned char*)0x81)
#define TCNT1H (*(volatile unsigned char*)0x85)
#define TCNT1L (*(volatile unsigned char*)0x84)
#define TIFR1  (*(volatile unsigned char*)0x36)

void UART_init()
{
    unsigned int ubrr = 103;

    UBRR0H = (ubrr >> 8);
    UBRR0L = ubrr;

    UCSR0B = (1<<3);
    UCSR0C = (1<<1) | (1<<2);
}

void UART_send_char(char data)
{
    while(!(UCSR0A & (1<<5)));
    UDR0 = data;
}

void UART_send_string(char *str)
{
    while(*str)
    {
        UART_send_char(*str++);
    }
}

void timer1_delay_1s()
{
    TCCR1B = 0x00;

    TCNT1H = 0xC2;
    TCNT1L = 0xF7;

    TCCR1B |= (1<<2) | (1<<0);

    while(!(TIFR1 & (1<<0)));

    TIFR1 |= (1<<0);
}

int main()
{
    UART_init();

    while(1)
    {
        UART_send_string("Hello from UART\r\n");
        timer1_delay_1s();
    }
}