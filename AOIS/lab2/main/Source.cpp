#include"SpreadSheetOfTruth.h"

int main() {
	string formula = "( ( A > B ) & ( ( B | A ) ~ A ) )";
	SpreadsheetOfTruth sheet(formula);
	sheet.PrintSubformules();

	return 0;
}
