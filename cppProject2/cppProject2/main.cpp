#include <iostream>
using namespace std;

class Person
{
private:
	int m_gender;
	int m_age;
public:
	Person(int a = 0, int b = 20) :m_gender(a), m_age(b)
	{
		cout << "gender = " << m_gender << endl;
		cout << "age = " << m_age << endl;
	}
	Person(const Person &person) :m_gender(person.m_gender), m_age(person.m_age)
	{
		cout << "拷贝gender = " << m_gender << endl;
		cout << "拷贝age = " << m_age << endl;
	}
};

class Student :Person
{
public:
	Student(int a = 1, int b = 25) :Person(a,b)
	{
		/*cout << "Student gender = " << m_gender << endl;
		cout << "Student age = " << m_age << endl;*/
	}
	Student(const Student &stu) :Person(stu)
	{

	}
};

int main()
{
	Person person1;
	Person person(person1);

	Student stu1;
	Student stu2(stu1);

	return 0;
}