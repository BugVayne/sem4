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

	BinaryMath b;
	BinaryMath c;
	c.SetDecimal(-1);
	b.SetDecimal(50);
	c.PrintDecimalForm();
	b.PrintDecimalForm();
	c.PrintBinaryForm();
	b.PrintBinaryForm();
	BinaryMath d;
	d = b + c;
	d.PrintBinaryForm();
	d.PrintDecimalForm();

	return 0;
}