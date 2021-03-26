/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : PeakCounter
Version : 1
Date    : 18.02.2020
Author  : A.Timofeev
Company : TAHTK
Comments: 


Chip type               : ATmega16A
Program type            : Application
AVR Core Clock frequency: 16,000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/
#include "config.h" // ��� ���������� � ������������ �������

#define SN 001


#define ALLOW_BLINK


#ifdef USE_UART
char uart_str[100];
#endif
char g_bSkipIndicate = 0; // ����� ��� ��������� (� �������)

unsigned int g_uiCntBtnShut, g_uiCntBtnStart;
enum BTN_STAT { btnPressed, btnHolded, btnExtra, btnNull } g_BtnShut, g_BtnStart;
char g_cStarted;                        // ���� ����������� ��������

eeprom char eeStartCounter;             // ������� ������
eeprom char eeInitEEPROM;               // ����������-������� ��� ����� ���������������� EEPROM
eeprom char eeKeyNum[KYENUM_LENGTH];	// �������� �����
eeprom char eeShutLimit;                // ����� ���������
eeprom int eeShutLength;                // ����� ��������

char g_cBlinkAllow;	// �������� ������� ����������
char blinkcnt = 0;

#ifdef SKIP_REUSE_BAD_KEY
char prevcard[MAX_DEVICES][9];
#endif

char masterkey[MAX_DEVICES][9];
char masterkeycnt;

// ������ �����������
// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
	TCNT0=0x64;
	if(!g_bSkipIndicate) Dyn_Indicate();
	g_bSkipIndicate = !g_bSkipIndicate;
}

// Timer1 overflow interrupt service routine
interrupt[TIM1_OVF] void timer1_ovf_isr(void)
{
	TCNT1 = 0xD8F0;
	if(BTN_SHUT)   // ������ ������ ������
	{
		g_uiCntBtnShut++;     // ������� ������������ �������
		if((g_uiCntBtnShut > LONG_PRESS) && (g_uiCntBtnShut < LONG_LONG_PRESS))  // ���� ����� ������
		{
			//g_uiCntBtnShut = LONG_PRESS;   // ������ �� �������
			g_BtnShut = btnHolded;         // ������ ���������
		}
		else if(g_uiCntBtnShut > LONG_LONG_PRESS)
		{
			g_uiCntBtnShut = LONG_LONG_PRESS;   // ������ �� �������
			g_BtnShut = btnExtra;         // ������ ������
		}
	}
	else            // ��������� ������
	{
		if((g_uiCntBtnShut > SHORT_PRESS) && (g_uiCntBtnShut < LONG_PRESS))  // ���� ������ ������ � �������� (�� �������)
		{
			g_BtnShut = btnPressed;       // ������ ������
		}
		else if(g_BtnShut == btnHolded)   // ���� ������ ���������
		{
			g_BtnShut = btnNull;          // ���������� ������
		}
		g_uiCntBtnShut = 0;               // ���������� ������� ���� ������ ��������
	}
	
	if(BTN_START)
	{
		g_uiCntBtnStart++;
		if(g_uiCntBtnStart > LONG_PRESS)
		{
			g_uiCntBtnStart = LONG_PRESS;
			g_BtnStart = btnHolded;
		}
	}
	else
	{
		if((g_uiCntBtnStart > SHORT_PRESS) && (g_uiCntBtnStart < LONG_PRESS))
		{
			g_BtnStart = btnPressed;
		}
		else if(g_BtnStart == btnHolded)
		{
			g_BtnStart = btnNull;
		}
		g_uiCntBtnStart = 0;
	}
	
	if(g_cBlinkAllow)                    // ������� ��� ������� ������
	{
		if(++blinkcnt > 200) blinkcnt = 0;
	}else blinkcnt = 150;
}

int g_Delay;      // ���� � ���������� �������� ������ 0 ������ �������
// ������ ������������ ������������ ������� ������
// Timer2 overflow interrupt service routine
interrupt [TIM2_OVF] void timer2_ovf_isr(void)
{
	TCNT2=0x38;
	
	if(g_Delay > 0) {MARKER = 1;g_Delay--;} else MARKER = 0;
}

// ��������� ����
char KeyCheck()
{
	char i;
	
	#ifdef SKIP_REUSE_BAD_KEY
	char skipcard = 0;
	#endif
	//return KEY_VALID;    // ���� ��� ������� ����� ��������� �������� �����
	// �������� ������
	masterkeycnt = 0;
	for(i = 0; i < KYENUM_LENGTH; i++)
	{
		if(masterkey[0][i] == rom_code[0][i]){
			if(++masterkeycnt == 5) break;
			#ifdef USE_UART
			sprintf(uart_str, "Key[%i] %02X\n\r", i, rom_code[0][i]);
			puts(uart_str);
			#endif
			continue;
		}
		#ifdef SKIP_REUSE_BAD_KEY
		if(prevcard[0][i] == rom_code[0][i])      // ��������� ������������� �� ���� ���� � ���������� ���
		{
			skipcard++;                            
		}
		#endif
		if(rom_code[0][i] != eeKeyNum[i]) // ���� �� ������
		{
			BEEP_ERR;
			#ifdef SKIP_REUSE_BAD_KEY
			for(i = 0; i < KYENUM_LENGTH; i++)
			{
				prevcard[0][i] = rom_code[0][i];
			}
			if(skipcard == KYENUM_LENGTH) return 1; // �������� ����� ���� �� ������������
			#endif
			#ifdef USE_UART
			sprintf(uart_str, "master key count = %i\n\r", masterkeycnt);
			puts(uart_str);
			#endif
			return 0;
		}
		
	}
	#ifdef USE_UART
	sprintf(uart_str, "master key count = %i\n\r", masterkeycnt);
	puts(uart_str);
	#endif
	BEEP_OK;
	return KEY_VALID;
}

