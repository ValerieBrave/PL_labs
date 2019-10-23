#pragma once
#include "FST.h"
#define GRAPH_MAIN	  FST::NODE(1, FST::RELATION('m', 1)),\
					  FST::NODE(1, FST::RELATION('a', 2)),\
					  FST::NODE(1, FST::RELATION('i', 3)),\
					  FST::NODE(1, FST::RELATION('n', 4)),\
					  FST::NODE()
#define GRAPH_DECLARE FST::NODE(1, FST::RELATION('d', 1)),\
					  FST::NODE(1, FST::RELATION('e', 2)),\
					  FST::NODE(1, FST::RELATION('c', 3)),\
					  FST::NODE(1, FST::RELATION('l', 4)),\
					  FST::NODE(1, FST::RELATION('a', 5)),\
					  FST::NODE(1, FST::RELATION('r', 6)),\
					  FST::NODE(1, FST::RELATION('e', 7)),\
					  FST::NODE()
#define GRAPH_INTEGER FST::NODE(1, FST::RELATION('i', 1)),\
					  FST::NODE(1, FST::RELATION('n', 2)),\
					  FST::NODE(1, FST::RELATION('t', 3)),\
					  FST::NODE(1, FST::RELATION('e', 4)),\
					  FST::NODE(1, FST::RELATION('g', 5)),\
					  FST::NODE(1, FST::RELATION('e', 6)),\
					  FST::NODE(1, FST::RELATION('r', 7)),\
					  FST::NODE()
#define GRAPH_STRING  FST::NODE(1, FST::RELATION('s', 1)),\
					  FST::NODE(1, FST::RELATION('t', 2)),\
					  FST::NODE(1, FST::RELATION('r', 3)),\
					  FST::NODE(1, FST::RELATION('i', 4)),\
					  FST::NODE(1, FST::RELATION('n', 5)),\
					  FST::NODE(1, FST::RELATION('g', 6)),\
					  FST::NODE()
#define GRAPH_FUNCTION FST::NODE(1, FST::RELATION('f', 1)),\
					   FST::NODE(1, FST::RELATION('u', 2)),\
					   FST::NODE(1, FST::RELATION('n', 3)),\
					   FST::NODE(1, FST::RELATION('c', 4)),\
					   FST::NODE(1, FST::RELATION('t', 5)),\
					   FST::NODE(1, FST::RELATION('i', 6)),\
					   FST::NODE(1, FST::RELATION('o', 7)),\
					   FST::NODE(1, FST::RELATION('n', 8)),\
					   FST::NODE()
#define GRAPH_PRINT FST::NODE(1, FST::RELATION('p', 1)),\
					FST::NODE(1, FST::RELATION('r', 2)),\
					FST::NODE(1, FST::RELATION('i', 3)),\
					FST::NODE(1, FST::RELATION('n', 4)),\
					FST::NODE(1, FST::RELATION('t', 5)),\
					FST::NODE()
#define GRAPH_RETURN  FST::NODE(1, FST::RELATION('r', 1)),\
					  FST::NODE(1, FST::RELATION('e', 2)),\
					  FST::NODE(1, FST::RELATION('t', 3)),\
					  FST::NODE(1, FST::RELATION('u', 4)),\
					  FST::NODE(1, FST::RELATION('r', 5)),\
					  FST::NODE(1, FST::RELATION('n', 6)),\
					  FST::NODE()
