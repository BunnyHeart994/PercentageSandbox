#pragma once
#include <iostream>
#include "definitions.h"

void describe1() // PERCENTAGE EXTRACTOR
{
	PRINT_ENDL(std::endl << "Percentage extractor asks the user for a number then a percentage," << std::endl <<
	"then shows how much of that number exists in that percentage.");
}
void describe2() // PERCENTAGE SUBTRACTOR
{
	PRINT_ENDL(std::endl << "Percentage subtractor asks the user for a number than a percentage," << std::endl <<
	"then shows the remainder of that percentage subtracted from the number.");
}
void describe3() // PERCENTAGE OF TOTAL
{
	PRINT_ENDL(std::endl << "Percentage of total asks the user for two numbers, then shows" << std::endl <<
	"the percentage that the first number (part) represents of the second (total).");
}
void describe4() // REVERSE PERCENTAGE
{
	PRINT_ENDL(std::endl << "Reverse percentage asks the user for a percentage and a final amount," << std::endl <<
		"then shows the number by which having that percentage added to or subtracted from it," << std::endl <<
		"results in the final amount.");
}