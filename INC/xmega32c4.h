// CodeVisionAVR C Compiler V3.11+
// (C) 1998-2014 Pavel Haiduc, HP InfoTech S.R.L.

// Peripheral Modules and Interrupt Vector definitions for the ATxmega32C4

#ifndef __XMEGA32C4_INCLUDED__
#define __XMEGA32C4_INCLUDED__

#define __CRC_EXISTS__
#define __USB_EXISTS__
#define __TC2_EXISTS__

#include <xmstruct.h> // definitions for the Peripheral Module structures
#include <xmbits_c4.h> // bit definitions for the Peripheral Modules registers

// General Purpose I/O Registers
sfrb GPIO0=0x00;
sfrb GPIO1=0x01;
sfrb GPIO2=0x02;
sfrb GPIO3=0x03;

sfrb GPIOR0=0x00;
sfrb GPIOR1=0x01;
sfrb GPIOR2=0x02;
sfrb GPIOR3=0x03;

sfrb VPORT0_DIR=0x10;
sfrb VPORT0_OUT=0x11;
sfrb VPORT0_IN=0x12;
sfrb VPORT0_INTFLAGS=0x13;

sfrb VPORT1_DIR=0x14;
sfrb VPORT1_OUT=0x15;
sfrb VPORT1_IN=0x16;
sfrb VPORT1_INTFLAGS=0x17;

sfrb VPORT2_DIR=0x18;
sfrb VPORT2_OUT=0x19;
sfrb VPORT2_IN=0x1A;
sfrb VPORT2_INTFLAGS=0x1B;

sfrb VPORT3_DIR=0x1C;
sfrb VPORT3_OUT=0x1D;
sfrb VPORT3_IN=0x1E;
sfrb VPORT3_INTFLAGS=0x1F;

sfrb OCD_OCDR0=0x2E;
sfrb OCD_OCDR1=0x2F;
sfrb CCP=0x34;
sfrb RAMPD=0x38;
sfrb RAMPX=0x39;
sfrb RAMPY=0x3A;
sfrb RAMPZ=0x3B;
sfrb EIND=0x3C;
sfrb SPL=0x3D;
sfrb SPH=0x3E;
sfrb SREG=0x3F;

#define VPORT0    (*(volatile VPORT_t *) 0x0010)  // Virtual Port 
#define VPORT1    (*(volatile VPORT_t *) 0x0014)  // Virtual Port 
#define VPORT2    (*(volatile VPORT_t *) 0x0018)  // Virtual Port 
#define VPORT3    (*(volatile VPORT_t *) 0x001C)  // Virtual Port 
#define OCD    (*(volatile OCD_t *) 0x002E)  // On-Chip Debug System 
#define CLK    (*(volatile CLK_t *) 0x0040)  // Clock System 
#define SLEEP    (*(volatile SLEEP_t *) 0x0048)  // Sleep Controller 
#define OSC    (*(volatile OSC_t *) 0x0050)  // Oscillator 
#define DFLLRC32M    (*(volatile DFLL_t *) 0x0060)  // DFLL 
#define DFLLRC2M    (*(volatile DFLL_t *) 0x0068)  // DFLL 
#define PR    (*(volatile PR_t *) 0x0070)  // Power Reduction 
#define RST    (*(volatile RST_t *) 0x0078)  // Reset 
#define WDT    (*(volatile WDT_t *) 0x0080)  // Watch-Dog Timer 
#define MCU    (*(volatile MCU_t *) 0x0090)  // MCU Control 
#define PMIC    (*(volatile PMIC_t *) 0x00A0)  // Programmable Multi-level Interrupt Controller 
#define PORTCFG    (*(volatile PORTCFG_t *) 0x00B0)  // I/O port Configuration 
#define CRC    (*(volatile CRC_t *) 0x00D0)  // Cyclic Redundancy Checker 
#define EVSYS    (*(volatile EVSYS_t *) 0x0180)  // Event System 
#define NVM    (*(volatile NVM_t *) 0x01C0)  // Non-volatile Memory Controller 
#define ADCA    (*(volatile ADC_t *) 0x0200)  // Analog-to-Digital Converter 
#define ACA    (*(volatile AC_t *) 0x0380)  // Analog Comparator 
#define RTC    (*(volatile RTC_t *) 0x0400)  // Real-Time Counter 
#define TWIC    (*(volatile TWI_t *) 0x0480)  // Two-Wire Interface 
#define TWIE    (*(volatile TWI_t *) 0x04A0)  // Two-Wire Interface 
#define USB    (*(volatile USB_t *) 0x04C0)  // Universal Serial Bus 
#define PORTA    (*(volatile PORT_t *) 0x0600)  // I/O Ports 
#define PORTB    (*(volatile PORT_t *) 0x0620)  // I/O Ports 
#define PORTC    (*(volatile PORT_t *) 0x0640)  // I/O Ports 
#define PORTD    (*(volatile PORT_t *) 0x0660)  // I/O Ports 
#define PORTE    (*(volatile PORT_t *) 0x0680)  // I/O Ports 
#define PORTR    (*(volatile PORT_t *) 0x07E0)  // I/O Ports 
#define TCC0    (*(volatile TC0_t *) 0x0800)  // 16-bit Timer/Counter 0 
#define TCC2    (*(volatile TC2_t *) 0x0800)  // 16-bit Timer/Counter type 2 
#define TCC1    (*(volatile TC1_t *) 0x0840)  // 16-bit Timer/Counter 1 
#define AWEXC    (*(volatile AWEX_t *) 0x0880)  // Advanced Waveform Extension 
#define HIRESC    (*(volatile HIRES_t *) 0x0890)  // High-Resolution Extension 
#define USARTC0    (*(volatile USART_t *) 0x08A0)  // Universal Synchronous/Asynchronous Receiver/Transmitter 
#define USARTC1    (*(volatile USART_t *) 0x08B0)  // Universal Synchronous/Asynchronous Receiver/Transmitter 
#define SPIC    (*(volatile SPI_t *) 0x08C0)  // Serial Peripheral Interface 
#define IRCOM    (*(volatile IRCOM_t *) 0x08F8)  // IR Communication Module 
#define TCD0    (*(volatile TC0_t *) 0x0900)  // 16-bit Timer/Counter 0 
#define TCD2    (*(volatile TC2_t *) 0x0900)  // 16-bit Timer/Counter type 2 
#define USARTD0    (*(volatile USART_t *) 0x09A0)  // Universal Synchronous/Asynchronous Receiver/Transmitter 
#define SPID    (*(volatile SPI_t *) 0x09C0)  // Serial Peripheral Interface 
#define TCE0    (*(volatile TC0_t *) 0x0A00)  // 16-bit Timer/Counter 0 

