#include <iostream>
using namespace std;

class MakeCar
{
public:
	virtual void MakeHead() =0;
	virtual void MakeBody() =0;
	virtual void MakeTail() =0;

public:
	void Make()//ģ�庯�� �涨��ҵ���߼�
	{
		MakeTail();
		MakeBody();
		MakeHead();
	}
};
class Jeep : public MakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "jeep head" << endl;
	}
	virtual void MakeBody()
	{
		cout << "jeep body" << endl;
	}
	virtual void MakeTail()
	{
		cout << "jeep tail" << endl;
	}

};

class Bus : public MakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "Bus head" << endl;
	}
	virtual void MakeBody()
	{
		cout << "Bus body" << endl;
	}
	virtual void MakeTail()
	{
		cout << "Bus tail" << endl;
	}

};

void main()
{
	//�����������
	MakeCar *car = new Bus;
	car->Make();//ģ�庯������Ҫд�麯��
	delete car;


	cout << "hello..." << endl;
	system("pause");
	return;
}