#include "BinaryMath.h"
#include"cmath"


BinaryMath BinaryMath::operator+ (BinaryMath _binary_number)
{
	BinaryForm a(*this);
	BinaryForm b(_binary_number);
	bool is_result_negative = 0;
	bool is_one_negative = 0;
	bool is_both_negative = 0;
	if (a.is_negative == 1 && b.is_negative == 1)
	{
		is_both_negative = 1;
		is_result_negative = 1;
	}
	else if (a.is_negative == 1)
		{
		if (abs(a.number) > abs(b.number))
			is_result_negative = 1;
		is_one_negative = 1;
		a.ConvertToInverse();
		a.ConvertToAdditional(0);
		a.PushTop(a.is_negative);
		b.PushTop(b.is_negative);
		}
	else if (b.is_negative == 1)
		{
		if (abs(a.number) < abs(b.number))
			is_result_negative = 1;
		is_one_negative = 1;
		b.ConvertToInverse();
		b.ConvertToAdditional(0);	
		a.PushTop(a.is_negative);
		b.PushTop(b.is_negative);
		}
	
	
	BinaryMath result;
	vector<bool> binary_sum;
	bool is_rank_up = 0;
	int i = a.binary_form.size()-1;
	int j = b.binary_form.size()-1;
	
	while (i >= 0 || j >= 0 || is_rank_up != 0) {
		int sum = is_rank_up;

		if (i >= 0)
		{
			sum += a.binary_form[i];
			i--;
		}
		if (j >= 0)
		{
			sum += b.binary_form[j];
			j--;
		}
		
		binary_sum.insert(binary_sum.begin(), sum % 2);
		is_rank_up = sum / 2;
	}
	if (is_one_negative)
	{
		binary_sum.erase(binary_sum.begin());
	}
	result.SetBinary(binary_sum, is_result_negative);
	if (is_result_negative && !is_both_negative)
	{
		result.ConvertToInverse();
		result.ConvertToAdditional(1);
	}
	return result;
}