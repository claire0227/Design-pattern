#include <iostream>
using namespace std;

//������
class CarHandle
{
public:
	virtual void HandleCar() =0;
};
//�������
class HeadCarHandle : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "�쳵ͷ" << endl;
	}
};
class BodyCarHandle  : public CarHandle
{
public:
	virtual void HandleCar() 
	{
		cout << "�쳵��" << endl;
	}
};
class TailCarHandle  : public CarHandle
{
public:
	virtual void HandleCar() 
	{
		cout << "�쳵β" << endl;
	}
};
void main()
{
	//ҵ���߼���д�����ͻ���
	CarHandle * h = new HeadCarHandle;
	CarHandle * b = new BodyCarHandle;
	CarHandle * t = new TailCarHandle;

	h->HandleCar();
	b->HandleCar();
	t->HandleCar();

	delete h;
	delete b;
	delete t;


	cout << "hello..." << endl;
	system("pause");
	return;
}