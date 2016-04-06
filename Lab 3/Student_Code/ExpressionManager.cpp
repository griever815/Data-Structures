#include "ExpressionManager.h"


ExpressionManager::ExpressionManager()
{


}


ExpressionManager::~ExpressionManager()
{


}




bool ExpressionManager::isBalanced(string expression)
{
	/*
	* Checks whether an expression is balanced on its parentheses
	* 
	* - The given expression will have a space between every number or operator
	* 
	* @return true if expression is balanced
	* @return false otherwise
	*/

	stack<string> bracketStack;
	string next;
	stringstream ss;
	ss << expression;

	/////So this should always work as long as there is something in ss to pass into next. If there is nothing to pass into next, then it kicks out of the loop.
	while(ss >> next) 
	{
		bool confirmBracket = isBracket(next);  ////If the string is a type of bracket, then isBracket will return true. If not, then isBracket returns false.
		
		if (confirmBracket == true)  //// if my isBracket function returned true, then it enters here.
		{
			if (next == OpenParenthesis || next == OpenCurlyBracket || next == OpenSquareBrace)  ////If next is one of the 3 open parethesis, then it pushes onto the stack.
			{
				bracketStack.push(next);
			}
			else if (next == CloseParenthesis || next == CloseCurlyBracket || next == CloseSquareBrace)  ////If next is one of the 3 closing parenthesis, then it enters here.
			{
				////If the next string is the closing of the same type of parentesis as the one on top of the stack, then it returns true. If not, it returns false.
				bool compared = CompareBracketTop(next, bracketStack); 
				if (compared == false) ////If CompareBracketTop returned false, then the equation is not balanced and it returns false.
				{
					return false;
				}
				else
				{

				}
			}
		}
	}

	bool isEmpty = bracketStack.empty();

	if (isEmpty == true) //// After the ss expression is done, and the bracketStack is empty, then it means the equation was balanced.
	{
		return true;
	}
	else if (isEmpty == false) //// After the ss expression is done, and the bracketStack is not empty, then it means the equation was not balanced.
	{
		return false;
	}
}


string ExpressionManager::postfixToInfix(string postfixExpression)
{
	/**
	 * Converts a postfix expression into an infix expression
	 * and returns the infix expression.
	 *
	 * - The given postfix expression will have a space between every number or operator.
	 * - The returned infix expression must have a space between every number or operator.
	 * - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
	 * - Check lab requirements for what will be considered invalid.
	 *
	 * return the string "invalid" if postfixExpression is not a valid postfix expression.
	 * otherwise, return the correct infix expression as a string.
	 */
	 stack<string> PostFixStack;
	 string PostFixString;
	 stringstream ss;

	 ss << postfixExpression;
	 string next;

	while(ss >> next)
	{
		
	 	bool NumberOrNot = isNumber(next);
	 	bool OperatorOrNot = isOperator(next);

	 	if (NumberOrNot == true)
	 	{
	 		PostFixStack.push(next);
	 	}
	 	if (OperatorOrNot == true)
	 	{
	 		if (PostFixStack.size() >= 2)
	 		{
	 			string OperatorAdd = next;
	 			string part1;
	 			string part2;

	 			part2 = PostFixStack.top();
	 			PostFixStack.pop();

	 			part1 = PostFixStack.top();
	 			PostFixStack.pop();

	 			PostFixString = OpenParenthesis + " " + part1 + " " + OperatorAdd + " " + part2 + " " + CloseParenthesis;
	 			PostFixStack.push(PostFixString);
	 		}
	 		else
	 		{
	 			return "invalid";
	 		}
	 	}
	}
	if (PostFixStack.size() == 1)
	{
		string toreturn = PostFixStack.top();

		return  toreturn;
		
	}
	else
	{
		return "invalid";
	}
}


string ExpressionManager::infixToPostfix(string infixExpression)
{
	  /*
	  * Converts an infix expression into a postfix expression 
	  * and returns the postfix expression
	  * 
	  * - The given infix expression will have a space between every number or operator.
	  * - The returned postfix expression must have a space between every number or operator.
	  * - Check lab requirements for what will be considered invalid.
	  * 
	  * return the string "invalid" if infixExpression is not a valid infix expression.
	  * otherwise, return the correct postfix expression as a string.
	  */

	stack<string> OperatorStack;
	string PostFixString = "";
	bool confirmBalance = isBalanced(infixExpression);
	bool confirmValid = isValidExpression(infixExpression);

	stringstream ss; 

	ss << infixExpression;
	string next;

	if (confirmBalance == true)
	{
		if (confirmValid == true)
		{
			while(ss >> next)
			{

				if (isNumber(next))
				{
					PostFixString += next;
					PostFixString += " ";
					
				}
				else if (isOperator(next))
				{
					process_operator(next, OperatorStack, PostFixString);
				}
				else
				{	
					return "invalid";
				}
			} // end while loop

			while(!OperatorStack.empty())
			{
				if (OperatorStack.size() == 1)
				{
					string add = OperatorStack.top();
					OperatorStack.pop();
					PostFixString = PostFixString + add;
					
				}
				else
				{
					string add = OperatorStack.top();
					OperatorStack.pop();
					PostFixString += add;
					PostFixString += " ";
				}
						
				
			}
		}
		else
		{	
		
		return "invalid";
		}	
	}
	else
	{	
		
		return "invalid";
	}

	return PostFixString;
}


