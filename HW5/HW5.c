#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>
#include <ctype.h>

#pragma region ������� � ���������� ��� ������_1

//C��� �� ������ �������.
int ArrayStack[32];

//��������� ��� �������.
int N = -1;

//������� ���������� �������� � ����
void Push(int i)
{
	if (N < 32)
	{
		N++;
		ArrayStack[N] = i;
	}
	else
		printf("Stack overflow");
}

//��������� �� ���������� � �������� ��������� ����.
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

//������� ������� �� �����
int Pop()
{
	if (N != -1)
		return ArrayStack[N--];
	else
		printf("Stack is empty");
}

#pragma endregion

#pragma region ������� � ���������� ��� ������_2

//������
#define T char
//������� ����� ��� ��� ���������.
typedef struct MyElement Element;
typedef struct MyStack Stack;

//������� �����.
struct MyElement
{
	T value;
	Element *Next;
};

//���� �� ������ ������������ ������.
struct MyStack
{
	Element *LastElement;
	int CurrentSize;
	int MaxSize;
};

//��������� ������� � �����.
void StackPush(T value, Stack* Stack)
{
	if (Stack == NULL) return;
	else if (Stack->CurrentSize < Stack->MaxSize)
	{
		Element *New = (Element*)malloc(sizeof(Element));
		New->value = value;
		New->Next = NULL;

		if (Stack->LastElement == NULL)
		{
			Stack->LastElement = New;
		}
		else
		{
			New->Next = Stack->LastElement;
			Stack->LastElement = New;
		}
		Stack->CurrentSize++;
	}
	else
	{
		printf("Stack is Full!");
	}
}

//������� ������� �� �����.
T StackPop(Stack* Stack)
{
	if (Stack == NULL || Stack->CurrentSize == 0) return;
	//printf("Element # %d has value %d\n", Stack->CurrentSize, Stack->LastElement->value);
	T Temp = Stack->LastElement->value;
	Stack->LastElement = Stack->LastElement->Next;
	Stack->CurrentSize--;
	return Temp;
}

//������� ������� ����� ����. ������� ����������� ����� ����������. ������ ������� ��� ������� ������ ������ �� �������� (
Stack* CreateNewStack(int MaxSize)
{
	Stack* S = (Stack*)malloc(sizeof(Element) * MaxSize);
	if (S != NULL)
	{
		S->MaxSize = MaxSize;
		S->CurrentSize = 0;
		S->LastElement = NULL;
		return S;
	}
	else
	{
		printf("Not enought memory");
		return NULL;
	}

}

//������� � ������� �������� �����.
void PrintStack(Stack* S)
{
	if (S == NULL) return;
	Element * current = S->LastElement;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->Next;
	}
}

#pragma endregion

#pragma region ������� � ���������� ��� ������_3

//������� ��������� "����������" ���� ������.
int BracketCheck(char Bracket, Stack *Open)
{
	int Result = StackPop(Open) + Bracket;
	switch (Result)
	{
	case 184:
	case 81:
	case 248:
		return 1;
	default:
		return 0;
	}
}

//������� ��������� ������������������ ������.
void Brackets(char String[])
{
	Stack *Open = CreateNewStack(strlen(String));
	int Flag = 1;

	for (int i = 0; i < strlen(String) & Flag == 1; i++)
	{
		switch (String[i])
		{
		case '(':
		case '{':
		case '[':
			StackPush(String[i], Open);
			break;

		case ')':
		case '}':
		case ']':
			Flag = BracketCheck(String[i], Open);
			break;
		}
	}

	if (Flag == 1 & Open->CurrentSize == 0)
	{
		printf("Brackets is Right!");
	}
	else
		printf("Brackets is Wrong!");
}

#pragma endregion

#pragma region ������� � ���������� ��� ������_4

