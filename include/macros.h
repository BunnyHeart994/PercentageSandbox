#pragma once
#define USHORT unsigned short
#define PRINT(x) std::cout << x
#define PRINT_ENDL(x) std::cout << x << std::endl
#define GET(x) std::cin >> x
#define GET_CHAR std::cin.get()
#include <limits>
#define CLEARIGNORECHAR_CIN std::cin.clear(); std::cin.ignore(std::numeric_limits<USHORT>::max(), '\n')
#include <string>
#define GET_LINE(x) std::getline(std::cin, x)
#define RIGHT_JUSTIFY std::cout << std::right