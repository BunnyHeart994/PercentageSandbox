#pragma once
#include <iostream>
#include "macros.h"

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