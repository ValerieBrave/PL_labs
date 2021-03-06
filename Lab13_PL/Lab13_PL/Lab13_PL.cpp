// Lab13_PL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Error.h"
#include "In.h"
#include "Parm.h"
#include "Log.h"
#include "FST.h"
#include "Parse.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	Log::LOG lg = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		lg = Log::getlog(parm.log);
		Log::WriteLog(lg);
		Log::WriteParm(lg, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(lg, in);
		Parse::auto_check(in, lg);
		Log::Close(lg);
	}
	catch (Error::ERROR er)
	{
		Log::WriteError(lg, er);
	}
    return 0; 
}


