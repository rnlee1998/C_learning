#include <iostream>
using namespace std;

class Person
{
public:

	int m_height;
	static int m_age;
	static void func()
	{
		m_age = 1;
		m_height = 5;
	}	
};

int Person::m_age = 5;

int main()
{		
	cout << Person::m_age << endl;
	Person person;
	cout << person.m_age << endl;
	Person *p = new Person();
	cout << p->m_age << endl;
	delete p;
	getchar();
	return 0;
}

