/*
Box Drawer
This is the part of the library that draws a box.
When calling the function that returns a string, whoever's calling it can define (respectively) the box's width (measured in characters), which characters that'll fill the top and lower boundaries and the sides of the box (separately), how many cells per row the box will have, the title for the box, and finally the items (strings) to fill the cells (as many as they like).

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
// Phone number and WhatsApp: +55 31 971306169

#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include<string>
#include <initializer_list>

#ifdef DEFINE_STATIC
#define DLL_BEHAVIOR
//#pragma message("STATIC DEFINED")
#elif defined(EXPORT_DLL)
#define DLL_BEHAVIOR __declspec(dllexport)
//#pragma message("dllexport DEFINED")
#elif defined(IMPORT_DLL)
#define DLL_BEHAVIOR __declspec(dllimport)
//#pragma message("dllimport DEFINED")
#else
#define DLL_BEHAVIOR
#endif

DLL_BEHAVIOR std::string strReturn(const int rowWidth, const char topChar, const char bottomChar, std::string sidesChar,
	const unsigned int cellPerRow, std::string title, std::initializer_list<std::string> items);