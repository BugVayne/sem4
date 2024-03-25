#include<iostream>
#include"BinaryMath.h"
#include"BinaryFloat.h"
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
	a.SetDecimal(13);
	b.SetDecimal(3);
	cout << " A: ";
	a.PrintBinaryForm();
	cout << " B: ";
	b.PrintBinaryForm();
	cout << " A _ B : \n";
	BinaryMath result;
	result = a / b;
	(result).PrintBinaryForm();
	(result).PrintDecimalForm();


	/*BinaryFloat a(15.23), b(1.32);
	cout << "\nresult\n";
	(a+b).PrintBinary();*/

	return 0;
}