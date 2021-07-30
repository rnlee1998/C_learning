#include <iostream>

using namespace std;

class Qnode
{
public:
	int data = 0;
	Qnode* next = nullptr;

};

class Linkqueue
{
public:

	Qnode* front;//队头指针
	Qnode* rear;//队尾指针
	Linkqueue()
	{
		front = new Qnode();
		rear = front;
	}
	~Linkqueue()
	{
		while (front)
		{
			rear = front->next;
			delete front;
			front = rear;
		}
	}
	void inQueue(int value);
	void outQueue(int &value);
};

int main()
{
	Linkqueue linkqueue;
	linkqueue.inQueue(5);
	linkqueue.inQueue(3);

	Qnode* p = linkqueue.front;
	while (p)
	{
		cout << p->data << endl;
		p = p->next;
	}
	cout << endl;
	int value = -99;
	linkqueue.outQueue(value);
	cout << value << endl;
	return 0;
}

void Linkqueue::inQueue(int value)
{
	rear->next = new Qnode();
	rear = rear->next;
	rear->data = value;
}

void Linkqueue::outQueue(int &value)
{
	if (!front->next) {
		cout << "队空了，不能出队" << endl;
		return;
	}
	Qnode* p = front->next;
	front->next = p->next;
	value = p->data;
	delete p;
}