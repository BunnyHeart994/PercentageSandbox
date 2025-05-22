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