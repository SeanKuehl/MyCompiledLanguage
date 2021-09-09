#include "FilteredLine.h"




FilteredLine::FilteredLine(string passedCommand, string passedCommandType, vector<string> passedParams, vector<string> passedParamTypes) {
	command = passedCommand;
	commandType = passedCommandType;
	params = passedParams;
	paramTypes = passedParamTypes;
}


string FilteredLine::GetCommandType() {
	return commandType;
}

string FilteredLine::GetCommand() {
	return command;
}

vector<string> FilteredLine::GetParameterTypes() {
	return paramTypes;
}

vector<string> FilteredLine::GetParameters() {
	return params;
}
