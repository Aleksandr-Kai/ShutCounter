/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
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
#include "config.h" // Все переменные и генерируемые функции

#define SN 001


#define ALLOW_BLINK


#ifdef USE_UART
char uart_str[100];
#endif
char g_bSkipIndicate = 0; // Нужно для индикации (в таймере)

unsigned int g_uiCntBtnShut, g_uiCntBtnStart;
enum BTN_STAT { btnPressed, btnHolded, btnExtra, btnNull } g_BtnShut, g_BtnStart;
char g_cStarted;                        // Флаг разрешающий стрельбу

eeprom char eeStartCounter;             // Счетчик циклов
eeprom char eeInitEEPROM;               // Переменная-признак что нужно инициализировать EEPROM
eeprom char eeKeyNum[KYENUM_LENGTH];	// Хранение ключа
eeprom char eeShutLimit;                // Лимит выстрелов
eeprom int eeShutLength;                // Длина импульса

char g_cBlinkAllow;	// Включить мигание индикатора
char blinkcnt = 0;

#ifdef SKIP_REUSE_BAD_KEY
char prevcard[MAX_DEVICES][9];
#endif

char masterkey[MAX_DEVICES][9];
char masterkeycnt;
unsigned int ShutInterval = 0;

// Таймер индикаторов
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
	if(BTN_SHUT)   // Нажата кнопка спуска
	{
		g_uiCntBtnShut++;     // Считаем длительность нажатия
		if(g_uiCntBtnShut > LONG_PRESS)
		{
			g_uiCntBtnShut = LONG_PRESS;   // Дальше не считаем
			g_BtnShut = btnHolded;         // Статус удержания
		}
		
	}
	else            // Отпустили кнопку
	{
		if((g_uiCntBtnShut > SHORT_PRESS) && (g_uiCntBtnShut < LONG_PRESS))  // Если кнопка нажата и отпущена (не дребезг)
		{
			g_BtnShut = btnPressed;       // Статус нажата
		}
		else if(g_BtnShut == btnHolded)   // Если статус УДЕРЖАНИЕ
		{
			g_BtnShut = btnNull;          // Сбрасываем статус
		}
		g_uiCntBtnShut = 0;               // Сбрасываем счетчик если кнопка отпущена
	}
	
	if(BTN_START)
	{
		g_uiCntBtnStart++;
		if((g_uiCntBtnStart > LONG_PRESS) && (g_uiCntBtnStart <= LONG_LONG_PRESS))
		{
			//g_uiCntBtnStart = LONG_PRESS;
			g_BtnStart = btnHolded;
		}
		else if(g_uiCntBtnStart > LONG_LONG_PRESS)
		{
			g_uiCntBtnStart = LONG_LONG_PRESS;   // Дальше не считаем
			g_BtnStart = btnExtra;         // Статус экстра
		}
	}
	else
	{
		if((g_uiCntBtnStart > SHORT_PRESS) && (g_uiCntBtnStart < LONG_PRESS))
		{
			g_BtnStart = btnPressed;
		}
		else if((g_BtnStart == btnHolded) || (g_BtnStart == btnExtra))
		{
			g_BtnStart = btnNull;
		}
		g_uiCntBtnStart = 0;
	}
	
	if(g_cBlinkAllow)                    // Счетчик для мигания цифрой
	{
		if(++blinkcnt > 200) blinkcnt = 0;
	}else blinkcnt = 150;
}

int g_Delay;      // Пока в переменной значение больше 0 держим уровень
// Таймер формирования длительности импулса спуска
// Timer2 overflow interrupt service routine
interrupt [TIM2_OVF] void timer2_ovf_isr(void)
{
	TCNT2=0x38;
	
	if(g_Delay > 0) {MARKER = 1;g_Delay--;if (g_Delay == 0) ShutInterval = SHUT_INTERVAL;} else MARKER = 0;
	if(ShutInterval > 0) ShutInterval--;
}

