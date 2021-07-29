#include <iostream>

using namespace std;


class Node
{
public:
	int data = 0;
	Node* next = nullptr;

};


class Linkstack
{
public:
	Node* head;
	Linkstack() :head(nullptr)
	{

	}
	~Linkstack()
	{

	}
	int isEmpty();
	void push(int value);
	void pop(int &value);
};

int main()
{
	Linkstack linkstack;
	cout << "空？" << linkstack.isEmpty() << endl;
	linkstack.push(5);
	linkstack.push(-1);
	linkstack.push(9);
	cout << "空？" << linkstack.isEmpty() << endl;
	for (int i = 1; i <= 4; i++) {
		int value;
		linkstack.pop(value);
		cout << "linkstack.data = " <<value  << endl;
	}
	cout << "空？" << linkstack.isEmpty() << endl;
	return 0;
}



void Linkstack::push(int value)
{
	Node*p = new Node();
	p->next = head;
	p->data = value;
	head = p;
}


void Linkstack::pop(int &value)
{
	if (!head)
	{
		cout << "栈空了，不能出栈了" << endl;
		return;
	}
	Node *p = head;
	value = head->data;
	head = head->next;
	delete p;
	
}

int Linkstack::isEmpty()
{
	return head == nullptr ? 1 : 0;
}