#pragma once
#include "ExpressionManagerInterface.h"
#include <sstream>
#include <istream>
#include <iostream>
#include <stack>
#include <cctype>
#include <string>


class ExpressionManager : 
	public ExpressionManagerInterface
{
protected:

	const string OpenSquareBrace = "[";
	const string CloseSquareBrace = "]";

	const string OpenCurlyBracket = "{";
	const string CloseCurlyBracket = "}";

	const string OpenParenthesis = "(";
	const string CloseParenthesis = ")";

	const string Division = "/";
	const string Multiplication = "*";
	const string Addition = "+";
	const string Subtraction = "-";
	const string Mod = "%";


	int MultiplicationPriority = 2;
	int AdditionPriority = 1;
	int OpeningBracketPriority = 0;
	int ClosingBracketPriority = 0;

	



public:
	ExpressionManager();

	~ExpressionManager();

	bool isBalanced(string expression);
	string postfixToInfix(string postfixExpression);
	string infixToPostfix(string infixExpression);
	string postfixEvaluate(string postfixExpression);

	bool isOperator(string ss);
	bool isNumber(string ss);
	bool isBracket(string ss);
	bool CompareBracketTop(string nextCompare, stack<string>& bracketStack);
	bool BracketType(string ss);

	int determinePriority(string ss, stack<string>& OperatorStack);

	bool isValidExpression(string ss);

	void process_operator(string ss, stack<string>& OperatorStack, string& PostFixString);

	int EvaluateOperator(string ss, stack<int>& NumberStack);

};