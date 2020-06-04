#include "pch.h"
#include "Dictionary.h"
#include <iostream>
namespace Dictionary
{
	
	Instance Create(const char *n, int size)
	{
		if (strlen(n) > DICTNAMEMAXSIZE) throw THROW01;
		if (size > DICTMAXSIZE) throw THROW02;
		Instance *dict = new Instance;
		strcpy_s(dict->name,n);
		dict->size = 0;
		
		dict->maxsize = size;
		dict->dictionary = new Entry[size];
		return *dict;
	}
	void AddEntry(Instance& dict, Entry* element)
	{
		if (dict.size + 1 >= dict.maxsize) throw THROW03;
		bool find=false;
		try
		{
			Entry en = GetEntry(dict, element->id);
			find = true;
		}
		catch (const char* e)
		{
			dict.dictionary[dict.size] = *element;
			dict.size++;
		}
		if (find) throw  THROW04;
	}
	Entry GetEntry(Instance dict, int id)
	{
		int k = 0;
		while (k < dict.size && dict.dictionary[k].id != id) k++;
		if (k == dict.size) throw THROW05;
		return dict.dictionary[k];
	}
	int GetIndexEntry(Instance dict, int id)
	{
		int k = 0;
		while (k < dict.size && dict.dictionary[k].id != id) k++;
		if (k == dict.size) throw THROW05;
		return k;
	}
	void DelEntry(Instance& dict, int id)
	{
		
		try
		{
			int ind = GetIndexEntry(dict, id);
			for (int i = ind; i < dict.size - 1; i++)
			{
				dict.dictionary[i] = dict.dictionary[i + 1];
			}
			dict.size--;
		}
		catch (const char*e)
		{
			throw THROW06;
		}
	}
	int GetIndexEntryR(Instance dict, int id)
	{
		int k = 0;
		while (k < dict.size && dict.dictionary[k].id != id) k++;
		if (k == dict.size) k = -1;
		return k;
	}
	void UpdEntry(Instance& dict, int id, Entry new_entry)
	{
		int index1 = GetIndexEntryR(dict, id);
		if (index1 < 0) throw THROW07;
		if (GetIndexEntryR(dict, new_entry.id) >= 0) throw THROW08;
		dict.dictionary[index1] = new_entry;
	}
	void Delete(Instance& dict)
	{
		dict.size = 0;
	}
	void Print(Instance &dict)
	{
		std::cout << dict.name << '\n';
		for (int i = 0; i < dict.size; i++)
		{
			std::cout << dict.dictionary[i].id << '\t' << dict.dictionary[i].name << '\n';
		}
	}
}