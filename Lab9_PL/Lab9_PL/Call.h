#pragma once
namespace Call
{
	int _cdecl cdevl(int&, int&, int&);
	int _stdcall cstd(int&, int, int);
	int _fastcall cfst(int, int, int);
	int defaultparm(int c, int d, int e, int a = 3, int b = 4);
	int defaultparm1(int c, int d, int e, int f, int k, int a = 3, int b = 4);
}