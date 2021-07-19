#include <iostream>
using namespace std;

//所有异常的基类
class Exception
{
public:
	virtual const char *what() = 0;//纯虚函数，实现在子类
};

class DivideException : public Exception
{
public:
	const char * what()
	{
		return "不能除以0";
	}
};

int divide(int v1, int v2) throw (int)
{
	if (!v2) throw DivideException();
	return v1 / v2;
}

int main()
{
	cout << "start" << endl;
	try
	{
		int a = 10;
		int b = 0;
		int c = divide(a, b);
	}
	catch (DivideException exception)
	{
		cout << "异常:" <<exception.what()<< endl;
			
	}
	cout << "end" << endl;
	return 0;

}


