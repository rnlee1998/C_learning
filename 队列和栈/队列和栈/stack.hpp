#pragma once
#include <iostream>

using namespace std;

template<typename Elemtype>
class Stack
{
public:
	int stacksize;
	Elemtype *top = nullptr;
	Elemtype *base = nullptr;
	Stack(int size = 0);
	~Stack();
	int getLength();
	int isEmpty();
	void clearStack();
	void push(Elemtype data);
	Elemtype pop();
};


template<typename Elemtype>
Stack<Elemtype>::Stack(int size) :stacksize(size)
{
	base = new Elemtype[stacksize];
	top = base;
	if (!base) {
		cout << "内存分配失败" << endl;
	}
	cout << "创建栈" << endl;
}


template<typename Elemtype>
Stack<Elemtype>::~Stack()
{
	delete[] base;
	base = nullptr;
	top = nullptr;
	stacksize = 0;
	cout << "删除栈" << endl;
}

template<typename Elemtype>
int Stack<Elemtype>::getLength()
{
	return (top - base);

}

template<typename Elemtype>
int Stack<Elemtype>::isEmpty()
{
	return (top - base) == 0 ? 1 : 0;
}

template<typename Elemtype>
void Stack<Elemtype>::clearStack()
{
	if (!base)
		top = base;
}
 
//进栈后，top指的并非刚入栈的元素，而是它的后一位
template<typename Elemtype>
void Stack<Elemtype>::push(Elemtype data)
{
	if (top - base == stacksize)
	{
		cout << "栈满,进栈失败" << endl;
		return;
	}
	*top = data;
	top++;
}

template<typename Elemtype>
Elemtype Stack<Elemtype>::pop()
{
	if (isEmpty()) {
		cout << "栈空，无法出栈" << endl;
		exit;
	}
	top--;
	return *top;
}