// Проверяем ключ
char KeyCheck()
{
	char i;
	
	#ifdef SKIP_REUSE_BAD_KEY
	char skipcard = 0;
	#endif
	//return KEY_VALID;    // Если для отладки нужно отключить проверку ключа
	// Проверка номера
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
		if(prevcard[0][i] == rom_code[0][i])      // Проверяем использовался ли этот ключ в предыдущий раз
		{
			skipcard++;                            
		}
		#endif
		if(rom_code[0][i] != eeKeyNum[i]) // Ключ не принят
		{
			BEEP_ERR;
			#ifdef SKIP_REUSE_BAD_KEY
			for(i = 0; i < KYENUM_LENGTH; i++)
			{
				prevcard[0][i] = rom_code[0][i];
			}
			if(skipcard == KYENUM_LENGTH) return 1; // Повторно левый ключ не обрабатываем
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

// Пытаемся сохранить ключ в EEPROM
void TrySaveKey()
{
	char i = 0;
	char timer = 0;
	while(timer < 10) // с таймаутом 1 сек нажать 15 раз спуск для сохранения ключа
	{
		Dyn_Code(DI_null, DI_minus, DI_minus, DI_minus, 0);
		if(g_BtnStart == btnPressed) // onClick()
		{
			ResetBtnStart // сброс состояния кнопки (обработано)
			timer = 0;
			if(++i == 15) // считаем количество нажатий
			{
				Dyn_Clear(0);
				
				if(w1_search(SEARCH_ROM, rom_code) > 0) // Проверяем что ключ приложен
				{
					for(i = 0; i < KYENUM_LENGTH; i++) // Сохранение ключа
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

// Режим установки лимита выстрелов	
void ModeLimit()
{
	unsigned _cnt = 0;
	char limit = eeShutLimit;
	ResetBtnStart
	g_cBlinkAllow = 0;
	while(++_cnt < 700) // Таймаут бездействия
	{
		if(g_BtnStart == btnPressed)   // Медленное увеличение
		{
			limit++;
			ResetBtnStart
			_cnt = 0;
		}
		else if((g_BtnStart == btnHolded) || (g_BtnStart == btnExtra))    // Быстрое увеличение
		{
			limit++;
			delay_ms(70);
			_cnt = 0;
		}
		
		if(limit > 99) limit = 1;        // Количество спусков не больше числа в условии
		if((blinkcnt > 50) || (g_BtnStart == btnHolded) || (g_BtnStart == btnExtra)) Dyn_Number(limit, 0, 0); else Dyn_Clear(0); // Если разрешено, мигаем числом
		if((_cnt > 200) && (w1_search(SEARCH_ROM, rom_code) > 0)) break;
		delay_ms(10);
	}
	eeShutLimit = limit;      // Сохраняем изменения
	#ifdef ALLOW_BLINK
	g_cBlinkAllow = 1;
	#endif
	BEEP_OK;
	Dyn_Code(DI_null, DI_code_S, DI_code_E, DI_code_t, 0);   // SEt
	delay_ms(1000);
}	

// Режим установки длины импульса
void ModeShutLength()
{
	unsigned _cnt = 0;
	int len = eeShutLength;
	
	g_cBlinkAllow = 0;
	while(++_cnt < 700) // Таймаут бездействия
	{
		if(g_BtnStart == btnPressed)   // Медленное увеличение
		{
			len++;
			ResetBtnStart
			_cnt = 0;
		}
		else if((g_BtnStart == btnHolded) || (g_BtnStart == btnExtra))    // Быстрое увеличение
		{
			len++;
			delay_ms(70);
			_cnt = 0;
		}
		if(len > 300) len = 50;
		if((blinkcnt > 50) || (g_BtnStart == btnHolded) || (g_BtnStart == btnExtra)) Dyn_Number(len, 0, 0); else Dyn_Clear(0); // Если разрешено, мигаем числом
		if((_cnt > 200) && (w1_search(SEARCH_ROM, rom_code) > 0)) break;    // Если приложили ключ, выходим. Но не раньше чем через 200 циклов, чтоб не вывалиться при входе
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
	int delay; // временная переменная для вычисления точной задержки
	char timer = 0;
	unsigned int keyTimer;
	
	// Номер мастер-ключа
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
		
	Dyn_Code(DI_null, digits[SN/100%10], digits[SN/10%10], digits[SN%10], 0);   // при подаче питания отображаем версию на 500мс
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
		// Приложена метка?
		// Входим в режим изменения лимита выстрелов
		if(!g_cStarted && (g_BtnStart != btnHolded) && (w1_search(SEARCH_ROM, rom_code) > 0))
		{
			ResetBtnStart
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
		// Удержание Старт
		// Вход в режим сброса счетчика циклов
		if(!g_cStarted && (g_BtnStart == btnHolded)){
			g_cBlinkAllow = 0;
			BEEP_OK
			timer = 0;
			uiStartCounter = eeStartCounter;
			while((timer < 100) && (g_BtnStart != btnExtra)) // 10 секунд на принятие решения
			{
				if((blinkcnt > 50) || (g_BtnStart == btnHolded)) Dyn_Number(uiStartCounter, 0, 0); else Dyn_Clear(0);
				if((w1_search(SEARCH_ROM, rom_code) > 0) && (KeyCheck() == KEY_VALID)){ // приложен ключ, выполнить сброс счетчика
					eeStartCounter = 0;
					uiStartCounter = 0;
					Dyn_Code(DI_null, DI_code_r, DI_code_S, DI_code_t, 0);
					break;
				}
				
				timer++;
				delay_ms(100);
			}
			if (g_BtnStart == btnHolded) {
				#ifdef ALLOW_BLINK
				g_cBlinkAllow = 1;
				#endif
				ResetBtnShut
				ResetBtnStart
				delay_ms(1000);
			}
		}
		//*************************************************************************************************************************
		// Долгое удержание спуска + приложена метка
		// Вход в режим настройки длины импульса
		if(!g_cStarted && (g_BtnStart == btnExtra)){               // Нужно дождаться когда статус кнопки изменится на удержание
			Dyn_Code(DI_null, DI_minus, DI_minus, DI_minus, 0);    // Отображаем что готовы принять метку, иначе ввалимся в режим лимита выстрелов (просто по метке)
			keyTimer = 10000;
			while((g_BtnStart == btnExtra) || (keyTimer > 0)){   // ждем метку пока держим спуск
				if (g_BtnStart != btnExtra) keyTimer--;
				if((w1_search(SEARCH_ROM, rom_code) > 0) && (KeyCheck() == KEY_VALID)){
					BEEP_OK
					ResetBtnStart
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
		// Формирование импульса по кнопке спуска
		if(g_cStarted && (g_uiCntBtnShut > 0) && (g_Delay == 0) && (ShutInterval == 0)){   // Следующий выстрел только если завершен предыдущий (g_Delay == 0)
			delay = eeShutLength;         // задержку во временную переменную
			g_Delay = delay * 9.885;      // корректируем счетчик для точности
			
			if(--cShutLimit == 0){        // Если выполнен последний выстрел, завершаем цикл
				BEEP_END
				g_cStarted = 0;
				#ifdef ALLOW_BLINK
				g_cBlinkAllow = 1;
				#endif
				eeStartCounter++;
			}else while(g_uiCntBtnShut){       // Пока кнопку не отпустим, дальше не пойдем. Исключение очереди
				Dyn_Number(cShutLimit, 0, 0);	
				delay_ms(10);
			}
			ResetBtnShut
			ResetBtnStart
		}
		//*************************************************************************************************************************
		// Старт/Стоп
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
				ResetBtnStart
			}
		}
		//*************************************************************************************************************************
		// Индикация
		if((blinkcnt > 100) || (g_BtnStart == btnHolded) || (g_BtnStart == btnExtra)) Dyn_Number(cShutLimit, 0, 0); else Dyn_Clear(0);
		//*************************************************************************************************************************
	}
}
