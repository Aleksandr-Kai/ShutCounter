/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.

ATmega8515 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __MEGA8515_BITS_INCLUDED__
#define __MEGA8515_BITS_INCLUDED__

/* ***** ANALOG_COMPARATOR ************ */
/* ACSR - Analog Comparator Control And Status Register */
#define    ACIS0           0       // Analog Comparator Interrupt Mode Select bit 0
#define    ACIS1           1       // Analog Comparator Interrupt Mode Select bit 1
#define    ACIC            2       // Analog Comparator Input Capture Enable
#define    ACIE            3       // Analog Comparator Interrupt Enable
#define    ACI             4       // Analog Comparator Interrupt Flag
#define    ACO             5       // Analog Compare Output
#define    ACBG            6       // Analog Comparator Bandgap Select
#define    AINBG           ACBG    // For compatibility
#define    ACD             7       // Analog Comparator Disable


/* ***** USART ************************ */
/* UDR - USART I/O Data Register */
#define    UDR0            0       // USART I/O Data Register bit 0
#define    UDR1            1       // USART I/O Data Register bit 1
#define    UDR2            2       // USART I/O Data Register bit 2
#define    UDR3            3       // USART I/O Data Register bit 3
#define    UDR4            4       // USART I/O Data Register bit 4
#define    UDR5            5       // USART I/O Data Register bit 5
#define    UDR6            6       // USART I/O Data Register bit 6
#define    UDR7            7       // USART I/O Data Register bit 7

/* UCSRA - USART Control and Status Register A */
#define    MPCM            0       // Multi-processor Communication Mode
#define    U2X             1       // Double the USART transmission speed
#define    UPE             2       // Parity Error
#define    PE              UPE     // For compatibility
#define    DOR             3       // Data overRun
#define    FE              4       // Framing Error
#define    UDRE            5       // USART Data Register Empty
#define    TXC             6       // USART Transmitt Complete
#define    RXC             7       // USART Receive Complete

/* UCSRB - USART Control and Status Register B */
#define    TXB8            0       // Transmit Data Bit 8
#define    RXB8            1       // Receive Data Bit 8
#define    UCSZ2           2       // Character Size Bit 2
#define    CHR9            UCSZ2   // For compatibility
#define    TXEN            3       // Transmitter Enable
#define    RXEN            4       // Receiver Enable
#define    UDRIE           5       // USART Data register Empty Interrupt Enable
#define    TXCIE           6       // TX Complete Interrupt Enable
#define    RXCIE           7       // RX Complete Interrupt Enable

/* UCSRC - USART Control and Status Register C */
#define    UCPOL           0       // Clock Polarity
#define    UCSZ0           1       // Character Size Bit 0
#define    UCSZ1           2       // Character Size Bit 1
#define    USBS            3       // Stop Bit Select
#define    UPM0            4       // Parity Mode Bit 0
#define    UPM1            5       // Parity Mode Bit 1
#define    UMSEL           6       // USART Mode Select
#define    URSEL           7       // Register Select

/* UBRRH - USART Baud Rate Register High Byte */
#define    UBRR8           0       // USART Baud Rate Register bit 8
#define    UBRR9           1       // USART Baud Rate Register bit 9
#define    UBRR10          2       // USART Baud Rate Register bit 10
#define    UBRR11          3       // USART Baud Rate Register bit 11
//#define  URSEL           7       // Register Select


/* ***** SPI ************************** */
/* SPDR - SPI Data Register */
#define    SPDR0           0       // SPI Data Register bit 0
#define    SPDR1           1       // SPI Data Register bit 1
#define    SPDR2           2       // SPI Data Register bit 2
#define    SPDR3           3       // SPI Data Register bit 3
#define    SPDR4           4       // SPI Data Register bit 4
#define    SPDR5           5       // SPI Data Register bit 5
#define    SPDR6           6       // SPI Data Register bit 6
#define    SPDR7           7       // SPI Data Register bit 7

/* SPSR - SPI Status Register */
#define    SPI2X           0       // Double SPI Speed Bit
#define    WCOL            6       // Write Collision Flag
#define    SPIF            7       // SPI Interrupt Flag

