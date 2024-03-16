#pragma once
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<cctype>
#include<cmath>
#include<algorithm>
using namespace std;


class SpreadsheetOfTruth
{
private:
	vector<vector<bool>> sheet;
	string formula;
	size_t rows, columns;
	string atomar_formules;
	vector<string> subformules;
	void InitializeSubFormules();
public:
	SpreadsheetOfTruth(string _formula);
};

