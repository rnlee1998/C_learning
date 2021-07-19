#include <iostream>

using namespace std;
int main()
{
	//自动识别类型
	auto a = 5.6;
	//decltype取类型
	decltype(a) b = 5;

	auto p = new int();
	//空指针
	p = nullptr;
	cout << p<< endl;


	//快速遍历
	int array[] = { 11,22,33,44,55,66 };
	for (int item : array)
	{
		cout << item << endl;
	}

	//更加简洁的初始化方式
	int array1[]{ 11,22,33,44,55,66 };


	auto p1 = []() {
		cout << "lambda func()" << endl;
	}; 
	p1();

	([]() {
		cout << "lambda func()----------------p2" << endl;
	});
	

	auto p3 = [](int a, int b) ->int{
		return a + b;
	};

	cout << p3(10, 20) << endl;

	int a = 1;
	([a]() mutable{
		a++;
		cout << "a = "<<a << endl;
	});

	getchar();
	return 0;

}