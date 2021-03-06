// Lab8_PL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Dictionary.h"
using namespace Dictionary;
int main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		Instance d1 = Create("Преподаватели", 10);
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
		UpdEntry(d1, 11, Entry("Чевжик", 10));
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
	return 0;
}
    


