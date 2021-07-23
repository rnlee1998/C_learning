#include <iostream>

using namespace std;

//链表的节点
class Node
{
public:	
	int data;
	Node *next;
};

//链表
class Linklist
{
	
public:
	Node *head;
	Linklist();
	~Linklist();

	//创建链表
	void createList(int len);
	
	//获取链表长度
	int getLength();

	//索引值
	int getData(int loc);
	
	//索引位置
	int getIndex(int value);
	
	//插入结点
	void insertNode(int loc, int value);
	
	//删除结点
	void deleteNode(int loc);

};


int main()
{
	
	Linklist list;
	list.createList(5);

	cout << "******************************************************" << endl;
	cout << "表长 = " << list.getLength() << endl;
	cout << "data(1)= "<<list.getData(1) << endl;
	list.insertNode(1, 100);
	cout << "表长 = " << list.getLength() << endl;
	cout << "data(1)= " << list.getData(1) << endl;
	list.deleteNode(1);
	cout << "表长 = " << list.getLength() << endl;
	cout << "data(1)= " << list.getData(1) << endl;

	cout << "******************************************************" << endl;

	return 0;

}

//构造函数
Linklist::Linklist()
{
	head = new Node();
	head->data = -1;
	head->next = nullptr;
	cout << "链表初始化head指向的地址" << head << endl;
}


//析构时应该释放所有堆空间（头节点+链表）
Linklist::~Linklist()
{
	Node *p1, *p2;
	p1 = head;
	while (p1)
	{
		p2 = p1;
		p1 = p1->next;
		cout << endl;
		cout << "将要释放的内存地址 = " << p2<<endl;
		delete p2;
	}
}

void Linklist::createList(int len)
{
	Node *p1 = head;
	for (int i = 1; i <= len; i++) {
		Node *p2 = new Node();
		p2->data = i;
		p2->next = nullptr;
		cout << "新开辟的内存地址 = " << p2 << " data = " << p2->data << " p2->next = " << p2->next << endl;
		cout  << endl;
		p1->next = p2;
		p1 = p2;
	}
}


//头结点不算链表长度
int Linklist::getLength()
{
	Node *p1, *p2;
	p1 = head;
	int cnt = 0;
	while (p1->next) {
		cnt++;
		p1 = p1->next;
	}
	return cnt;
}

int Linklist::getData(int loc)
{
	int len = this->getLength();
	if (loc <= 0 || loc > len) {
		cout << "索引越界" << endl;
		exit(0);
	}
	Node *p1 = head->next;
	for(int i=1;i<=loc-1;i++)
	{
		p1 = p1->next;	
	}
	return p1->data;
}

int Linklist::getIndex(int value)
{
	Node *p= head->next;
	int len = this->getLength();
	for (int i = 1; i <= len; i++) {
		cout << p->data << endl;
		if (p->data == value) 	return i;
		p = p->next;
	}
	cout << "没有这个数" << endl;
	return 0;
}

void Linklist::insertNode(int loc, int value)
{
	int len = this->getLength();
	if (loc <= 0 || loc > len+1) {
		cout << "插入位置非法！" << endl;
		return;
	}
	Node *p = head;
	Node *s = new Node();
	for (int i = 1; i <= loc-1; i++) { 
		p = p->next;
	}
	s->next = p->next;
	p->next = s;
	s->data = value;
}

void Linklist::deleteNode(int loc)
{
	int len = this->getLength();
	if (loc <= 0 || loc > len) {
		cout << "删除位置非法！" << endl;
		return;
	}
	Node *p = head;
	Node *s = nullptr;
	for (int i = 1; i <= loc-1; i++)
	{
		p = p->next;
	}
	s = p->next;
	p->next = p->next->next;
	delete s;
}