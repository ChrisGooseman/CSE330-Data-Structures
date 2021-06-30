/*
 *Author: Christopher Guzman
 *File: Lab 1 - Part 2
 *Course: MURPHY - CSE330
 */

#include "stack.h"
#include <iostream>
#include <string>

// Function Declarations
bool isOperand(char c);
bool isOperator(char c);
int checkPrecedence(char c);
string infix2postfix(string x);

using namespace std;

int main(){
	// expression to be converted
	string expression = "(A+B)*C-(D/(J+D))";
	cout << "Infix notation: " << expression << endl;
	expression += ']';

	string postfix = infix2postfix(expression);
	cout << "Postfix notation: " <<  postfix << endl;

	return 0;
}	
// Function Definitions
// evaluate character for operand
bool isOperand(char c){
	if(c >= 'A' && c <= 'Z') return true;

	return false;
}

// evaluate character for operator
bool isOperator(char c){
	if(c == '*' || c == '/' || c == '+' || c == '-') return true;

	return false;
}

// check the precedence of operators
int checkPrecedence(char c){
	if(c == '*' || c == '/') return 2;
	if(c == '+' || c == '-') return 1;

	return 0;
}

// convert expression from infix to postfix
string infix2postfix(string x){
	string y;
	int index = 0;
	char s = x[index];

	Stack<char> stack;
	stack.push('[');

	// iterate through expression until the end
	while(s != ']'){
		if(s == '(')
			stack.push(s);
		else if(s == ')'){
			while(stack.gettop() != '('){
				y += stack.gettop();
				stack.pop();
			}
			// pop the remaining  opening paranthesis
			stack.pop();
		}// add to string if operand
		else if(isOperand(s))
			y += s;
		else if(isOperator(s)){
			// check if there are more operators in stack
			if(isOperator(stack.gettop())){
				// check operator precedences
				if(checkPrecedence(stack.gettop()) >= checkPrecedence(s)){
					while(stack.gettop() != '['){
						y += stack.gettop();
						stack.pop();
					}
					stack.push(s);
				}
				else // if operator is greater than operators in stack. push
					stack.push(s);
			}
			else // if no operators in stack. push
				stack.push(s);
		}// increment index
		index++;
		s = x[index];
	}

	// push remaining elements in stack if any
	if(!stack.isempty()){
		while(stack.gettop() != '['){
			y += stack.gettop();
			stack.pop();
		}
	}

	return y;
}
