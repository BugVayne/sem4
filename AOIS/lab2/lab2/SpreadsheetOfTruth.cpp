#include "SpreadsheetOfTruth.h"

SpreadsheetOfTruth::SpreadsheetOfTruth(string _formula)
{
	this->formula = _formula;
	this->atomar_formules = "";
	int counter_of_letters = 0;
	for (size_t i = 0; i < formula.length(); i++)
	{
		if (isalpha(formula[i]))
			this->atomar_formules += formula[i];
	}
	this->rows = pow(2,this->atomar_formules.length());
	this->columns = counter_of_letters;
	for (size_t i = 0; i < formula.length(); i++)
	{
		if (formula[i] == '(')
			this->columns++;
	}
	this->InitializeSubFormules();
}

void SpreadsheetOfTruth::InitializeSubFormules()
{
	stack<char> stack;
	for (size_t i = 0; i < this->formula.length(); i++)
	{
		stack.push(this->formula.at(i));
		if (this->formula.at(i) == ')')
		{
			string subformule = "";
			while (stack.top() != '(')
			{
				subformule += stack.top();
				stack.pop();
			}
			subformule += stack.top();
			stack.pop();
			reverse(subformule.begin(), subformule.end());
			this->subformules.push_back(subformule);
			stack.push(static_cast<char>((this->subformules.size() - 1) + '0'));
		}
	}

	
}
void SpreadsheetOfTruth::PrintSubformules()
{
	cout << "  Subformules:  \n";
	for (size_t i = 0; i < this->subformules.size(); i++)
	{
		cout << this->subformules.at(i) << " --- ";
	}
	cout << endl;
}
