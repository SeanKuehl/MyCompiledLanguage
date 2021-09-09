#pragma once
#include <functional>	//for std::function
#include <vector>
#include <string>

#include "StandardLibraryFunction.h"
#include "UserVariable.h"



using namespace std;

//this is where I will make all the standard library functions and load them

//only function that should be exposed to the rest of the program in the 
//LoadStandardLibrary function

extern vector<UserVariable> userVariables;	//this is a global, using something declared in Source.cpp
//extern void ExecuteLines(vector<FilteredLine> linesToRun);	//this is so standard lib functions like loops, ifs and others can work
//make more funcs from source extern so that I can go from "string" args to commands

vector<StandardLibraryFunction> LoadStandardLibrary();