#ifndef __DYN_DEF__
#define __DYN_DEF__

//=======================================================
//                       Катоды
//    ___________________________________________
//   |    _     |     _    |     _    |     _    |
//   |   |_|    |    |_|   |    |_|   |    |_|   |
//   |   |_|    |    |_|   |    |_|   |    |_|   |
//   |DI_LED1_K1000|DI_LED1_K100 | DI_LED1_K10 |  DI_LED1_K1 |
//   |__________|__________|__________|__________|
//=======================================================
#define DI_LED1_K1		PORTA.1  // катоды ПЕРВОГО индикатора
#define DI_LED1_K10		PORTA.0  // * * * * * * * * * * * * *
#define DI_LED1_K100	PORTA.2  // * * * * * * * * * * * * *
//#define DI_LED1_K1000	PORTA.0  // * * * * * * * * * * * * *

//#define DI_LED2_K1		PORTA.1  // катоды ВТОРОГО индикатора  
//#define DI_LED2_K10		PORTA.0  // * * * * * * * * * * * * *  
//#define DI_LED2_K100	PORTA.2  // * * * * * * * * * * * * *  
//#define DI_LED2_K1000	PORTA.0  // * * * * * * * * * * * * *  
	

//======================	
//         Aноды
//           A
//         -----
//      F |     | B
//		  |  G  |
//         -----
//      E |     | C
//        |     |
//         ----- * 
//           D     H
//======================
#define DI_A	PORTB.7
#define DI_B	PORTB.5
#define DI_C	PORTB.4
#define DI_D	PORTB.1
#define DI_E	PORTB.0
#define DI_F	PORTB.6
#define DI_G	PORTB.2
#define DI_H	PORTB.3

//==========================================================
//           Дальше ничего не менять
//==========================================================


#define abs(x) ((x<0)? -x : x)
#define true	0xFF
#define false	0x00


//=============================
//           Разряды
//=============================
#define DI_p1		0
#define DI_p10		1
#define DI_p100		2
#define DI_p1000	3


//=============================
//           Индикаторы
//=============================
#define DI_LED1		0
#define DI_LED2		1


//=============================
//           Буквы
//=============================
#define DI_code_A	17
#define DI_code_b	193
#define DI_code_C	99
#define DI_code_c	229
#define DI_code_d	133
#define DI_code_E	97
#define DI_code_F	113
#define DI_code_G	67
#define DI_code_H	145
#define DI_code_h	209
#define DI_code_i	223
#define DI_code_J	135
#define DI_code_L	227
#define DI_code_n	213
#define DI_code_o	197
#define DI_code_P	49
#define DI_code_r	245
#define DI_code_S	73
#define DI_code_t	225
#define DI_code_U	131
#define DI_code_u	199


//=============================
//    Специальные символы
//=============================
#define DI_minus 253
#define DI_null 255
#define DI_fail 239
#define DI_dot 254

#endif