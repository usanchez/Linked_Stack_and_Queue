/**
Program for creating the queue using the linked list. Program performs all the operations such as push, pop and display. It takes care of queue underflow condition. There can not be queue full condition in queue using linked list. 
**/

#include <iostream>
#include <cstdlib>

using namespace std;


// Declaration for data structure of linked queue
template <class T>
class Lqueue {
	private:
	typedef struct queue {
		T data;
		struct queue *next;
	}node;

	node *front, *rear;

	public:
	Lqueue() {
		front = NULL;
		rear = NULL;
	}
	
	void enqueue();
	void display();
	void dequeue();	
};

/*enqueue function*/
template <class T>
void Lqueue <T> ::enqueue() {
	node *temp = new node;
	temp->next = NULL;
	cout << "Enter the new item:" << endl;
	cin >> temp->data;
	if (front == NULL)
		front = temp;
	else
		rear->next = temp;
	rear = temp;
}
/*dequeue function*/
template <class T>
void Lqueue <T>::dequeue() {
	if (front == NULL)
		cout << "No more elements left. Stack underflow." << endl;
	else {
		node *temp = new node;
		cout << "The dequeued item is: " << front->data << endl;
		temp = front;
		front = front->next;
		delete temp;
	}
}
/*Display function*/
template <class T>
void Lqueue <T>::display() {
	if(front == NULL)
		cout << "The queue is empty.";
	else{
		node *temp = new node;
		temp = front;
		cout << "Queue display:" << endl;
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
	Lqueue <int> queue; // object for int type
	cout << "queue using Linked List" << endl;
	while(ans == 'y') {
		cout << "Main menu" << endl;
		cout << "1. Enqueue\n2. Dequeue\n3. Display" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;
		switch(choice) {
			case 1: queue.enqueue(); break;
			case 2: queue.dequeue(); break;
			case 3: queue.display(); break;
			default: exit(0);
		}
		cout << "Do you want to continue? y/n" << endl;
		cin >> ans;
	}
}
