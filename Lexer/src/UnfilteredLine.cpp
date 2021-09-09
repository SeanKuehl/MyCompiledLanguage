#include "UnfilteredLine.h"




UnfilteredLine::UnfilteredLine(string passedCommand, vector<string> params) {
	command = passedCommand;
	listOfParameters = params;
}



string UnfilteredLine::GetCommand() {
	return command;
}

vector<string> UnfilteredLine::GetParameters() {
	return listOfParameters;
}
