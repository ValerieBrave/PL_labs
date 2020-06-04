#include "pch.h"
#include <iostream>
#include <fstream>
#include "In.h"
#include "Error.h"
namespace In
{

	IN getin(const char* infile)
	{
		IN *rc = new IN;
		std::ifstream file;
		file.open(infile);
		if (!file.is_open()) throw ERROR_THROW(110);
		file.seekg(0, std::ios_base::end);
		rc->size = file.tellg();
		file.seekg(0, std::ios_base::beg);
		if (rc->size != 0)
		{
			rc->text = new unsigned char[rc->size];
			int i = 0, l = 0, c = 0;
			char buf;
			while (!file.eof())
			{
				file.read(&buf, 1);
				if (buf == IN_CODE_ENDL) { l++; c = 0; }
				switch (rc->code[(unsigned char)buf])
				{
				case IN::F: throw ERROR_THROW_IN(111, l, c); break;
				case IN::T: rc->text[i] = buf; i++; break;
				case IN::I:rc->ignor++; break;

				default:rc->text[i] = (unsigned char)rc->code[(unsigned char)buf]; i++; break;
				}
				c++;
			}
			rc->text[i - 1] = 0x00;
			rc->lines = l;
			rc->size -= rc->ignor;
		}
		file.close();
		return *rc;
	}
}