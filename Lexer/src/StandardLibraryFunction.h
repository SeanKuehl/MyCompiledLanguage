#pragma once
#include <string>
#include <vector>
#include <functional>	//needed for std::function


using namespace std;


class StandardLibraryFunction
{

public:
	StandardLibraryFunction(string passedName, vector<string> paramTypes, function<void(vector<void*>)> passedFunction);

	string GetName();

	vector<string> GetArgumentTypes();

	void CallFunction(vector<void*> parameters);



private:
	string name = "";
	vector<string> argumentTypes;
	function<void(vector<void*>)> callFunction;

};

