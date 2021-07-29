#include <iostream>
#include "stack.hpp"

using namespace std;

int main()
{
	Stack<int> stack(2);

	stack.push(5);
	stack.push(1);
	
	cout<<"出栈数 = "<<stack.pop()<<endl;
	cout<< "出栈数 = " << stack.pop()<<endl;
	stack.pop();
	return 0;
}

