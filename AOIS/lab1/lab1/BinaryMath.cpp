#include "BinaryMath.h"
#include"cmath"


BinaryMath BinaryMath::operator+ (BinaryMath _binary_number)
{
	bool is_result_negative = 0;
	bool is_one_negative = 0;
	if (_binary_number.is_negative == 1 && this->is_negative == 1)
	{
		is_result_negative = 1;
	}
	else if (this->is_negative == 1)
		{
		if (abs(this->number) > abs(_binary_number.number))
			is_result_negative = 1;
		is_one_negative = 1;
		this->ConvertToInverse();
		this->ConvertToAdditional(0);
		}
	else if (_binary_number.is_negative == 1)
		{
		if (abs(this->number) < abs(_binary_number.number))
			is_result_negative = 1;
		is_one_negative = 1;
		_binary_number.ConvertToInverse();
		_binary_number.ConvertToAdditional(0);
		}
	
	BinaryMath result;
	vector<bool> binary_sum;
	bool is_rank_up = 0;
	int i = this->binary_form.size()-1;
	int j = _binary_number.binary_form.size()-1;
	while (i >= 0 || j >= 0 || is_rank_up != 0) {
		int sum = is_rank_up;

		if (i >= 0)
		{
			sum += this->binary_form[i];
			i--;
		}
		if (j >= 0)
		{
			sum += _binary_number.binary_form[j];
			j--;
		}
		
		binary_sum.insert(binary_sum.begin(), sum % 2);
		//cout << "xxxxxxxxx     " << binary_sum.size()<<"  "<<sum%2 << endl;
		is_rank_up = sum / 2;
	}

	result.SetBinary(binary_sum, is_result_negative);
	if (is_one_negative)
	{
		result.ConvertToInverse();
		result.ConvertToAdditional(1);
	}
	return result;
}