string ExpressionManager::postfixEvaluate(string postfixExpression)
{
	/*
	 * Evaluates a postfix expression returns the result as a string
	 * 
	 * - The given postfix expression will have a space between every number or operator.
	 * - Check lab requirements for what will be considered invalid.
	 * 
	 * return the string "invalid" if postfixExpression is not a valid postfix Expression
	 * otherwise, return the correct evaluation as a string
	 */ 

	stack<int> NumberStack;
	stack<string> OperatorStack;

	stringstream ss;
	ss << postfixExpression;
	string next;

	while(ss >> next)
	{
		if (isBalanced(postfixExpression))
		{
			if (isValidExpression(postfixExpression))
			{
				if (isNumber(next))
				{
					stringstream cc;
					cc << next;
					int value;
					cc >> value;

					NumberStack.push(value);
				}
				else if (isOperator(next))
				{
					if (NumberStack.size() < 2)
					{
						
					}
					else
					{

						int newNumber = EvaluateOperator(next, NumberStack);
						if (newNumber == -111)
						{

							return "invalid";
						}
						else
						{
							
							NumberStack.push(newNumber);
						}
					}
				}
			}
		}
		
	}
	if (NumberStack.size() == 1)
	{
		int toreturn = NumberStack.top();

		stringstream vv;
		vv << toreturn;
		string finalReturn;
		vv >> finalReturn;
		return finalReturn;
	}
	else
	{
		return "invalid";
	}


		
}

////If the ss string is an Operator, then it returns true. If not, then it returns false.
bool ExpressionManager::isOperator(string ss)
{
	if (ss == Division || ss == Multiplication || ss == Addition || ss == Subtraction || ss == Mod || 
		ss == OpenParenthesis || ss == OpenSquareBrace || ss == OpenCurlyBracket || ss == CloseParenthesis || ss == CloseSquareBrace || ss == CloseCurlyBracket)
	{
		return true;
	}
	else
	{
		return false;
	}
}


////This should check to see if the string is a number, and not something like a9 or 24t or 1b3, etc etc.
bool ExpressionManager::isNumber(string ss)
{
	int count = 0;
	int increment = 0;

	for(increment; increment < ss.size(); increment++) 
	{
		if (isdigit(ss[increment]))
		{
			count++;
		}
	}

	if (increment == count)
	{
		return true;
	}
	else
	{
		return false;
	}
}
	
////If the string is a type of bracket, then it will return true. If not, then it returns false.
bool ExpressionManager::isBracket(string ss)
{

	string next = ss;
	

	////If the string is a type of bracket, then it will return true. If not, then it returns false.
	if (next == OpenParenthesis || next == CloseParenthesis || next == OpenSquareBrace || next == CloseSquareBrace || 
		next == OpenCurlyBracket || next == CloseCurlyBracket)
	{
		return true;
	}
	else
	{
		return false;
	}
}

////If the nextCompare string is the closing of the same type of parentesis as the one on top of the stack, then it returns true. If not, it returns false.
bool ExpressionManager::CompareBracketTop(string nextCompare, stack<string>& bracketStack)
{	
	bool isEmpty = bracketStack.empty();  ////Checks to see if the stack is empty before we do anything to it.
	if (isEmpty == false) ////If the stack is not empty, then we can do stuff to it.
	{
		if (nextCompare == CloseParenthesis) ////If nextCompare is the same as CloseParethesis, then it checks to see if the OpenParenthesis is on top of the stack.
		{
			if (bracketStack.top() == OpenParenthesis)
			{
				bracketStack.pop();////If it was the matching type, then it removes the open type and returns true.
				return true;
			}
		}


		if (nextCompare == CloseCurlyBracket)////If nextCompare is the same as CloseCurlyBracket, then it checks to see if the OpenCurlyBracket is on top of the stack.
		{
			if (bracketStack.top() == OpenCurlyBracket)
			{
				bracketStack.pop();  ////If it was the matching type, then it removes the open type and returns true.
				return true;
			}
		}


		if (nextCompare == CloseSquareBrace)////If nextCompare is the same as CloseSquareBrace, then it checks to see if the OpenSquareBrace is on top of the stack.
		{
			if (bracketStack.top() == OpenSquareBrace)
			{
				bracketStack.pop();////If it was the matching type, then it removes the open type and returns true.
				return true;
			}
		}
	}
	
	return false;
}


