#include <iostream>

using namespace std;

class Array
{
private:
	int *m_data;//指向首元素的指针
	int m_size;//当前元素个数
	int m_capacity;//能容纳元素的容量

public:
	Array(int capacity)
	{
		m_capacity = (capacity >0) ? capacity:10;
		m_data = new int[m_capacity] {};
	}
	~Array()
	{
		if (m_data == NULL)	return;
		delete[] m_data;
	}
	void add(int value)
	{
		if (m_size == m_capacity)
		{
			int *tmp = m_data;
			int *m_data = new int[m_capacity + 1];
			for (int i = 0; i <= m_size; i++) {
				*(m_data +i) = *(tmp+i);
			}
			delete[] tmp;
		}
		m_data[m_size++] = value;
	}

	int get(int index)
	{
		if (index < 0 || index >= m_size) {
			cout << "越界" << endl;
			return -1;
		};
		
		return m_data[index];

	}

	int size()
	{
		return m_size;
	}
};



int main()
{
	Array a(2);

	a.add(12);
	cout << "size = " << a.size() << endl;
	cout << "a(0) = " << a.get(0) << endl;

	a.add(15);
	cout << "size = " << a.size() << endl;
	cout << "a(1) = " << a.get(1) << endl;
	
	a.add(20);
	cout << "size = " << a.size() << endl;
	cout << "a(2) = " << a.get(2) << endl;

	a.add(40);
	cout << "size = " << a.size() << endl;
	cout << "a(3) = " << a.get(3) << endl;



	getchar();
	return 0;
}