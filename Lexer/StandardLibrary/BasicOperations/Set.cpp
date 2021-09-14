#include "Set.h"


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