////Returns True if is an opening bracket, and returns false if it is a closing.
bool ExpressionManager::BracketType(string ss)
{
	if (ss == OpenParenthesis || ss == OpenSquareBrace || ss == OpenCurlyBracket)
	{
		return true;
	}
	else
	{
		return false;
	}
}

////Returns true if the operator/parenthesis can be added to the stack.
int ExpressionManager::determinePriority(string ss, stack<string>& OperatorStack)
{
	bool isEmpty = OperatorStack.empty();
	
	int NewPriorty;
	
	if (isEmpty == false)
	{
		string WhatsOnTop = OperatorStack.top();

		if (ss == OpenParenthesis || ss == OpenSquareBrace || ss == OpenCurlyBracket)
		{
			NewPriorty = OpeningBracketPriority;
		}
		if (ss == CloseParenthesis || ss == CloseSquareBrace || ss == CloseCurlyBracket)
		{
			NewPriorty = ClosingBracketPriority;
		}
		if (ss == Addition || ss == Subtraction)
		{
			NewPriorty = AdditionPriority;
		}
		if (ss == Multiplication || ss == Division || ss == Mod)
		{
			NewPriorty = MultiplicationPriority;
		}		
	}

	return NewPriorty;
}


bool ExpressionManager::isValidExpression(string ss)
{
	string next;
	stringstream stream;

	int numbsize;
	int optsize;

	stack<string> numbers;
	stack<string> operators;

	stream << ss;

	while(stream >> next)
	{
		bool numb = isNumber(next);
		bool opt = isOperator(next);

		if (numb == true)
		{
			numbers.push(next);
		}
		if (next == Division || next == Multiplication || next == Addition || next == Subtraction || next == Mod)
		{
			operators.push(next);
		}
	}

	numbsize = numbers.size();
	optsize = operators.size();

	if (numbsize == (optsize + 1))
	{
		return true;
	}
	else
	{
		return false;
	}

}


void ExpressionManager::process_operator(string ss, stack<string>& OperatorStack, string& PostFixString)
{
	if (OperatorStack.empty() || ss == OpenParenthesis || ss == OpenSquareBrace || ss == OpenCurlyBracket)
	{
		OperatorStack.push(ss);
	}
	else
	{
		if (determinePriority(ss, OperatorStack) > determinePriority(OperatorStack.top(), OperatorStack))
		{
			OperatorStack.push(ss);
		}
		else
		{
			while(!OperatorStack.empty()
				&& (OperatorStack.top() != OpenParenthesis && OperatorStack.top() != OpenSquareBrace && OperatorStack.top() != OpenCurlyBracket)
				&& (determinePriority(ss, OperatorStack) <= determinePriority(OperatorStack.top(), OperatorStack)))
			{
			
				PostFixString += OperatorStack.top();
				PostFixString += " ";
				OperatorStack.pop();
			}

			if (ss == CloseParenthesis || ss == CloseSquareBrace || ss == CloseCurlyBracket) 
			{
				if (!OperatorStack.empty()
					&& (OperatorStack.top() == OpenParenthesis || OperatorStack.top() == OpenSquareBrace || OperatorStack.top() == OpenCurlyBracket))
				{
					OperatorStack.pop();
				}
			}
			else
			{
				OperatorStack.push(ss);
			}
		}
	}
}



int ExpressionManager::EvaluateOperator(string ss, stack<int>& NumberStack)
{
	int rhs;
	int lhs;
	int int3;
	int divisionbyzero = -111;

	rhs = NumberStack.top();
	NumberStack.pop();
	lhs = NumberStack.top();
	NumberStack.pop();

	if (ss == Addition)
	{
		int3 = lhs + rhs;

	}
	
	else if (ss == Subtraction)
	{
		int3 = lhs - rhs;
	}
	
	else if (ss == Multiplication)
	{
		int3 = lhs * rhs;
	}

	else if (ss == Division)
	{
		if (lhs == 0 || rhs == 0)
		{
			return divisionbyzero;
		}
		else
		{
			int3 = lhs / rhs;
		}
	}
	else if (ss == Mod)
	{
		int3 = lhs % rhs;
	}

	

	return int3;
}