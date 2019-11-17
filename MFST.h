#pragma once
#include <stack>
#include <iomanip>
#include "LT.h"
#include "GRB.h"
#define MFST_DIAGN_MAXSIZE 2*ERROR_MAXSIZE_MESSAGE
#define MFST_DIAGN_NUMBER 3
#define MFST_TRACE_START std::cout<<std::setw(4)<<std::left<<"���"<<":" \
								  <<std::setw(20)<<std::left<<" �������" \
								  <<std::setw(30)<<std::left<<" ������� �����" \
								  <<std::setw(20)<<std::left<<" ����" \
								  <<std::endl;
int FST_TRACE_n = -1;
char rbuf[205], sbuf[205], lbuf[1024]; // ������
#define ISNS(n) GRB::Rule::Chain::isN(n)
#define MFST_TRACE1 std::cout<<std::setw(4)<<std::left<<++FST_TRACE_n<<": " \
							 <<std::setw(20)<<std::left<<rule.getCRule(rbuf, nrulechain) \
							 <<std::setw(30)<<std::left<<getCLenta(lbuf, lenta_position) \
							 <<std::setw(20)<<std::left<<getCSt(sbuf) \
							 <<std::endl;
#define MFST_TRACE2 std::cout<<std::setw(4)<<std::left<<FST_TRACE_n<<": " \
							 <<std::setw(20)<<std::left<<" " \
							 <<std::setw(30)<<std::left<<getCLenta(lbuf, lenta_position) \
							 <<std::setw(20)<<std::left<<getCSt(sbuf) \
							 <<std::endl;
#define MFST_TRACE3 std::cout<<std::setw(4)<<std::left<<++FST_TRACE_n<<": " \
							 <<std::setw(20)<<std::left<<" " \
							 <<std::setw(30)<<std::left<<getCLenta(lbuf, lenta_position) \
							 <<std::setw(20)<<std::left<<getCSt(sbuf) \
							 <<std::endl;
#define MFST_TRACE4(c) std::cout<<std::setw(4)<<std::left<<++FST_TRACE_n<<": "<<std::setw(20)<<std::left<<c<<std::endl;
#define MFST_TRACE5(c) std::cout<<std::setw(4)<<std::left<<  FST_TRACE_n<<": "<<std::setw(20)<<std::left<<c<<std::endl;
#define MFST_TRACE6(c,k) std::cout<<std::setw(4)<<std::left<<  FST_TRACE_n<<": "<<std::setw(20)<<std::left<<c<<k<<std::endl;
#define MFST_TRACE7 std::cout<<std::setw(4)<<std::left<<state.lenta_position<<": " \
							 <<std::setw(20)<<std::left<<rule.getCRule(rbuf, state.nrulechain) \
							 <<std::endl;
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
			for (int k = 0; k < this->lenta_size; k++) this->lenta[k] = TS(LT.table[k].lexema[0]);
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
		bool savestate() // ��������� ��������� ��������
		{
			this->storestate.push(MfstState(this->lenta_position, this->st, this->nrule, this->nrulechain));
			MFST_TRACE6("SAVESTATE:", this->storestate.size());
			return true;
		}
		bool reststate() // ������������ ��������� ��������
		{
			bool rc = false;
			MfstState state;
			if (rc = (this->storestate.size() > 0))
			{
				state = this->storestate.top();
				this->lenta_position = state.lenta_position;
				this->st = state.st;
				this->nrule = state.nrule;
				this->nrulechain = state.nrulechain;
				this->storestate.pop();
				MFST_TRACE5("RESSTATE")
				MFST_TRACE2
			}
			return rc;
		}
		bool push_chain(GRB::Rule::Chain chain) // ��������� ������� ������� � ����
		{
			for (int k = chain.size - 1; k >= 0; k--) this->st.push(chain.nt[k]);
			return true;
		}
		bool savediagnodsis(RC_STEP prc_step) //  ��������� ���
		{
			bool rc = false;
			short k = 0;
			while (k < MFST_DIAGN_NUMBER && this->lenta_position <= this->diagnosis[k].lenta_position) k++;
			if (rc = (k < MFST_DIAGN_NUMBER))
			{
				this->diagnosis[k] = MfstDiagnosis(this->lenta_position, prc_step, this->nrule, this->nrulechain);
				for (short j = k + 1; j < MFST_DIAGN_NUMBER; j++) this->diagnosis[j].lenta_position = -1;
			}
			return rc;
		}
		RC_STEP step() // ��� ��������
		{
			RC_STEP rc = SURPRISE;
			if (this->lenta_position < this->lenta_size)
			{
				if (ISNS(this->st.top()))
				{
					GRB::Rule rule;
					if ((this->nrule = this->greibach.getRule(this->st.top(), rule)) >= 0)
					{
						GRB::Rule::Chain chain;
						if ((this->nrulechain = rule.getNextChain(this->lenta[this->lenta_position], chain, this->nrulechain + 1)) >= 0)
						{
							MFST_TRACE1
							savestate(); this->st.pop(); this->push_chain(chain); rc = NS_OK;
							MFST_TRACE2
						}
						else
						{
							MFST_TRACE4("TNS_NORULECHAIN / NS_NORULE")
							savediagnodsis(NS_NORULECHAIN); rc = reststate() ? NS_NORULECHAIN : NS_NORULE;
						}
					}
					else rc = NS_ERROR;
				}
				else if ((this->st.top() == this->lenta[this->lenta_position]))
				{
					this->lenta_position++; this->st.pop(); this->nrulechain = -1; rc = TS_OK;
					MFST_TRACE3
				}
				else { MFST_TRACE4("TS_NOK/NS_NORULECHAIN") rc = reststate() ? TS_NOK : NS_NORULECHAIN; }
			}
			else { rc = LENTA_END; MFST_TRACE4("LENTA_END") }
			return rc;
		}
		bool start() // ��������� �������
		{
			bool rc = false;
			RC_STEP rc_step = SURPRISE;
			char buf[MFST_DIAGN_MAXSIZE];
			rc_step = step();
			while (rc_step == NS_OK || rc_step == NS_NORULECHAIN || rc_step == TS_OK || rc_step == TS_NOK) rc_step = step();
			switch (rc_step)
			{
			case LENTA_END: 
			{
				MFST_TRACE4("-------->NS_NORULE")
				std::cout << "----------------------------------------------------" << std::endl;
				sprintf_s(buf, MFST_DIAGN_MAXSIZE, "%d: ����� ����� %d,  �������������� ������ �������� ��� ������", 0, this->lenta_size);
				std::cout << std::setw(4) << std::left << 0 << ": ����� ����� " << this->lenta_size << ", �������������� ������ �������� ��� ������" << std::endl;
				rc = true;
			} break;
			case NS_NORULE:
			{
				MFST_TRACE4("-------->NS_NORULE")
				std::cout << "----------------------------------------------------" << std::endl;
				std::cout << getDiagnosis(0, buf) << std::endl;
				std::cout << getDiagnosis(1, buf) << std::endl;
				std::cout << getDiagnosis(2, buf) << std::endl;
			} break;
			case NS_NORULECHAIN: {MFST_TRACE4("-------->NS_NORULECHAIN")} break;
			case NS_ERROR: {MFST_TRACE4("-------->NS_ERRROR")} break;
			case SURPRISE: {MFST_TRACE4("-------->SURPRISE")} break;
			}
			return rc;
		}
	};
}