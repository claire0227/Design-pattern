#include <iostream>
using namespace std;

//抽象类
class CarHandle
{
public:
	virtual void HandleCar() =0;
};
//具体的类
class HeadCarHandle : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "造车头" << endl;
	}
};
class BodyCarHandle  : public CarHandle
{
public:
	virtual void HandleCar() 
	{
		cout << "造车身" << endl;
	}
};
class TailCarHandle  : public CarHandle
{
public:
	virtual void HandleCar() 
	{
		cout << "造车尾" << endl;
	}
};
void main()
{
	//业务逻辑被写死到客户端
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