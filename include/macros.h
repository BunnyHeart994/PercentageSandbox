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

#pragma once
#define USHORT unsigned short
#include <limits>
//#define USHORT_MINV std::numeric_limits<USHORT>::min()
//#define USHORT_MAXV std::numeric_limits<USHORT>::max()
//#define CHAR_MAXV std::numeric_limits<char>::max()
#define PRINT(x) std::cout << x
#define PRINT_ENDL(x) std::cout << x << std::endl
#define GET(x) std::cin >> x
#define GET_CHAR std::cin.get()
//#define CLEARIGNORECHAR_CIN std::cin.clear(); std::cin.ignore(USHORT_MAXV, '\n')
#include <ios>
//#define CLEAR_IGNORE_CHAR(x) std::cin.clear(); std::cin.ignore(sizeof(std::streamsize), x)

//#define CLEAR_IGNORE_CHARAMOUNT(x) std::cin.clear(); std::cin.ignore(x, 0); std::cin.clear()
#define CIN_IGNORE(x, y) std::cin.ignore(x, y)
//#define IGNORE_UNTILFIND(y) std::cin.ignore(sizeof(std::streamsize), y)
#define IGNORE_MAXCHARAMOUNT std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')
#define CLEAR_CIN std::cin.clear()
//#define IGNORE_CHARAMOUNT(x) std::cin.ignore(x, '\n')
#include <string>
#define GET_LINE(x) std::getline(std::cin, x)
#define RIGHT_JUSTIFY std::cout << std::right