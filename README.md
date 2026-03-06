# Arduino Assignment

This repository contains two implementations using direct register access on ATmega328P.

Branches:
- `GPIO_dev`
- `UART_dev`

---

## GPIO_dev

Blinking the onboard LED (PB5 / Arduino Pin 13) using Timer1 based delay.

### Registers

**DDRB (0x24)** – Configures Port B pins as input/output  
**PORTB (0x25)** – Writes HIGH/LOW to Port B pins  
**TCCR1A (0x80)** – Timer1 control register A  
**TCCR1B (0x81)** – Timer1 control register B (prescaler control)  
**TCNT1H (0x85)** – Timer1 counter high byte  
**TCNT1L (0x84)** – Timer1 counter low byte  
**TIFR1 (0x36)** – Timer1 overflow flag register  

### Working
PB5 is set as output and toggled every ~500 ms using Timer1 overflow.

---

## UART_dev

UART transmission using register-level configuration.

### Registers

**UDR0 (0xC6)** – UART data register  
**UCSR0A (0xC0)** – UART status register  
**UCSR0B (0xC1)** – Enables UART transmitter  
**UCSR0C (0xC2)** – Frame format configuration  
**UBRR0H (0xC5)** – Baud rate high byte  
**UBRR0L (0xC4)** – Baud rate low byte  

**TCCR1A / TCCR1B / TCNT1H / TCNT1L / TIFR1** – Used for Timer1 delay.

### Working
UART is initialized at **9600 baud** and sends  
`Hello from UART` every 1 second.
