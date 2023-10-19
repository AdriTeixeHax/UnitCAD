#include "Calculator.h"

#include <cmath>
#include <vector>
#include <sstream>
#include <stdexcept>

///
#include <iostream>
///

using namespace mathCad2;

const char Calculator::operatorOrder[] = { '^', '*', '/', '+', '-' };
const char Calculator::invertIfAfter[] = { '*', '/', ')' };

bool Calculator::testIfFirstIsNegative(std::vector<std::string>& elements, int operatorIndex)
{
	if (operatorIndex - 2 >= 0 && elements.at(operatorIndex - 2).c_str()[0] == '-')
	{
		if (operatorIndex - 2 == 0)
		{
			return true;
		}

		for (char oper : invertIfAfter)
		{
			if (elements.at(operatorIndex - 3).c_str()[0] == oper)
			{
				return true;
			}
		}
	}

	return false;
}

bool Calculator::testIfSecondIsNegative(std::vector<std::string>& elements, int operatorIndex)
{
	if (elements.at(operatorIndex + 1).c_str()[0] == '-')
	{
		return true;
	}

	return false;
}

dataType_t getValue(std::string element)
{
	double value;
	try
	{
		value = stod(element);
	}
	catch (const std::invalid_argument&)
	{
		// @TODO: Search in the variables
	}
	catch (const std::out_of_range&)
	{
		// @TODO: The number is to big?
		///
		std::cerr << "The number is to big?" << std::endl;
		///
	}

	return value;
}

dataType_t Calculator::operate(dataType_t rhs, dataType_t lhs, char oper)
{
	switch (oper)
	{
	case '+':
		return (rhs + lhs);
	case '-':
		return (rhs - lhs);
	case '*':
		return (rhs * lhs);
	case '/':
		return (rhs / lhs);
	case '^':
		return pow(rhs, lhs);
	}
}

bool Calculator::compute(std::string rawExpression, dataType_t& result)
{
	std::stringstream ss(rawExpression);

	std::string element;
	std::vector<std::string> elements[2];
	while (ss >> element)
	{
		elements[0].push_back(element);
	}

	bool bank = false;
	bool resultIsEmpty = true;

	// @TODO: Do the parenthesis ouside the other operators
	for (char oper : operatorOrder)
	{
		int newBankCopied = 0;

		for (int i = 1; i < elements[bank].size() - 1; i++)
		{
			if (elements[bank].at(i).length() == 1 && elements[bank].at(i).c_str()[0] == oper)
			{
				// Asign the first operand
				bool isFirstNegative = testIfFirstIsNegative(elements[bank], i);
				dataType_t firstOperand = (1 - 2 * isFirstNegative) * getValue(elements[bank].at(i - 1));

				// Asign the second operand
				bool isSecondNegative = testIfSecondIsNegative(elements[bank], i);
				dataType_t secondOperand = (1 - 2 * isSecondNegative) * getValue(elements[bank].at(i + 1 + isSecondNegative));

				result = operate(firstOperand, secondOperand, oper);

				// Copy the expression before the operation to the other memory bank
				if (i > 1)
				{
					elements[!bank].insert(elements[!bank].begin(), elements[bank].begin(), elements[bank].begin() + i - 1 - isFirstNegative);
				}

				// Add the result to the other bank
				elements[!bank].emplace_back(std::to_string(result));

				// Copy the expression after the operation to the other memory bank
				if (i < elements[bank].size() - 3)
				{
					elements[!bank].insert(elements[!bank].begin(), elements[bank].begin() + i + 1 + isSecondNegative, elements[bank].end());
				}
				
				// Clear the current memory bank and change the bank
				elements[bank].clear();
				bank = !bank;

				i += 2 + isSecondNegative;
			}
		}
	}
	//while (false)
	//{
	//	bool invertResult = false;
	//	if (firstElement == "-")
	//	{
	//		ss >> firstElement;

	//		invertResult = true;
	//	}

	//	// Test if it is an operator
	//	switch (firstElement.c_str()[0])
	//	{
	//	case '+':
	//	{

	//		break;
	//	}
	//	case '(':
	//	{

	//		break;
	//	}
	//	default:
	//	{
	//		// The first element is a literal or an operator
	//		break;
	//	}
	//	}

	//	else
	//	{
	//		dataType_t aux;
	//		try
	//		{
	//			result = stod(rawExpression);
	//		}
	//		catch (const std::invalid_argument&)
	//		{

	//		}
	//		catch (const std::out_of_range&)
	//		{
	//			// @TODO: The number is to big?
	//			///
	//			std::cerr << "The number is to big?" << std::endl;
	//			///
	//		}
	//	}
	//}

	return true;
}