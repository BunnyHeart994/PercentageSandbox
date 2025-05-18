#include <iostream>
#include <iomanip>
#include "../include/definitions.h"
#include "../include/descriptions.h"
//#define MENU_ICON '*'

// CONSTANTS
const USHORT COL_WIDTH_MENU = 98; 
const char MENU_ICON = '=';		    

// PROTOTYPED FUNCTIONS
static void mainMenu(char defChar);
USHORT descPrompt(void (*funcPtr)());

static void closeApp() { PRINT_ENDL(std::endl << "Bye." << std::endl); } // One-line function, because it's small.
static USHORT extractPercentage() // 1
{
	if (descPrompt(describe1) == 0) return -1;

	float target, percentage;
	PRINT_ENDL("* PERCENTAGE EXTRACTOR *");
	PRINT("Enter the target number: ");
	GET(target);
	PRINT("Enter a percentage: ");
	GET(percentage);
	//float result = target * (percentage / 100);
	PRINT_ENDL(percentage << "% of " << target << " is " << target * (percentage / 100) << "." << std::endl);
	
	return target * (percentage / 100);
	//mainMenu(MENU_ICON); // PROBLEM -> DON'T DO THIS
}
static USHORT percentageSubtractor() // 2
{
	if (descPrompt(describe2) == 0) return -1;

	float target, percentage;
	PRINT_ENDL("* PERCENTAGE SUBTRACTOR *");
	PRINT("Enter the target number: ");
	GET(target);
	PRINT("Enter a percentage (1 - 100): ");
	GET(percentage);
	while (percentage < 1 || percentage > 100)
	{
		PRINT("Invalid value. Only 1 through 100 is allowed." << std::endl << "Try again: ");
		GET(percentage);
	}
	PRINT_ENDL(target << " minus " << percentage << "% is " << target - target * (percentage / 100) << ".");

	return target - target * (percentage / 100);
}
static USHORT percentageOfTotal() // 3
{
	if (descPrompt(describe3) == 0) return -1;

	float part, total;
	PRINT_ENDL("* PERCENTAGE OF TOTAL *");
	PRINT("Enter the first number (part): ");
	GET(part);
	PRINT("Enter the second number (total): ");
	GET(total); // 9 -> 90 = 10
	//90 100
	//9  x
	PRINT_ENDL(part << " represents " << (part * 100) / total << "% of " << total << ".");
	return (part * 100) / total;
}
USHORT descPrompt(void (*funcPtr)()) // DESCRIPTION PROMPT - FUNCTION POINTER
{
	USHORT choice;
	//bool stop = false;
	funcPtr();
	PRINT_ENDL("Do you wish to continue?");
	while (true)
	{
		PRINT("1 - Yes" << std::endl << "0 - Back to main menu" << std::endl <<
			"---> ");
		GET(choice);
		switch (choice)
		{
		case 0: return 0; break;
		case 1: PRINT(std::endl); return 1; break; //stop = true; break;
		default: PRINT_ENDL("Invalid option. Try again."); break;
		}
		//break;
	}
}
static void mainMenu(char defChar) // Main menu
{
	USHORT opt;
	bool drawBox = true;
	do
	{
		if (drawBox)
		{
			PRINT(std::setfill(' '));
			PRINT_ENDL(std::setw(COL_WIDTH_MENU / 3) << "" << std::left << "* MAIN MENU *");
			PRINT_ENDL(std::setfill(defChar) << std::setw(COL_WIDTH_MENU) << ""); // Draw upper boundary.
			PRINT(std::setfill(' '));

			PRINT(std::left << std::setw(COL_WIDTH_MENU / 3) << "| 1 - Percentage extractor" << '|');
			PRINT(std::left << std::setw(COL_WIDTH_MENU / 3) << "2 - Percentage subtractor" << '|');
			PRINT_ENDL(std::right << std::setw((COL_WIDTH_MENU / 3) + COL_WIDTH_MENU % 3 - 2) << "3 - Percentage of total|");

			PRINT_ENDL(std::setfill(defChar) << std::setw(COL_WIDTH_MENU) << ""); // Draw lower boundary.
		}
		
		drawBox = true;
		PRINT("Enter an option from the box above (or '0' to quit the program): ");
		GET(opt);
		switch (opt)
		{
		case 0: break;
		case 1:
			extractPercentage(); break;
		case 2:
			percentageSubtractor(); break;
		case 3:
			percentageOfTotal(); break;
		default:
			PRINT("Invalid option. Try again." << std::endl); drawBox = false; break;
		}
	} while (opt != 0);
	closeApp();
	return;
}
int main()
{
	PRINT_ENDL("");
	//PRINT_ENDL("*************************************");
	PRINT_ENDL("Percentage Sandbox by Henrique Soares" << std::endl);
	mainMenu(MENU_ICON);
	//PRINT_ENDL(std::endl << "*************************************" << std::endl);
	return 0;
}