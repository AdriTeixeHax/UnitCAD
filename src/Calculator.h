#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <vector>

namespace mathCad2
{
	typedef double dataType_t;

	static class Calculator
	{
		// Constants
		const static char operatorOrder[];
		const static char invertIfAfter[];

		// Private methods
		static bool testIfFirstIsNegative(std::vector<std::string>& elements, int operatorIndex);
		static bool testIfSecondIsNegative(std::vector<std::string>& elements, int operatorIndex);
		static dataType_t operate(dataType_t rhs, dataType_t lhs, char oper);
	public:
		// Public methods
		static bool compute(std::string rawExpression, dataType_t& result);
	};
}


#endif