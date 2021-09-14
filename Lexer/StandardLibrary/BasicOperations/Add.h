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



void AddIntegerValue(vector<void*> args);
void AddStringValue(vector<void*> args);