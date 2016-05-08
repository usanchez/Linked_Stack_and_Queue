/**
Program for creating the stack using the linked list. Program performs all the operations such as push, pop and display. It takes care of stack underflow condition. There can not be stack full condition in stack using linked list. 
**/

#include <iostream>
#include <stdlib.h>

using namespace std;

// Declaration for data structure  of linked stack
template <class T>
class Lstack {
	private:
	typedef struct stack {
		T data;
		struct stack *next;
	}node;
	node *top, *temp;
	public:
	Lstack() {
		top = NULL;
	}
	
	void push();
	void display();
	void pop();
};

/*push function*/
template <class T>
void Lstack <T> ::push() {
	node *temp = new node;
	temp->next = NULL;
	cout << "Enter the new item:" << endl;
	cin >> temp->data;
	temp -> next = top;
	top = temp;
}
/*pop function*/
template <class T>
void Lstack <T> ::pop() {
	if (top == NULL)
		cout << "No more elements left. Stack underflow." << endl;
	else {
		node *temp = new node;
		cout << "The popped item is: " << top->data << endl;
		temp = top;
		top = top -> next;
		delete temp;
	}
}
/*display function*/
template <class T>
void Lstack <T> ::display() {
	if (top == NULL)
		cout << "The stack is empty.";
	else {
		node *temp = new node;
		temp = top;
		cout << "Stack display:" << endl;
		while (temp != NULL) {
			cout << " " << temp->data;
			temp = temp->next;
		}
	}
	cout << endl;
}
/*main*/
void main() {
	int choice;
	char ans = 'y';
	Lstack <int> stack;
	cout << "Stack using Linked List" << endl;
	while(ans == 'y') {
		cout << "Main menu" << endl;
		cout << "1. push\n2. pop\n3. display" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;
		switch(choice) {
			case 1: stack.push(); break;
			case 2: stack.pop(); break;
			case 3: stack.display(); break;
			default: exit(0);
		}
		cout << "Do you want to continue? y/n" << endl;
		cin >> ans;
	}
}