#include <iostream>
#include <string>
#include <stack>

using namespace std;

template<typename T>
class Stack: public stack<T>		// my stack: pop == top + pop, much more comfortable = =b
{
public:
	T pop()
	{
		T re = stack<T>::top();//好东西
		stack<T>::pop();
		return re;
	}
};

class BoolExpression
{
public:
	BoolExpression(): exp("") {}

	BoolExpression(const string& s): exp(s){}

	static void Trim(string& s)
	{
		string newstr = "";
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] != ' ')
				newstr += s[i];
		}
		s = newstr;
	}

	void SetExpression(const string& s)
	{
		exp = s;
	}

	enum opeType
	{
		opeNot, opeAnd, opeOr, opeLPar, opeRPar
	};

	bool GetValue()
	{
		Stack<bool> sOperand;
		Stack<opeType> sOperator;
		int i = 0;
		int l = exp.length();
		bool a, b;
		while(i < l)
		{
			switch(exp[i])
			{
			case '!':
				if(sOperator.empty() == false && sOperator.top() == opeNot)		// !! == no ! at all
					sOperator.pop();
				else
					sOperator.push(opeNot);
				break;
			case '&':
				if(sOperator.empty() == false && sOperator.top() == opeAnd)		// 当且仅当前一个运算式逻辑与时，做运算
				{
					sOperator.pop();
					a = sOperand.pop();
					b = sOperand.pop();
					sOperand.push(a && b);
				}
				sOperator.push(opeAnd);
				break;
			case '|':
				if(sOperator.empty() == false && (sOperator.top() == opeAnd || sOperator.top() == opeOr))	// 由于优先级低，所以时逻辑与和逻辑或都算掉
				{
					a = sOperand.pop();
					b = sOperand.pop();
					if(sOperator.pop() == opeAnd)
						sOperand.push(a && b);
					else
						sOperand.push(a || b);
				}
				sOperator.push(opeOr);
				break;
			case 'V':								// 值前面可能有逻辑非
				if(sOperator.empty() == false && sOperator.top() == opeNot)
				{
					sOperand.push(false);
					sOperator.pop();
				}
				else
					sOperand.push(true);
				break;
			case 'F':								// 值前面可能有逻辑非
				if(sOperator.empty() == false && sOperator.top() == opeNot)
				{
					sOperand.push(true);
					sOperator.pop();
				}
				else
					sOperand.push(false);
				break;
			case '(':								// 括号前面也可能有逻辑非
				sOperator.push(opeLPar);
				break;
			case ')':
				opeType ope;
				while((ope = sOperator.pop()) != opeLPar)
				{
					a = sOperand.pop();
					b = sOperand.pop();
					if(ope == opeAnd)
						sOperand.push(a && b);
					else
						sOperand.push(a || b);
				}
				if(sOperator.empty() == false && sOperator.top() == opeNot)		// 取反后压入
				{
					sOperator.pop();
					sOperand.push(!(sOperand.pop()));
				}
				break;
			default:
				break;
			}
			i++;
		}

		while(sOperator.empty() == false)
		{
			a = sOperand.pop();
			b = sOperand.pop();
			if(sOperator.pop() == opeAnd)
				sOperand.push(a && b);
			else
				sOperand.push(a || b);
		}

		return sOperand.pop();
	}
private:
	string exp;
};

int main()
{
	int i = 1;
	string exp;
	while(getline(cin ,exp))
	{
		BoolExpression::Trim(exp);	// remove white space from expressions
		if(exp != "")
			cout << "Expression " << i++ << ": " << (BoolExpression(exp).GetValue() == true? 'V': 'F') << endl;
	}

	return 0;
}
