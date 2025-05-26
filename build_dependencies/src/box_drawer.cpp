#include "../include/box_drawer.h"

//std::string box(const int rowWidth, const char topChar, const char bottom, const char sides)
std::string strReturn(const int rowWidth, const char topChar, const char bottomChar, std::string sidesChar,
	const unsigned int cellsPerRow, std::string title, std::initializer_list<std::string> items)
{
	// rw 103 cpr 5 !
	const unsigned short charPerRowLimitTweak = ((cellsPerRow - 1) * 3) + 4; // This is because of cell and box delimiters // 16 V
	unsigned short widthDivModulo = (rowWidth % cellsPerRow != 0) ? rowWidth % cellsPerRow : 0; // 3 V
	// Amount of chars each cell holds
	unsigned short charPerRowLimit = rowWidth - charPerRowLimitTweak; // 87 V
	unsigned short charPerCellLimit = charPerRowLimit / cellsPerRow; // 17 V
	const unsigned short charPerCellRemainder = charPerRowLimit % cellsPerRow; // 2 V
	 
	// ceil(3 / 5) = 1
	//unsigned short itemLabelCharLimitTweak = std::ceil((float)(rowWidth % cellsPerRow) / (float)cellsPerRow); // 1
	unsigned short charPerCellLimitTweak = std::ceil((float)(rowWidth % cellsPerRow) / (float)cellsPerRow); // 1
	
	// Not using items.size() directly in further checking exps because of static analysing giving POSSIBLY unnecessary warnings
	const unsigned short itemsSize = items.size(); // Amount of elements in "items" init_list
	std::string* itemsCopy = new std::string[itemsSize]; // itemsCopy stores strings
	const std::string* itemsListPtr = items.begin(); // itemsListPtr gets pointer to beginning of items
	for (unsigned short i = 0; i < itemsSize; i++) // This stores whatever's in items, into itemsCopy
	{
		//*(itemsCopy + i) = *(itemsListPtr + i);
		itemsCopy[i] = *(itemsListPtr + i);
	}
	//unsigned short cpcrCopy = charPerCellRemainder; // 2
	for (unsigned short i = 0; i < itemsSize; i++) // This shorten the strings in itemsCopy if necessary
	{
		if (itemsCopy[i].length() > charPerCellLimit)
		{
			//unsigned short itemLength = itemsCopy[i].length();
			itemsCopy[i].erase(charPerCellLimit - 1); // "- 1" because of append below
			itemsCopy[i].append("?");
		}
		//cpcrCopy--;
		//if (cpcrCopy > 0) cpcrCopy--;
		/* else = imput length <= ilcl */
	}

	// MEASURES, SETS AND PRINTS TITLE POSITION
	unsigned short titlePos = (rowWidth / 2 - (title.length() + 4) / 2) + widthDivModulo / 2; // + 4 because of extra "*  *"
	// Filling first positions
	std::string finalStr(titlePos, ' ');
	finalStr.append("* ").append(title).append(" *").append(titlePos, ' ').append("\n");

	// DRAWS UPPER BOX BOUNDARY
	finalStr.append(rowWidth, topChar);
	finalStr.append("\n");

	// DRAWS MIDDLE WHILE INSERTING ITEMS
	sidesChar.erase(1);

	const unsigned short rowAmount = std::ceil((float)itemsSize / cellsPerRow); // 5/5 = 1
	for (unsigned short row = 0; row < rowAmount; row++)
	{
		finalStr.append(sidesChar).append(" "); // Draws : "| "
		for (unsigned short column = 0; column < cellsPerRow; column++) // Represents cells
		{
			unsigned short index = row * cellsPerRow + column; // if row = 1, column = 0, cpr = 3, index = 3
			if (index < itemsSize)
			{
				unsigned short itemAtIndexLength = itemsCopy[index].length();
				//if (column < cellsPerRow - 1) finalStr.append(charPerCellLimit, ' ');
				//else finalStr.append(charPerCellLimit + charPerCellRemainder, ' ');
				//
				if (itemAtIndexLength < charPerCellLimit) // Less than or equals... // lim10 / len9
					if (column == cellsPerRow - 1)
						finalStr.append(itemsCopy[index]).append(
							(charPerCellLimit - itemAtIndexLength) + charPerCellRemainder, ' ');
					else finalStr.append(itemsCopy[index]).append(charPerCellLimit - itemAtIndexLength, ' ');
				else finalStr.append(itemsCopy[index]);
			}
			else
				if (column < cellsPerRow - 1) finalStr.append(charPerCellLimit, ' ');
				else finalStr.append(charPerCellLimit + charPerCellRemainder, ' '); // 1 / 


			if (column < cellsPerRow - 1)
				finalStr.append(" | ");
		}
		finalStr.append(" ").append(sidesChar).append("\n");
		if (row != rowAmount - 1)
			finalStr.append(rowWidth, '-').append("\n");
	}
	delete[] itemsCopy;

	finalStr.append(rowWidth, topChar).append("\n"); // Draws lower box boundary

	// FOR DEBUG
	/*std::cout << "row width: " << rowWidth << std::endl;
	std::cout << "cells per row: " << cellsPerRow << std::endl;
	std::cout << "RAW char per row limit: " << rowWidth / cellsPerRow << std::endl;
	std::cout << "char per row limit: " << charPerRowLimit << std::endl;
	std::cout << "char per cell limit: " << charPerCellLimit << std::endl;
	std::cout << "char per row limit tweak: " << charPerRowLimitTweak << std::endl;
	std::cout << "width left over: " << widthDivModulo << std::endl;
	std::cout << "char per cell remainder: " << charPerCellRemainder << std::endl;*/

	return finalStr;
}