//����� �������� ����� �����(����������� ������)
Stack* StackCopy(Stack* Source)
{
	Stack* Result = (Stack*)malloc(sizeof(Element) * Source->MaxSize);
	if (Result != NULL)
	{
		Result->LastElement = NULL;
		Result->MaxSize = Source->MaxSize;
		Result->CurrentSize = 0;

		Element *Current = Source->LastElement;

		T* Array = (T*) malloc(sizeof(T)*Source->MaxSize);

		int counter = 0;

		for (int i = 0; i < Source->MaxSize & Current != NULL; i++)
		{
			Array[i] = Current->value;
			Current = Current->Next;
			counter = i;
		}

		for (int k = counter; k >=0 ; k--)
		{
			StackPush(Array[k], Result);
		}
		return Result;
	}
	else
	{
		return NULL;
	}
}

#pragma endregion

#pragma region ������� � ���������� ��� ������_6

//������
#define C char

//������� ����� ��� ��� ���������.
typedef struct QueueCell Cell;
typedef struct MyQueue Queue;

//������� �������.
struct QueueCell
{
	C value;
	Cell *Next;
};

//������� �� ������ ������������ ������.
struct MyQueue
{
	Cell *FirstCell;
	int CurrentSize;
	int MaxSize;
};

//������� ���������� � �������.
void Enqueue(C value, Queue* Queue)
{
	if (Queue == NULL) return;

	else if (Queue->CurrentSize < Queue->MaxSize)
	{
		Cell *New = (Cell*)malloc(sizeof(Cell));
		New->value = value;
		New->Next = NULL;

		if (Queue->FirstCell == NULL)
		{
			Queue->FirstCell = New;
		}
		else
		{
			Cell *Temp = Queue->FirstCell;
			while (Temp->Next != NULL)
			{
				Temp = Temp->Next;
			}
			Temp->Next = New;
		}
		Queue->CurrentSize++;
	}
	else
	{
		printf("Queue is Full!");
	}
}

//������� �������� �� �������.
C Dequeue(Queue* Queue)
{
	if (Queue == NULL || Queue->CurrentSize == 0) return;
	//printf("Element # %d has value %c\n", Queue->CurrentSize, Queue->FirstCell->value);
	C Temp = Queue->FirstCell->value;
	Queue->FirstCell = Queue->FirstCell->Next;
	Queue->CurrentSize--;
	return Temp;
}

//�������� �������.
Queue* CreateQueue(int MaxSize)
{
	Queue* Q = (Queue*)malloc(sizeof(Cell) * MaxSize);
	Q->MaxSize = MaxSize;
	Q->CurrentSize = 0;
	Q->FirstCell = NULL;
	return Q;
}

//������� ������ ������� � �������.
void PrintQueue(Queue* Q)
{
	if (Q == NULL) return;
	Cell * current = Q->FirstCell;
	while (current != NULL)
	{
		printf("%c ", current->value);
		current = current->Next;
	}
}

#pragma endregion

#pragma region ������� � ���������� ��� ������_5

//������� �������� ���������� ������.
char* DeleteBrackets(char String[])
{
	char* Result = String;

	for (int i = 0; i < strlen(String); i++)
	{
		switch (String[i])
		{
			case '(':
			case '{':
			case '[':
				Result[i] = ' ';
				break;

			default:
				break;
		}
	}
	return Result;
}

//������� �������� �� ��������� ������ ��������������� ��������� � �����������.
void Prefix(char String[], Stack* Stack, Queue* Queue)
{
	//C������ �������������� ������� ��� ������ � �������.
	struct MyQueue* TempQueue = CreateQueue(strlen(String));

	int Counter = 0;
	int Number = 0;

	int Flag = 0;

	for (int i = 0; i < strlen(String); i++)
	{
		if (isdigit(String[i]))
		{
			switch (Flag)
			{
				case 0:
					Enqueue(' ', Queue);
					Enqueue(String[i], Queue);
					Flag = 1;
					Counter+=2;
					break;
				case 1: 
					Enqueue(String[i], Queue);
					Counter++;
					break;
			}
		}
		else 
		{
			Flag = 0;

			if (String[i] != ' ')
			{
				switch (String[i])
				{
					case ')':
					case '}':
					case ']':
						while (Counter > 0)
						{
							Enqueue(Dequeue(Queue), TempQueue);
							Counter--;
						}
						Enqueue(StackPop(Stack), TempQueue);
						break;

					default:
						StackPush(String[i], Stack);
						break;
				}
			}
		}
	}
	PrintQueue(TempQueue);
}

