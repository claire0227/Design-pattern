#include <iostream>
#include "string"
using namespace std;
class Car
{
public:
	virtual void show() =0;
};

//具体类
class runCar : public Car
{
public:
	virtual void show()
	{
		cout << "可以跑" << endl;
	}
};
//装饰器
class swinCar : public Car
{
public:
	swinCar(Car*p)
	{
		m_car =p;
	}
	void swim()
	{
		cout << "可以游泳" << endl;
	}
	virtual void show()
	{
		m_car->show();
		swim();
	}
private:
	Car *m_car;
};
class flyCar : public Car
{
public:
	flyCar(Car*p)
	{
		m_car =p;
	}
	void fly()
	{
		cout << "可以飞翔" << endl;
	}
	virtual void show()
	{
		m_car->show();
		fly();
	}
private:
	Car *m_car;
};


void main()
{
	Car *mycar = NULL;
	mycar = new runCar;
	mycar->show();

	flyCar *flycar = new flyCar(mycar);
	flycar->show();

	delete mycar,flycar;
	system("pause");
	return;
}
