
#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#include "UnfilteredLine.h"
#include "FilteredLine.h"

#include "StandardLibrary.h"
#include "UserVariable.h"

#define SIZE_OF_ALL_CHARS 3

using namespace std;


//read off of the file stage
vector<string> GetTextFromFile();
UnfilteredLine GetTokensFromLineOfText(string lineOfText);
vector<UnfilteredLine> GetTokensFromLinesOfText(vector<string> linesOfText);

vector<FilteredLine> FilterAllLines(vector<UnfilteredLine> linesToFilter);
FilteredLine FilterLine(UnfilteredLine lineToFilter);
vector<string> CheckUnfilteredParameters(vector<string> parameters);
string FilterParameter(string parameter);
void ExecuteLines(vector<FilteredLine> linesToRun);

bool ParameterIsInteger(string parameter);
bool ParameterIsDouble(string parameter);


//verification stage
//verify command by checking if it's in the function map(make function map thing)
//verify params by checking if it's a plain value("hello"), or a user variable(make user variable thing)

//note to self: might have to make list of user variables a global so standard lib funcs can use them

vector<StandardLibraryFunction> standardLib = LoadStandardLibrary();
vector<UserVariable> userVariables;

int main(void) {
    


    //vector<StandardLibraryFunction> standardLib = LoadStandardLibrary();
    /*string test = "hello";
    string testing = "works";
    standardLib.at(0).CallFunction({&test, &testing});*/
    // Create a text string, which is used to output the text file
    string myText;
    string thisToken = "";

    vector<string> unfilteredText = GetTextFromFile();
    vector<UnfilteredLine> unfilteredLineList = GetTokensFromLinesOfText(unfilteredText);
    vector<FilteredLine> filteredLines = FilterAllLines(unfilteredLineList);
    ExecuteLines(filteredLines);
    //format: read until first ':', this is the command
    //after space after first ':' read until ;, and so on until there are no more, ; signals there is another parameter

    //all lines, commands etc. will be in the form
    //command: param; param; param;...
    

    //for each line in unfilteredText, split it into command and params(maybe a class for this)

    //go through and get the command, but check in case it's an invalid line


    return 0;
}

void ExecuteLines(vector<FilteredLine> linesToRun) {
    //check whether command is build in func or user func in final version
    //but for now just assume they are library functions
    
    
    

    for (int i = 0; i < linesToRun.size(); i++) {
        for (int k = 0; k < standardLib.size(); k++) {
            //create a list of strings, one for each parameter in line(needs to be here so it doesn't go out of scope before CallFunction happens)
            vector<string> temp = linesToRun.at(i).GetParameters();
            
            if (linesToRun.at(i).GetCommand() == standardLib.at(k).GetName()) {
                if (linesToRun.at(i).GetParameterTypes() == standardLib.at(k).GetArgumentTypes()) {
                    //execute function
                    //convert parameters to void* to pass to the function
                    vector<void*> parametersToPassToFunction;
                    for (int j = 0; j < linesToRun.at(i).GetParameters().size(); j++) {
                        temp.at(j) = linesToRun.at(i).GetParameters().at(j);
                        
                        void* convertedParam = &temp.at(j);
                        
                        parametersToPassToFunction.push_back(convertedParam);
                    }
                    
                    standardLib.at(k).CallFunction(parametersToPassToFunction);
                    
                    

                    
                }
            }
        }
        
    }

}

vector<FilteredLine> FilterAllLines(vector<UnfilteredLine> linesToFilter) {
    vector<FilteredLine> toReturn;

    for (int i = 0; i < linesToFilter.size(); i++) {
        toReturn.push_back(FilterLine(linesToFilter.at(i)));
        
    }
    return toReturn;
}

FilteredLine FilterLine(UnfilteredLine lineToFilter) {
    //check if command is valid and check what types each of the params are(brute force and try/catch I think, or maybe with strings there's a way to check)

    //check the type of params
    vector<string> paramTypes = CheckUnfilteredParameters(lineToFilter.GetParameters());

    string commandType = "";
    
    //check if command is valid(needed list of parameters to check against function parameters)
    for (int i = 0; i < standardLib.size(); i++) {
        //if the names match, check the parameters. If the parameters match,
        //then it's a match and actually valid
        if (lineToFilter.GetCommand() == standardLib.at(i).GetName()) {
            if (paramTypes == standardLib.at(i).GetArgumentTypes()) {
                //it's a match, command is a standard library function

                commandType = "library";
            }
        }
    }

    //check against user defined functions if not found in library
    //...

    FilteredLine toReturn = FilteredLine(lineToFilter.GetCommand(), commandType, lineToFilter.GetParameters(), paramTypes);
    return toReturn;

    

}



