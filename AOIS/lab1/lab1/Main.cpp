#include<iostream>
#include"BinaryMath.h"

int main()
{
	BinaryForm a;
	/*a.SetDecimal(-12);
	a.PrintBinaryForm();
	a.PrintDecimalForm();
	a.ConvertToInverse();
	a.PrintBinaryForm();
	a.ConvertToAdditional(0);
	a.PrintBinaryForm();
	a.ConvertToInverse();
	a.PrintBinaryForm();
	a.ConvertToAdditional(1);
	a.PrintBinaryForm();*/

	BinaryMath b;
	BinaryMath c;
	c.SetDecimal(2);
	c.PrintDecimalForm();
	b.SetDecimal(-6);
	b.PrintDecimalForm();
	c.PrintBinaryForm();
	b.PrintBinaryForm();
	BinaryMath d;
	d = b + c;
	d.PrintBinaryForm();
	d.PrintDecimalForm();

	return 0;
}