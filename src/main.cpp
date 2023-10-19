#include <iostream>
#include <sstream>
#include <map>
#include <vector>

#include "InterpretedLine.h"

using namespace std;

//class Expr
//{
//	bool isValueAssigned = false;
//	double value;
//	string raw;
//
//public:
//	Expr(string& raw)
//	{
//		try
//		{
//			value = stod(raw);
//			isValueAssigned = true;
//		}
//		catch (const invalid_argument&)
//		{
//			this->raw = raw;
//		}
//		catch (const out_of_range&)
//		{
//			// @TODO: The number is to big?
//			cerr << "The number is to big?" << endl;
//		}
//	}
//
//	string toString()
//	{
//		if (isValueAssigned)
//		{
//			return to_string(value);
//		}
//		else
//		{
//			return raw;
//		}
//	}
//};
//
//class InterpretedLine
//{
//	string variableName;
//	vector<string> functionArguments;
//	Expr expression;
//
//public:
//
//};
//
//map<string, map<int, Expr>> definedVariables;
//vector<InterpretedLine> documentLines;
//
//vector<string> inputStrVector = {
//		/*"A : 7",*/
//		"A =",
//		"A : 5",
//		"A ="
//	};
//
//bool tryInterpretString(int lineNumber, string& inputStr)
//{
//	stringstream ss(inputStr);
//	string lhs, operStr;
//	ss >> lhs;
//	ss >> operStr;
//	
//	if (operStr.length() != 1)
//	{
//		// @TODO: Error Message: The operator is not valid
//		cerr << "The operator is not valid (line " << lineNumber << ")" << endl;
//		return false;
//	}
//	
//	bool operatorFound = false;
//	if (operStr == "(")
//	{
//		// @TODO: Functions
//
//		operatorFound = true;
//	}
//	else if (operStr == ":")
//	{
//		string rhs;
//		ss >> rhs;
//
//		if (definedVariables.find(lhs) == definedVariables.end())
//		{
//			// The variable is not defined
//			map<int, Expr> aux; 
//			aux.emplace(lineNumber, rhs);
//			definedVariables.emplace(lhs, aux);
//		}
//		else
//		{
//			// The variable is already defined
//			definedVariables.at(lhs).emplace(lineNumber, rhs);
//		}
//
//		operatorFound = true;
//	}
//
//	// @TODO: Make it search for the = in the inputString
//	else if (operStr == "=")
//	{
//		if (definedVariables.find(lhs) == definedVariables.end())
//		{
//			// The variable is not defined
//			// @TODO: Error Message: The variable is undefined
//			cerr << "The variable is undefined (line " << lineNumber << ")" << endl;
//		}
//		else
//		{
//			// The variable is already defined
//			for (map<int, Expr>::reverse_iterator mapIterator = definedVariables.at(lhs).rbegin(); mapIterator != definedVariables.at(lhs).rend(); mapIterator--)
//			{
//				if (mapIterator->first < lineNumber)
//				{
//					cout << (mapIterator)->second.toString() << endl;
//					break;
//				}
//				else if (mapIterator == definedVariables.at(lhs).rend())
//				{
//					// @TODO: Error Message: The variable was not previously declared
//					cerr << "The variable was not previously declared (line " << lineNumber << ")" << endl;
//				}
//			}
//		}
//	}
//	else
//	{
//		// @TODO: Error Message: The line syntax is incorrect
//		cerr << "The line syntax is incorrect (line " << lineNumber << ")" << endl;
//		return false;
//	}
//	
//	return true;
//}
//
//int main()
//{
//	for (int i = 0; i < inputStrVector.size(); i++)
//	{
//		tryInterpretString(i, inputStrVector.at(i));
//	}
//
//	return 0;
//}

using namespace mathCad2;

void print(InterpretedLine& interpretedLine)
{
	if (interpretedLine.getDisplayResult()) cout << interpretedLine.getResult() << endl;
}

vector<InterpretedLine> interpretedLineVector = {
	InterpretedLine("3 - 5"),
	InterpretedLine("- 3 * - 5"),
	InterpretedLine("- 3 / 5"),
	InterpretedLine(" 3 - 5 * 8"),
	InterpretedLine(" 230 * 3 ^ 0.5"),
};

int main()
{
	for (InterpretedLine& interpretedLine : interpretedLineVector) print(interpretedLine);

	return 0;
}