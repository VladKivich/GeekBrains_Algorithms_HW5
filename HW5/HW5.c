#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int Stack[32];
int N = -1;

//Добавляем элемент.
void Push(int i)
{
	if (N < 32)
	{
		N++;
		Stack[N] = i;
	}
	else
		printf("Stack overflow");
}

//Переводим из десятичной в двоичную используя стек.
void IntegerToString(int X, int count)
{
	int temp = X >> count;
	if (temp != 0) 
	{
		if (temp & 1)
		{
			Push(1);
		}
		else
		{
			Push(0);
		}
		count++;
		IntegerToString(X, count);
	}
}

//Удаляем элемент.
int Pop()
{
	if (N != -1)
		return Stack[N--];
	else
		printf("Stack is empty");
}

int main()
{
	setlocale(LC_ALL, "Rus");

#pragma region Task_1

	////1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.

	//int a = 134;
	//IntegerToString(a, 0);

	//while (N != -1)
	//{
	//	printf("%d", Pop());
	//}

#pragma endregion

#pragma region Task_2



#pragma endregion



	getchar();
	return 0;
}