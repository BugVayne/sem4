#include"SpreadSheetOfTruth.h"

int main() {
	string formula = "( ( A > B ) & ( ( B | A ) ~ A ) )";
	SpreadsheetOfTruth sheet(formula);


	return 0;
}
