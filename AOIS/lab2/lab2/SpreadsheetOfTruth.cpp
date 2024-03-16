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
	
	/*while (!my_stack.empty())
	{
		char iter_char = my_stack.top();
		if (iter_char == ')')
			flag = 1;
		if (flag)
			subformule += iter_char;
		if (iter_char == '(')
		{
			flag = 0;
			reverse(subformule.begin(), subformule.end());
			this->subformules.push_back(subformule);
			subformule = "";
		}
		my_stack.pop();
	}*/
	
	for (char iter_char : this->formula)
	{
		stack<char> stack;
		if (iter_char == '(')
			stack.push(iter_char);
		else if (iter_char == ')')
		{
			string subformula = "";
			while (!stack.empty() && stack.top() != '(')
			{
				subformula = stack.top() + subformula;
				stack.pop();
			}
			stack.pop();
			subformula = subformula + ')';
			this->subformules.push_back(subformula);
		}
		else
			stack.push(iter_char);
	}

	for (size_t i = 0; i < this->subformules.size(); i++)
	{
		cout << endl << i << " - " << subformules.at(i) << endl;
	}
}
