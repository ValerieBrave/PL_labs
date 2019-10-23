#include "pch.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Error.h"
#include "IT.h"
#include "Semantica.h"
namespace Sem
{
	IT::IDDATATYPE define_dtype(Parse::Words all_units, LT::LexTable LT, int position)
	{
		IT::IDDATATYPE dtype;
		while (*LT.table[position].lexema != 't') position--;
		if (!strcmp((const char*)all_units.words[LT.table[position].globalIndex], "string")) dtype = IT::IDDATATYPE::STR;
		else dtype = IT::IDDATATYPE::INT;
		return dtype;
	}
	IT::IDTYPE define_type(LT::LexTable LT, int position) // ��� �������������� ����� ���������
	{
		IT::IDTYPE type;
		if (*LT.table[position - 2].lexema == 'd') type = IT::IDTYPE::V; // ���������� ����������
		if (*LT.table[position - 2].lexema == '(' || *LT.table[position - 2].lexema == ',') type = IT::IDTYPE::P; // ���������� ���������
		if (*LT.table[position - 1].lexema == 'f' || *LT.table[position+1].lexema == '(') type = IT::IDTYPE::F; // ���������� �������
		return type;
	}
	void AddPref(unsigned char* prefix, LT::LexTable LT, Parse::Words all_units, IT::Entry &en, int i)
	{
		int k = 0;
		int fullLen = strlen((const char*)prefix) + strlen((const char*)all_units.words[LT.table[i].globalIndex]);//+1
		for (; k < strlen((const char*)prefix); k++) en.fullID[k] = prefix[k];
		en.fullID[k++] = '~';
		for (; k < fullLen + 1; k++) en.fullID[k] = all_units.words[LT.table[i].globalIndex][k - strlen((const char*)prefix) - 1]; // �������� �������
		en.fullID[k] = 0x00;
	}
	int checkNum(LT::LexTable LT, Parse::Words all_units, int position)//������� ������� � ������� ������
	{
		if (strlen((const char*)all_units.words[LT.table[position].globalIndex]) > 11) throw ERROR_THROW(116);
		long value = atol((const char*)all_units.words[LT.table[position].globalIndex]);
		if (value > INT_MAX) value = TI_INT_DEFAULT;
		return (int)value;
	}
	void fillInVstr(LT::LexTable LT, IT::Entry &en, Parse::Words all_units, int position)
	{
		if (strlen((const char*)all_units.words[LT.table[position].globalIndex]) > TI_STR_MAXSIZE + 2) throw ERROR_THROW(117);
		strcpy_s(en.value.vstr.str, (const char*)all_units.words[LT.table[position].globalIndex]);
		en.value.vstr.len = (unsigned char)strlen(en.value.vstr.str);
	}
	void genStrName(IT::Entry &en, int glob)
	{
		unsigned char* name = new unsigned char[8];
		sprintf_s((char*)name, 8, "st%d", glob);
		strcpy_s(en.id, (const char*)name);
		strcpy_s((char*)en.fullID, 2 * ID_MAXSIZE - 1, (const char*)name);
	}
	unsigned char* genNumName(int glob)
	{
		unsigned char* name = new unsigned char[8];
		sprintf_s((char*)name, 8, "nu%d", glob);
		return name;
	}
	IT::IdTable getIDTable(LT::LexTable &LT, Parse::Words all_units)
	{
		IT::IdTable IDTab = IT::IdTable(LT.current);
		unsigned char* prefix = new unsigned char[2 * ID_MAXSIZE+1];
		for (int i = 0; i < LT.current; i++) // �� ���� ������� ������ ���� ��������������
		{
			if (*LT.table[i].lexema == 'f')
			{
				prefix = all_units.words[LT.table[i + 1].globalIndex]; //  ����� ������� ��� ���������������
			}
			else if (*LT.table[i].lexema == 'm')
			{
				prefix = all_units.words[LT.table[i].globalIndex];
			}
			if (LT.table[i].idxTI != TI_NULLIDX) // ���� ������� - ������������� 
			{
				if (LT.table[i].littype == LT::LITTYPE::NOT) //�� ������� => ���������� ���� ��� �������
				{
					IT::Entry en = IT::Entry();
					AddPref(prefix, LT, all_units, en, i);
					if(*LT.table[i+1].lexema == '(') strcpy_s((char*)en.fullID, 2 * ID_MAXSIZE - 1, (const char*)all_units.words[LT.table[i].globalIndex]);
					// ������ �������� �� ���������
					if (IDTab.here(en) == -1) // ���� ��������� ���
					{
						strcpy_s(en.id, (const char*)all_units.words[LT.table[i].globalIndex]);
						IT::IDTYPE idtype = define_type(LT, i);
						IT::IDDATATYPE iddatatype = define_dtype(all_units, LT, i);
						if (idtype == IT::IDTYPE::F) strcpy_s((char*)en.fullID, 2 * ID_MAXSIZE - 1, (const char*)en.id);
						en.idxfirstLE = LT.table[i].sn;
						en.LTind = i;
						en.iddatatype = iddatatype;
						en.idtype = idtype;
						if (iddatatype == IT::IDDATATYPE::INT && !(idtype == IT::IDTYPE::F || idtype == IT::IDTYPE::LIB)) en.value.vint = TI_INT_DEFAULT;
						else if(iddatatype == IT::IDDATATYPE::STR && !(idtype == IT::IDTYPE::F || idtype == IT::IDTYPE::LIB))
						{
							//strcpy_s(en.value.vstr.str, (const char*)TI_STR_DEFAULT);
							en.value.vstr.str[0] = TI_STR_DEFAULT;
							en.value.vstr.len = (unsigned char)strlen((const char*)en.value.vstr.str);
						}
						LT.table[i].idxTI = IDTab.current;
						IT::Add(IDTab, en);
					}
					else LT.table[i].idxTI = IDTab.here(en);
				}
				else if (LT.table[i].littype == LT::LITTYPE::F)
				{
					IT::Entry en = IT::Entry();
					en.idxfirstLE = LT.table[i].sn;
					en.LTind = i;
					en.idtype = IT::IDTYPE::LIB;
					strcpy_s((char*)en.libname, 20, (const char*)all_units.words[LT.table[i].globalIndex]);
					IT::Add(IDTab, en);
				}
				else if (LT.table[i].littype == LT::LITTYPE::N) // ��������� �������
				{
					IT::Entry en = IT::Entry();
					en.idxfirstLE = LT.table[i].sn;
					en.LTind = i;
					en.iddatatype = IT::IDDATATYPE::INT;
					en.idtype = IT::IDTYPE::L;
					en.value.vint = checkNum(LT, all_units, i);
					strcpy_s(en.id, (const char*)genNumName(LT.table[i].globalIndex));
					strcpy_s((char*)en.fullID, 2 * ID_MAXSIZE - 1,(const char*)genNumName(LT.table[i].globalIndex));
					IT::Add(IDTab, en);
				}
				else if (LT.table[i].littype == LT::LITTYPE::S) // ��������� �������
				{
					IT::Entry en = IT::Entry();
					en.LTind = i;
					en.idxfirstLE = LT.table[i].sn;
					en.iddatatype = IT::IDDATATYPE::STR;
					en.idtype = IT::IDTYPE::L;
					fillInVstr(LT, en, all_units, i);
					genStrName(en, LT.table[i].globalIndex);
					IT::Add(IDTab, en);
				}
			}
		}
		return IDTab;
	}
}