#pragma once
#include <vector>
#include <string>


using namespace std;


class UnfilteredLine
{
	//this is an unfiltered line because the command hasn't been checked for validity
	//and the params haven't been type checked/checked for validity
public:
	UnfilteredLine(string passedCommand, vector<string> params);

	string GetCommand();

	vector<string> GetParameters();


private:
	string command;
	vector<string> listOfParameters;


};

