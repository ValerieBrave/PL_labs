// Lab9_PL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Varparm.h"
#include "Call.h"
using namespace Varparm;
using namespace Call;
int main()
{
   int mult1 = ivarparm(0);
   int mult2 = ivarparm(1, 3);
   int mult3 = ivarparm(2, 3, 4);
   int mult7 = ivarparm(6, 1, 2, 3, 4, 5, 6);
   int smult1 = svarparm(0);
   int smult2 = svarparm(1, 3);
   int smult3 = svarparm(2, 3, 4);
   int smult7 = svarparm(6, 1, 2, 3, 4, 5, 6);
   //double dsum1 = fvarparm(FLT_MAX);
   double dsum2 = fvarparm( 2.0f, FLT_MAX);
   double dsum3 = fvarparm(3.5f, 1.5f, FLT_MAX);
   double dsum7 = fvarparm(3.5f, 1.5f, 2.5f, 4.7f, 3.4f, 8.8f, FLT_MAX);
   double sum1 = dvarparm(DBL_MAX);
   double sum2 = dvarparm(3.0, DBL_MAX);
   double sum3 = dvarparm(2.5, 1.5, DBL_MAX);
   double sum7 = dvarparm(3.3, 4.5, 5.5, 2.5, 1.5, 3.0, DBL_MAX);
   //---------------------------------------------------------------------
   int a = 3, b = 4, c = 5;
   int mul1 = cdevl(a, b, c);
   int mul2 = cstd(a, b, c);
   int mul3 = cfst(a, b, c);
   //---------------------------------------------------------------------
   int sr1 = defaultparm1(1, 2, 3, 4, 5, 6, 7);
   int sr2 = defaultparm(1, 2, 3, 4, 5);
   system("pause");
   return 0; 
}


