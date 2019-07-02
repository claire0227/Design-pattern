#include <iostream>
using namespace std;

//定义抽象类，注意需要定义虚函数
class fruit
{
public:
	virtual void getFruit()=0;
};
//定义具体类，重写虚函数
class banana : public fruit//记住这部分的语法
{
public:
	virtual void getFruit()
	{
		cout << " 我是香蕉。。。" << endl;
	}
};
class apple : public fruit//记住这部分的语法
{
public:
	virtual void getFruit()
	{
		cout << " 我是苹果。。。" << endl;
	}
};
//工厂类
class factory
{
public:
	static fruit* create( char *p)
	{
		if(strcmp(p,"banana")==0)
		{
			return new banana;
		}
		if(strcmp(p,"apple")==0)
		{
			return new apple;
		}
		else
		{
			printf("不支持\n");
			return NULL;
		}
	}
};
void main()
{
	//创建工厂类
	factory *f = new factory;
	fruit *p = NULL;//创建父类指针
	//工厂生产香蕉
	p=f->create("banana");//父类指针指向子类对象
	p->getFruit();
	delete p;

	//生产苹果
	p=NULL;
	p=f->create("apple");//父类指针指向子类对象
	p->getFruit();
	delete p;

	delete f;
	cout << "hello..." << endl;
	system("pause");
	return;
}