#define GRAPH_IDENTIFICATOR FST::NODE(52, FST::RELATION('a', 1), FST::RELATION('b', 1),\
										  FST::RELATION('c', 1), FST::RELATION('d', 1),\
										  FST::RELATION('e', 1), FST::RELATION('f', 1),\
										  FST::RELATION('g', 1), FST::RELATION('h', 1),\
										  FST::RELATION('i', 1), FST::RELATION('j', 1),\
										  FST::RELATION('k', 1), FST::RELATION('l', 1),\
										  FST::RELATION('m', 1), FST::RELATION('n', 1),\
										  FST::RELATION('o', 1), FST::RELATION('p', 1),\
										  FST::RELATION('q', 1), FST::RELATION('r', 1),\
										  FST::RELATION('s', 1), FST::RELATION('t', 1),\
										  FST::RELATION('u', 1), FST::RELATION('v', 1),\
										  FST::RELATION('w', 1), FST::RELATION('x', 1),\
										  FST::RELATION('y', 1), FST::RELATION('z', 1),\
										  FST::RELATION('a', 2), FST::RELATION('b', 2),\
										  FST::RELATION('c', 2), FST::RELATION('d', 2),\
										  FST::RELATION('e', 2), FST::RELATION('f', 2),\
										  FST::RELATION('g', 2), FST::RELATION('h', 2),\
										  FST::RELATION('i', 2), FST::RELATION('j', 2),\
										  FST::RELATION('k', 2), FST::RELATION('l', 2),\
										  FST::RELATION('m', 2), FST::RELATION('n', 2),\
										  FST::RELATION('o', 2), FST::RELATION('p', 2),\
										  FST::RELATION('q', 2), FST::RELATION('r', 2),\
										  FST::RELATION('s', 2), FST::RELATION('t', 2),\
										  FST::RELATION('u', 2), FST::RELATION('v', 2),\
										  FST::RELATION('w', 2), FST::RELATION('x', 2),\
										  FST::RELATION('y', 2), FST::RELATION('z', 2)),\
							FST::NODE(52, FST::RELATION('a', 1), FST::RELATION('b', 1),\
										  FST::RELATION('c', 1), FST::RELATION('d', 1),\
										  FST::RELATION('e', 1), FST::RELATION('f', 1),\
										  FST::RELATION('g', 1), FST::RELATION('h', 1),\
										  FST::RELATION('i', 1), FST::RELATION('j', 1),\
										  FST::RELATION('k', 1), FST::RELATION('l', 1),\
										  FST::RELATION('m', 1), FST::RELATION('n', 1),\
										  FST::RELATION('o', 1), FST::RELATION('p', 1),\
										  FST::RELATION('q', 1), FST::RELATION('r', 1),\
										  FST::RELATION('s', 1), FST::RELATION('t', 1),\
										  FST::RELATION('u', 1), FST::RELATION('v', 1),\
										  FST::RELATION('w', 1), FST::RELATION('x', 1),\
										  FST::RELATION('y', 1), FST::RELATION('z', 1),\
										FST::RELATION('a', 2), FST::RELATION('b', 2), \
										FST::RELATION('c', 2), FST::RELATION('d', 2), \
										FST::RELATION('e', 2), FST::RELATION('f', 2), \
										FST::RELATION('g', 2), FST::RELATION('h', 2), \
										FST::RELATION('i', 2), FST::RELATION('j', 2), \
										FST::RELATION('k', 2), FST::RELATION('l', 2), \
										FST::RELATION('m', 2), FST::RELATION('n', 2), \
										FST::RELATION('o', 2), FST::RELATION('p', 2), \
										FST::RELATION('q', 2), FST::RELATION('r', 2), \
										FST::RELATION('s', 2), FST::RELATION('t', 2), \
										FST::RELATION('u', 2), FST::RELATION('v', 2), \
										FST::RELATION('w', 2), FST::RELATION('x', 2), \
										FST::RELATION('y', 2), FST::RELATION('z', 2)),\
							FST::NODE()
