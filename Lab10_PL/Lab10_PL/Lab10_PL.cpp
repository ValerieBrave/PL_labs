// Lab10_PL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
//#include <Winbase.h>
#include <iostream>

#include "Error.h"
#include "Parm.h"
#include "In.h"
#include "Log.h"
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	/*LPWSTR buffer = new WCHAR[_MAX_PATH];
	GetCurrentDirectory(sizeof(buffer), buffer);*/
	
	/*try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		std::cout << "in: " << parm.in << " out:" << parm.out << " log:" << parm.log << '\n';
	}
	catch (Error::ERROR er) { std::cout << "Error: " << er.id << ": " << er.message << '\n'; }*/
	
	//In::IN *in = new In::IN();
	Log::LOG lg = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		lg = Log::getlog(parm.log);
		//char c1[] = "hello", c2[] = "world", c3[]="";
		Log::WriteLog(lg);
		Log::WriteParm(lg, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(lg, in);
		Log::Close(lg);
		int m = 0;
	}
	catch(Error::ERROR er)
	{ 
		//std::cout << "Error: " << er.id << ": " << er.message << " line:" << er.inext.line << " position:" << er.inext.col<< '\n';
		Log::WriteError(lg, er);
	}
	system("pause");
	return 0;
}

/*try { throw ERROR_THROW(100); } catch (Error::ERROR er) {std::cout << "Error: " << er.id << ": " << er.message << '\n';}
	std::cout << "-----------------\n";
	try { throw ERROR_THROW_IN(100,7,11); }
	catch (Error::ERROR er) { std::cout << "Error: " << er.id << ": " << er.message << " line:" << er.inext.line << " position:" << er.inext.col << '\n'; }*/
//"-in:C:\Users\valerie_brave\Desktop\Языки Программирования\Lab10_PL\Debug\Test.txt"