#include <iostream>
using namespace std;

class Point
{
	friend Point operator+(Point p1, Point p2);
	friend ostream  &operator<<(ostream &,const Point &);
private:
	
	int m_x;
	int m_y;
public:
	int getX() {
		return m_x;
	} 
	int getY() {
		return m_y;
	}
	Point(int x, int y) :m_x(x), m_y(y)
	{

	}
	void display()
	{
		cout << "P("<<m_x<<","<<m_y<<")" << endl;
	}
};


Point operator+(Point p1, Point p2)
{
	return Point(p1.m_x + p2.getX(), p1.getY() + p2.getY());
}

ostream  &operator<<(ostream &cout,const Point &p)
{
	cout << "P(" << p.m_x << "," << p.m_y << ")" << endl;
	return cout;
}

template <typename T>
T add(T a, T b)
{
	return a + b;
}



int main()
{
	add<int>(10, 20);
	add(0.5, 1.3);
	add<Point>(Point(5, 5), Point(3, 2)).display();

	return 0;
}