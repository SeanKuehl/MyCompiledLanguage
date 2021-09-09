#include <vector>
#include <functional>
#include <string>
#include <iostream>

#include "StandardLibraryFunction.h"
#include "UserVariable.h"
#include "StandardLibrary.h"


using namespace std;

//if when searching there are multiple funcs of same name(print etc.) compare
//the types of the args to the types of args in the function class




//for print stuff, make it that the value has to be string to be allowed to be printed
void samplePrint(vector<void*> args) {
	
	

	for (int i = 0; i < args.size(); i++) {
		string toPrint = *(string*)(args.at(i));
		toPrint.erase(toPrint.begin() + 0);	//trim off the " at the start
		toPrint.erase(toPrint.begin() + (toPrint.size() - 1));	//trim off the " on the end
		cout << toPrint <<  endl;
		
	}

}

void PrintVariable(vector<void*> args) {
	
	//assume only one user variable
	string variableName = *(string*)(args.at(0));
	//get the variable value
	
	//it was fine when I was doing only x, there's something up with 
	//userVariables and storing things correctly, I think
	for (int i = 0; i < userVariables.size(); i++) {
		if (variableName == userVariables.at(i).GetName()) {
			cout << userVariables.at(i).GetValue() << endl;
			
		}
	}

}

//make a function that allows you to declare variables, will need access to user variables list
void DeclareInteger(vector<void*> args) {
	//first argument is a name(user variable) i.e. "x", second argument is of type int but we're just storing it so just keep string for now
	string variableName = *(string*)(args.at(0));
	
	string variableValue = *(string*)(args.at(1));	
	string variableType = "integer";
	UserVariable newVar = UserVariable(variableName, variableValue, variableType);
	userVariables.push_back(newVar);	//this is the global list of userVariables
	
	

}

void DeclareString(vector<void*> args) {
	//first argument is a name(user variable) i.e. "x", second argument is of type string
	string variableName = *(string*)(args.at(0));
	
	string variableValue = *(string*)(args.at(1));	
	variableValue.erase(variableValue.begin() + 0);	//trim off the " at the start
	variableValue.erase(variableValue.begin() + (variableValue.size() - 1));	//trim off the " on the end
	string variableType = "string";
	UserVariable newVar = UserVariable(variableName, variableValue, variableType);
	userVariables.push_back(newVar);	//this is the global list of userVariables

}

//for loops, funcs and things, I could gain access to the filteredLinesList
//and take or give lines as needed, or loops and storing loop names and addresses in
//the list might be easier, or I could search through the lines list and find it

void GetUserInput(vector<void*> args) {
	//only one argument, a user variable
	string variableName = *(string*)(args.at(0));
	string userInput = "";
	cin >> userInput;

	//set variable value to userInput
	for (int i = 0; i < userVariables.size(); i++) {
		if (variableName == userVariables.at(i).GetName()) {
			userVariables.at(i).SetValue(userInput);
		}
	}

}

void SetIntegerValue(vector<void*> args) {
	//assume two arguments, a user variable and an integer
	string variableName = *(string*)(args.at(0));
	string secondArgumentValue = *(string*)(args.at(1));	//we store values are strings, so just keep it string for now
	//this one fails but the string version succeeds no problems. Problem could also be in the prints
	for (int i = 0; i < userVariables.size(); i++) {
		
		if (variableName == userVariables.at(i).GetName()) {
			
			userVariables.at(i).SetValue(secondArgumentValue);
		}
	}

}

void SetStringValue(vector<void*> args) {
	//assume two arguments, a user variable and a string
	string variableName = *(string*)(args.at(0));
	string secondArgumentValue = *(string*)(args.at(1));
	secondArgumentValue.erase(secondArgumentValue.begin() + 0);	//trim off the " at the start
	secondArgumentValue.erase(secondArgumentValue.begin() + (secondArgumentValue.size() - 1));	//trim off the " on the end

	for (int i = 0; i < userVariables.size(); i++) {
		if (variableName == userVariables.at(i).GetName()) {
			userVariables.at(i).SetValue(secondArgumentValue);
		}
	}

}


void AddIntegerValue(vector<void*> args) {
	//assume two arguments, a user variable and an integer
	string variableName = *(string*)(args.at(0));
	int secondArgumentValue = stoi(*(string*)(args.at(1)));	
	//this one fails but the string version succeeds no problems. Problem could also be in the prints
	for (int i = 0; i < userVariables.size(); i++) {

		if (variableName == userVariables.at(i).GetName()) {
			int currentValue = stoi(userVariables.at(i).GetValue());
			currentValue += secondArgumentValue;
			string valueToSet = to_string(currentValue);
			userVariables.at(i).SetValue(valueToSet);
		}
	}

}


void AddStringValue(vector<void*> args) {
	//assume two arguments, a user variable and a string
	string variableName = *(string*)(args.at(0));
	string secondArgumentValue = *(string*)(args.at(1));
	secondArgumentValue.erase(secondArgumentValue.begin() + 0);	//trim off the " at the start
	secondArgumentValue.erase(secondArgumentValue.begin() + (secondArgumentValue.size() - 1));	//trim off the " on the end

	for (int i = 0; i < userVariables.size(); i++) {
		if (variableName == userVariables.at(i).GetName()) {
			string currentValue = userVariables.at(i).GetValue();
			currentValue += secondArgumentValue;
			
			
			userVariables.at(i).SetValue(currentValue);
		}
	}

}
//make the unfiltered list extern global and then edit the list/do loops from here or something
//have a "stack pointer" that I can shift so that the execute function won't execute things it doens't need to
//like commands inside of a function, this function should be able to manipulate it

vector<StandardLibraryFunction> LoadStandardLibrary() {
	//there will be some UGLY code in this function

	vector<StandardLibraryFunction> standardLib;

	
	standardLib.push_back(StandardLibraryFunction("add", { "user variable", "integer" }, AddIntegerValue));
	standardLib.push_back(StandardLibraryFunction("add", { "user variable", "string" }, AddStringValue));

	standardLib.push_back(StandardLibraryFunction("set", { "user variable", "integer" }, SetIntegerValue));
	standardLib.push_back(StandardLibraryFunction("set", { "user variable", "string" }, SetStringValue));

	standardLib.push_back(StandardLibraryFunction("string", { "user variable", "string" }, DeclareString));
	standardLib.push_back(StandardLibraryFunction("input", { "user variable" }, GetUserInput));
	standardLib.push_back(StandardLibraryFunction("print", { "user variable" }, PrintVariable));
	standardLib.push_back(StandardLibraryFunction("int", { "user variable", "integer" }, DeclareInteger));
	standardLib.push_back(StandardLibraryFunction("print", {"string"}, samplePrint));
	return standardLib;
}