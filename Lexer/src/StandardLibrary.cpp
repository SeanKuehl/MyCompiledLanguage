#include <vector>
#include <functional>
#include <string>
#include <iostream>

#include "StandardLibraryFunction.h"
#include "UserVariable.h"
#include "StandardLibrary.h"

#include "Add.h"
#include "Set.h"


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

//void SetIntegerValue(vector<void*> args) {
//	//assume two arguments, a user variable and an integer
//	string variableName = *(string*)(args.at(0));
//	string secondArgumentValue = *(string*)(args.at(1));	//we store values are strings, so just keep it string for now
//	//this one fails but the string version succeeds no problems. Problem could also be in the prints
//	for (int i = 0; i < userVariables.size(); i++) {
//		
//		if (variableName == userVariables.at(i).GetName()) {
//			
//			userVariables.at(i).SetValue(secondArgumentValue);
//		}
//	}
//
//}
//
//void SetStringValue(vector<void*> args) {
//	//assume two arguments, a user variable and a string
//	string variableName = *(string*)(args.at(0));
//	string secondArgumentValue = *(string*)(args.at(1));
//	secondArgumentValue.erase(secondArgumentValue.begin() + 0);	//trim off the " at the start
//	secondArgumentValue.erase(secondArgumentValue.begin() + (secondArgumentValue.size() - 1));	//trim off the " on the end
//
//	for (int i = 0; i < userVariables.size(); i++) {
//		if (variableName == userVariables.at(i).GetName()) {
//			userVariables.at(i).SetValue(secondArgumentValue);
//		}
//	}
//
//}

//
//void AddIntegerValue(vector<void*> args) {
//	//assume two arguments, a user variable and an integer
//	string variableName = *(string*)(args.at(0));
//	int secondArgumentValue = stoi(*(string*)(args.at(1)));	
//	//this one fails but the string version succeeds no problems. Problem could also be in the prints
//	for (int i = 0; i < userVariables.size(); i++) {
//
//		if (variableName == userVariables.at(i).GetName()) {
//			int currentValue = stoi(userVariables.at(i).GetValue());
//			currentValue += secondArgumentValue;
//			string valueToSet = to_string(currentValue);
//			userVariables.at(i).SetValue(valueToSet);
//		}
//	}
//
//}
//
//
//void AddStringValue(vector<void*> args) {
//	//assume two arguments, a user variable and a string
//	string variableName = *(string*)(args.at(0));
//	string secondArgumentValue = *(string*)(args.at(1));
//	secondArgumentValue.erase(secondArgumentValue.begin() + 0);	//trim off the " at the start
//	secondArgumentValue.erase(secondArgumentValue.begin() + (secondArgumentValue.size() - 1));	//trim off the " on the end
//
//	for (int i = 0; i < userVariables.size(); i++) {
//		if (variableName == userVariables.at(i).GetName()) {
//			string currentValue = userVariables.at(i).GetValue();
//			currentValue += secondArgumentValue;
//			
//			
//			userVariables.at(i).SetValue(currentValue);
//		}
//	}
//
//}

