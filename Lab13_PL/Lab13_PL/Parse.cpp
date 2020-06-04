#include "pch.h"
#include <iostream>
#include "Parse.h"
#include "Error.h"
namespace Parse
{
	unsigned char* parse(unsigned char* text, char eos)
	{
		unsigned char* buf = new unsigned char[strlen((const char*)text)];
		int i = 0;
		while (text[i] != 0x00 && text[i] != eos)
		{
			buf[i] = text[i];
			i++;
		}
		buf[i] = 0x00;
		return buf; // возвращает отдельную цепочку
	}
	void auto_check(In::IN in, Log::LOG lg)
	{
		Log::WriteLine(lg, "--------ѕротокол разбора---------\n", "");
		int l = 0;
		unsigned char* temp , *par = in.text;
		while (par[0] != 0x00)
		{
			temp = parse(par, IN_CODE_ENDL); //вычленили цепочку
			par += strlen((const char*)temp)+1;  // нарастили указатель в общем тексте, чтобы в след.раз читать с конца предыдущей цепочки
			l++; // нарастили строку
			FST::FST fst((const char*)temp, 30, GRAPH3); // автомат дл€ текущей цепочки
			if (FST::execute(fst))
			{
				char tbuf[256];
				sprintf_s(tbuf, 256, "—трока  %d успешно разобрана", l);
				Log::WriteLine(lg, tbuf, "");
			}
			else throw ERROR_THROW_IN(111,l, fst.position);
		}
		
	}
}