#pragma once
#include <vector>
#include <string>

using namespace std;

class UserVariable
{
	//a user variable has a string name, a string value, string type
public:
	UserVariable(string passedName, string passedValue, string passedType);

	string GetName();

	string GetValue();

	void SetValue(string newVal);

	string GetType();

private:
	string name = "";
	string value = "";
	string type = "";



};

