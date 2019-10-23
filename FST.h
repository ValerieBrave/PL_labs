#pragma once
#include "LT.h"
namespace FST
{
	struct RELATION
	{
		char symbol;  //������ ��������
		short nnode; //����� ������� �������
		RELATION(char c = 0x00, short ns = 0)
		{
			this->symbol = c;
			this->nnode = ns;
		}
	};

	struct NODE
	{
		short n_relation; // ���������� ����������� �����
		RELATION* relations; //����������� �����
		NODE()
		{
			this->n_relation = 0;
			this->relations = nullptr;
		}
		NODE(short n, RELATION rel, ...)
		{
			this->relations = new RELATION[this->n_relation = n];
			RELATION *p = &rel;
			for (int i = 0; i < n; i++) this->relations[i] = p[i];
		}
	};
	struct FST
	{
		const char* string;   //�������� �������
		short position;  // ������� ������� � �������
		short nstates;  //���������� ��������� ��������
		NODE* nodes;  // ���� ���������
		short* rstates; // ��������� ��������� �������� �� ������ �������
		int type; // ��� ��������: �������, �������������, �������
		enum {LEXEM=1, IDENTIFICATOR=2, STR_LITERAL=3, NUM_LITERAL=4, LIB_NAME = 5};
		FST()
		{
			this->string = "";
			this->position = -1;
			this->nstates = 0;
			this->type = 0;
			this->rstates = nullptr;
			this->nodes = nullptr;
		}
		FST(const char* s, short ns, int type, NODE n, ...)
		{
			this->position = -1;
			this->rstates = new short[ns];
			memset(this->rstates, 0xff, sizeof(short)*ns);
			this->rstates[0] = 0;
			this->string = s;
			this->nstates = ns;
			this->type = type;
			this->nodes = new NODE[ns];
			NODE* p = &n;
			for (int i = 0; i < ns; i++) this->nodes[i] = p[i];
		}
		void reinit(const char* s)
		{
			this->position = -1;
			memset(this->rstates, 0xff, sizeof(short)*this->nstates);
			this->rstates[0] = 0;
			this->string = s;
		}
	};
	struct FST_lexems
	{
		char lexem[2] = "";
		FST fst;
		FST_lexems()
		{
			this->fst = FST("", 0, 0, NODE());
		}
		FST_lexems(const char lex, FST f)
		{
			this->lexem[0] = lex;
			this->lexem[1] = 0x00;
			this->fst = f;
		}
	};
	bool execute(FST& fst);
	
	
};