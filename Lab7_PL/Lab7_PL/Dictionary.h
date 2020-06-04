#pragma once
#include "pch.h"
#include <iostream>
#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30
#define THROW01 "Create: превышен размер имени словаря"
#define THROW02 "Create: превышен размер максимальной ёмкости словаря"
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идентификатора"
namespace Dictionary
{
	struct Entry //элемент словаря
	{
		int id;
		char name[ENTRYNAMEMAXSIZE];
		Entry(const char*n, int i)
		{
			strcpy_s(name, n);
			id = i;
		}
		Entry()
		{
			strcpy_s(name, "");
			id = 0;
		}
	};
	struct Instance
	{
		char name[DICTNAMEMAXSIZE];
		int maxsize;// < DICTMAXSIZE
		int size; //текущий размер
		Entry* dictionary;
	};
	//-----------------------------------------------------
	
	Instance Create(const char *n, int size);
	void AddEntry(Instance& dict, Entry* element);
	Entry GetEntry(Instance dict, int id);
	void DelEntry(Instance& dict, int id);
	void Delete(Instance& dict);
	void UpdEntry(Instance& dict, int id, Entry new_entry);
	int GetIndexEntryR(Instance dict, int id);
	void Print(Instance &dict);
}