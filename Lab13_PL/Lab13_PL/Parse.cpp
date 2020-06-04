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
		return buf; // ���������� ��������� �������
	}
	void auto_check(In::IN in, Log::LOG lg)
	{
		Log::WriteLine(lg, "--------�������� �������---------\n", "");
		int l = 0;
		unsigned char* temp , *par = in.text;
		while (par[0] != 0x00)
		{
			temp = parse(par, IN_CODE_ENDL); //��������� �������
			par += strlen((const char*)temp)+1;  // ��������� ��������� � ����� ������, ����� � ����.��� ������ � ����� ���������� �������
			l++; // ��������� ������
			FST::FST fst((const char*)temp, 30, GRAPH3); // ������� ��� ������� �������
			if (FST::execute(fst))
			{
				char tbuf[256];
				sprintf_s(tbuf, 256, "������  %d ������� ���������", l);
				Log::WriteLine(lg, tbuf, "");
			}
			else throw ERROR_THROW_IN(111,l, fst.position);
		}
		
	}
}