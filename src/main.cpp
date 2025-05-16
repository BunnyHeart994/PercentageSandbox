#include <iostream>
#include <iomanip>
#include <string>
#include "../include/definitions.h"

const USHORT COL_WIDTH_MENU = 98;

static void closeApp() { PRINT_ENDL(std::endl << "Bye." << std::endl); }
static void getPercentageOf()
{
	float percentage, target;
	PRINT_ENDL("*PERCENTAGE CALCULATOR*");
	PRINT("Enter a percentage: ");
	GET(percentage);
	PRINT("Enter the target number: ");
	GET(target);
	//float result = target * (percentage / 100);
	PRINT_ENDL(percentage << "% of " << target << " is " << target * (percentage / 100) << "." << std::endl);
}
static void minusPercentageOf()
{
	float target, percentage;
	PRINT_ENDL("*PERCENTAGE EXTRACTOR*");

}
static void mainMenu(char defChar)
{
	PRINT_ENDL(std::setfill(defChar) << std::setw(COL_WIDTH_MENU) << ""); // Draw upper boundary.
	PRINT(std::setfill(' '));

	PRINT(std::left << std::setw(COL_WIDTH_MENU / 3) << "| 1 - Percentage calculator" << '|');
	PRINT(std::left << std::setw(COL_WIDTH_MENU / 3) << "2 - Incognito" << '|');
	PRINT_ENDL(std::right << std::setw((COL_WIDTH_MENU / 3) + COL_WIDTH_MENU % 3 - 2) << "3 - Incognito |");

	PRINT_ENDL(std::setfill(defChar) << std::setw(COL_WIDTH_MENU) << ""); // Draw lower boundary.

	USHORT opt;
	PRINT("Enter an option: ");
	while (true)
	{
		GET(opt);
		switch (opt)
		{
		case 1:
			getPercentageOf(); break;
		case 0:
			closeApp(); break;
		default:
			PRINT("Invalid option. Try again." << std::endl << "Enter an option: "); continue;
		}
		break;
	}
}
int main()
{
	PRINT_ENDL("");
	//PRINT_ENDL("*************************************");
	PRINT_ENDL("Percentage Sandbox by Henrique Soares" << std::endl);
	mainMenu('*');

	//PRINT_ENDL(std::endl << "*************************************" << std::endl);
}