// ========== Interrupt Vector Definitions ========== 
// Reset
#define RESET_vect (0+1)

// OSC interrupt vectors 
#define OSC_OSCF_vect      (1+1)  // Oscillator Failure Interrupt (NMI+1) 

// PORTC interrupt vectors 
#define PORTC_INT0_vect      (2+1)  // External Interrupt 0 
#define PORTC_INT1_vect      (3+1)  // External Interrupt 1 

// PORTR interrupt vectors 
#define PORTR_INT0_vect      (4+1)  // External Interrupt 0 
#define PORTR_INT1_vect      (5+1)  // External Interrupt 1 

// RTC interrupt vectors 
#define RTC_OVF_vect      (10+1)  // Overflow Interrupt 
#define RTC_COMP_vect      (11+1)  // Compare Interrupt 

// TWIC interrupt vectors 
#define TWIC_TWIS_vect      (12+1)  // TWI Slave Interrupt 
#define TWIC_TWIM_vect      (13+1)  // TWI Master Interrupt 

// TCC0 interrupt vectors 
#define TCC0_OVF_vect      (14+1)  // Overflow Interrupt 

// TCC2 interrupt vectors 
#define TCC2_LUNF_vect      (14+1)  // Low Byte Underflow Interrupt 

// TCC0 interrupt vectors 
#define TCC0_ERR_vect      (15+1)  // Error Interrupt 

// TCC2 interrupt vectors 
#define TCC2_HUNF_vect      (15+1)  // High Byte Underflow Interrupt 

// TCC0 interrupt vectors 
#define TCC0_CCA_vect      (16+1)  // Compare or Capture A Interrupt 

// TCC2 interrupt vectors 
#define TCC2_LCMPA_vect      (16+1)  // Low Byte Compare A Interrupt 

// TCC0 interrupt vectors 
#define TCC0_CCB_vect      (17+1)  // Compare or Capture B Interrupt 

// TCC2 interrupt vectors 
#define TCC2_LCMPB_vect      (17+1)  // Low Byte Compare B Interrupt 

// TCC0 interrupt vectors 
#define TCC0_CCC_vect      (18+1)  // Compare or Capture C Interrupt 

// TCC2 interrupt vectors 
#define TCC2_LCMPC_vect      (18+1)  // Low Byte Compare C Interrupt 

// TCC0 interrupt vectors 
#define TCC0_CCD_vect      (19+1)  // Compare or Capture D Interrupt 

// TCC2 interrupt vectors 
#define TCC2_LCMPD_vect      (19+1)  // Low Byte Compare D Interrupt 

