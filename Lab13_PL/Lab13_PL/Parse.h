#pragma once
#include "In.h"
#include "Log.h"
#include "FST.h"
#define GRAPH3 FST::NODE(1, FST::RELATION('p', 1)),\
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

namespace Parse
{
	unsigned char* parse(unsigned char* text, char eos);
	void auto_check(In::IN in, Log::LOG lg);
}