#include <iostream>
using namespace std;

//定义抽象水果类
class Fruit
{
public:
	virtual void sayname()
	{
		cout << "水果" << endl;
	}
};
//定义抽象工厂类
class FruitFactory
{
public:
	virtual Fruit* getApple()
	{
		return new Fruit;
	}
	virtual Fruit* getBanana()
	{
		return new Fruit;
	}
};
//定义具体水果类
class SouthApple : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "南方苹果" << endl;
	}
};
class SouthBanana : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "南方香蕉" << endl;
	}
};
class NorthApple : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "北方苹果" << endl;
	}
};
class NorthBanana : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "北方香蕉" << endl;
	}
};
//定义具体工厂类
class SouthFruitFactory : public FruitFactory
{
public:
	virtual Fruit* getApple()
	{
		return new SouthApple;
	}
	virtual Fruit* getBanana()
	{
		return new SouthBanana;
	}
};
class NorthFruitFactory : public FruitFactory
{
public:
	virtual Fruit* getApple()
	{
		return new NorthApple;
	}
	virtual Fruit* getBanana()
	{
		return new NorthBanana;
	}
};
void main()
{
	FruitFactory* f = NULL;
	Fruit * fr = NULL;

	f = new NorthFruitFactory;
	fr= f->getApple();
	fr->sayname();

	delete f;
	delete fr;
	cout << "hello" << endl;
	system("pause");
	return;
}