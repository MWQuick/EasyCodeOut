//       ______           ___      ___
//         /    /\    /  /   \    /   \
//        /    /  \  /  /        /
//       /    /    \/   \___/    \___/
//
// Date: 2/19/2019
// Name: Matthew Quick
// Project: ReadAndBlock
// Inputs: Text File containing code
// Outputs: String Vector containing code and comments from the text file, with formatted code.
// Program Description:
/*
	This program is designed to take either code snippets or whole programs from a .cpp file, seperate it into lines defined by the natural newlines made in an IDE, properly tab based off of the curly braces
		if that formatting does not survive the copying, to tab after code snippits to allow for pleasant looking color blocking.
*/
// Task 1 cont.: Implement a file reader that looks for a bin or resource folder in its directory and look for a hardcoded, named file within it.
// Task 1 cont.: Copy the contents of each line to a string vector.
// Design Choice: Moved task 1 to a seperate function "getText"
//
//
// Task ?: Move and revise code from "FormattedBlockOutput" into a method in this program.
// Design Choice: tabCode needs to be changed so that after each comment the columnLength collapses to the least largest necessary length.
//******************************************

#include <iostream>		//header containing cout and cin
#include <fstream>		//header containing stream elements
#include <vector>		//header containing vectors
#include <string>		//header containing strings

using namespace std;		//introduces namespace std needed to use cout and cin

//Given a vector, it will tab each line according to IDE standards and will ensure that the overall length is a multiple of 8.
//Needs to be modified from the standalone to ignore comments
/*
void tabCode (vector<string>& codeList)
{
	//Begin code unique to FormattedBlockOutput and its derivatives
	//Declare variables
	int tabStops = 0, columnLength;
	vector<int> prefixTabVals, suffixTabVals;
	
	//This block finds the number of tabs that each entry should have before the text.
	for(int i = 0; i < codeList.size(); i++)
	{	
		//If there is a closing bracket, decrement the tab stop
		if (codeList[i].find('}',0) != -1)
		{
			tabStops--;
		}
		//Sandwhiched to correctly tab before an opening curly brace and after a closing brace
		prefixTabVals.push_back(tabStops);
		//If there is an opening bracket, increments the tab stop
		if (codeList[i].find('{',0) != -1)
		{
			tabStops++;
		}
	}
	//This block will determine the tabbed longest length of the column
	//Note about code: The initial assignment and the first if statement might not assign the right value if all of the lines are less than 8 or if the first line is zero with no tab length.
	columnLength = (prefixTabVals[0] * 8) + codeList[0].length();
	for(int i = 1; i < codeList.size() - 1; i++)
	{		
		if(((prefixTabVals[i] * 8) + codeList[i].length()) > columnLength && ((prefixTabVals[i] * 8) + codeList[i].length()) <= 8)
		{
			columnLength = 8;
		}
		else if (((prefixTabVals[i] * 8) + codeList[i].length()) > columnLength)
		{
			columnLength = (prefixTabVals[i] * 8) + codeList[i].length() + (8 - (codeList[i].length() % 8));
		}
	}
	//This block will determine the suffix tabs
	for(int i = 0; i < codeList.size(); i++)
	{
		suffixTabVals.push_back(((columnLength / 8) - (codeList[i].length() / 8)) - prefixTabVals[i]);	
	}

	//Final Assignment Loop
	//This block will add the tabs to the lines
	for(int i = 0; i < codeList.size(); i++)
	{
		//Adds the tabs before the text
		for(int j = 0; j < prefixTabVals[i]; j++)
		{
			codeList[i] = "\t" + codeList[i];
		}
		//Adds the tabs after the text
		for(int j = 0; j < suffixTabVals[i]; j++)
		{
			codeList[i] += "\t";
		}
	}	
	
}
*/

//Gets the contents of the file located in the passed string, and return them to a vector string
vector<string> getText(string location)
{
	//Declare variable
	vector<string> text;
	int i = 0;
	string holdingString;
	
	//Blocked out for reference purposes and annotated for the same reason
	//Instantiate input file stream
	ifstream inFile;
	//Open the target folder in a subfolder of the directory that ReadAndBlock.cpp is in.
	inFile.open(location.c_str());
	//Manipulate the file only if the file is open, thus it won't cause a runtime error if the file doesn't exist
	if(inFile.is_open())
	{
		//returns 1 if the operation is successful, so it will loop until it reads the whole text file
		while(getline(inFile,holdingString))
		{
			text.push_back(holdingString);
		}
		//Closes the file, emptying the buffer, and releasing the file
		inFile.close();
	}
	else
	{
		cout << "Error, file not found!";
	}
	
	return text;
}

int main ()
{
	//Declare variables
	vector<string> codeList;	
	//Get the contents of the file
	codeList = getText("bin\\example1.cpp");
	
	
	return 0;
}

