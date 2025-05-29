/*
Percentage Sandbox v1.0
An interactive program that performs some operations regarding percentage.

Copyright (C) 2025  Henrique Augusto Gonçalves Soares

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
// Contact me:
// Email: henriqueags994@gmail.com

#include <iostream>
#include <iomanip>
#include <format>
#include <cmath>
#include "../include/macros.h"
#include "../include/libraries.h"
//#define MENU_ICON '*'

// CONSTANTS
const USHORT COL_WIDTH_MENU = 98; 
const char MENU_ICON = '=';		    

// PROTOTYPED FUNCTIONS
static void mainMenu(char defChar);
USHORT descPrompt(void (*funcPtr)());

static void about()
{
	PRINT_ENDL("Percentage Sandbox v1.0  Copyright (C) 2025  Henrique Augusto Goncalves Soares" << std::endl <<
		"This program comes with ABSOLUTELY NO WARRANTY. This is free software, and you are welcome to" << std::endl <<
		"redistribute it under certain conditions.\n");
}
static void closeApp() { PRINT_ENDL(std::endl << "Bye." << std::endl); } // One-line function, because it's small.
static void getNumInput(float* num) // float input getter with checker for non-float input // CURRENT
{
	do
	{
		GET(*num);
		char nextChar = std::cin.peek();
		//PRINT_ENDL("DEBUG: c = " << nextChar);
		if (std::cin.fail() || (nextChar != EOF && nextChar != '\n'))
		{
			CLEAR_CIN;
			IGNORE_MAXCHARAMOUNT;
			PRINT("Only numbers are accepted." << std::endl << "Try again : ");
		}
		else break;
	} while (true);
}
static void getNumInput(USHORT* num) // Overloaded for USHORT
{
	do
	{
		GET(*num);
		char nextChar = std::cin.peek();
		//PRINT_ENDL("DEBUG: c = " << nextChar);
		if (std::cin.fail() || (nextChar != EOF && nextChar != '\n'))
		{
			CLEAR_CIN;
			IGNORE_MAXCHARAMOUNT;
			PRINT("Only numbers are accepted." << std::endl << "Try again : ");
		}
		else break;
	} while (true);
}
// FUTURE TEST
/*static void getSingleDigitNum(USHORT* num, USHORT digitLimit) // Overloaded for USHORT
{
	GET(*num);
	char nextChar = std::cin.peek();
	PRINT_ENDL("DEBUG: nextChar = " << nextChar);
	if (std::cin.fail() || (nextChar != EOF && nextChar != '\n'))
	{
		CLEAR_CIN;
		IGNORE_MAXCHARAMOUNT;
		PRINT("Only numbers are accepted." << std::endl << "Try again : ");
	}
}*/
// ORIGINALS
/*static void getInput(float* opt) // Overloaded for floats
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
}*/
// DESCRIPTIONS
void describe1() // PERCENTAGE EXTRACTOR
{
	PRINT_ENDL(std::endl << "Percentage extractor asks the user for a number then a percentage," << std::endl <<
		"then extracts that percentage from the number and shows the result of it." << std::endl <<
		"EXAMPLE: If user enter 100 as the number and 20 as the percentage, the program will return 20," << std::endl <<
		"because 20% of 100 is 20.");
}
void describe2() // PERCENTAGE SUBTRACTOR
{
	PRINT_ENDL(std::endl << "Percentage subtractor asks the user for a number than a percentage," << std::endl <<
		"then shows the remainder of that percentage subtracted from the number." << std::endl <<
		"EXAMPLE: If user enters 100 as the number and 60 as the percentage, the program returns 40," << std::endl <<
		"because 100 minus 60% (of 100) results in 40.");
}
void describe3() // PERCENTAGE OF TOTAL
{
	PRINT_ENDL(std::endl << "Percentage of total asks the user for two numbers, then shows" << std::endl <<
		"the percentage that the first number (part) represents of the second (total)." << std::endl <<
		"EXAMPLE: If user enters 100 as the first number and 200 as the second, the program returns 50%," << std::endl <<
		"because 100 represents 50% (half) of 200.");
}
void describe4() // REVERSE PERCENTAGE
{
	PRINT_ENDL(std::endl << "Reverse percentage asks the user for a percentage and a total," << std::endl <<
		"then shows the number (the unknown) that by having that percentage (relative to the unknown number)" << std::endl <<
		"added to or subtracted from it, results in the total." << std::endl <<
		"EXAMPLE: If user enters 50 as the percentage and 15 as the total, the addition and subtraction equations" << std::endl <<
		"will respectively return 10 and 30 as the unknowns, since 10 + 50% of 10 results in 15," << std::endl <<
		"and 30 - 50% of 30 results in 15.");
}
// DESCRIPTIONS END
static USHORT extractPercentage() // 1
{
	if (descPrompt(describe1) == 0) return -1;

	float target, percentage;
	PRINT_ENDL("* PERCENTAGE EXTRACTOR *");
	PRINT("Enter the target number: ");
	getNumInput(&target);
	PRINT("Enter a percentage: ");
	getNumInput(&percentage);
	float result = target * (percentage / 100);
	bool expNotValid = (std::isinf(result) || std::isnan(result));
	if (expNotValid)
		PRINT_ENDL("THE RESULT IS EITHER NOT A NUMBER, OR INFINITY");
	//else PRINT_ENDL(percentage << "% of " << target << " is " << result << ".");
	else PRINT(std::format("{0}% of {1} is {2:.2f}.\n", percentage, target, result));
	
	return result; //target * (percentage / 100);

	//mainMenu(MENU_ICON); // PROBLEM -> DON'T DO THIS
}
static USHORT percentageSubtractor() // 2
{
	if (descPrompt(describe2) == 0) return -1;

	float target, percentage;
	PRINT_ENDL("* PERCENTAGE SUBTRACTOR *");
	PRINT("Enter the target number: ");
	getNumInput(&target);
	PRINT("Enter a percentage (1 - 100): ");
	getNumInput(&percentage);
	while (percentage < 1 || percentage > 100)
	{
		PRINT("Invalid value. Only 1 through 100 is allowed." << std::endl << "Try again: ");
		getNumInput(&percentage);
	}
	float result = target - target * (percentage / 100);
	bool expNotValid = (std::isinf(result) || std::isnan(result));
	if (expNotValid)
		PRINT_ENDL("THE RESULT IS EITHER NOT A NUMBER, OR INFINITY");
	//else PRINT_ENDL(target << " minus " << percentage << "% is " << result << ".");
	else PRINT(std::format("{0} minus {1}% is {2:.2f}.\n", target, percentage, result));

	return result; //target - target * (percentage / 100);
}
static USHORT percentageOfTotal() // 3 // 1
{
	if (descPrompt(describe3) == 0) return -1;

	float part, total;
	PRINT_ENDL("* PERCENTAGE OF TOTAL *");
	PRINT("Enter the first number (part): ");
	getNumInput(&part);
	PRINT("Enter the second number (total): ");
	getNumInput(&total); // 9 -> 90 = 10
	//90 100
	//9  x
	float result = (part * 100) / total;
	bool expNotValid = (std::isinf(result) || std::isnan(result));
	if (expNotValid)
		PRINT_ENDL("THE RESULT IS EITHER NOT A NUMBER, OR INFINITY");
	else PRINT(std::format("{0} represents {1:.2f}% of {2}.\n", part, result, total));
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
	getNumInput(&percentage);
	//percentage = getUShort();
	PRINT("Enter the desired total: ");
	getNumInput(&total);
	//total = getUShort();
	PRINT_ENDL("");

	// OLD ADDITION EQUATION (RESULT ALSO WORKS) | t = 300 | p = 50 | x = 1 | y (final) = 200
	// t = x + x * p/100
	// 300 = x + x * 0.5
	// 300 = x(1 + 0.5)
	// 1.5 * x = 300 ---
	// x * 1.5 = 300
	// x = 300 / 1.5
	// final = total / x + x * (percentage/100)
	// FINAL EQUATION: final = total / x + x * (percentage/100)
	
	// NEW CURRENT EQUATION | t = 500 | p = 100 | y = 250 |
	// NEW CURRENT EQUATION | t = 15 | p = 50 | y = 10 |
	// y + y * (p/100) = t
	// (y * 1) + (y * (p/100)) = t
	// y(1 + p/100) = t ---> RAW
	// y * 2 = t
	// y = t / 2
	// y = 250
	// 
	// y(1 + 0.5) = t
	// y * 1.5 = t
	// y = t / 1.5 ---> EUREKA!
	// FINAL EQUATION (READY FOR CODE): y = t / (1 + (p/100))

	//float x = 1;

	//float currExpResult = (total / (percentage/100)) / 2;
	float currExpResult = total / (1 + (percentage / 100));
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

	// OLD SUBTRACTION EQUATION | t = 300 | p = 50 | x = 1 |
	// t = x - x * p/100
	// 300 = x - x * 0.5 | 300 = 600 - 600 * 0.5
	// 300 = x(1 - 0.5) | 
	// x * 0.5 = 300
	// x = 300 / 0.5
	// final = total / x - x * (percentage/100)

	// Old PRINTS (without std::format) -> HAD PROBLEM WITH "std::fixed << std::setprecision()"
	
	/*PRINT(std::format(
		"And to get to {0} by SUBTRACTING {1}% of a number from itself, this number must be {2:.2f}.\n\n",
		total, percentage, (total / (x - x * (percentage / 100)))));*/
	
	// CURRENT EQUATION (SUBTRACTION) | t = 15 | p = 50 | y = 30 |
	// 30 - 30 * 50% = 15
	// y - y * 50/100 = 15
	// y * 1 - y * 50/100 = 15
	// y(1 - 0.5) = 15
	// y * 0.5 = 15
	// y = 15 / 0.5 ---> EUREKA!
	// FINAL EQUATION (READY FOR CODE): y = t / (1 - (p/100))
	
	currExpResult = total / (1 - (percentage / 100));
	expNotValid = (std::isinf(currExpResult) || std::isnan(currExpResult));
	/*PRINT((expNotValid) ? | Problematic ternary
		std::format("To get to {0} by ADDING {1}% of a number to itself, this number must be {2}.\n",
			total, percentage, "RESULT IS NOT A NUMBER, OR INFINITY") :
		std::format("To get to {0} by SUBTRACTING {1}% of a number from itself, this number must be {2:.2f}.\n",
			total, percentage, currExpResult));*/
	if (expNotValid)
		PRINT(std::format("And to get to {0} by SUBTRACTING {1}% of a number from itself, this number must be {2}.\n",
			total, percentage, "(RESULT IS NOT A NUMBER, OR INFINITY)"));
	else PRINT(std::format("And to get to {0} by SUBTRACTING {1}% of a number from itself, this number must be {2:.2f}.\n",
			total, percentage, currExpResult));

	// SLEEPER CODE - TO BE ACTIVATED IN FUTURE VERSIONS
	/*PRINT_ENDL(std::endl << "NOTE: Every one of this program's functions return a value (for certain future purposes). As only one value " <<
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

	return (opt == 0) ? total / (1 + (percentage / 100)) : total / (1 - (percentage / 100));*/
	return 0;
}
USHORT descPrompt(void (*funcPtr)()) // DESCRIPTION PROMPT - FUNCTION POINTER
{
	USHORT opt;
	funcPtr();
	PRINT_ENDL(std::endl << "Do you wish to continue?");
	while (true)
	{
		PRINT("1 - Yes" << std::endl << "0 - Back to main menu" << std::endl <<
			"---> ");
		getNumInput(&opt);
		switch (opt)
		{
		case 0: return 0; break;
		case 1: PRINT(std::endl); return 1; break;
		default: PRINT_ENDL("Invalid option. Try again."); break;
		}
	}
}
static void mainMenu(char defChar) // Main menu
{
	PRINT_ENDL("");
	USHORT opt;
	bool drawBox = true;
	do
	{
		if (drawBox)
		{
			PRINT_ENDL(strReturn(COL_WIDTH_MENU, MENU_ICON, MENU_ICON, "|", 3, "MAIN MENU", {"1 - Percentage extractor",
				"2 - Percentage subtractor", "3 - Percentage of total", "4 - Reverse percentage", "5 - ABOUT",
				"Coming in the future"}));
			//PRINT(std::setfill(' '));
			//PRINT_ENDL(std::setw(COL_WIDTH_MENU / 3) << "" << std::left << "* MAIN MENU *");
			//PRINT_ENDL(std::setfill(defChar) << std::setw(COL_WIDTH_MENU) << ""); // Draw upper boundary.
			//PRINT(std::setfill(' '));

			//PRINT(std::left << std::setw(COL_WIDTH_MENU / 3) << "| 1 - Percentage extractor" << '|');
			//PRINT(std::left << std::setw(COL_WIDTH_MENU / 3) << "2 - Percentage subtractor" << '|');
			//PRINT_ENDL(std::right << std::setw((COL_WIDTH_MENU / 3) + COL_WIDTH_MENU % 3 - 2) << "3 - Percentage of total |");

			//PRINT(std::left << std::setw(COL_WIDTH_MENU / 3) << "| 4 - Reverse percentage" << '|');
			//PRINT(std::left << std::setw(COL_WIDTH_MENU / 3) << " Coming in the future" << '|');
			//PRINT_ENDL(std::right << std::setw((COL_WIDTH_MENU / 3) + COL_WIDTH_MENU % 3 - 2) << " Coming in the future |");

			//// TEMPLATE FOR WHEN BOXES AREN'T FILLED
			///*PRINT(std::right << std::setw(COL_WIDTH_MENU / 3 + 1) << '|');
			//PRINT_ENDL(std::right << std::setw((COL_WIDTH_MENU / 3) + COL_WIDTH_MENU % 3 - 2) << '|');*/

			//PRINT_ENDL(std::setfill(defChar) << std::setw(COL_WIDTH_MENU) << ""); // Draw lower boundary.
		}
		
		drawBox = true;
		PRINT("Enter an option from the box above or '0' to quit the program: ");
		//getSingleDigitNum(&opt);
		getNumInput(&opt);
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
		case 5:
			about(); break;
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
	PRINT_ENDL("Percentage Sandbox v1.0 by Henrique Soares" << std::endl);
	mainMenu(MENU_ICON);

	return 0;
}