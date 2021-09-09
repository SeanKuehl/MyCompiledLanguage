#include "UserVariable.h"



UserVariable::UserVariable(string passedName, string passedValue, string passedType) {
	name = passedName;
	value = passedValue;
	type = passedType;
}


string UserVariable::GetName() {
	return name;
}

string UserVariable::GetValue() {
	return value;
}

void UserVariable::SetValue(string newVal) {
	value = newVal;
}

string UserVariable::GetType() {
	return type;
}