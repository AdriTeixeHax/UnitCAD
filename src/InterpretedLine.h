#ifndef INTERPRETED_LINE_H
#define INTERPRETED_LINE_H

#include <string>
#include <vector>

#include "Expression.h"

namespace mathCad2
{
	// Private variables
	class InterpretedLine
	{
		bool _displayResult;
		std::string _variableName;
		//std::vector<Expression> _functionArguments;
		Expression _expression;

	public:
		// Constructors
		InterpretedLine(std::string expressionStr) : _expression(expressionStr), _displayResult(true) {} // Showing the result of an expression
		//InterpretedLine(std::string variableName, std::vector<std::vector<double>> functionArguments); // Displaying a function or expression with functions
		InterpretedLine(std::string variableName, std::string expressionStr, bool displayResult = false) : // Declaration of a variable
			_variableName(variableName), _expression(expressionStr), _displayResult(displayResult) {}
		//InterpretedLine(std::string variableName, std::vector<double> functionArguments, std::string expressionStr, bool displayResult = false); // Declaration of a function
	
		// Getters
		bool getDisplayResult() { return _displayResult; }
		std::string getVariableName() { return _variableName; }
		std::string getResult() { return _expression.toString(); }

		// Public methods
	};
}

#endif
