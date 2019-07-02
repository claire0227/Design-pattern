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
		cout << "�����㽶" << endl;
	}
};
class Apple : public Fruit
{
public:
	virtual void sayname()
	{
		cout << "����ƻ��" << endl;
	}
};
//���󹤳������󹤳�����һ��Э��Լ��
class AbFactory
{
public:
	virtual  Fruit* CreateProduct()=0;
};
//����Ĺ���
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
//ʵ���˽���ϣ�ֻҪ���������ͳ��󹤳�����
void main()
{
//����������ָ��
	AbFactory *factory = NULL;
	Fruit * fruit = NULL;

	//���㽶
	factory = new BananaFactory;//����ָ��ָ���������
	fruit = factory->CreateProduct();
	fruit->sayname();

	//��ƻ��
	factory = new AppleFactory;//����ָ��ָ���������
	fruit = factory->CreateProduct();
	fruit->sayname();

	delete factory;
	delete fruit;
	cout << "hello..." << endl;
	system("pause");
}