bool IsIntIfTrue(int firstArg, string op, int secondArg) {

	//get what operator it is
	if (op == "<") {
		if (firstArg < secondArg) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (op == ">") {
		if (firstArg > secondArg) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (op == "=") {
		if (firstArg == secondArg) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (op == "!") {
		if (firstArg != secondArg) {
			return true;
		}
		else {
			return false;
		}
	}

	cout << "There was an error in the IsIntIfTrue func in standard library" << endl;
	return false;
}

//consider having named end ifs (endif: "hello")
void UserVarAndIntIfConditional(vector<void*> args) {
	//assume first is user variable, second is operator, third is integer, fourth is string name of endif
	string variableName = *(string*)(args.at(0));
	int variableValue = 0;
	string secondArgumentValue = *(string*)(args.at(1));
	secondArgumentValue.erase(secondArgumentValue.begin() + 0);	//trim off the | at the start
	secondArgumentValue.erase(secondArgumentValue.begin() + (secondArgumentValue.size() - 1));	//trim off the | on the end
	int thirdArgumentValue = stoi((*(string*)args.at(2)));
	string fourthArgumentValue = *(string*)(args.at(3));	//we'll be comparing it with another string, so don't cut off the ""
	


	for (int i = 0; i < userVariables.size(); i++) {
		if (variableName == userVariables.at(i).GetName()) {
			variableValue = stoi(userVariables.at(i).GetValue());
			
		}
	}

	if (IsIntIfTrue(variableValue, secondArgumentValue, thirdArgumentValue)) {
		//let the code below execute
	}
	else {
		//the if is false, skip ahead to the next endif with the same name as the fourth argument
		

		for (int i = instructionPointer; i < filteredLines.size(); i++) {
			if (filteredLines.at(i).GetCommand() == "endif") {
				//there is only one parameter in an endif
				if (filteredLines.at(i).GetParameters().at(0) == fourthArgumentValue) {
					instructionPointer = i + 1;	//set the instruction pointer to the instruction after the endif
					break;
				}
			}
		}
	}


}


void UserVarAndIntWhileLoop(vector<void*> args) {
	//assume first is user variable, second is operator, third is integer, fourth is string name of endwhile
	string variableName = *(string*)(args.at(0));
	int variableValue = 0;
	string secondArgumentValue = *(string*)(args.at(1));
	secondArgumentValue.erase(secondArgumentValue.begin() + 0);	//trim off the | at the start
	secondArgumentValue.erase(secondArgumentValue.begin() + (secondArgumentValue.size() - 1));	//trim off the | on the end
	int thirdArgumentValue = stoi((*(string*)args.at(2)));
	string fourthArgumentValue = *(string*)(args.at(3));	//we'll be comparing it with another string, so don't cut off the ""



	for (int i = 0; i < userVariables.size(); i++) {
		if (variableName == userVariables.at(i).GetName()) {
			variableValue = stoi(userVariables.at(i).GetValue());

		}
	}

	if (IsIntIfTrue(variableValue, secondArgumentValue, thirdArgumentValue)) {
		//let the code below execute
	}
	else {
		//the if is false, skip ahead to the next endif with the same name as the fourth argument


		for (int i = instructionPointer; i < filteredLines.size(); i++) {
			if (filteredLines.at(i).GetCommand() == "endwhile") {
				//there is only one parameter in an endif
				if (filteredLines.at(i).GetParameters().at(0) == fourthArgumentValue) {
					instructionPointer = i + 1;	//set the instruction pointer to the instruction after the endwhile
					break;
				}
			}
		}
	}
}

void EndWhile(vector<void*> args) {
	//expecting only one argument, the name of a while loop
	//if this has been reached, we go back to where the while loop is 
	string firstArgumentValue = *(string*)(args.at(0));	//don't want to cut off "" because we'll be comparing with another string
	//go backwards through the list, the while loop is "above" us
	for (int i = instructionPointer; i > -1; i--) {
		if (filteredLines.at(i).GetCommand() == "while") {
			//get the while's fourth argument
			if (filteredLines.at(i).GetParameters().at(3) == firstArgumentValue) {
				instructionPointer = i;	//set the instruction pointer to the while loop, we need it to check if it should run again
				break;
			}
		}
	}

}


//while loops will work almost the same as if statements, only different is the endwhile will actually run most times, because it might have to 
//go back to start as opposed to the endif which is never actually run and is always skipped

vector<StandardLibraryFunction> LoadStandardLibrary() {
	//there will be some UGLY code in this function

	vector<StandardLibraryFunction> standardLib;
	
	standardLib.push_back(StandardLibraryFunction("endwhile", { "string" }, EndWhile));
	standardLib.push_back(StandardLibraryFunction("while", { "user variable", "operator", "integer", "string" }, UserVarAndIntWhileLoop));

	//this worked first try! (the if statement)
	standardLib.push_back(StandardLibraryFunction("if", { "user variable", "operator", "integer", "string" }, UserVarAndIntIfConditional));

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