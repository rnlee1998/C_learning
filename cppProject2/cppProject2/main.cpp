#include <iostream>
using namespace std;

class Car
{
private:
	int m_price;
	int m_height;
public:
	Car(int a = 0,int b = 0):m_price(a),m_height(b)
	{
		cout << "m_price = " << m_price << endl;
		cout << "m_height = " << m_height << endl;
	}
	////拷贝构造函数
	//Car(const Car &car):m_price(car.m_price),m_height(car.m_height)
	//{
	//	cout << "m_price = " << m_price << endl;
	//	cout << "m_height = " << m_height << endl;
	//}
	int m_other = 99;
};


int main()
{
	Car car1;
	Car car2(200000, 6);

	Car car3(car2);
	
	cout << car3.m_other<< endl;
	return 0;
}