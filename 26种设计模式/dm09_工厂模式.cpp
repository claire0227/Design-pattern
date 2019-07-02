#include <iostream>
using namespace std;

class Fruit
{
public:
	virtual void sayname()=0;
};
class Banana : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "我是香蕉" << endl;
	}
};
class Apple : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "我是苹果" << endl;
	}
};
//抽象工厂，抽象工厂做了一层协议约定
class AbFactory
{
public:
	virtual  Fruit* CreateProduct()=0;
};
//具体的工厂
class BananaFactory : public AbFactory
{
public:
	virtual  Fruit* CreateProduct()
	{
		return new Banana;
	}
};
class AppleFactory : public AbFactory
{
public:
	virtual  Fruit* CreateProduct()
	{
		return new Apple;
	}
};
//实现了解耦合，只要定义抽象类和抽象工厂即可
void main()
{
//定义抽象类的指针
	AbFactory *factory = NULL;
	Fruit * fruit = NULL;

	//吃香蕉
	factory = new BananaFactory;//父类指针指向子类对象
	fruit = factory->CreateProduct();
	fruit->sayname();

	//吃苹果
	factory = new AppleFactory;//父类指针指向子类对象
	fruit = factory->CreateProduct();
	fruit->sayname();

	delete factory;
	delete fruit;
	cout << "hello..." << endl;
	system("pause");
}