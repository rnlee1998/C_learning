#include <iostream>
#define MAXQSIZE 100
using namespace std;

template <typename ElemType>
class Queue
{
public:
	ElemType* base;
	int front;//队头下标
	int rear;//队尾下标
	Queue()
	{
		front = rear = 0;
		base = new ElemType[MAXQSIZE]();
	}
	~Queue()
	{
		delete[] base;
	}
	int getLength();
	void inQueue(ElemType value);//这里用少存一个元素的方式来求长度
	void outQueue(ElemType &value);

};



int main()
{
	

	Queue<int> queue;

	cout << "队长为 = "<<queue.getLength() << endl;
	for (int i = 1; i <= 100; i++) {

		queue.inQueue(i);
	}
	cout << "队长为 = " << queue.getLength() << endl;
	for (int i = 1; i <= 95; i++) {
		int value;
		queue.outQueue(value);
	}
	for (int i = 96; i <= 100; i++) {
		int value;
		queue.outQueue(value);
		cout << "第" << i << "个入队的数 = " << value << endl;
	}



	return 0;
}

template <typename ElemType>
int Queue<ElemType>::getLength()
{
	return (rear + MAXQSIZE - front) % MAXQSIZE;
}

template <typename ElemType>
void Queue<ElemType>::inQueue(ElemType value)
{
	if ((rear + 1) % MAXQSIZE == front) {
		cout << "队满了，不能入队" << endl;
		return;
	}
	base[rear] = value;
	rear =(rear+1)%MAXQSIZE;//实现了循环的列表 

}
template <typename ElemType>
void Queue<ElemType>::outQueue(ElemType &value)
{
	if (rear == front) {
		cout << "队空，不能出队" << endl;
		return;
	}
	value = base[front];
	front = (front + 1) % MAXQSIZE;

}

