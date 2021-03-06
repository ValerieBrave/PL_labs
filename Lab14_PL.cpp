// Lab14_PL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stack>
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
#include "GRB.h"
#include "MFST.h"

int priority(char op)
{
	int pr = 0;
	switch (op)
	{
	case '(': pr = 1; break;
	case '+': pr = 2; break;
	case '-': pr = 2; break;
	case '*': pr = 3; break;
	case '/': pr = 3; break;
	}
	return pr;
}
bool PolishNotation(int lextable_pos, LT::LexTable &lextable, IT::IdTable &idtable)
{
	/*ДОБАВИТЬ ОБРАБОТКУ ЛИТЕРАЛОВ*/
	bool converted = true;
	std::stack <LT::Entry> operations;
	int i = lextable_pos, ires = 0, k = lextable_pos, commas = 0, params = 0;
	while (lextable.table[k].lexema[0] != LEX_SEMOCOLON) k++;
	LT::Entry * expression = new LT::Entry[k - lextable_pos];
	while (lextable.table[i].lexema[0] != LEX_SEMOCOLON) // по выражению
	{
		if ((lextable.table[i].lexema[0] == LEX_ID || lextable.table[i].lexema[0] == LEX_LITERAL) && lextable.table[i+1].lexema[0] != LEX_LEFTHESIS) // нашли идентификатор => переносим его в результирующую строку
		{
			expression[ires] = lextable.table[i];
			ires++;
			if (lextable.table[i-1].lexema[0] == LEX_COMMA) { commas++; params++; }
		}
		else if (lextable.table[i].lexema[0] == LEX_ID  && lextable.table[i + 1].lexema[0] == LEX_LEFTHESIS) // нашли вызов функции
		{
			int start = i;
			i++;
			while (lextable.table[i].lexema[0] != LEX_RIGHTHESIS)
			{
				if (lextable.table[i].lexema[0] == LEX_ID || lextable.table[i].lexema[0] == LEX_LITERAL)
				{
					expression[ires] = lextable.table[i];
					ires++; params++;
				}
				i++;
			}
			expression[ires] = lextable.table[start]; ires++;
			char buf[2];
			_itoa_s(params, buf, 10);
			expression[ires] = LT::Entry(buf[0], lextable.table[start].sn, 0, TI_NULLIDX, LT::LITTYPE::NOT, ' ', -1); ires++;
			
		}
		else if (lextable.table[i].lexema[0] == LEX_LEFTHESIS)
		{
			operations.push(lextable.table[i]);
		}
		else if (lextable.table[i].lexema[0] == LEX_RIGHTHESIS)
		{
			while ((operations.top()).lexema[0] != LEX_LEFTHESIS)
			{
				expression[ires] = operations.top();
				operations.pop();
				ires++;
			}
			operations.pop();
			
		}
		else if (lextable.table[i].lexema[0] == 'v')
		{
			if(!operations.empty() && lextable.table[i].priority <= priority((operations.top()).operation))
			{
				while (!operations.empty() && lextable.table[i].priority <= priority((operations.top()).operation))
				{
					expression[ires] = operations.top();
					operations.pop();
					ires++;
				}
			}
			if (operations.empty() || lextable.table[i].priority > priority((operations.top()).operation))
			{
				operations.push(lextable.table[i]);
			}
				
		}
		i++;
	}
	if (!operations.empty())
	{
		while (!operations.empty())
		{
			expression[ires] = operations.top();
			operations.pop();
			ires++;
		}
	}
	int length = i - lextable_pos;
	if (ires > length) converted = false; // если полиш получилась длиннее исходного
	else
	{
		int i = 0;
		while (i < ires)
		{
			lextable.table[lextable_pos + i] = expression[i];
			i++;
		}
		lextable.table[lextable_pos + i].lexema[0] = LEX_SEMOCOLON;
		lextable.table[lextable_pos + i].operation = ' ';
		lextable.table[lextable_pos + i].idxTI = TI_NULLIDX;
		if (i < length)
		{
			i++;
			while (i <= length)
			{
				lextable.table[lextable_pos + i].lexema[0] = '#';
				lextable.table[lextable_pos + i].idxTI = TI_NULLIDX;
				lextable.table[lextable_pos + i].operation = ' ';
				i++;
			}
		}
		
	}
	
	return converted;
}

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
		//--------------------------------------------
		LT.table[LT.current] = LT::Entry('$', LT.table[LT.current - 1].sn);
		LT.current++;
		GRB::Greibach greibach = GRB::getGreibach();
		MFST_TRACE_START
		MFST::Mfst mfst(LT, greibach);
		mfst.start();
		mfst.savededucation();
		mfst.printrules();
		//--------------------------------------------
		LT.print_coded(lg);
		iTab.print(lg);
		/*PolishNotation(28, LT, iTab);
		PolishNotation(47, LT, iTab);
		PolishNotation(57, LT, iTab);*/
		LT.print_coded(lg);
		Log::Close(lg);
	}
	catch (Error::ERROR er)
	{
		Log::WriteError(lg, er);
		std::cout << er.id << " "<< er.message << " "  << er.inext.line;
		Log::Close(lg);
	}
	system("pause");
   return 0; 
}
