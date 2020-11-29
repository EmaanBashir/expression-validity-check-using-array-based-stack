#include <iostream>
using namespace std;

//class Stack
class Stack {

	//private fields
private:
	char* stack;
	int top = -1;
	int size;

	//public methods
public:

	//constructor
	Stack(int n) {
		size = n;
		stack = new char[size];
	}

	//push method to insert elements into the stack
	void push(char element) {
		if (!this->isFull()) {
			stack[++top] = element;
		}
		else {
			cout << "Stack Overflow!" << endl;
		}
	}

	//pop method to remove and return top most element from the stack
	char pop() {
		if (!this->isEmpty()) {
			char element = stack[top];
			stack[top--] = NULL;
			return element;
		}
		else {
			cout << "Stack is Empty!" << endl;
		}
	}

	//method to check if the stack is empty
	bool isEmpty() {
		return (top == -1);
	}

	//method to check if the stack is full
	bool isFull() {
		return (top == size - 1);
	}

	//method to clear the stack
	void clear() {
		while (!this->isEmpty()) {
			this->pop();
		}
	}

	//method to return the top most element of the stack
	char peak() {
		if (!this->isEmpty()) {
			return stack[top];
		}
		else {
			cout << "The Stack is empty" << endl;
		}
	}
};

//method to check the validity of an expression using stack
void validityCheck(string expression) {
	bool valid = true;
	Stack stack(expression.size() / 2);

	//for loop to traverse over the expression string
	for (char character : expression) {

		//check for opening brackets
		if (character == '(' || character == '{' || character == '[') {
			stack.push(character);
		}

		//check for closing brackets
		else if (character == ')' || character == '}' || character == ']') {
			if (!stack.isEmpty()) {
				if (character == ')' && stack.peak() == '(') {
					stack.pop();
				}
				else if (character == '}' && stack.peak() == '{') {
					stack.pop();
				}
				else if (character == ']' && stack.peak() == '[') {
					stack.pop();
				}
				else {
					valid = false;
				}
			}
			else {
				valid = false;
			}
		}
	}
	if (!stack.isEmpty()) {
		valid = false;
	}
	cout << (valid ? "Valid Expression" : "Invalid Expression") << endl;
}

//main method to test the code
int main() {
	string expression;
	while (1) {
		cout << "Enter an expression to check its validity (x to exit): ";
		cin >> expression;
		if (expression == "x") {
			break;
		}
		validityCheck(expression);
	}
	return 0;
}