/* SPCR - SPI Control Register */
#define    SPR0            0       // SPI Clock Rate Select 0
#define    SPR1            1       // SPI Clock Rate Select 1
#define    CPHA            2       // Clock Phase
#define    CPOL            3       // Clock polarity
#define    MSTR            4       // Master/Slave Select
#define    DORD            5       // Data Order
#define    SPE             6       // SPI Enable
#define    SPIE            7       // SPI Interrupt Enable


/* ***** CPU ************************** */
/* SREG - Status Register */
#define    SREG_C          0       // Carry Flag
#define    SREG_Z          1       // Zero Flag
#define    SREG_N          2       // Negative Flag
#define    SREG_V          3       // Two's Complement Overflow Flag
#define    SREG_S          4       // Sign Bit
#define    SREG_H          5       // Half Carry Flag
#define    SREG_T          6       // Bit Copy Storage
#define    SREG_I          7       // Global Interrupt Enable

/* EMCUCR - Extended MCU Control Register */
#define    ISC2            0       // Interrupt Sense Control 2
#define    SRW11           1       // Wait State Select Bits for Upper Sector, bit 1
#define    SRW00           2       // Wait State Select Bits for Lower Sector, bit 0
#define    SRW01           3       // Wait State Select Bits for Lower Sector, bit 1
#define    SRL0            4       // Wait State Selector Limit bit 0
#define    SRL1            5       // Wait State Selector Limit bit 1
#define    SRL2            6       // Wait State Selector Limit bit 2
#define    SM0             7       // Sleep Mode Select Bit 0

/* MCUCR - MCU Control Register */
#define    ISC00           0       // Interrupt Sense Control 0 Bit 0
#define    ISC01           1       // Interrupt Sense Control 0 Bit 1
#define    ISC10           2       // Interrupt Sense Control 1 Bit 0
#define    ISC11           3       // Interrupt Sense Control 1 Bit 1
#define    SM1             4       // Sleep Mode Select Bit 1
#define    SE              5       // Sleep Enable
#define    SRW10           6       // Wait State Select Bits for Upper Sector, bit 0
#define    SRE             7       // External SRAM/XMEM Enable

/* MCUCSR - MCU Control And Status Register */
#define    MCUSR           MCUCSR  // For compatibility
#define    PORF            0       // Power-on reset flag
#define    EXTRF           1       // External Reset Flag
#define    BORF            2       // Brown-out Reset Flag
#define    WDRF            3       // Watchdog Reset Flag
#define    SM2             5       // Sleep Mode Select Bit 2

/* OSCCAL - Oscillator Calibration Value */
#define    CAL0            0       // Oscillator Calibration Value Bit0
#define    CAL1            1       // Oscillator Calibration Value Bit1
#define    CAL2            2       // Oscillator Calibration Value Bit2
#define    CAL3            3       // Oscillator Calibration Value Bit3
#define    CAL4            4       // Oscillator Calibration Value Bit4
#define    CAL5            5       // Oscillator Calibration Value Bit5
#define    CAL6            6       // Oscillator Calibration Value Bit6
#define    CAL7            7       // Oscillator Calibration Value Bit7

/* SPMCR - Store Program Memory Control Register */
#define    SPMEN           0       // Store Program Memory Enable
#define    PGERS           1       // Page Erase
#define    PGWRT           2       // Page Write
#define    BLBSET          3       // Boot Lock Bit Set
#define    RWWSRE          4       // Read-While-Write Section Read Enable
#define    ASRE            RWWSRE  // For compatibility
#define    RWWSB           6       // Read-While-Write Section Busy
#define    ASB             RWWSB   // For compatibility
#define    SPMIE           7       // SPM Interrupt Enable

/* SFIOR - Special Function IO Register */
#define    PSR10           0       // Prescaler Reset Timer / Counter 1 and Timer / Counter 0
#define    PUD             2       // Pull-up Disable
#define    XMM0            3       // External Memory High Mask Bit 0
#define    XMM1            4       // External Memory High Mask Bit 1
#define    XMM2            5       // External Memory High Mask Bit 2
#define    XMBK            6       // External Memory Bus Keeper Enable


/* ***** EXTERNAL_INTERRUPT *********** */
/* GICR - General Interrupt Control Register */
#define    GIMSK           GICR    // For compatibility
#define    IVCE            0       // Interrupt Vector Change Enable
#define    IVSEL           1       // Interrupt Vector Select
#define    INT2            5       // External Interrupt Request 2 Enable
#define    INT0            6       // External Interrupt Request 0 Enable
#define    INT1            7       // External Interrupt Request 1 Enable

