// Lab14_PL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Error.h"
#include "In.h"
#include "Parm.h"
#include "Log.h"
#include "FST.h"
#include "Parse.h"
#include "IT.h"
#include "LT.h"
#include "Automats.h"
#include "Semantica.h"

//bool PolishNotation(int lextable_pos, LT::LexTable &lexlable, IT::IdTable & idtable)
//{
//
//}
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	Log::LOG lg = Log::INITLOG;
	
	FST::FST_lexems auto_array[] = {FST::FST_lexems(LEX_MAIN, FST::FST("", 5, FST::FST::LEXEM, GRAPH_MAIN)),
									FST::FST_lexems(LEX_DECLARE, FST::FST("", 8, FST::FST::LEXEM, GRAPH_DECLARE)),
									FST::FST_lexems(LEX_FUNCTION, FST::FST("", 9, FST::FST::LEXEM, GRAPH_FUNCTION)),
									FST::FST_lexems(LEX_STRLEN, FST::FST("", 7, FST::FST::LIB_NAME, GRAPH_STRLEN)),
									FST::FST_lexems(LEX_SUBSTR, FST::FST("", 7, FST::FST::LIB_NAME, GRAPH_SUBSTR)),
									FST::FST_lexems(LEX_PRINT, FST::FST("", 6, FST::FST::LIB_NAME, GRAPH_PRINT)),
									FST::FST_lexems(LEX_INTEGER, FST::FST("", 8, FST::FST::LEXEM, GRAPH_INTEGER)),
									FST::FST_lexems(LEX_STRING, FST::FST("", 7, FST::FST::LEXEM, GRAPH_STRING)),
									FST::FST_lexems(LEX_RETURN, FST::FST("", 7, FST::FST::LEXEM, GRAPH_RETURN)),
									FST::FST_lexems(LEX_ID, FST::FST("", 3, FST::FST::IDENTIFICATOR, GRAPH_IDENTIFICATOR)),
									FST::FST_lexems(LEX_LITERAL, FST::FST("", 3, FST::FST::NUM_LITERAL, GRAPH_NUMBER)),
									FST::FST_lexems(LEX_LITERAL, FST::FST("", 5, FST::FST::STR_LITERAL, GRAPH_STR))};
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		lg = Log::getlog(parm.log);
		Log::WriteLog(lg);
		Log::WriteParm(lg, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(lg, in);
		in.text=in.del_useless_blanks();
		int auto_amount = sizeof(auto_array) / sizeof(FST::FST_lexems);
		Parse::Words all_units = Parse::find_lexems(in);
		LT::LexTable LT = Parse::auto_check(all_units, auto_array, auto_amount, in, lg);
		IT::IdTable iTab = Sem::getIDTable(LT, all_units);
		LT.print_coded(lg);
		iTab.print(lg);
		Log::Close(lg);
	}
	catch (Error::ERROR er)
	{
		Log::WriteError(lg, er);
		std::cout << er.id << " "<< er.message << " "  << er.inext.line;
		Log::Close(lg);
	}
   return 0; 
}
