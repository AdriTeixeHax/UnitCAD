#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

namespace mathCad2
{
	class Expression
	{
		bool _hasValue = false;
		double _value;
		std::string _expressionStr;

	public:
		Expression(std::string& _expressionStr);

		std::string toString();
	};
}

#endif
