#include<iostream>
#include"BinaryMath.h"

int main()
{
	/*BinaryForm a;
	a.SetDecimal(-13);
	a.PrintBinaryForm();
	a.PrintDecimalForm();
	a.ConvertToInverse();
	a.PrintBinaryForm();
	a.ConvertToAdditional(0);
	a.PrintBinaryForm();*/

	BinaryMath a, b;
	a.SetDecimal(19);
	b.SetDecimal(19);
	cout << " A: ";
	a.PrintBinaryForm();
	cout << " B: ";
	b.PrintBinaryForm();
	cout << " A _ B : \n";
	(a / b).PrintBinaryForm();
	(a / b).PrintDecimalForm();
	
	return 0;
}