
#include <string>
#include <vector>
#include "Add.h"

using namespace std;

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