// TCC1 interrupt vectors 
#define TCC1_OVF_vect      (20+1)  // Overflow Interrupt 
#define TCC1_ERR_vect      (21+1)  // Error Interrupt 
#define TCC1_CCA_vect      (22+1)  // Compare or Capture A Interrupt 
#define TCC1_CCB_vect      (23+1)  // Compare or Capture B Interrupt 

// SPIC interrupt vectors 
#define SPIC_INT_vect      (24+1)  // SPI Interrupt 

// USARTC0 interrupt vectors 
#define USARTC0_RXC_vect      (25+1)  // Reception Complete Interrupt 
#define USARTC0_DRE_vect      (26+1)  // Data Register Empty Interrupt 
#define USARTC0_TXC_vect      (27+1)  // Transmission Complete Interrupt 

// USARTC1 interrupt vectors 
#define USARTC1_RXC_vect      (28+1)  // Reception Complete Interrupt 
#define USARTC1_DRE_vect      (29+1)  // Data Register Empty Interrupt 
#define USARTC1_TXC_vect      (30+1)  // Transmission Complete Interrupt 

// NVM interrupt vectors 
#define NVM_EE_vect      (32+1)  // EE Interrupt 
#define NVM_SPM_vect      (33+1)  // SPM Interrupt 

// PORTB interrupt vectors 
#define PORTB_INT0_vect      (34+1)  // External Interrupt 0 
#define PORTB_INT1_vect      (35+1)  // External Interrupt 1 

// PORTE interrupt vectors 
#define PORTE_INT0_vect      (43+1)  // External Interrupt 0 
#define PORTE_INT1_vect      (44+1)  // External Interrupt 1 

// TWIE interrupt vectors 
#define TWIE_TWIS_vect      (45+1)  // TWI Slave Interrupt 
#define TWIE_TWIM_vect      (46+1)  // TWI Master Interrupt 

// TCE0 interrupt vectors 
#define TCE0_OVF_vect      (47+1)  // Overflow Interrupt 
#define TCE0_ERR_vect      (48+1)  // Error Interrupt 
#define TCE0_CCA_vect      (49+1)  // Compare or Capture A Interrupt 
#define TCE0_CCB_vect      (50+1)  // Compare or Capture B Interrupt 
#define TCE0_CCC_vect      (51+1)  // Compare or Capture C Interrupt 
#define TCE0_CCD_vect      (52+1)  // Compare or Capture D Interrupt 

// PORTD interrupt vectors 
#define PORTD_INT0_vect      (64+1)  // External Interrupt 0 
#define PORTD_INT1_vect      (65+1)  // External Interrupt 1 

// PORTA interrupt vectors 
#define PORTA_INT0_vect      (66+1)  // External Interrupt 0 
#define PORTA_INT1_vect      (67+1)  // External Interrupt 1 

// ACA interrupt vectors 
#define ACA_AC0_vect      (68+1)  // AC0 Interrupt 
#define ACA_AC1_vect      (69+1)  // AC1 Interrupt 
#define ACA_ACW_vect      (70+1)  // ACW Window Mode Interrupt 

// ADCA interrupt vectors 
#define ADCA_CH0_vect      (71+1)  // Interrupt 0 

// TCD0 interrupt vectors 
#define TCD0_OVF_vect      (77+1)  // Overflow Interrupt 

// TCD2 interrupt vectors 
#define TCD2_LUNF_vect      (77+1)  // Low Byte Underflow Interrupt 

// TCD0 interrupt vectors 
#define TCD0_ERR_vect      (78+1)  // Error Interrupt 

// TCD2 interrupt vectors 
#define TCD2_HUNF_vect      (78+1)  // High Byte Underflow Interrupt 

// TCD0 interrupt vectors 
#define TCD0_CCA_vect      (79+1)  // Compare or Capture A Interrupt 

// TCD2 interrupt vectors 
#define TCD2_LCMPA_vect      (79+1)  // Low Byte Compare A Interrupt 

// TCD0 interrupt vectors 
#define TCD0_CCB_vect      (80+1)  // Compare or Capture B Interrupt 

// TCD2 interrupt vectors 
#define TCD2_LCMPB_vect      (80+1)  // Low Byte Compare B Interrupt 

// TCD0 interrupt vectors 
#define TCD0_CCC_vect      (81+1)  // Compare or Capture C Interrupt 

// TCD2 interrupt vectors 
#define TCD2_LCMPC_vect      (81+1)  // Low Byte Compare C Interrupt 

// TCD0 interrupt vectors 
#define TCD0_CCD_vect      (82+1)  // Compare or Capture D Interrupt 

// TCD2 interrupt vectors 
#define TCD2_LCMPD_vect      (82+1)  // Low Byte Compare D Interrupt 

// SPID interrupt vectors 
#define SPID_INT_vect      (87+1)  // SPI Interrupt 

