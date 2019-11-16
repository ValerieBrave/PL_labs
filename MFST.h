#pragma once
#include <stack>
#include "LT.h"
#include "GRB.h"
#define MFST_DIAGN_MAXSIZE 2*ERROR_MAXSIZE_MESSAGE
#define MFST_DIAGN_NUMBER 3
typedef std::stack<short> MFSTSTACK; // ���� ��������
namespace MFST
{
	struct MfstState // ��������� ��������
	{
		short lenta_position; // ������� �� �����
		short nrule; // ����� �������� �������
		short nrulechain; // ����� ������� ������� �������� �������
		MFSTSTACK st; //  ���� ��������
		MfstState()
		{
			this->lenta_position = 0;
			this->nrule = -1;
			this->nrulechain = -1;
		}
		MfstState(short pposition, MFSTSTACK pst, short pnrulechain)
		{
			this->lenta_position = pposition;
			this->nrulechain = pnrulechain;
			this->st = pst;
		}
		MfstState(short pposition, MFSTSTACK pst, short pnrule, short pnrulechain)
		{
			this->lenta_position = pposition;
			this->nrule = pnrule;
			this->nrulechain = pnrulechain;
			this->st = pst;
		}
	};
	struct Mfst //
	{
		enum RC_STEP { // ��� �������� ������� step
			NS_OK, // ������� ������� � �������, ������� �������� � ����
			NS_NORULE, // �� ������� ������� ����������(������ � ����������)
			NS_NORULECHAIN, //�� ������� ���������� ������� �������(������ � ���������)
			NS_ERROR, // ����������� �������������� ������ ����������
			TS_OK, //������� ������ ����� == ������� �����, ������� �����, ������� ������ �� �����
			TS_NOK, //������� ������ ����� != ������� �����, ��������������� ���������
			LENTA_END, // ������� ����� => �� �������
			SURPRISE // ����������� ��� �������� (������ � ����)
		};
		struct MfstDiagnosis // �����������
		{
			short lenta_position; // ������� �� �����
			RC_STEP rc_step; //��� ���������� ����
			short nrule; // ����� �������
			short nrule_chain; // ����� ������� �������
			MfstDiagnosis()
			{
				this->lenta_position = -1;
				this->rc_step = RC_STEP::SURPRISE;
				this->nrule = -1;
				this->nrule_chain = -1;
			}
			MfstDiagnosis(short plenta_position, RC_STEP prc_step, short pnrule, short pnrule_chain)
			{
				this->lenta_position = plenta_position;
				this->rc_step = prc_step;
				this->nrule = pnrule;
				this->nrule_chain = pnrule_chain;
			}
		} diagnosis[MFST_DIAGN_NUMBER];
		GRBALPHABET *lenta;
		short lenta_position;
		short nrule;
		short nrulechain;
		short lenta_size;
		GRB::Greibach greibach;
		LT::LexTable LT;
		MFSTSTACK st;
		std::stack<MfstState> storestate;
		Mfst()
		{
			this->lenta =0;
			this->lenta_size = this->lenta_position = 0;
		}
		Mfst(LT::LexTable pLT, GRB::Greibach pgrb)
		{
			this->greibach = pgrb;
			this->LT = pLT;
			this->lenta = new short[this->lenta_size = LT.current];
			for (int k = 0; k < this->lenta_size; k++) this->lenta[k] = GRB::Rule::Chain::T(LT.table[k].lexema[0]);
			this->lenta_position = 0;
			this->st.push(this->greibach.stbottomT);
			this->st.push(this->greibach.startN);
			this->nrulechain = -1;
		}
		char* getCSt(char* buf) // �������� ���������� �����
		{
			for (int k = (signed)st.size() - 1; k >= 0; --k)
			{
				short p = st._Get_container()[k];
				buf[st.size() - 1 - k]; GRB::Rule::Chain::alphabet_to_char(p);
			}
			buf[st.size()] = 0x00;
			return buf;
		}
		char* getCLenta(char* buf, short pos, short n = 25)
		{
			short i, k = (pos + n < this->lenta_size) ? pos + n : this->lenta_size;
			for (i = pos; i < k; i++) buf[i - pos] = GRB::Rule::Chain::alphabet_to_char(this->lenta[i]);
			buf[i - pos] = 0x00;
			return buf;
		}
		char* getDiagnosis(short n, char* buf) // �������� ����� ������ �����������
		{
			char *rc = (char*)"";
			int errid = 0, lpos = -1;
			if (n < MFST_DIAGN_NUMBER && (lpos = diagnosis[n].lenta_position) >= 0)
			{
				errid = this->greibach.getRule(this->diagnosis[n].nrule).iderror;
				Error::ERROR err = Error::geterror(errid);
				sprintf_s(buf, MFST_DIAGN_MAXSIZE, "%d:  ������ %d,  %s", err.id, LT.table[lpos].sn, err.message);
				rc = buf;
			}
			return rc;
		}
	};
}