#define GRAPH_NUMBER FST::NODE(20, FST::RELATION('0', 1), FST::RELATION('1', 1),\
								   FST::RELATION('2', 1), FST::RELATION('3', 1),\
								   FST::RELATION('4', 1), FST::RELATION('5', 1),\
								   FST::RELATION('6', 1), FST::RELATION('7', 1),\
								   FST::RELATION('8', 1), FST::RELATION('9', 1),\
								   FST::RELATION('0', 2), FST::RELATION('1', 2),\
								   FST::RELATION('2', 2), FST::RELATION('3', 2),\
								   FST::RELATION('4', 2), FST::RELATION('5', 2),\
								   FST::RELATION('6', 2), FST::RELATION('7', 2),\
								   FST::RELATION('8', 2), FST::RELATION('9', 2)),\
					 FST::NODE(20, FST::RELATION('0', 1), FST::RELATION('1', 1),\
								   FST::RELATION('2', 1), FST::RELATION('3', 1),\
								   FST::RELATION('4', 1), FST::RELATION('5', 1),\
								   FST::RELATION('6', 1), FST::RELATION('7', 1),\
								   FST::RELATION('8', 1), FST::RELATION('9', 1),\
								   FST::RELATION('0', 2), FST::RELATION('1', 2),\
								   FST::RELATION('2', 2), FST::RELATION('3', 2),\
								   FST::RELATION('4', 2), FST::RELATION('5', 2),\
								   FST::RELATION('6', 2), FST::RELATION('7', 2),\
								   FST::RELATION('8', 2), FST::RELATION('9', 2)),\
					 FST::NODE()