#pragma endregion

int main()
{

	setlocale(LC_ALL, "Rus");

#pragma region Task_1

	////1. ����������� ������� �� ���������� � �������� ������� ��������� � �������������� �����.

	int a = 134;
	IntegerToString(a, 0);

	while (N != -1)
	{
		printf("%d", Pop());
	}
	printf("\n");

#pragma endregion

#pragma region Task_2

	//2. �������� � ��������� ����������� ����� �� ������ ������������ ������� �������� �� ��������� ������. 
	//���� ������ �� ����������, �� ��������� ��������������� ���������. 
	//������������ ������� ��������, ����� ������ �� ����� ���������� (����������� �������� ���������� ������).

	////�� ������ ������.
	//Stack *NewStack = CreateNewStack(100000000000000000);

	//������ ������.
	Stack *NewStack = CreateNewStack(10);


	StackPush(1, NewStack);
	StackPush(2, NewStack);
	StackPush(3, NewStack);
	StackPush(4, NewStack);
	StackPush(5, NewStack);

	PrintStack(NewStack);

	/*printf("\n");

	StackPop(NewStack);
	StackPop(NewStack);
	StackPop(NewStack);
	StackPop(NewStack);*/

	printf("\n");


#pragma endregion

#pragma region Task_3

	//3. �������� ���������, ������� ����������, �������� �� ��������� ��������� ������������������ ����������. 
	//������� ���������� ��������� ���������: (), ([])(), {}(), ([{}]), ������������ � )(, ())({), (, ])}), ([(]) ��� ������ [,(,{.
	//�������� : (2 + (2 * 2)) ���[2 / {5 * (4 + 7)}]

	char RightBracket[] = "(2 + [2 *[] 2] - {5 / 2})";
	char WrongBracket[] = "(2 + [2 * 2]] - {{5 / 2})";

	Brackets(RightBracket);
	//Brackets(WrongBracket);
	printf("\n");

	//printf(" [ =  %d\n", '['); //91
	//printf(" ] =  %d\n", ']'); //93
	//printf(" ( =  %d\n", '('); //40
	//printf(" ) =  %d\n", ')'); //41
	//printf(" { =  %d\n", '{'); //123
	//printf(" } =  %d\n", '}'); //125


#pragma endregion

#pragma region Task_4

	//4. *������� �������, ���������� ����������� ������ (�� ���� ������� � ������ ����� ������������ ������, ��� �������� ������� ������).
	
	Stack *Copy = StackCopy(NewStack);

	StackPop(Copy);
	PrintStack(Copy);
	printf("\n");
	PrintStack(NewStack);
	printf("\n");

#pragma endregion

#pragma region Task_5
	//5. **����������� �������� �������� �� ��������� ������ ��������������� ��������� � �����������.

	char Example[] = "((((1 + 2) * (3 - 4)) / 10) - 5)";

	char* Res = DeleteBrackets(Example);

	Stack *S = CreateNewStack(strlen(Res));
	Queue *Q = CreateQueue(strlen(Res));

	Prefix(Res, S, Q);

	printf("\n");

#pragma endregion

#pragma region Task_6

	////6. *����������� �������.

	Queue *NewQueue = CreateQueue(10);

	Enqueue('a', NewQueue);
	Enqueue('b', NewQueue);
	Enqueue('c', NewQueue);
	Enqueue('d', NewQueue);
	Enqueue('e', NewQueue);

	PrintQueue(NewQueue);

	Dequeue(NewQueue);
	Dequeue(NewQueue);
	Dequeue(NewQueue);
	Dequeue(NewQueue);

#pragma endregion

	getchar();
	return 0;
}