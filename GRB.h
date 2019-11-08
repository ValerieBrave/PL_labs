#pragma once
#include "Error.h"
typedef short GRBALPHABET; // символы алфавита грамматики: терминалы >0, нетерминалы <0
namespace GRB
{
	struct Rule // правило в грамматике Грейбах
	{
		GRBALPHABET nn; // нетерминал (левый символ правила) <0
		int iderror; // идентификатор диагностического сообщения
		short size; // количество цепочек - правых частей правила
		struct Chain
		{
			short size; // Длина цепочки
			GRBALPHABET* nt; // цепочка терминалов и нетерминалов
			Chain()
			{
				this->size = 0;
				this->nt = 0;
			}
			Chain(short psize, GRBALPHABET s, ...)
			{
				this->nt = new GRBALPHABET[this->size = psize];
				GRBALPHABET *p = &s;
				for (int i = 0; i < psize; i++) this->nt[i] = p[i];
			}
			void getCChain(char* b) /*Что тут должно происходить*/
			{
				int i = 0;
				for (; i < this->size; i++) b[i] = (char)this->nt[i];
				b[i] = 0x00;
			}
			static GRBALPHABET T(char t) { return GRBALPHABET(t); };
			static GRBALPHABET N(char n) { return -GRBALPHABET(n); };
			static bool isT(GRBALPHABET s) { return s > 0; };
			static bool isN(GRBALPHABET s) { return !isT(s); };
			static char alphabet_to_char(GRBALPHABET s) { return isT(s) ? char(s) : char(-s); };
		}* chains;
		Rule()
		{
			this->nn = 0x00;
			this->size = 0;
			this->iderror = 0;
			this->chains = 0;
		}
		Rule(GRBALPHABET pnn, int iderror, short psize, Chain c, ...)
		{
			this->nn = pnn;
			this->iderror = iderror;
			this->size = psize;
			this->chains = new Chain[psize];
			Chain* p = &c;
			for (int i = 0; i < psize; i++) this->chains[i] = p[i];
		}
		void CopyIn(Rule &r)
		{
			r.iderror = this->iderror;
			r.nn = this->nn;
			r.size = this->size;
			for (int i = 0; i < this->size; i++) r.chains[i] = this->chains[i];
		}
		char* getCRule(char *buf, short nchain)
		{
			buf[0] = Rule::Chain::alphabet_to_char(this->nn);
			buf[1] = '-';
			buf[2] = '>';
			int ibuf = 3, i = 0, ind =0;
			Rule::Chain* chain = this->chains;
			while (i < nchain)
			{
				chain++; i++;
			}
			while (ind < chain->size)
			{
				buf[ibuf] = Rule::Chain::alphabet_to_char(chain->nt[ind]);
				ibuf++; ind++;
			}
			buf[ibuf] = 0x00;
			return buf;
		}
		short getNextChain(GRBALPHABET t, Rule::Chain& pchain, short j) // t-первый символ цепочки,pchain - вернуть эту цепочку, j текущая
		{
			short chainnum = -1;
			bool found = false;
			while (j < this->size && !found)
			{
				if (this->chains[j].nt[0] == t) 
				{
					found = true; chainnum = j;
				}
				j++;
			}
			return chainnum;
		}
	};
	struct Greibach
	{
		short size; // количество правил
		GRBALPHABET startN; //стартовый символ
		GRBALPHABET stbottomT; // дно стека
		Rule* rules; // множество правил
		Greibach()
		{
			this->size = 0;
			this->startN = 0;
			this->stbottomT = 0;
			this->rules = 0;
		}
		Greibach(GRBALPHABET pstartN, GRBALPHABET pstbottomT, short psize, Rule r, ...)
		{
			this->startN = pstartN;
			this->stbottomT = pstbottomT;
			this->size = psize;
			this->rules = new Rule[psize];
			Rule *p = &r;
			for (int i = 0; i < psize; i++) this->rules[i] = p[i];
		}
		short getRule(GRBALPHABET pnn, Rule& prule) //зачем тут пруле???
		{
			short rulenum = -1;
			int i = 0;
			while (i < this->size && rulenum==-1)
			{
				if (this->rules[i].nn == pnn)
				{
					rulenum = i;
					this->rules[i].CopyIn(prule);
				}
				i++;
			}
			return rulenum;
		}
		Rule getRule(short n)
		{
			Rule *p = this->rules;
			for (int i = 0; i < n; i++) p++;
			Rule *rc = new Rule();
			p->CopyIn(*rc);
			return *rc;
		}
		
	};
	Greibach getGreibach(); //что должно происходить?
	
}