// �������� ��������� ���� � EEPROM
void TrySaveKey()
{
	char i = 0;
	char timer = 0;
	while(timer < 10) // � ��������� 1 ��� ������ 15 ��� ����� ��� ���������� �����
	{
		Dyn_Code(DI_null, DI_minus, DI_minus, DI_minus, 0);
		if(g_BtnShut == btnPressed) // onClick()
		{
			ResetBtnShut // ����� ��������� ������ (����������)
			timer = 0;
			if(++i == 15) // ������� ���������� �������
			{
				Dyn_Clear(0);
				
				if(w1_search(SEARCH_ROM, rom_code) > 0) // ��������� ��� ���� ��������
				{
					for(i = 0; i < KYENUM_LENGTH; i++) // ���������� �����
					{
						eeKeyNum[i] = rom_code[0][i];
					}
					Dyn_Code(DI_null, DI_code_S, DI_code_E, DI_code_t, 0);
					BEEP_OK;
					delay_ms(2000);
					return;
				}
				else
				{
					Dyn_Code(DI_null, DI_code_E, DI_code_r, DI_code_r, 0);
					BEEP_ERR;
				}
			}
			
		}
		timer++;
		delay_ms(100);
	}
	delay_ms(2000);
}

// ����� ��������� ������ ���������	
void ModeLimit()
{
	unsigned _cnt = 0;
	char limit = eeShutLimit;
	ResetBtnShut
	g_cBlinkAllow = 0;
	while(++_cnt < 700) // ������� �����������
	{
		if(g_BtnShut == btnPressed)   // ��������� ����������
		{
			limit++;
			ResetBtnShut
			_cnt = 0;
		}
		else if(g_BtnShut == btnHolded)    // ������� ����������
		{
			limit++;
			delay_ms(70);
			_cnt = 0;
		}
		
		if(limit > 99) limit = 1;        // ���������� ������� �� ������ ����� � �������
		if((blinkcnt > 50) || (g_BtnShut == btnHolded)) Dyn_Number(limit, 0, 0); else Dyn_Clear(0); // ���� ���������, ������ ������
		if((_cnt > 200) && (w1_search(SEARCH_ROM, rom_code) > 0)) break;
		delay_ms(10);
	}
	eeShutLimit = limit;      // ��������� ���������
	#ifdef ALLOW_BLINK
	g_cBlinkAllow = 1;
	#endif
	BEEP_OK;
	Dyn_Code(DI_null, DI_code_S, DI_code_E, DI_code_t, 0);   // SEt
	delay_ms(1000);
}	

// ����� ��������� ����� ��������
void ModeShutLength()
{
	unsigned _cnt = 0;
	int len = eeShutLength;
	
	g_cBlinkAllow = 0;
	while(++_cnt < 700) // ������� �����������
	{
		if(g_BtnShut == btnPressed)   // ��������� ����������
		{
			len++;
			ResetBtnShut
			_cnt = 0;
		}
		else if(g_BtnShut == btnHolded)    // ������� ����������
		{
			len++;
			delay_ms(70);
			_cnt = 0;
		}
		if(len > 300) len = 50;
		if((blinkcnt > 50) || (g_BtnShut == btnHolded)) Dyn_Number(len, 0, 0); else Dyn_Clear(0); // ���� ���������, ������ ������
		if((_cnt > 200) && (w1_search(SEARCH_ROM, rom_code) > 0)) break;    // ���� ��������� ����, �������. �� �� ������ ��� ����� 200 ������, ���� �� ���������� ��� �����
		delay_ms(10);
	}
	eeShutLength = len;
	#ifdef ALLOW_BLINK
	g_cBlinkAllow = 1;
	#endif
	BEEP_OK;
	Dyn_Code(DI_null, DI_code_S, DI_code_E, DI_code_t, 0);   // SEt
	delay_ms(1000);
}

