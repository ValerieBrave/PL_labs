// LP_Lab_c.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#pragma comment(lib, "..\\Debug\\LP_Lab_a.lib")

extern "C"
{
	int __stdcall getmax(int *arr, int n);
	int __stdcall getmin(int *arr, int n);
}

int main() {
	int arr[] = { -1, -36, -90, -47, -22, -12, -100, -99, -69, -17, 20 };
	int max = getmax(&arr[0], 11);
	int min = getmin(&arr[0], 11);
	std::cout << "getmax - getmin = " << max - min << std::endl << std::endl;

	system("pause");

	return 0;
}
