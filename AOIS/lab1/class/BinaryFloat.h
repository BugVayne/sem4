#pragma once
#include<vector>
#include<iostream>
#include<cmath>

using namespace std;



class BinaryFloat
{
private:
	double number;
	vector<bool> exp;
	vector<bool> mantiss;
	size_t mantiss_size = 23;
	size_t exp_size = 8;
	size_t shift=0;

public:
	BinaryFloat(double _num) : number(_num) { this->CalculateMantissAndExp(); };
	BinaryFloat() {};
	void CalculateMantissAndExp();
	void CalcBinary(double _number);
	void CalcMantiss(double _number);
	void PrintBinary();
	BinaryFloat operator+(BinaryFloat _number);
	void ShiftMantiss(size_t _shift);
	vector<bool> MantissSum(BinaryFloat _number);
	void SetMantiss(vector<bool> _mantiss) { this->mantiss = _mantiss; }
	void SetExp(vector<bool> _exp) { this->exp = _exp; }
};

