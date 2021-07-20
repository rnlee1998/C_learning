#include <iostream>

#define ERROR -1
#define LEN 10
using namespace std;

template <typename ElemType>
class Sqlist
{
private:
	ElemType *data;
	int length;
public:
	Sqlist();
	~Sqlist();
	int clearList();
	int getLength();
	int isEmpty();
	ElemType getElem(int loc);
	int locateElem(ElemType value);
	void insertElem(ElemType value, int loc);
	void deleteElem(int loc);

};


int main()
{

	Sqlist<int> list;

	list.insertElem(99, -1);

	list.insertElem(11, 0);

	list.insertElem(22, 1);

	list.insertElem(33, 2);

	list.insertElem(44, 3);

	list.deleteElem(4);




	for (int i = 0; i <= list.getLength()-1; i++) {
		cout << list.getElem(i) << endl;
	}
	return 0;
}


//构造函数
template <typename ElemType>
Sqlist<ElemType>::Sqlist():length(0)
{
	data = new ElemType[LEN]();
	if (!data)
	{
		cout << "内存分配失败" << endl;
		return;
	}
	length = 0;
}

//析构函数
template <typename ElemType>
Sqlist<ElemType>::~Sqlist()
{
	if (!data)
		delete[] data;
	data = nullptr;
}

template <typename ElemType>
int Sqlist<ElemType>::clearList()
{
	length = 0;
}

template <typename ElemType>
int Sqlist<ElemType>::getLength()
{
	return length;
}

template <typename ElemType>
int Sqlist<ElemType>::isEmpty()
{
	if (!length) return 1;
	return 0;
}

template <typename ElemType>
ElemType Sqlist<ElemType>::getElem(int loc)
{
	if (loc < 0 || loc >= length) {
		cout << "访问越界" ;
		return -1;
	}
	return data[loc];
}

template <typename ElemType>
int Sqlist<ElemType>::locateElem(ElemType value)
{
	for (int i = 0; i <= length - 1; i++) {
		if (data[i] == value)	
			return i;
		else {
			cout << "没有这个元素" << endl;
			return	-1;
		}
	}
}

template <typename ElemType>
void Sqlist<ElemType>::insertElem(ElemType value, int loc)
{
	if (length == LEN || loc < 0 || loc > length) {
		cout << "插入位置错误" << endl;
		return;
	}
	for (int i = length - 1; i >= loc; i--) {
		data[i + 1] = data[i];
	}
	length++;
	data[loc] = value;
}

template <typename ElemType>
void Sqlist<ElemType>::deleteElem(int loc)
{
	if (length == 0 || loc < 0 || loc>=length) {
		cout << "删除位置错误" << endl;
		return;
	}

	for (int i = loc + 1; i <= length - 1; i++) {
		data[loc] = data[loc + 1];
	}
	length--;

}