/* GIFR - General Interrupt Flag Register */
#define    INTF2           5       // External Interrupt Flag 2
#define    INTF0           6       // External Interrupt Flag 0
#define    INTF1           7       // External Interrupt Flag 1


/* ***** WATCHDOG ********************* */
/* WDTCR - Watchdog Timer Control Register */
#define    WDTCSR          WDTCR   // For compatibility
#define    WDP0            0       // Watch Dog Timer Prescaler bit 0
#define    WDP1            1       // Watch Dog Timer Prescaler bit 1
#define    WDP2            2       // Watch Dog Timer Prescaler bit 2
#define    WDE             3       // Watch Dog Enable
#define    WDCE            4       // Watchdog Change Enable
#define    WDTOE           WDCE    // For compatibility


/* ***** TIMER_COUNTER_0 ************** */
/* TCCR0 - Timer/Counter 0 Control Register */
#define    CS00            0       // Clock Select 0
#define    CS01            1       // Clock Select 1
#define    CS02            2       // Clock Select 2
#define    WGM01           3       // Waveform Generation Mode 1
#define    CTC0            WGM01   // For compatibility
#define    COM00           4       // Compare match Output Mode 0
#define    COM01           5       // Compare Match Output Mode 1
#define    WGM00           6       // Waveform Generation Mode 0
#define    PWM0            WGM00   // For compatibility
#define    FOC0            7       // Force Output Compare

/* TCNT0 - Timer/Counter 0 Register */
#define    TCNT0_0         0       // 
#define    TCNT0_1         1       // 
#define    TCNT0_2         2       // 
#define    TCNT0_3         3       // 
#define    TCNT0_4         4       // 
#define    TCNT0_5         5       // 
#define    TCNT0_6         6       // 
#define    TCNT0_7         7       // 

/* OCR0 - Timer/Counter 0 Output Compare Register */
#define    OCR0_0          0       // 
#define    OCR0_1          1       // 
#define    OCR0_2          2       // 
#define    OCR0_3          3       // 
#define    OCR0_4          4       // 
#define    OCR0_5          5       // 
#define    OCR0_6          6       // 
#define    OCR0_7          7       // 

/* TIMSK - Timer/Counter Interrupt Mask Register */
#define    OCIE0           0       // Timer/Counter0 Output Compare Match Interrupt register
#define    TOIE0           1       // Timer/Counter0 Overflow Interrupt Enable

/* TIFR - Timer/Counter Interrupt Flag register */
#define    OCF0            0       // Output Compare Flag 0
#define    TOV0            1       // Timer/Counter0 Overflow Flag


/* ***** TIMER_COUNTER_1 ************** */
/* TIMSK - Timer/Counter Interrupt Mask Register */
#define    TICIE1          3       // Timer/Counter1 Input Capture Interrupt Enable
#define    OCIE1B          5       // Timer/Counter1 Output CompareB Match Interrupt Enable
#define    OCIE1A          6       // Timer/Counter1 Output CompareA Match Interrupt Enable
#define    TOIE1           7       // Timer/Counter1 Overflow Interrupt Enable

/* TIFR - Timer/Counter Interrupt Flag register */
#define    ICF1            3       // Input Capture Flag 1
#define    OCF1B           5       // Output Compare Flag 1B
#define    OCF1A           6       // Output Compare Flag 1A
#define    TOV1            7       // Timer/Counter1 Overflow Flag

/* TCCR1A - Timer/Counter1 Control Register A */
#define    WGM10           0       // Pulse Width Modulator Select Bit 0
#define    PWM10           WGM10   // For compatibility
#define    WGM11           1       // Pulse Width Modulator Select Bit 1
#define    PWM11           WGM11   // For compatibility
#define    FOC1B           2       // Force Output Compare for Channel B
#define    FOC1A           3       // Force Output Compare for Channel A
#define    COM1B0          4       // Compare Output Mode 1B, bit 0
#define    COM1B1          5       // Compare Output Mode 1B, bit 1
#define    COM1A0          6       // Compare Ouput Mode 1A, bit 0
#define    COM1A1          7       // Compare Output Mode 1A, bit 1

