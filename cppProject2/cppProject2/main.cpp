#include <iostream>
using namespace std;

class Point
{
	friend Point operator+(Point p1, Point p2);
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

int main()
{
	Point point1(1,0);
	Point point2(2, 1);
	Point point3 = point1+point2;
	point3.display();

	return 0;
}