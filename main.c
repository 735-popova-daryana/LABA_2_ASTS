/*******************************************************************************
*
* Copyright (C) 2019 TUSUR, FB, Popova Dariyana
*
* File              : main.cpp
* Compiler          : IAR EWB IDE 6.30
* Version           : 1.0
* Created File      : 02.06.2019
* Last modified     : 08.06.2019
*
* Support mail      : dariyana@mail.ru
* Target MCU        : MCU: Milandr 1986BE9x
*
* Description       : Work with stack
*
********************************************************************************/
/*
CODE_SELECTION:
0 - ������������ ����� � ������� ������� PUSH
1 - ������ ��������� � ������� R13
2 - ������������ ��������� R13 � R1
3 - ������������ ����� ��� ������ ��������
4 - �������� ���������� ������� ����� ����
5 - ������������ �� �������������� ����
*/
#define CODE_SELECTION 5 

int recursion(void){
  return recursion();
}

int send_params(int a, int b, int c, int d, int e, int f){
  return (a+b+c+d+e+f);    
}

void main()
{

#if CODE_SELECTION == 0 
    while(1) //(Warning)
    {
      __asm(
            "PUSH {R1}" 
            );
    }

#elif CODE_SELECTION == 1
    __asm( "MOV R13, #10"); // R13 = 10 (ERROR)

#elif CODE_SELECTION == 2
    __asm( "MOV R1, #8888\n" "ADD R13, R1"); // R1 = 8888, R13=(R1+R13) (WARNING)

#elif CODE_SELECTION == 3
    recursion();

#elif CODE_SELECTION == 4
    int sum = send_params(0x1,0x2,0x3,0x4,0x5,0x6); // Stack params

#elif CODE_SELECTION == 5
    __asm( "MOV R0, #0x2\n" "MSR CONTROL, R0"); // CONTROL
#endif

  return;
}

