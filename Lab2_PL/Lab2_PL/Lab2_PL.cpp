// Lab2_PL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"

int mul(int a, int b);
int sub(int a, int b);
int sum(int a, int b);

int main()
{
	int a = 5, b = 4;
	std::cout << "a=" << a << "\t b=" << b << '\n';
	std::cout << "a+b=" << sum(a, b) << '\n';
	std::cout << "a-b=" << sub(a, b) << '\n';
	std::cout << "a*b=" << mul(a, b) << '\n';
	system("pause");
	return 0;
}