/* TCCR1B - Timer/Counter1 Control Register B */
#define    CS10            0       // Clock Select1 bit 0
#define    CS11            1       // Clock Select1 bit 1
#define    CS12            2       // Clock Select1 bit 2
#define    WGM12           3       // Pulse Width Modulator Select Bit 2
#define    CTC10           WGM12   // For compatibility
#define    WGM13           4       // Pulse Width Modulator Select Bit 3
#define    CTC11           WGM13   // For compatibility
#define    ICES1           6       // Input Capture 1 Edge Select
#define    ICNC1           7       // Input Capture 1 Noise Canceler


/* ***** PORTA ************************ */
/* PORTA - Port A Data Register */
#define    PORTA0          0       // Port A Data Register bit 0
#define    PORTA1          1       // Port A Data Register bit 1
#define    PORTA2          2       // Port A Data Register bit 2
#define    PORTA3          3       // Port A Data Register bit 3
#define    PORTA4          4       // Port A Data Register bit 4
#define    PORTA5          5       // Port A Data Register bit 5
#define    PORTA6          6       // Port A Data Register bit 6
#define    PORTA7          7       // Port A Data Register bit 7

/* DDRA - Port A Data Direction Register */
#define    DDA0            0       // Data Direction Register, Port A, bit 0
#define    DDA1            1       // Data Direction Register, Port A, bit 1
#define    DDA2            2       // Data Direction Register, Port A, bit 2
#define    DDA3            3       // Data Direction Register, Port A, bit 3
#define    DDA4            4       // Data Direction Register, Port A, bit 4
#define    DDA5            5       // Data Direction Register, Port A, bit 5
#define    DDA6            6       // Data Direction Register, Port A, bit 6
#define    DDA7            7       // Data Direction Register, Port A, bit 7

/* PINA - Port A Input Pins */
#define    PINA0           0       // Input Pins, Port A bit 0
#define    PINA1           1       // Input Pins, Port A bit 1
#define    PINA2           2       // Input Pins, Port A bit 2
#define    PINA3           3       // Input Pins, Port A bit 3
#define    PINA4           4       // Input Pins, Port A bit 4
#define    PINA5           5       // Input Pins, Port A bit 5
#define    PINA6           6       // Input Pins, Port A bit 6
#define    PINA7           7       // Input Pins, Port A bit 7


/* ***** PORTB ************************ */
/* PORTB - Port B Data Register */
#define    PORTB0          0       // Port B Data Register bit 0
#define    PORTB1          1       // Port B Data Register bit 1
#define    PORTB2          2       // Port B Data Register bit 2
#define    PORTB3          3       // Port B Data Register bit 3
#define    PORTB4          4       // Port B Data Register bit 4
#define    PORTB5          5       // Port B Data Register bit 5
#define    PORTB6          6       // Port B Data Register bit 6
#define    PORTB7          7       // Port B Data Register bit 7

/* DDRB - Port B Data Direction Register */
#define    DDB0            0       // Port B Data Direction Register bit 0
#define    DDB1            1       // Port B Data Direction Register bit 1
#define    DDB2            2       // Port B Data Direction Register bit 2
#define    DDB3            3       // Port B Data Direction Register bit 3
#define    DDB4            4       // Port B Data Direction Register bit 4
#define    DDB5            5       // Port B Data Direction Register bit 5
#define    DDB6            6       // Port B Data Direction Register bit 6
#define    DDB7            7       // Port B Data Direction Register bit 7

/* PINB - Port B Input Pins */
#define    PINB0           0       // Port B Input Pins bit 0
#define    PINB1           1       // Port B Input Pins bit 1
#define    PINB2           2       // Port B Input Pins bit 2
#define    PINB3           3       // Port B Input Pins bit 3
#define    PINB4           4       // Port B Input Pins bit 4
#define    PINB5           5       // Port B Input Pins bit 5
#define    PINB6           6       // Port B Input Pins bit 6
#define    PINB7           7       // Port B Input Pins bit 7


/* ***** PORTC ************************ */
/* PORTC - Port C Data Register */
#define    PORTC0          0       // Port C Data Register bit 0
#define    PORTC1          1       // Port C Data Register bit 1
#define    PORTC2          2       // Port C Data Register bit 2
#define    PORTC3          3       // Port C Data Register bit 3
#define    PORTC4          4       // Port C Data Register bit 4
#define    PORTC5          5       // Port C Data Register bit 5
#define    PORTC6          6       // Port C Data Register bit 6
#define    PORTC7          7       // Port C Data Register bit 7

