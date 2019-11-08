#include "pch.h"
#include "GRB.h"
#define GRB_ERROR_SERIES 600
namespace GRB
{
#define NS(n) Rule::Chain::N(n)
#define TS(n) Rule::Chain::T(n)
	Greibach getGreibach()
	{
		Greibach greibach(NS('S'), TS('$'), 9,
			Rule(NS('S'), GRB_ERROR_SERIES + 0, 3,
				Rule::Chain(8, TS('m'), TS('{'), NS('B'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';')),
				Rule::Chain(9, TS('m'), TS('{'), NS('B'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('F')),
				Rule::Chain(12, TS('t'), TS('f'), TS('i'), NS('P'), TS('{'), NS('B'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S'))),
			Rule(NS('F'), GRB_ERROR_SERIES + 0, 2,
				Rule::Chain(11, TS('t'), TS('f'), TS('i'), NS('P'), TS('{'), NS('B'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';')),
				Rule::Chain(12, TS('t'), TS('f'), TS('i'), NS('P'), TS('{'), NS('B'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('F'))),
			Rule(NS('B'), GRB_ERROR_SERIES + 1, 6,
				Rule::Chain(4, TS('d'), TS('t'), TS('i'), TS(';')),
				Rule::Chain(5, TS('d'), TS('t'), TS('i'), TS(';'), NS('B')),
				Rule::Chain(3, TS('r'), NS('E'), TS(';')),
				Rule::Chain(4, TS('r'), NS('E'), TS(';'), NS('B')),
				Rule::Chain(4, TS('i'), TS('='), NS('E'), TS(';')),
				Rule::Chain(5, TS('i'), TS('='), NS('E'), TS(';'), NS('B'))),
			Rule(NS('E'), GRB_ERROR_SERIES + 2, 8,
				Rule::Chain(1, TS('i')),
				Rule::Chain(2, TS('i'), NS('A')),
				Rule::Chain(1, TS('l')),
				Rule::Chain(2, TS('l'), NS('A')),
				Rule::Chain(3, TS('('), NS('E'), TS(')')),
				Rule::Chain(4, TS('('), NS('E'), TS(')'), NS('A')),
				Rule::Chain(2, TS('i'), NS('C')),
				Rule::Chain(3, TS('i'), NS('C'), NS('A'))),
			Rule(NS('A'), GRB_ERROR_SERIES + 3, 2,
				Rule::Chain(2, TS('v'), NS('E')),
				Rule::Chain(3, TS('v'), NS('E'), NS('A'))),
			Rule(NS('P'), GRB_ERROR_SERIES + 4, 2, // формальные параметры
				Rule::Chain(2, TS('('), TS(')')),
				Rule::Chain(3, TS('('), NS('R'), TS(')'))),
			Rule(NS('R'), GRB_ERROR_SERIES + 4, 4,
				Rule::Chain(2, TS('t'), TS('i')),
				Rule::Chain(3, TS('t'), TS('i'), TS(','), NS('R')),
				Rule::Chain(1, TS('l')),
				Rule::Chain(3, TS('l'), TS(','), NS('R'))),
			Rule(NS('C'), GRB_ERROR_SERIES + 5, 2, // фактические параметры
				Rule::Chain(2, TS('('), TS(')')),
				Rule::Chain(3, TS('('), NS('W'), TS(')'))),
			Rule(NS('W'), GRB_ERROR_SERIES + 5, 4,
				Rule::Chain(1, TS('i')),
				Rule::Chain(1, TS('l')),
				Rule::Chain(3, TS('i'), TS(','), NS('W')),
				Rule::Chain(3, TS('l'), TS(','), NS('W'))));
		return greibach;
	}
	
	 
}