#pragma once
#include <string>
#include <vector>


using namespace std;


class FilteredLine
{

public:
	FilteredLine(string passedCommand, string passedCommandType, vector<string> passedParams, vector<string> passedParamTypes);

	string GetCommandType();

	string GetCommand();

	vector<string> GetParameterTypes();

	vector<string> GetParameters();

private:
	string command = "";
	string commandType = "";	//either user function or builtin function

	vector<string> params;
	vector<string> paramTypes;




};

