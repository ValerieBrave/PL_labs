#include "pch.h"
#include <iostream>
namespace Call
{
	int _cdecl cdevl(int& a, int& b, int& c)
	{
		return a * b * c;
	}
	int _stdcall cstd(int& a, int b, int c)
	{
		return a * b * c;
	}
	int _fastcall cfst(int a, int b, int c)
	{
		return a * b * c;
	}
	int defaultparm(int c, int d, int e, int a = 3, int b = 4)
	{
		return (a + b + c + d + e) / 5;
	}
	int defaultparm1(int c, int d, int e,int f, int k, int a = 3, int b = 4)
	{
		return (a + b + c + d + e+ f + k) / 7;
	}
}