// USARTD0 interrupt vectors 
#define USARTD0_RXC_vect      (88+1)  // Reception Complete Interrupt 
#define USARTD0_DRE_vect      (89+1)  // Data Register Empty Interrupt 
#define USARTD0_TXC_vect      (90+1)  // Transmission Complete Interrupt 

// USB interrupt vectors 
#define USB_BUSEVENT_vect      (125+1)  // SOF, suspend, resume, reset bus event interrupts, crc, underflow, overflow and stall error interrupts 
#define USB_TRNCOMPL_vect      (126+1)  // Transaction complete interrupt 

#define _VECTOR_SIZE 4 // Size of individual vector. 
#define _VECTORS_SIZE (127 * _VECTOR_SIZE)

// ========== Constants ========== 

#define PROGMEM_START     (0x0000)
#define PROGMEM_SIZE      (36864)
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#define APP_SECTION_START     (0x0000)
#define APP_SECTION_SIZE      (32768)
#define APP_SECTION_PAGE_SIZE (256)
#define APP_SECTION_END       (APP_SECTION_START + APP_SECTION_SIZE - 1)

#define APPTABLE_SECTION_START     (0x7000)
#define APPTABLE_SECTION_SIZE      (4096)
#define APPTABLE_SECTION_PAGE_SIZE (256)
#define APPTABLE_SECTION_END       (APPTABLE_SECTION_START + APPTABLE_SECTION_SIZE - 1)

#define BOOT_SECTION_START     (0x8000)
#define BOOT_SECTION_SIZE      (4096)
#define BOOT_SECTION_PAGE_SIZE (256)
#define BOOT_SECTION_END       (BOOT_SECTION_START + BOOT_SECTION_SIZE - 1)

#define DATAMEM_START     (0x0000)
#define DATAMEM_SIZE      (12288)
#define DATAMEM_END       (DATAMEM_START + DATAMEM_SIZE - 1)

#define IO_START     (0x0000)
#define IO_SIZE      (4096)
#define IO_PAGE_SIZE (0)
#define IO_END       (IO_START + IO_SIZE - 1)

#define MAPPED_EEPROM_START     (0x1000)
#define MAPPED_EEPROM_SIZE      (1024)
#define MAPPED_EEPROM_PAGE_SIZE (0)
#define MAPPED_EEPROM_END       (MAPPED_EEPROM_START + MAPPED_EEPROM_SIZE - 1)

#define INTERNAL_SRAM_START     (0x2000)
#define INTERNAL_SRAM_SIZE      (4096)
#define INTERNAL_SRAM_PAGE_SIZE (0)
#define INTERNAL_SRAM_END       (INTERNAL_SRAM_START + INTERNAL_SRAM_SIZE - 1)

#define EEPROM_START     (0x0000)
#define EEPROM_SIZE      (1024)
#define EEPROM_PAGE_SIZE (32)
#define EEPROM_END       (EEPROM_START + EEPROM_SIZE - 1)

#define SIGNATURES_START     (0x0000)
#define SIGNATURES_SIZE      (3)
#define SIGNATURES_PAGE_SIZE (0)
#define SIGNATURES_END       (SIGNATURES_START + SIGNATURES_SIZE - 1)

#define FUSES_START     (0x0000)
#define FUSES_SIZE      (6)
#define FUSES_PAGE_SIZE (0)
#define FUSES_END       (FUSES_START + FUSES_SIZE - 1)

#define LOCKBITS_START     (0x0000)
#define LOCKBITS_SIZE      (1)
#define LOCKBITS_PAGE_SIZE (0)
#define LOCKBITS_END       (LOCKBITS_START + LOCKBITS_SIZE - 1)

#define USER_SIGNATURES_START     (0x0000)
#define USER_SIGNATURES_SIZE      (256)
#define USER_SIGNATURES_PAGE_SIZE (256)
#define USER_SIGNATURES_END       (USER_SIGNATURES_START + USER_SIGNATURES_SIZE - 1)

#define PROD_SIGNATURES_START     (0x0000)
#define PROD_SIGNATURES_SIZE      (64)
#define PROD_SIGNATURES_PAGE_SIZE (256)
#define PROD_SIGNATURES_END       (PROD_SIGNATURES_START + PROD_SIGNATURES_SIZE - 1)

#define FLASHSTART   PROGMEM_START
#define FLASHEND     PROGMEM_END
#define SPM_PAGESIZE 256
#define RAMSTART     INTERNAL_SRAM_START
#define RAMSIZE      INTERNAL_SRAM_SIZE
#define RAMEND       INTERNAL_SRAM_END
#define E2END        EEPROM_END
#define E2PAGESIZE   EEPROM_PAGE_SIZE

// ========== Signature ========== 
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x95
#define SIGNATURE_2 0x44

#endif

