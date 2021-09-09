#include "StandardLibraryFunction.h"



StandardLibraryFunction::StandardLibraryFunction(string passedName, vector<string> paramTypes, function<void(vector<void*>)> passedFunction) {
	name = passedName;
	argumentTypes = paramTypes;
	callFunction = passedFunction;
}


string StandardLibraryFunction::GetName() {
	return name;
}

vector<string> StandardLibraryFunction::GetArgumentTypes() {
	return argumentTypes;
}

void StandardLibraryFunction::CallFunction(vector<void*> parameters) {
	callFunction(parameters);
}
