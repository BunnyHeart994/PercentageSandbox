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