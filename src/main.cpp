#include <iostream>
#include <iomanip>
//#include <exception>
#include <format>
#include <cmath>
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
static void getInput(USHORT* opt) // USHORT input getter with checker for non-USHORT input
{
	bool stop = false;
	do
	{
		GET(*opt);
		try
		{
			if (std::cin.fail()) throw "Please enter an integer.\nTry again: ";
			else stop = true;
		}
		catch (const char* msg)
		{
			PRINT(msg);
			stop = false;
			CLEARIGNORECHAR_CIN;
		}
	} while (stop == false);
}
static void getInput(float* opt) // Overloaded for floats
{
	bool stop = false;
	do
	{
		GET(*opt);
		try
		{
			if (std::cin.fail()) throw "Please enter an integer.\nTry again: ";
			else stop = true;
		}
		catch (const char* msg)
		{
			PRINT(msg);
			stop = false;
			CLEARIGNORECHAR_CIN;
		}
	} while (stop == false);
}
static USHORT extractPercentage() // 1
{
	if (descPrompt(describe1) == 0) return -1;

	float target, percentage;
	PRINT_ENDL("* PERCENTAGE EXTRACTOR *");
	PRINT("Enter the target number: ");
	getInput(&target);
	PRINT("Enter a percentage: ");
	getInput(&percentage);
	float result = target * (percentage / 100);
	bool expNotValid = (std::isinf(result) || std::isnan(result));
	if (expNotValid)
		PRINT_ENDL("THE RESULT IS EITHER NOT A NUMBER, OR INFINITY");
	else PRINT_ENDL(percentage << "% of " << target << " is " << result << "." << std::endl);
	
	return result; //target * (percentage / 100);

	//mainMenu(MENU_ICON); // PROBLEM -> DON'T DO THIS
}
static USHORT percentageSubtractor() // 2
{
	if (descPrompt(describe2) == 0) return -1;

	float target, percentage;
	PRINT_ENDL("* PERCENTAGE SUBTRACTOR *");
	PRINT("Enter the target number: ");
	getInput(&target);
	PRINT("Enter a percentage (1 - 100): ");
	getInput(&percentage);
	while (percentage < 1 || percentage > 100)
	{
		PRINT("Invalid value. Only 1 through 100 is allowed." << std::endl << "Try again: ");
		getInput(&percentage);
	}
	float result = target - target * (percentage / 100);
	bool expNotValid = (std::isinf(result) || std::isnan(result));
	if (expNotValid)
		PRINT_ENDL("THE RESULT IS EITHER NOT A NUMBER, OR INFINITY");
	else PRINT_ENDL(target << " minus " << percentage << "% is " << result << ".");

	return result; //target - target * (percentage / 100);
}
static USHORT percentageOfTotal() // 3 // 1
{
	if (descPrompt(describe3) == 0) return -1;

	float part, total;
	PRINT_ENDL("* PERCENTAGE OF TOTAL *");
	PRINT("Enter the first number (part): ");
	getInput(&part);
	PRINT("Enter the second number (total): ");
	getInput(&total); // 9 -> 90 = 10
	//90 100
	//9  x
	float result = (part * 100) / total;
	bool expNotValid = (std::isinf(result) || std::isnan(result));
	if (expNotValid)
		PRINT_ENDL("THE RESULT IS EITHER NOT A NUMBER, OR INFINITY");
	else PRINT_ENDL(part << " represents " << result << "% of " << total << ".");
	return result;
}
static USHORT reversePercentage() // 4
{
	// % = 50 / total = 300 / result+ = 200. because 200 + 50% of 200 is 300 (total);
	// 300 = x + x * 50/100
	// 1.5x = 300
	// 200
	
	// t = x + x * p/100
	// 1.5x = 300
	// 200
	
	if (descPrompt(describe4) == 0) return -1;

	float percentage, total;
	PRINT_ENDL("* REVERSE PERCENTAGE *");
	PRINT("Enter the percentage: ");
	getInput(&percentage);
	PRINT("Enter the desired total: ");
	getInput(&total);
	PRINT_ENDL("");

	// EQUATION CODE
	// t = x + x * p/100
	// 300 = x + x * 0.5
	// 300 = x(1 + 0.5)
	// 1.5 * x = 300 ---
	// x * 1.5 = 300
	// x = 300 / 1.5
	// final = total / x + x * (percentage/100)

	float x = 1;

	// Old PRINT (without std::format) // HAD PROBLEM WITH "std::fixed << std::setprecision()"
	/*PRINT_ENDL("To get to " << total << " by ADDING " << percentage << "% of a number to itself, this number must be " <<
		std::fixed << std::setprecision(2) << total / (x + x * (percentage / 100)) << "." << std::endl);*/
	float currExpResult = total / (x + x * (percentage / 100));
	bool expNotValid = (std::isinf(currExpResult) || std::isnan(currExpResult));
	/*bool expNotValid = (std::isinf(total / (x + x * (percentage / 100))) ||
		std::isnan(total / (x + x * (percentage / 100))));*/
	
	/*PRINT(std::format(
	"To get to {0} by ADDING {1}% of a number to itself, this number must be {2}.\n",
	total, percentage), (expNotValid) ? "RESULT IS NaN OR INFINITY" : currExpResult);*/

	/*PRINT((expNotValid) ? // Problematic ternary
		std::format("To get to {0} by ADDING {1}% of a number to itself, this number must be {2}.\n",
		total, percentage, "RESULT IS NOT A NUMBER, OR INFINITY") :
		std::format("To get to {0} by ADDING {1}% of a number to itself, this number must be {2:.2f}.\n",
			total, percentage, currExpResult));*/
	if (expNotValid)
		PRINT(std::format("To get to {0} by ADDING {1}% of a number to itself, this number must be {2}.\n",
			total, percentage, "(RESULT IS NOT A NUMBER, OR INFINITY)"));
	else PRINT(std::format("To get to {0} by ADDING {1}% of a number to itself, this number must be {2:.2f}.\n",
		total, percentage, currExpResult));

	// Test equation
	/*final = total - (total - (total * (percentage / 100)));
	PRINT_ENDL("NEW: " << final);*/

	// SECOND EQUATION CODE | t = 300 | p = 50 | x = 1 |
	// t = x - x * p/100
	// 300 = x - x * 0.5 | 300 = 600 - 600 * 0.5
	// 300 = x(1 - 0.5)
	// x * 0.5 = 300
	// x = 300 / 0.5
	// final = total / x - x * (percentage/100)

	// Old PRINT (without std::format) // HAD PROBLEM WITH "std::fixed << std::setprecision()"
	/*PRINT_ENDL("To get to " << total << " by SUBTRACTING " << percentage << "% of a number to itself, this number must be " <<
		std::fixed << std::setprecision(2) << total / (x - x * (percentage / 100)) << "." << std::endl);*/
	
	/*PRINT(std::format(
		"And to get to {0} by SUBTRACTING {1}% of a number from itself, this number must be {2:.2f}.\n\n",
		total, percentage, (total / (x - x * (percentage / 100)))));*/

	currExpResult = total / (x - x * (percentage / 100));
	expNotValid = (std::isinf(currExpResult) || std::isnan(currExpResult));
	/*PRINT((expNotValid) ? // Problematic ternary
		std::format("To get to {0} by ADDING {1}% of a number to itself, this number must be {2}.\n",
			total, percentage, "RESULT IS NOT A NUMBER, OR INFINITY") :
		std::format("To get to {0} by ADDING {1}% of a number to itself, this number must be {2:.2f}.\n",
			total, percentage, currExpResult));*/
	if (expNotValid)
		PRINT(std::format("To get to {0} by ADDING {1}% of a number to itself, this number must be {2}.\n",
			total, percentage, "(RESULT IS NOT A NUMBER, OR INFINITY)"));
	else PRINT(std::format("To get to {0} by ADDING {1}% of a number to itself, this number must be {2:.2f}.\n",
			total, percentage, currExpResult));

	PRINT_ENDL("NOTE: Every one of this program's functions return a value (for certain purposes). As only one value " <<
		std::endl << "can be returned from this one, choose wether it should return its operation with addition or subtraction." << std::endl);
	
	USHORT opt;
	bool flag = false;
	do
	{
		if (flag) PRINT("Invalid option. ");
		PRINT("Enter '0' for ADDITION and '1' for SUBTRACTION: ");
		getInput(&opt);
		PRINT_ENDL("");
		flag = (opt != 0 && opt != 1);
	} while (flag);

	if (opt == 0) PRINT_ENDL("ADDITION RETURNED");
	else PRINT_ENDL("SUBTRACTION RETURNED");

	return (opt == 0) ? total / (x + x * (percentage / 100)) : total / (x - x * (percentage / 100));
}
USHORT descPrompt(void (*funcPtr)()) // DESCRIPTION PROMPT - FUNCTION POINTER
{
	USHORT opt;
	//bool stop = false;
	funcPtr();
	PRINT_ENDL("Do you wish to continue?");
	while (true)
	{
		PRINT("1 - Yes" << std::endl << "0 - Back to main menu" << std::endl <<
			"---> ");
		getInput(&opt);
		switch (opt)
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
			PRINT_ENDL(std::right << std::setw((COL_WIDTH_MENU / 3) + COL_WIDTH_MENU % 3 - 2) << "3 - Percentage of total |");

			PRINT(std::left << std::setw(COL_WIDTH_MENU / 3) << "| 4 - Reverse percentage" << '|');
			PRINT(std::left << std::setw(COL_WIDTH_MENU / 3) << "Coming in the future" << '|');
			PRINT_ENDL(std::right << std::setw((COL_WIDTH_MENU / 3) + COL_WIDTH_MENU % 3 - 2) << "Coming in the future |");

			/*PRINT(std::right << std::setw(COL_WIDTH_MENU / 3 + 1) << '|'); // TEMPLATE FOR WHEN BOXES AREN'T FILLED
			PRINT_ENDL(std::right << std::setw((COL_WIDTH_MENU / 3) + COL_WIDTH_MENU % 3 - 2) << '|');*/

			PRINT_ENDL(std::setfill(defChar) << std::setw(COL_WIDTH_MENU) << ""); // Draw lower boundary.
		}
		
		drawBox = true;
		PRINT("Enter an option from the box above (or '0' to quit the program): ");
		//GET(opt);
		getInput(&opt);
		switch (opt)
		{
		case 0: break;
		case 1:
			extractPercentage(); break;
		case 2:
			percentageSubtractor(); break;
		case 3:
			percentageOfTotal(); break;
		case 4:
			reversePercentage(); break;
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
	
	// NEW FUNC USAGE EXAMPLE
	/*USHORT opt;
	getInput(&opt);
	PRINT_ENDL(std::endl << "after func: " << opt);*/

	PRINT_ENDL("Percentage Sandbox by Henrique Soares" << std::endl);
	mainMenu(MENU_ICON);

	//PRINT_ENDL(std::endl << "*************************************" << std::endl);
	return 0;
}