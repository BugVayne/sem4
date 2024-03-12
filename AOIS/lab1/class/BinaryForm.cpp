#include "BinaryForm.h"
#include <cmath>
void BinaryForm::PrintBinaryForm()
{
	cout << "\n    --- Binary form --- \n";
	if (this->is_negative)
		cout << "\t 1 ";
	else
		cout << "\t 0 ";
	for (vector<bool>::iterator Iter = this->binary_form.begin(); Iter!=this->binary_form.end() ; Iter++)
	{
		cout << " " << *Iter;
	}
	cout << endl;
}

void BinaryForm::PrintDecimalForm()
{
	cout << "\n    --- Decimal form --- \n";
	cout << "\t" << this->number << endl;
}
void BinaryForm::ConvertToBinary()
{
	if (this->number == 0)
	{
		this->PushTop(0);
		return;
	}
	int a = this->number;
	if (a < 0)
		this->is_negative = true;
	for (a = abs(a); a > 0; a = a / 2)
	{
		this->PushTop( a % 2);
	}
	//this->PushTop(this->is_negative); //if you want to add - to whole number
}

void BinaryForm::PushTop(bool _element)
{
	vector<bool> new_vector;
	new_vector.push_back(_element);
	for (size_t i = 0; i < this->binary_form.size(); i++)
		new_vector.push_back(this->binary_form.at(i));
	this->binary_form = new_vector;
}

void BinaryForm::ConvertToDecimal()
{
	this->number = 0;
	for (size_t i = 0; i<this->binary_form.size(); i++)
	{
		this->number += int(this->binary_form.at(i)) * pow(2, (this->binary_form.size() - 1) - i);
	}
	if (this->is_negative)
		this->number = this->number * -1;
}



void BinaryForm::ConvertToInverse()
{
	for (size_t i = 0; i < this->binary_form.size(); i++)
	{
		if (this->binary_form.at(i) == 0)
			this->binary_form.at(i) = 1;
		else this->binary_form.at(i) = 0;
	}
	this->type = INVERSE;
}

void BinaryForm::ConvertToAdditional(bool _is_to_straight)
{ 	
	bool is_next_rank = true;
	for (size_t i = this->binary_form.size()-1; i>=0 && is_next_rank == true; --i)
	{	
		if (this->binary_form.at(i) == 1)
		{
			this->binary_form.at(i) = 0;
		}
		else
		{
			this->binary_form.at(i) = 1;
			is_next_rank = false;
		}
	}
	if (is_next_rank == true)
	{
		//this->binary_form.at(0) = 0;
		this->PushTop(1);
	}
	if (_is_to_straight)
	{
		this->type = STRAIGHT;
		this->ConvertToDecimal();
	}
	else 
		this->type = ADDITIONAL;
}

