// Lab3_PL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

char lf[] = "SmelovaValeria2000";
char rf[] = "СмеловаВалерия2000";
char lr[] = "Смелова2000Valeria";

wchar_t Llf[] = L"SmelovaValeria2000";
wchar_t Lrf[] = L"СмеловаВалерия2000";
wchar_t Llr[] = L"Смелова2000Valeria";
void func(char *destination, char *sourse)
{
	
    int size = strlen(sourse);
	for (int i = 0;i<size ; i++)
	{
		*(destination + i) = *(sourse + i) - 32;
	}
	
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char sourse[]="абвгдежзиклмн", destination[]="абвгдежзиклмн";
	func(destination, sourse);
	std::cout << "Строка: \t" << sourse << '\n';
	std::cout << "Измененная строка: \t" << destination<<'\n';
	system("pause");
	return 0;
}


