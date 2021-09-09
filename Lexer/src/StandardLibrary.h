#pragma once
#include <functional>	//for std::function
#include <vector>
#include <string>

#include "StandardLibraryFunction.h"
#include "UserVariable.h"
#include "FilteredLine.h"



using namespace std;

//this is where I will make all the standard library functions and load them

//only function that should be exposed to the rest of the program in the 
//LoadStandardLibrary function

//yes, I know, globals are code crimes, sue me
extern vector<UserVariable> userVariables;	//this is a global, using something declared in Source.cpp
extern int instructionPointer;
extern vector<FilteredLine> filteredLines;
//extern void ExecuteLines(vector<FilteredLine> linesToRun);	//this is so standard lib functions like loops, ifs and others can work
//with all of these, standard lib functions can change the order of execution and do ifs, loops and functions
//ExecuteLines won't be needed, better for functions and ifs to just change order of execution
//an if could just change the instruction pointer to the next end if or after it for instance
vector<StandardLibraryFunction> LoadStandardLibrary();