#define GRAPH_STR FST::NODE(1, FST::RELATION('\'', 1)),\
				  FST::NODE(139, FST::RELATION(' ', 2), FST::RELATION('a', 2), FST::RELATION('b', 2),\
								FST::RELATION('c', 2), FST::RELATION('d', 2),\
								FST::RELATION('e', 2), FST::RELATION('f', 2),\
								FST::RELATION('g', 2), FST::RELATION('h', 2),\
								FST::RELATION('i', 2), FST::RELATION('j', 2),\
								FST::RELATION('k', 2), FST::RELATION('l', 2),\
								FST::RELATION('m', 2), FST::RELATION('n', 2),\
								FST::RELATION('o', 2), FST::RELATION('p', 2),\
								FST::RELATION('q', 2), FST::RELATION('r', 2),\
								FST::RELATION('s', 2), FST::RELATION('t', 2),\
								FST::RELATION('u', 2), FST::RELATION('v', 2),\
								FST::RELATION('w', 2), FST::RELATION('x', 2),\
								FST::RELATION('y', 2), FST::RELATION('z', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
								FST::RELATION('0', 2), FST::RELATION('1', 2),\
								FST::RELATION('2', 2), FST::RELATION('3', 2),\
								FST::RELATION('4', 2), FST::RELATION('5', 2),\
								FST::RELATION('6', 2), FST::RELATION('7', 2),\
								FST::RELATION('8', 2), FST::RELATION('9', 2),\
								FST::RELATION('a', 3), FST::RELATION('b', 3),\
								FST::RELATION('c', 3), FST::RELATION('d', 3),\
								FST::RELATION('e', 3), FST::RELATION('f', 3),\
								FST::RELATION('g', 3), FST::RELATION('h', 3),\
								FST::RELATION('i', 3), FST::RELATION('j', 3),\
								FST::RELATION('k', 3), FST::RELATION('l', 3),\
								FST::RELATION('m', 3), FST::RELATION('n', 3),\
								FST::RELATION('o', 3), FST::RELATION('p', 3),\
								FST::RELATION('q', 3), FST::RELATION('r', 3),\
								FST::RELATION('s', 3), FST::RELATION('t', 3),\
								FST::RELATION('u', 3), FST::RELATION('v', 3),\
								FST::RELATION('w', 3), FST::RELATION('x', 3),\
								FST::RELATION('y', 3), FST::RELATION('z', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
								FST::RELATION('0', 3), FST::RELATION('1', 3),\
								FST::RELATION('2', 3), FST::RELATION('3', 3),\
								FST::RELATION('4', 3), FST::RELATION('5', 3),\
								FST::RELATION('6', 3), FST::RELATION('7', 3),\
								FST::RELATION('8', 3), FST::RELATION('9', 3)),\
				  FST::NODE(139,FST::RELATION(' ', 2), FST::RELATION('a', 2), FST::RELATION('b', 2),\
								FST::RELATION('c', 2), FST::RELATION('d', 2),\
								FST::RELATION('e', 2), FST::RELATION('f', 2),\
								FST::RELATION('g', 2), FST::RELATION('h', 2),\
								FST::RELATION('i', 2), FST::RELATION('j', 2),\
								FST::RELATION('k', 2), FST::RELATION('l', 2),\
								FST::RELATION('m', 2), FST::RELATION('n', 2),\
								FST::RELATION('o', 2), FST::RELATION('p', 2),\
								FST::RELATION('q', 2), FST::RELATION('r', 2),\
								FST::RELATION('s', 2), FST::RELATION('t', 2),\
								FST::RELATION('u', 2), FST::RELATION('v', 2),\
								FST::RELATION('w', 2), FST::RELATION('x', 2),\
								FST::RELATION('y', 2), FST::RELATION('z', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),\
								FST::RELATION('0', 2), FST::RELATION('1', 2),\
								FST::RELATION('2', 2), FST::RELATION('3', 2),\
								FST::RELATION('4', 2), FST::RELATION('5', 2),\
								FST::RELATION('6', 2), FST::RELATION('7', 2),\
								FST::RELATION('8', 2), FST::RELATION('9', 2),\
								FST::RELATION('a', 3), FST::RELATION('b', 3),\
								FST::RELATION('c', 3), FST::RELATION('d', 3),\
								FST::RELATION('e', 3), FST::RELATION('f', 3),\
								FST::RELATION('g', 3), FST::RELATION('h', 3),\
								FST::RELATION('i', 3), FST::RELATION('j', 3),\
								FST::RELATION('k', 3), FST::RELATION('l', 3),\
								FST::RELATION('m', 3), FST::RELATION('n', 3),\
								FST::RELATION('o', 3), FST::RELATION('p', 3),\
								FST::RELATION('q', 3), FST::RELATION('r', 3),\
								FST::RELATION('s', 3), FST::RELATION('t', 3),\
								FST::RELATION('u', 3), FST::RELATION('v', 3),\
								FST::RELATION('w', 3), FST::RELATION('x', 3),\
								FST::RELATION('y', 3), FST::RELATION('z', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3), FST::RELATION('�', 3),\
								FST::RELATION('0', 3), FST::RELATION('1', 3),\
								FST::RELATION('2', 3), FST::RELATION('3', 3),\
								FST::RELATION('4', 3), FST::RELATION('5', 3),\
								FST::RELATION('6', 3), FST::RELATION('7', 3),\
								FST::RELATION('8', 3), FST::RELATION('9', 3)),\
				   FST::NODE(1, FST::RELATION('\'', 4)),\
				   FST::NODE()
#define GRAPH_STRLEN  FST::NODE(1, FST::RELATION('s', 1)),\
					  FST::NODE(1, FST::RELATION('t', 2)),\
					  FST::NODE(1, FST::RELATION('r', 3)),\
					  FST::NODE(1, FST::RELATION('l', 4)),\
					  FST::NODE(1, FST::RELATION('e', 5)),\
					  FST::NODE(1, FST::RELATION('n', 6)),\
					  FST::NODE()
#define GRAPH_SUBSTR  FST::NODE(1, FST::RELATION('s', 1)),\
					  FST::NODE(1, FST::RELATION('u', 2)),\
					  FST::NODE(1, FST::RELATION('b', 3)),\
					  FST::NODE(1, FST::RELATION('s', 4)),\
					  FST::NODE(1, FST::RELATION('t', 5)),\
					  FST::NODE(1, FST::RELATION('r', 6)),\
					  FST::NODE()
					 