void main(void)
{	
	char Key;
	unsigned int uiStartCounter = 0;
	char cShutLimit;
	int delay; // ��������� ���������� ��� ���������� ������ ��������
	char timer = 0;
	unsigned int keyTimer;
	
	// ����� ������-�����
	masterkey[0][0] = 0x01;
	masterkey[0][1] = 0x82;
	masterkey[0][2] = 0xDC;
	masterkey[0][3] = 0xC5;
	masterkey[0][4] = 0x00;
	masterkey[0][5] = 0x00;
	
	if(eeInitEEPROM)
	{
		eeInitEEPROM = 0;
		eeShutLimit = 6;
		eeStartCounter = 0;
		eeShutLength = 150;
	}
	
	ChipInit();
	
	w1_init();
		
	Dyn_Code(DI_null, digits[SN/100%10], digits[SN/10%10], digits[SN%10], 0);   // ��� ������ ������� ���������� ������ �� 500��
	delay_ms(500);
	
	Dyn_Clear(0);
	cShutLimit = 0;
	g_cStarted = 0;
	ResetBtnShut
	ResetBtnStart
	#ifdef ALLOW_BLINK
	g_cBlinkAllow = 1;
	#endif
	
	while(1)
	{
		//*************************************************************************************************************************
		// ��������� �����?
		// ������ � ����� ��������� ������ ���������
		if(!g_cStarted && (g_BtnShut != btnHolded) && (w1_search(SEARCH_ROM, rom_code) > 0))
		{
			ResetBtnShut
			Key = KeyCheck();
			if(Key == KEY_VALID){
				BEEP_OK
				ModeLimit();
				ResetBtnShut
				ResetBtnStart
			}else if(Key == 0){
				TrySaveKey();
				ResetBtnShut
				ResetBtnStart
			}
		}
		//*************************************************************************************************************************
		// ��������� �����
		// ���� � ����� ������ �������� ������
		if(!g_cStarted && (g_BtnStart == btnHolded)){
			ResetBtnShut
			g_cBlinkAllow = 0;
			BEEP_OK
			timer = 0;
			uiStartCounter = eeStartCounter;
			while(timer < 100) // 10 ������ �� �������� �������
			{
				if((blinkcnt > 50) || (g_BtnShut == btnHolded)) Dyn_Number(uiStartCounter, 0, 0); else Dyn_Clear(0);
				if((w1_search(SEARCH_ROM, rom_code) > 0) && (KeyCheck() == KEY_VALID)){ // �������� ����, ��������� ����� ��������
					eeStartCounter = 0;
					uiStartCounter = 0;
					Dyn_Code(DI_null, DI_code_r, DI_code_S, DI_code_t, 0);
					break;
				}
				
				timer++;
				delay_ms(100);
			}
			#ifdef ALLOW_BLINK
			g_cBlinkAllow = 1;
			#endif
			ResetBtnShut
			ResetBtnStart
			delay_ms(1000);
		}
		//*************************************************************************************************************************
		// ������ ��������� ������ + ��������� �����
		// ���� � ����� ��������� ����� ��������
		if(!g_cStarted && (g_BtnShut == btnExtra)){               // ����� ��������� ����� ������ ������ ��������� �� ���������
			Dyn_Code(DI_null, DI_minus, DI_minus, DI_minus, 0);    // ���������� ��� ������ ������� �����, ����� �������� � ����� ������ ��������� (������ �� �����)
			keyTimer = 10000;
			while((g_BtnShut == btnExtra) || (keyTimer > 0)){   // ���� ����� ���� ������ �����
				if (g_BtnShut != btnExtra) keyTimer--;
				if((w1_search(SEARCH_ROM, rom_code) > 0) && (KeyCheck() == KEY_VALID)){
					BEEP_OK
					ResetBtnShut
					Dyn_Number(eeShutLength, 0, 0);
					delay_ms(1000);
					ModeShutLength();
					keyTimer = 0;
					ResetBtnShut
					ResetBtnStart
				}
			}
		}
		//*************************************************************************************************************************
		// ������������ �������� �� ������ ������
		if(g_cStarted && (g_uiCntBtnShut > 0) && (g_Delay == 0)){   // ��������� ������� ������ ���� �������� ���������� (g_Delay == 0)
			delay = eeShutLength;         // �������� �� ��������� ����������
			g_Delay = delay * 9.885;      // ������������ ������� ��� ��������
			
			if(--cShutLimit == 0){        // ���� �������� ��������� �������, ��������� ����
				BEEP_END
				g_cStarted = 0;
				#ifdef ALLOW_BLINK
				g_cBlinkAllow = 1;
				#endif
				eeStartCounter++;
			}else while(g_uiCntBtnShut){       // ���� ������ �� ��������, ������ �� ������. ���������� �������
				Dyn_Number(cShutLimit, 0, 0);	
				delay_ms(10);
			}
			ResetBtnShut
		}
		//*************************************************************************************************************************
		// �����/����
		if(g_BtnStart == btnPressed){
			ResetBtnStart
			if(g_cStarted) {
				g_cStarted = 0; 
				cShutLimit = 0;
				#ifdef ALLOW_BLINK
				g_cBlinkAllow = 1;
				#endif
			}else {
				g_cBlinkAllow = 0;
				g_cStarted = 1;
				cShutLimit = eeShutLimit;
				BEEP_OK
				ResetBtnShut
			}
		}
		//*************************************************************************************************************************
		// ���������
		if((blinkcnt > 100) || (g_BtnShut == btnHolded)) Dyn_Number(cShutLimit, 0, 0); else Dyn_Clear(0);
		//*************************************************************************************************************************
	}
}
