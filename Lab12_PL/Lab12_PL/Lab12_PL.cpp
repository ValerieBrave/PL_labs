// Lab12_PL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "FST.h"

int main()
{
	setlocale(LC_ALL, "rus");
	FST::FST fst1("proc     end", 30, GRAPH);
	FST::FST fst2("proc start(cos())  end", 30, GRAPH);
	FST::FST fst3("proc start(sin(x))   end", 30, GRAPH);
	FST::FST fst4("proc  start(cos(yy)) end", 30, GRAPH);
	FST::FST fst5("proc start(sin(xxx))    end", 30, GRAPH);
	FST::FST fst6("proc start(cos())start(sin(x))    end", 30, GRAPH);
	FST::FST fst7("proc  start(cos())start(cos()) end", 30, GRAPH);
	//---------------------------------------------------------------------
	FST::FST fst8("proc  start(cos())start(cos()) en", 30, GRAPH);
	//---------------------------------------------------------------------
	FST::FST fst9("proc  startV(cos(yy)) end", 30, GRAPH);
	FST::FST fst10("proc start(sin(xxx))    Mend", 30, GRAPH);
	//---------------------------------------------------------------------
	if (FST::execute(fst1)) std::cout << "1) Разобрана\n";
	else std::cout << "Ошибка разбора\n";
	if (FST::execute(fst2)) std::cout << "2) Разобрана\n";
	else std::cout << "Ошибка разбора\n";
	if (FST::execute(fst3)) std::cout << "3) Разобрана\n";
	else std::cout << "Ошибка разбора\n";
	if (FST::execute(fst4)) std::cout << "4) Разобрана\n";
	else std::cout << "Ошибка разбора\n";
	if (FST::execute(fst5)) std::cout << "5) Разобрана\n";
	else std::cout << "Ошибка разбора\n";
	if (FST::execute(fst6)) std::cout << "6) Разобрана\n";
	else std::cout << "Ошибка разбора\n";
	if (FST::execute(fst7)) std::cout << "7) Разобрана\n";
	else std::cout << "7)Ошибка разбора\n";
	if (FST::execute(fst8)) std::cout << "8) Разобрана\n";
	else std::cout << "8)Ошибка разбора\n";
	if (FST::execute(fst9)) std::cout << "9) Разобрана\n";
	else std::cout << "9)Ошибка разбора\n";
	if (FST::execute(fst10)) std::cout << "10) Разобрана\n";
	else std::cout << "10)Ошибка разбора\n";
	system("pause");
   return 0; 
}

