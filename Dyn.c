//========================================================
//          ���������� ������������ ����������
//
// ���������� �������������� ������ ������������ ���
// ������� � ������ � ������������ ����� Dyn_def.h
//
// � ������� 
//		unsigned char DI_Digit[4][DI_Second_Led+1]
// ����������� ���� �������� ��������� �� ����������
// ������� Dyn_Indicate() ���������� �� �������
// � ��������� ���������������� ������� �������
//========================================================
#include "Dyn.h"

unsigned char 	kIndex;
unsigned char DI_Digit[4][2];
char digits[10] = {3, 159, 37, 13, 153, 73, 65, 31, 1, 9};


//=========================================================
//                      Dyn_SignOut()
//                   ���������� �������
//                ���������� ���� �� ������
//=========================================================
void Dyn_SignOut(unsigned char dig)
{
	DI_A = dig & 128;
	DI_B = dig & 64;
	DI_C = dig & 32;
	DI_D = dig & 16;
	DI_E = dig & 8;
	DI_F = dig & 4;
	DI_G = dig & 2;
	DI_H = dig & 1;
}


//=========================================================
//                      Dyn_Indicate()
//                   ���������� ��������
//        ����������� �� �������� ���� � ����� �����
//=========================================================
void Dyn_Indicate()
{	
	//�������� �����(������) ��������(���������) ������
	//kIndex = DI_LED1_K1 | (DI_LED1_K10<<1) | (DI_LED1_K100<<2) | (DI_LED1_K1000<<3);
	#ifndef DI_LED1_K1
		return;
	#endif
	kIndex = DI_LED1_K1;
	#ifdef DI_LED1_K10
		kIndex |= DI_LED1_K10 << 1;
	#endif
	
	#ifdef DI_LED1_K100
		kIndex |= DI_LED1_K100 << 2;
	#endif
	
	#ifdef DI_LED1_K1000
		kIndex |= DI_LED1_K1000 << 3;
	#endif
	
	
	
	#ifdef DI_LED2_K1
		kIndex |= DI_LED2_K1 << 4;
	#endif
	
	#ifdef DI_LED2_K10
		kIndex |= DI_LED2_K10 << 5;
	#endif
	
	#ifdef DI_LED2_K100
		kIndex |= DI_LED2_K100 << 6;
	#endif
	
	#ifdef DI_LED2_K1000
		kIndex |= DI_LED2_K1000 << 7;
	#endif
	
	//if(DI_Second_Led > 0) kIndex = kIndex | (DI_LED2_K1<<4) | (DI_LED2_K10<<5) | (DI_LED2_K100<<6) | (DI_LED2_K1000<<7);
	
	switch(kIndex){
		case 1: {	
					//���������� ������� ������� ����������
					DI_LED1_K1 = 0;
					#ifdef DI_LED1_K10
						Dyn_SignOut(DI_Digit[DI_p10][DI_LED1]);
						DI_LED1_K10 = 1;
					#else
						#ifdef DI_LED2_K1
							Dyn_SignOut(DI_Digit[DI_p1][DI_LED2]);
							DI_LED2_K1 = 1;
						#else
							Dyn_SignOut(DI_Digit[DI_p1][DI_LED1]);
							DI_LED1_K1 = 1;
						#endif
					#endif
					break;
				}
		#ifdef DI_LED1_K10
		case 2: {	
					//���������� ����� ������� ����������
					DI_LED1_K10 = 0;
					#ifdef DI_LED1_K100
						Dyn_SignOut(DI_Digit[DI_p100][DI_LED1]);
						DI_LED1_K100 = 1;
					#else
						#ifdef DI_LED2_K1
							Dyn_SignOut(DI_Digit[DI_p1][DI_LED2]);
							DI_LED2_K1 = 1;
						#else
							Dyn_SignOut(DI_Digit[DI_p1][DI_LED1]);
							DI_LED1_K1 = 1;
						#endif
					#endif
					break;
				}
		#endif
		#ifdef DI_LED1_K100
		case 4: {	
					//���������� ������ ������� ����������
					DI_LED1_K100 = 0;
					#ifdef DI_LED1_K1000
						Dyn_SignOut(DI_Digit[DI_p1000][DI_LED1]);
						DI_LED1_K1000 = 1;
					#else
						#ifdef DI_LED2_K1
							Dyn_SignOut(DI_Digit[DI_p1][DI_LED2]);
							DI_LED2_K1 = 1;
						#else
							Dyn_SignOut(DI_Digit[DI_p1][DI_LED1]);
							DI_LED1_K1 = 1;
						#endif
					#endif
					break;
				}
		#endif
		#ifdef DI_LED1_K1000
		case 8: {	
					DI_LED1_K1000 = 0;
					#ifdef DI_LED2_K1
						Dyn_SignOut(DI_Digit[DI_p1][DI_LED2]);
						DI_LED2_K1 = 1;
					#else
						Dyn_SignOut(DI_Digit[DI_p1][DI_LED1]);
						DI_LED1_K1 = 1;
					#endif
					break;
				}
		#endif
		#ifdef DI_LED2_K1
		case 16: {	
					//���������� ������� ������� ����������
					DI_LED2_K1 = 0;
					#ifdef DI_LED2_K10
						Dyn_SignOut(DI_Digit[DI_p10][DI_LED2]);
						DI_LED2_K10 = 1;
					#else
						Dyn_SignOut(DI_Digit[DI_p1][DI_LED1]);
						DI_LED1_K1 = 1;
					#endif
					break;
				}
		#endif
		#ifdef DI_LED2_K10
		case 32: {	
					//���������� ����� ������� ����������
					DI_LED2_K10 = 0;
					#ifdef DI_LED2_K100
						Dyn_SignOut(DI_Digit[DI_p100][DI_LED2]);
						DI_LED2_K100 = 1;
					#else
						Dyn_SignOut(DI_Digit[DI_p1][DI_LED1]);
						DI_LED1_K1 = 1;
					#endif
					break;
				}
		#endif
		#ifdef DI_LED2_K100
		case 64: {	
					//���������� ������ ������� ����������
					DI_LED2_K100 = 0;
					#ifdef DI_LED2_K1000
						Dyn_SignOut(DI_Digit[DI_p1000][DI_LED2]);
						DI_LED2_K1000 = 1;
					#else
						Dyn_SignOut(DI_Digit[DI_p1][DI_LED1]);
						DI_LED1_K1 = 1;
					#endif
					break;
				}	
		#endif
		#ifdef DI_LED2_K1000
		case 128: {	//������� �������� ���� ����������� ��������
					DI_LED2_K1000 = 0;
					Dyn_SignOut(DI_Digit[DI_p1][DI_LED1]);
					DI_LED1_K1 = 1;
					break;
				}
		#endif
		default: {//���� ����� ������������ ��������, �������� �������
					DI_LED1_K1 = 0;
					#ifdef DI_LED1_K10
						DI_LED1_K10 = 0;
					#endif
					
					#ifdef DI_LED1_K100
						DI_LED1_K100 = 0;
					#endif
					
					#ifdef DI_LED1_K1000
						DI_LED1_K1000 = 0;
					#endif
					
					#ifdef DI_LED2_K1
						DI_LED2_K1 = 0;
					#endif
					
					#ifdef DI_LED2_K10
						DI_LED2_K10 = 0;
					#endif
					
					#ifdef DI_LED2_K100
						DI_LED2_K100 = 0;
					#endif
					
					#ifdef DI_LED2_K1000
						DI_LED2_K1000 = 0;
					#endif
					Dyn_SignOut(DI_Digit[DI_p1][DI_LED1]);
					DI_LED1_K1 = 1;
				}
	}
}

