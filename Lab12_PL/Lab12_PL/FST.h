#pragma once
#define GRAPH FST::NODE(1, FST::RELATION('p', 1)),\
			  FST::NODE(1, FST::RELATION('r', 2)),\
			  FST::NODE(1, FST::RELATION('o', 3)),\
			  FST::NODE(1, FST::RELATION('c', 4)),\
			  FST::NODE(1, FST::RELATION(' ', 5)),\
			  FST::NODE(3, FST::RELATION(' ', 6), FST::RELATION('s', 7), FST::RELATION(' ', 25)),\
			  FST::NODE(2, FST::RELATION('s', 7), FST::RELATION(' ', 5)),\
			  FST::NODE(1, FST::RELATION('t', 8)),\
			  FST::NODE(1, FST::RELATION('a', 9)),\
			  FST::NODE(1, FST::RELATION('r', 10)),\
			  FST::NODE(1, FST::RELATION('t', 11)),\
			  FST::NODE(1, FST::RELATION('(', 12)),\
			  FST::NODE(2, FST::RELATION('s', 13), FST::RELATION('c', 19)),\
			  FST::NODE(1, FST::RELATION('i', 14)),\
			  FST::NODE(1, FST::RELATION('n', 15)),\
			  FST::NODE(1, FST::RELATION('(', 16)),\
			  FST::NODE(1, FST::RELATION('x', 17)),\
			  FST::NODE(3, FST::RELATION('x', 18), FST::RELATION(')', 18), FST::RELATION(')', 24)),\
			  FST::NODE(3, FST::RELATION('x', 17), FST::RELATION(')', 24), FST::RELATION(')', 17)),\
			  FST::NODE(1, FST::RELATION('o', 20)),\
			  FST::NODE(1, FST::RELATION('s', 21)),\
			  FST::NODE(1, FST::RELATION('(', 22)),\
			  FST::NODE(2, FST::RELATION(')', 23), FST::RELATION('y', 22)),\
			  FST::NODE(1, FST::RELATION(')', 24)),\
			  FST::NODE(2, FST::RELATION(' ', 25), FST::RELATION('s', 7)),\
			  FST::NODE(2, FST::RELATION('e', 27), FST::RELATION(' ', 26)),\
			  FST::NODE(2, FST::RELATION('e', 27), FST::RELATION(' ', 25)),\
			  FST::NODE(1, FST::RELATION('n', 28)),\
			  FST::NODE(1, FST::RELATION('d', 29)),\
			  FST::NODE()

namespace FST
{
	struct RELATION
	{
		char symbol;  //символ перехода
		short nnode; //номер смежной вершины
		RELATION(char c = 0x00, short ns = 0)
		{
			this->symbol = c;
			this->nnode = ns;
		}
	};

	struct NODE
	{
		short n_relation; // количество инцидентных ребер
		RELATION* relations; //инцидентные ребра
		NODE()
		{
			this->n_relation = 0;
			this->relations = nullptr;
		}
		NODE(short n, RELATION rel, ...)
		{
			this->relations = new RELATION[this->n_relation=n];
			RELATION *p = &rel;
			for (int i = 0; i < n; i++) this->relations[i] = p[i];
		}
	};
	struct FST
	{
		const char* string;   //исходная цепочка
		short position;  // текущая позиция в цепочке
		short nstates;  //количество состояний автомата
		NODE* nodes;  // граф переходов
		short* rstates; // возможные состояния автомата на данной позиции
		FST(const char* s, short ns, NODE n, ...)
		{
			this->position = -1;
			this->rstates = new short[ns];
			memset(this->rstates, 0xff, sizeof(short)*ns);
			this->rstates[0] = 0;
			this->string = s;
			this->nstates = ns;
			this->nodes = new NODE[ns];
			NODE* p = &n;
			for (int i = 0; i < ns; i++) this->nodes[i] = p[i];
		}
	};
	bool execute(FST& fst);
}