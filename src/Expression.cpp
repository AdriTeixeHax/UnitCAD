#include "Expression.h"

#include "Calculator.h"

using namespace mathCad2;

Expression::Expression(std::string& expressionStr)
{
	dataType_t result;
	if (Calculator::compute(expressionStr, result))
	{
		_value = result;
		_hasValue = true;
	}
	else
	{
		_expressionStr = expressionStr;
	}
}

std::string Expression::toString()
{
	if (_hasValue)
	{
		return std::to_string(_value);
	}
	else
	{
		return _expressionStr;
	}
}