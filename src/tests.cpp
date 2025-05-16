#include <iostream>
#include <iomanip>
#include <string>
#include "../include/definitions.h"
//#define COL_WIDTH 30

//const UINT8 COL_WIDTH = 28;
const USHORT COL_WIDTH_MENU = 98;

static std::string repeatChar(char target, int times, bool nL)
{
	std::string newStr = target + "\n";
	if (nL)
	{
		for (int i = 0; i < times + 1; ++i)
			newStr += target + "\n";
		return newStr;
	}
	else
	{
		for (int i = 0; i < times + 1; ++i)
			newStr += target;
		return newStr;
	}
}
//static std::string drawColumn(char icon) { return for (USHORT j = 0; j < 3; j++) { '|' }; }
static void mainMenu(char defChar)
{
	// PREVIOUS TESTS
	/*for (UINT8 i = 0; i < 65; i++)
	{
		PRINT_ENDL("*");
		for (UINT8 j = 0; j < 65; j++)
		{
			PRINT("*");
			if (j == 64)
				for (UINT8 k = 0; i < 65; k++) { PRINT_ENDL("*"); }
			PRINT_ENDL("");
		}
	}*/
	/*for (UINT8 i = 0; i < 65; i++)
	{
		PRINT_ENDL("*");
		for (UINT8 j = 0; j < 65; j++)
		{
			PRINT("*");
			if (j == 64)
				for (UINT8 k = 0; i < 65; k++) { PRINT_ENDL("*"); }
			PRINT_ENDL("");
		}
	}*/
	
	// Code below just draws a box. FUNCTIONAL
	/*PRINT_ENDL(std::setfill(defChar) << std::setw(COL_WIDTH_MENU * 1.5) << ""); // Draws upper boundary.
	PRINT(std::setfill(' ')); // Resets "setfill" to default, since once it's defined, it's permanent until changed.
	for (UINT8 i = 0; i < 33; i++) // Draws both sides all the way down until the end.
		PRINT_ENDL(std::left << std::setw(COL_WIDTH_MENU * 1.5 - 1) << '|' << '|');
		// Line above draws specified character at both sides/ends of the box, one at a time, then jumps line and does it again.

	PRINT(std::setfill(defChar) << std::setw(COL_WIDTH_MENU * 1.5) << "");*/

	// 2nd TEST BELOW
	//PRINT_ENDL(std::setfill(defChar) << std::setw(COL_WIDTH_MENU) << "");
	//PRINT(std::setfill(' '));
	//for (UINT8 i = 0; i < COL_WIDTH_MENU / 2; i++)
	//	PRINT_ENDL(std::left << std::setw(COL_WIDTH_MENU / 3) << "| 1 - Percentage calculator" <<
	//		std::left << std::setw(COL_WIDTH_MENU / 3) << "2 - Incognito" <<
	//		std::right << std::setw((COL_WIDTH_MENU / 3) + COL_WIDTH_MENU % 3) << "3 - Incognito |" << std::endl <<
	//		// SECOND LINE (-1)
	//		std::left << std::setw(COL_WIDTH_MENU / 3) << "| Calculate how much will" <<
	//		std::left << std::setw(COL_WIDTH_MENU / 3) << "Don't know yet." <<
	//		std::right << std::setw((COL_WIDTH_MENU / 3) + COL_WIDTH_MENU % 3) << "Don't know, yet again. |" << std::endl <<
	//		std::left << std::setw(COL_WIDTH_MENU / 2) << '|' <<
	//		std::right << std::setw(COL_WIDTH_MENU / 2) << '|' << std::endl);// <<

	//		// THIRD LINE
	//		//std::left << std::setw(COL_WIDTH_MENU / 3) << "| remain after a certain" << // FIRST LINE (-1)
	//		//std::left << std::setw(COL_WIDTH_MENU / 3) << "Don't know yet, again again." <<
	//		//std::right << std::setw((COL_WIDTH_MENU / 3) + COL_WIDTH_MENU % 3) << "Don't know, yet yet again. |" <<
	//		//std::left << std::setw(COL_WIDTH_MENU / 2) << '|' <<
	//		//std::right << std::setw(COL_WIDTH_MENU / 2) << '|' << std::endl);

	//PRINT(std::setfill(defChar) << std::setw(COL_WIDTH_MENU) << "");




	/*PRINT_ENDL(std::setfill(defChar) << std::setw(COL_WIDTH_MENU) << "");
	PRINT(std::setfill(' '));
	for (UINT8 i = 0; i < COL_WIDTH_MENU / 2; i++)
		PRINT_ENDL(std::left << std::setw(COL_WIDTH_MENU / 3) << "| 1 - Percentage calculator" <<
			std::left << std::setw(COL_WIDTH_MENU / 3) << "2 - Incognito" <<
			std::right << std::setw((COL_WIDTH_MENU / 3) + COL_WIDTH_MENU % 3) << "3 - Incognito |");

	PRINT(std::setfill(defChar) << std::setw(COL_WIDTH_MENU) << "");*/

	// CURRENT
	PRINT_ENDL(std::setfill(defChar) << std::setw(COL_WIDTH_MENU) << ""); // Draw upper boundary.
	PRINT(std::setfill(' '));

	PRINT(std::left << std::setw(COL_WIDTH_MENU / 3) << "| 1 - Percentage calculator" << '|');
	PRINT(std::left << std::setw(COL_WIDTH_MENU / 3) << "2 - Incognito" << '|');
	PRINT_ENDL(std::right << std::setw((COL_WIDTH_MENU / 3) + COL_WIDTH_MENU % 3 - 2) << "3 - Incognito |");

	PRINT_ENDL(std::setfill(defChar) << std::setw(COL_WIDTH_MENU) << ""); // Draw lower boundary.
}
int main()
{
	mainMenu('*');
	//PRINT(repeatChar('|', 30, true));
}