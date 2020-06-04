#include "pch.h"
#include <iostream>
#include <algorithm>
#include "FST.h"
namespace FST
{
#define GRAPH1 NODE(1, RELATION('p', 1)),\
			  NODE(1, RELATION('r', 2)),\
			  NODE(1, RELATION('o', 3)),\
			  NODE(1, RELATION('c', 4)),\
			  NODE(1, RELATION(' ', 5)),\
			  NODE(3, RELATION(' ', 6), RELATION('s', 7), RELATION(' ', 25)),\
			  NODE(2, RELATION('s', 7), RELATION(' ', 5)),\
			  NODE(1, RELATION('t', 8)),\
			  NODE(1, RELATION('a', 9)),\
			  NODE(1, RELATION('r', 10)),\
			  NODE(1, RELATION('t', 11)),\
			  NODE(1, RELATION('(', 12)),\
			  NODE(2, RELATION('s', 13), RELATION('c', 19)),\
			  NODE(1, RELATION('i', 14)),\
			  NODE(1, RELATION('n', 15)),\
			  NODE(1, RELATION('(', 16)),\
			  NODE(1, RELATION('x', 17)),\
			  NODE(3, RELATION('x', 18), RELATION(')', 18), RELATION(')', 24)),\
			  NODE(3, RELATION('x', 17), RELATION(')', 24), RELATION(')', 17)),\
			  NODE(1, RELATION('o', 20)),\
			  NODE(1, RELATION('s', 21)),\
			  NODE(1, RELATION('(', 22)),\
			  NODE(2, RELATION(')', 23), RELATION('y', 22)),\
			  NODE(1, RELATION(')', 24)),\
			  NODE(2, RELATION(' ', 25), RELATION('s', 7)),\
			  NODE(2, RELATION('e', 27), RELATION(' ', 26)),\
			  NODE(2, RELATION('e', 27), RELATION(' ', 25)),\
			  NODE(1, RELATION('n', 28)),\
			  NODE(1, RELATION('d', 29)),\
			  NODE()

	bool step(FST& fst, short* &rstates)
	{
		bool rc = false;
		std::swap(rstates, fst.rstates);
		for (short i = 0; i < fst.nstates; i++)
		{
			if (rstates[i] == fst.position)
				for (short j = 0; j < fst.nodes[i].n_relation; j++)
				{
					if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
					{
						fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
						rc = true;
					}
				}
		}
		return rc;
	}
	bool execute(FST& fst) // выполнить разбор цепочки
	{
		short* rstates = new short[fst.nstates];
		memset(rstates, 0xff, sizeof(short)*fst.nstates); // забиваем -1
		short lstring = strlen(fst.string); // длина текущей цепочки
		bool rc = true;
		short i = 0;
		for (i = 0; i < lstring && rc; i++)
		{
			fst.position++;
			rc = step(fst, rstates);
		}
		delete[] rstates;
		return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);
	}
	unsigned char* parse(unsigned char* text) // для выделения отдельных цепочек
	{
		bool rc = false;
		unsigned char* buf=new unsigned char[strlen((const char*)text)] ;
		int i = 0;
		while (text[i]!=0x00 && text[i] != '|')
		{
			buf[i] = text[i];
			i++;
		}
		buf[i] = 0x00;
		FST fst((const char*)buf, 30, GRAPH1);
		//if (execute(fst)) std::cout << "ok\n";
		//else std::cout << "notok\n";
		return text+i+1; // возвращаю позицию после перевода строки |
	}
}