vector<string> CheckUnfilteredParameters(vector<string> parameters) {
    vector<string> toReturn;

    for (int i = 0; i < parameters.size(); i++) {
        toReturn.push_back(FilterParameter(parameters.at(i)));
    }

    return toReturn;
}

string FilterParameter(string parameter) {
    //if it's a string, char etc. then it will have the "" or '' or [] etc. as the first and last chars
    //maybe add a constraint, like doubles have to end in f, integers with an i etc.
    //parameter could also be a user variable, check this later

    
    //is it a string? It is if the first and last character are "
    if (parameter.at(0) == '"' && parameter.at(parameter.size() - 1) == '"') {
        return "string";
    }
    //is it a char? It is if the first and last character are '(should also check it's size)
    else if (parameter.at(0) == '\'' && parameter.at(parameter.size() - 1) == '\'' && parameter.size() == SIZE_OF_ALL_CHARS) {
        return "character";
    }
    //check if it's integer
    //make funcs with try/catch to check whether parameter is int, float, etc.
    else if (ParameterIsInteger(parameter)) {
        return "integer";
    }
    //check if it's a double
    else if (ParameterIsDouble(parameter)) {
        return "double";
    }
    else {
        
        //because I don't execute things right away, userVariables isn't populated until during the execution phase
        return "user variable";
    }
}



bool ParameterIsInteger(string parameter) {
    try {
        int intParam = stoi(parameter);
        intParam -= 5;
        return true;
    }
    catch (...) {
        //something went wrong, probably not an int
        return false;
    }
}


bool ParameterIsDouble(string parameter) {
    try {
        //stod would allow integers as well, be careful
        double dubParam = stod(parameter);
        dubParam -= 5.0;
        return true;
    }
    catch (...) {
        //something went wrong, probably not an int
        return false;
    }
}


vector<UnfilteredLine> GetTokensFromLinesOfText(vector<string> linesOfText) {
    vector<UnfilteredLine> toReturn;

    for (int i = 0; i < linesOfText.size(); i++) {
        toReturn.push_back(GetTokensFromLineOfText(linesOfText.at(i)));
    }

    return toReturn;
}

UnfilteredLine GetTokensFromLineOfText(string lineOfText) {

    string token = "";
    string command = "";
    vector<string> listOfParameters;
    string param = "";
    

    //this gets the command
    for (int i = 0; i < lineOfText.size(); i++) {
        if (lineOfText.at(i) == ':') {
            
            command = token;
            token = "";
            //remove all the characters up to the current one from lineOfText,
            //be careful of possible spaces before each param
            lineOfText.erase(0, i + 1); //erase up to and including ':' in the line

            break;
        }
        else {
            token += lineOfText.at(i);
        }


    }


    while (lineOfText.size() > 0) {
        //this gets the params
      //handle the possible space before each parameter



        if (lineOfText.at(0) == ' ') {
            lineOfText.erase(lineOfText.begin() + 0);
        }


        for (int i = 0; i < lineOfText.size(); i++) {
            if (lineOfText.at(i) == ';') {

                lineOfText.erase(0, i + 1); //erase up to and including the current param's ';'
                listOfParameters.push_back(param);
                param = "";
                break;

            }
            else {
                param += lineOfText.at(i);
            }

        }

        //if the last character of the parameter is a space there should be an error

        //keep reading in parameters until the lineOfText has a length/size of 0
    }
    UnfilteredLine newLine = UnfilteredLine(command, listOfParameters);
    return newLine;




}



vector<string> GetTextFromFile() {

    vector<string> unfilteredText;
    string myText = "";

    // Read from the text file
    ifstream MyReadFile("TestFiles/Text.txt");

    // Use a while loop together with the getline() function to read the file line by line


    //string.at()

    while (getline(MyReadFile, myText)) {
        // Output the text from the file
        //add an extra space at the end of myText to get what I want

        //if first character is # it's a comment
        if (myText.at(0) == '#') {
            myText = "";
        }
        else if (myText == "" || myText == " " || myText == "\n") {
            //it's an empty line
            myText = "";
        }
        else {
            unfilteredText.push_back(myText);

            myText = "";
        }

        


    }

    // Close the file
    MyReadFile.close();

    return unfilteredText;

}