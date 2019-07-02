#include <iostream>
using namespace std;

//�������ˮ����
class Fruit
{
public:
	virtual void sayname()
	{
		cout << "ˮ��" << endl;
	}
};
//������󹤳���
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
//�������ˮ����
class SouthApple : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "�Ϸ�ƻ��" << endl;
	}
};
class SouthBanana : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "�Ϸ��㽶" << endl;
	}
};
class NorthApple : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "����ƻ��" << endl;
	}
};
class NorthBanana : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "�����㽶" << endl;
	}
};
//������幤����
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