// Lab4_PL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

int sum(int, int);
int main()
{
	int X = 21, Y = 22, Z = 23;
	float S = 13.0f;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	bool b1 = true, b2 = false;
	//b1=01
	//b2=00
	char a = 'a';
	//a=0x61
	wchar_t le = 'ц';
	//le= 0xfff6
	short int si1 = X,si2 = -X;
	// X = 0x15
	// X=0xffeb
	short int mxs = SHRT_MAX, mns = SHRT_MIN;
	// mxs=0x7fff=32767	
	// mns=0x800=-32768	

	unsigned short int mxus = USHRT_MAX;
	// mxus=0xffff
	// mxus=65535	

	int i1 = Y, i2 = -Y;
	// Y=0x00000016
	//-Y=0xffffffea

	int mxi = INT_MAX;
	//mxi= 0x7fffffff
	//mxi=2147483647	

	unsigned int mxui = UINT_MAX;
	// mxui=0xcccccccc=	3435973836	
	long int li1 = Z, li2 = -Z;
	// Y=0x00000017
	//-Y=0xffffffe9
	int sz = sizeof(double);
	long int mxli = LONG_MAX, mnli = LONG_MIN;
	// mxli=2147483647	=0x7fffffff
	// mnli=-2147483648 =0x80000000
	unsigned long int mxuli = ULONG_MAX;
	// mxuli=4294967295 =0xffffffff
	float f1 = S, f2 = -S;
	//f1=0x41500000
	//f2=0xc1500000
	float f3 = f1 / 0, f4 = f2 / 0, f5=sqrt(-1);
	//f3=inf
	//f4=-inf
	//f5=-ind
	//------------------------------------------------------------------------------------------------
	double d = 15;
	char *pchar=&a, *pchar3=pchar+3;
	wchar_t *pwchar_t=&le, *pwchar_t3=pwchar_t+3;
	short int *pshint=&mns, *pshint3= pshint+3;
	int *pint=&X, *pint3= pint+3;
	long int *plint=&li1, *plint3= plint+3;
	float *pfloat=&f1, *pfloat3= pfloat+3;
	double *pdouble = &d, *pdouble3= pdouble+3;
	//------------------------------------------------------------------------------------------------
	int(*psum)(int, int) = &sum;
	//указатель на функцию содержит адрес входа функции
	//-----------------------------------------------------------------------------------------------
	char &ch = a;
	wchar_t &wch = le;
	short int &shi = si1;
	int &in = i1;
	float &fl = f1;
	double &doub = d;
	return 0;
}
int sum(int x, int y) { return x + y; }


