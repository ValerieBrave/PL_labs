#include "stdafx.h"

extern "C"
{
	int getmin(int *parr, int count)
	{
		int min = parr[0];
		for (int i = 0; i < count; i++)
			if (min > parr[i])
				min = parr[i];
		return min;
	}
	int getmax(int *parr, int count)
	{
		int max = parr[0];
		for (int i = 0; i < count; i++)
			if (max < parr[i])
				max = parr[i];
		return max;
	}
}