#include "pch.h"
#include <iostream>
#include "Varparm.h"
namespace Varparm
{
	int ivarparm(int k, ...)
	{
		int res = 1,i = 0;
		int*p = &k;
		p++;
		while (i < k)
		{
			res = res * p[i];
			i++;
		}
		return res;
	}
	//--------------------------------------------------------
	int svarparm(short k, ...)
	{
		int i = 0;
		int res = 1;
		
		short*ps = &k;
		ps+=2;        // потому что хранится в первых двух байтах 4-байтного поля
		while (i < 2*k)
		{
			res = res * ps[i];
			i+=2;
		}
		return res;
	}
	//---------------------------------------------------------------------------
	double fvarparm(float f, ...)
	{
		double res = (double)f;
		double *p = (double*)(&f + 1);
		int i = 0;
		while (p[i] != (double)FLT_MAX)
		{
			res += p[i];
			i++;
		}
		return res;
	}
	//-----------------------------------------------------------
	double dvarparm(double d, ...)
	{
		double *p = &d;
		double res = 0;
		int i = 0;
		while (p[i] != DBL_MAX)
		{
			res += p[i];
			i++;
		}
		return res;
	}
}