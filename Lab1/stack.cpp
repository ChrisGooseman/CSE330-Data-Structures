#include <vector>
#include <string>

using namespace std;

template<typename T>
class Stack
{
 public:
 Stack();//creates the stack
 bool isempty(); // returns true if the stack is empty
 T gettop();//returns the front of the list 
 void push(T entry);//add entry to the top of the stack
 void pop();//remove the top of the stack
 private:
 vector<T> stack;
}; // Stack

template<typename T>
Stack<T>::Stack()
{
}

template<typename T>
bool Stack<T>::isempty()
{ if (stack.size() == 0)
	return true;
	else
	return false;
}

template<typename T>
T Stack<T>::gettop()
{ return stack[stack.size()-1];
}

template<typename T>
void Stack<T>::push(T entry)
{
   stack.push_back(entry);
}

template<typename T>
void Stack<T>::pop()
{
   stack.pop_back();
}
