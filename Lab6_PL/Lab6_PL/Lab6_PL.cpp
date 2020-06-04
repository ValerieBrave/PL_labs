// Lab6_PL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;
struct Date
{
	day dd;
	month mm;
	year yyyy;
};
struct Student
{
	int course;
	int group;
	int subgroup;
	char fullname[100];
	Student(int c, int g, int s,  const char* f)
	{
		course = c;
		group = g;
		subgroup = s;
		strcpy_s(fullname, f);
	}
	Student()
	{

	}
};
bool operator < (Date t1, Date t2)
{
	bool b = (t1.dd < t2.dd && t1.mm <= t2.mm && t1.yyyy <= t2.yyyy) || (t1.dd <= t2.dd && t1.mm < t2.mm && t1.yyyy <= t2.yyyy) || (t1.dd <= t2.dd && t1.mm <= t2.mm && t1.yyyy < t2.yyyy);
	return b;
}
bool operator > (Date t1, Date t2)
{
	bool b = (t1.dd > t2.dd && t1.mm >= t2.mm && t1.yyyy >= t2.yyyy) || (t1.dd >= t2.dd && t1.mm > t2.mm && t1.yyyy >= t2.yyyy) || (t1.dd >= t2.dd && t1.mm >= t2.mm && t1.yyyy > t2.yyyy);
	return b;
}
bool operator == (Date t1, Date t2)
{
	bool b = (t1.dd==t2.dd && t1.mm==t2.mm && t1.yyyy== t2.yyyy);
	return b;
}
bool  operator -= (Student st, int a)
{
	bool b = (st.course == a);
	return b;
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Date date1 = {7,1,1980};
	Date date2 = { 7,2,1993};
	Date date3 = { 7,1,1980 };
	if (date1 < date2) std::cout << "true\n";
	else std::cout << "false\n";
	if (date1 > date2) std::cout << "true\n";
	else std::cout << "false\n";
	if (date1 == date2) std::cout << "true\n";
	else std::cout << "false\n";
	if (date1 == date3) std::cout << "true\n";
	else std::cout << "false\n";
	std::cout << "----------------------------------\n";
	Student people[4] = { Student(1, 4, 1, "Иванов Сергей Иванович"),Student(2, 2, 2, "Юндов Петр Дмитриевич"),
	Student(4, 9, 1, "Дриневский Алексей Анатольевич"),Student(1, 5, 2, "Шаманский Дмитрий Витальевич") };
	for (int i = 0; i < 4; i++)
	{
		if (people[i] -= 1) std::cout << "Student of first course: " << people[i].fullname << '\n';
	}
	system("pause");
   return 0; 
}

