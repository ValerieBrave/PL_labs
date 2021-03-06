// Lab7_PL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "Dictionary.h"
#include <iostream>
#include <Windows.h>
using namespace Dictionary;
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::cout << "------------БИБЛИОТЕКА СЛОВАРЕЙ-------------\n";
	
#ifdef TEST_CREATE_01
	{
		try
		{
			Instance d = Create("123456789123456789123", 5);
		}
		catch (const char* e)
		{
			std::cout << e <<'\n';
		}
	}
#endif 
#ifdef TEST_CREATE_02
	{
		try
		{
			Instance d = Create("1234567891233", 101);
		}
		catch (const char* e)
		{
			std::cout << e << '\n';
		}
	}
#endif 
#ifdef TEST_ADDENTRY_03
	{
		try
		{
			Instance d = Create("12345789123", 1);
			AddEntry(d, new Entry("Овсянка", 11));
			AddEntry(d, new Entry("Манка", 12));
		}
		catch (const char* e)
		{
			std::cout << e << '\n';
		}
	}
#endif
#ifdef TEST_ADDENTRY_04
	{
		try
		{
			Instance d = Create("12345789123", 5);
			AddEntry(d, new Entry("Овсянка", 11));
			AddEntry(d, new Entry("Манка", 11));
		}
		catch (const char* e)
		{
			std::cout << e << '\n';
		}
	}
#endif
#ifdef	TEST_GETENTRY_05
	{
		try
		{
			Instance d = Create("12345789123", 5);
			AddEntry(d, new Entry("Овсянка", 11));
			AddEntry(d, new Entry("Манка", 12));
			Entry entry = GetEntry(d, 13);
		}
		catch (const char* e)
		{
			std::cout << e << '\n';
		}
	}
#endif
#ifdef	TEST_DELENTRY_06
	{
		try
		{
			Instance d = Create("12345789123", 5);
			AddEntry(d, new Entry("Овсянка", 11));
			AddEntry(d, new Entry("Манка", 12));
			DelEntry(d, 13);
		}
		catch (const char* e)
		{
			std::cout << e << '\n';
		}
	}
#endif
#ifdef	TEST_UPDENTRY_07
	{
		try
		{
			Instance d = Create("12345789123", 5);
			AddEntry(d, new Entry("Овсянка", 11));
			AddEntry(d, new Entry("Манка", 12));
			UpdEntry(d, 13, Entry("Рис", 10));
		}
		catch (const char* e)
		{
			std::cout << e << '\n';
		}
	}
#endif
#ifdef	TEST_UPDENTRY_08
	{
		try
		{
			Instance d = Create("12345789123", 5);
			AddEntry(d, new Entry("Овсянка", 11));
			AddEntry(d, new Entry("Манка", 12));
			UpdEntry(d, 12, Entry("Рис", 11));
		}
		catch (const char* e)
		{
			std::cout << e << '\n';
		}
	}
#endif
#ifdef TEST_DICTIONARY
	{
		try
		{
			Instance d1 = Create("Преподаватели",10);
			AddEntry(d1, new Entry("Наркевич", 11));
			AddEntry(d1, new Entry("Жиляк", 12));
			AddEntry(d1, new Entry("Щербович", 13));
			AddEntry(d1, new Entry("Юрча", 14));
			AddEntry(d1, new Entry("Пацей", 15));
			AddEntry(d1, new Entry("Ловенецкая", 16));
			AddEntry(d1, new Entry("Белодед", 17));
			Instance d2 = Create("Студенты", 10);
			AddEntry(d2, new Entry("Свердлова", 21));
			AddEntry(d2, new Entry("Гринцевич", 22));
			AddEntry(d2, new Entry("Заблоцкий", 23));
			AddEntry(d2, new Entry("Пестов", 24));
			AddEntry(d2, new Entry("Ожилевський", 25));
			AddEntry(d2, new Entry("Ельсуков", 26));
			AddEntry(d2, new Entry("Конон", 27));
			DelEntry(d1, 17);
			DelEntry(d2, 23);
			Entry e1 = GetEntry(d1, 13);
			Entry e2 = GetEntry(d2, 21);
			UpdEntry(d1, 11, Entry("Чевжик",10));
			UpdEntry(d2, 24, Entry("Перевозчиков", 20));
			Print(d1);
			Print(d2);
			Delete(d1);
			Delete(d2);
		}
		catch (const char* e)
		{
			std::cout << e << '\n';
		}
	}
#endif
	Instance d1;
	try
	{
		d1 = Create("Каши", 5);
		//Entry e1 = Entry("Овсянка", 11), e2 = Entry("Манка", 12);
		AddEntry(d1, new Entry("Овсянка", 11));
		AddEntry(d1, new Entry("Манка", 12));
		AddEntry(d1, new Entry("Гречка", 13));
		
		//Entry e1 = GetEntry(d1, 11);
		DelEntry(d1, 11);
		//UpdEntry(d1, 12, Entry("Перловка", 15));
		int m = 0;
	}
	catch (const char* e)
	{
		std::cout << e << '\n';
	}
	
	Print(d1);
	system("pause");
	return 0;
}


