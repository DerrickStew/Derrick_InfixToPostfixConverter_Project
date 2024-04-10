#pragma once
#include <stack>
#include <string>
using namespace std;

// converts an infix expression into an equivalent postfix expression
class InfixToPostfixConverter
{
private:
	string postfix;

	// precondition - character is not null
	// postcondition - returns 1 if operator is + or -, returns 2 if 
	// operator is * or /, & returns 0 otherwise
	int getOperatorPrecedence(char operation)
	{
		if (operation == '+' || operation == '-')
			return 1;
		else if (operation == '*' || operation == '/')
			return 2;
		return 0;
	}

public:
	InfixToPostfixConverter()
	{
		postfix = "";
	}

	// precondition - string is not empty
	// postcondition - converts infix expression into postfix expression
	void convertToPostfix(const string& infix)
	{
		stack<char> operatorStack;
		postfix = "";
		for (char character : infix)
		{
			if (isalpha(character))
				postfix += character;
			else if (character == '(')
				operatorStack.push(character);
			else if (character == ')')
			{
				while (!operatorStack.empty() && operatorStack.top() != '(')
				{
					postfix += operatorStack.top();
					operatorStack.pop();
				}
				operatorStack.pop();
			}
			else if (character == ' ')
				continue;
			else
			{
				while (!operatorStack.empty() && getOperatorPrecedence(character)
					<= getOperatorPrecedence(operatorStack.top()))
				{
					postfix += operatorStack.top();
					operatorStack.pop();
				}
				operatorStack.push(character);
			}
		}
		while (!operatorStack.empty())
		{
			postfix += operatorStack.top();
			operatorStack.pop();
		}
	}

	//postcondition - returns postfix
	string getPostfix() { return postfix; }
};