//=========================================================
//                      Dyn_Code()
//                   ��������� ���������
//               ����������� ����� � �������
//=========================================================
void Dyn_Code(unsigned char p1000, unsigned char p100, unsigned char p10, unsigned char p1, unsigned char led)
{	
	DI_Digit[DI_p1][led] = p1;
	DI_Digit[DI_p10][led] = p10;
	DI_Digit[DI_p100][led] = p100;
	DI_Digit[DI_p1000][led] = p1000;
}

void Dyn_Clear(char led)
{
	Dyn_Code(DI_null, DI_null, DI_null, DI_null, led);
}

void Dyn_Number(int value, char dot, char led)
{
	unsigned char p[5];
	char i;
	char sign = 0;
	char e = 0;
	char digcnt;
	
	#ifndef DI_LED2_K1
		if(led > 0) return;
	#endif
	
	if(led == 0)
	{
		#ifdef DI_LED1_K1000
			digcnt = 4;
		#else
			#ifdef DI_LED1_K100
				digcnt = 3;
			#else
				#ifdef DI_LED1_K10
					digcnt = 2;
				#else
					digcnt = 1;
				#endif
			#endif
		#endif
	}
	else
	{
		#ifdef DI_LED2_K1000
			digcnt = 4;
		#else
			#ifdef DI_LED2_K100
				digcnt = 3;
			#else
				#ifdef DI_LED2_K10
					digcnt = 2;
				#else
					digcnt = 1;
				#endif
			#endif
		#endif
	}
	
	for(i = digcnt; i < 5; i++)// ��� �������������� ����� � ������� ��������� ��������
	{
		p[i] = DI_null;
	}
	
	if(value < 0)
	{
		sign = 1;
		value = -value;
	}
	
	for(i = 0; i < digcnt; i++)// ��������� ����� �� �������
	{
		p[i] = digits[value % 10];
		value /= 10;
	}
	
	i = digcnt - 1;
	while(i > 0)// ������� ���������� ���� �������
	{
		if((p[i+1] == DI_null) && (p[i] == digits[0])) p[i] = DI_null;
		i--;
	}
	
	if(value > 0)// ���� ����� �� ����������, �������� �������
	{
		p[digcnt - 1] = DI_code_E;
	}
	
	if(sign && (p[digcnt - 1] != DI_null)) // ���� ���� �� ����������, �������� �������
	{
		p[digcnt - 1] = DI_code_E;
	}
	
	if(sign)// ������� ����
	{
		i = digcnt - 1;
		while(i != 0)
		{
			if((p[i] == DI_null) && (p[i-1] != DI_null)) 
			{
				p[i] = DI_minus;
				break;
			}
			i--;
		}
	}
	if(dot) p[0] &= DI_dot;
	Dyn_Code(p[3], p[2], p[1], p[0], led);
}
/*
void Dyn_Number(float value, char accuracy, char led)
{
	char sign = 0;
	unsigned int i;
	unsigned int f;
	char L[4] = {DI_null, DI_null, DI_null, DI_null};
	char cnt = 0;
	char p = 0;
	
	if(accuracy >= digcnt)
	{
		Dyn_Number(value, led);
		return;
	}
	
	if(value < 0)
	{
		sign = 1;
		value = -value;
		cnt++;
	}
	i = value;
	while(i > 0)
	{
		cnt++;
		i /= 10;
	}
	i = value;
	p = cnt;
	if((i < 1000) && !sign)
	{
		value -= i;
		do
		{
			value *= 10;
			cnt++;
			if(cnt == 4)
			{
				value += 0.5;
				break;
			}
		}while(value - (int)value != 0);
		f = value;
	}
	
	
	if(i > 999)
	{
		p1 = i % 10;
		i /= 10;
		
		p10 = i % 10;
		i /= 10;
		
		p100 = i % 10;
		p1000 = i / 10;
	}
	else if(i > 99)
	{
		p10 = i % 10;
		i /= 10;
		
		p100 = i % 10;
		i /= 10;
		
		p1000 = i / 10;
	}
	else if(i > 9)
	{
		p100 = i % 10;
		i /= 10;
		
		p1000 = i / 10;
	}
	else
	{
		p100 = i % 10;
	}
	
	DI_Digit[DI_p1][led] = p1;
	DI_Digit[DI_p10][led] = p10;
	DI_Digit[DI_p100][led] = p100;
	DI_Digit[DI_p1000][led] = p1000;
}*/