/* DDRC - Port C Data Direction Register */
#define    DDC0            0       // Port C Data Direction Register bit 0
#define    DDC1            1       // Port C Data Direction Register bit 1
#define    DDC2            2       // Port C Data Direction Register bit 2
#define    DDC3            3       // Port C Data Direction Register bit 3
#define    DDC4            4       // Port C Data Direction Register bit 4
#define    DDC5            5       // Port C Data Direction Register bit 5
#define    DDC6            6       // Port C Data Direction Register bit 6
#define    DDC7            7       // Port C Data Direction Register bit 7

/* PINC - Port C Input Pins */
#define    PINC0           0       // Port C Input Pins bit 0
#define    PINC1           1       // Port C Input Pins bit 1
#define    PINC2           2       // Port C Input Pins bit 2
#define    PINC3           3       // Port C Input Pins bit 3
#define    PINC4           4       // Port C Input Pins bit 4
#define    PINC5           5       // Port C Input Pins bit 5
#define    PINC6           6       // Port C Input Pins bit 6
#define    PINC7           7       // Port C Input Pins bit 7


/* ***** PORTD ************************ */
/* PORTD - Port D Data Register */
#define    PORTD0          0       // Port D Data Register bit 0
#define    PORTD1          1       // Port D Data Register bit 1
#define    PORTD2          2       // Port D Data Register bit 2
#define    PORTD3          3       // Port D Data Register bit 3
#define    PORTD4          4       // Port D Data Register bit 4
#define    PORTD5          5       // Port D Data Register bit 5
#define    PORTD6          6       // Port D Data Register bit 6
#define    PORTD7          7       // Port D Data Register bit 7

/* DDRD - Port D Data Direction Register */
#define    DDD0            0       // Port D Data Direction Register bit 0
#define    DDD1            1       // Port D Data Direction Register bit 1
#define    DDD2            2       // Port D Data Direction Register bit 2
#define    DDD3            3       // Port D Data Direction Register bit 3
#define    DDD4            4       // Port D Data Direction Register bit 4
#define    DDD5            5       // Port D Data Direction Register bit 5
#define    DDD6            6       // Port D Data Direction Register bit 6
#define    DDD7            7       // Port D Data Direction Register bit 7

/* PIND - Port D Input Pins */
#define    PIND0           0       // Port D Input Pins bit 0
#define    PIND1           1       // Port D Input Pins bit 1
#define    PIND2           2       // Port D Input Pins bit 2
#define    PIND3           3       // Port D Input Pins bit 3
#define    PIND4           4       // Port D Input Pins bit 4
#define    PIND5           5       // Port D Input Pins bit 5
#define    PIND6           6       // Port D Input Pins bit 6
#define    PIND7           7       // Port D Input Pins bit 7


/* ***** PORTE ************************ */
/* PORTE - Port E Data Register */
#define    PORTE0          0       // 
#define    PORTE1          1       // 
#define    PORTE2          2       // 

/* DDRE - Port E Data Direction Register */
#define    DDE0            0       // 
#define    DDE1            1       // 
#define    DDE2            2       // 

/* PINE - Port E Input Pins */
#define    PINE0           0       // 
#define    PINE1           1       // 
#define    PINE2           2       // 


/* ***** EEPROM *********************** */
/* EEDR - EEPROM Data Register */
#define    EEDR0           0       // EEPROM Data Register bit 0
#define    EEDR1           1       // EEPROM Data Register bit 1
#define    EEDR2           2       // EEPROM Data Register bit 2
#define    EEDR3           3       // EEPROM Data Register bit 3
#define    EEDR4           4       // EEPROM Data Register bit 4
#define    EEDR5           5       // EEPROM Data Register bit 5
#define    EEDR6           6       // EEPROM Data Register bit 6
#define    EEDR7           7       // EEPROM Data Register bit 7

/* EECR - EEPROM Control Register */
#define    EERE            0       // EEPROM Read Enable
#define    EEWE            1       // EEPROM Write Enable
#define    EEMWE           2       // EEPROM Master Write Enable
#define    EEWEE           EEMWE   // For compatibility
#define    EERIE           3       // EEPROM Ready Interrupt Enable

#endif

