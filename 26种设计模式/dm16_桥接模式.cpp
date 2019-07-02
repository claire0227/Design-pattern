#include<iostream>
using namespace std;

//车安装发动机，抽象的发动机，分离了动作
class Engine
{
public:
	virtual void InstallEngine() =0;
};
//具体的发动机，分离了动作
class Engine4400cc : public Engine//不能数字开头
{
public:
	virtual void InstallEngine()
	{
		cout << "我是4400cc发动机 安装完毕" << endl;
	}
};
class Engine4500cc : public Engine
{
public:
	virtual void InstallEngine()
	{
		cout << "我是4500cc发动机 安装完毕" << endl;
	}
};
//抽象的车类
class Car
{
public:
	Car(Engine *engine )
	{
		this->m_engine = engine;
	}
	virtual void installEngine()=0;
protected://易错点
	Engine *m_engine;//应该设置为共有变量
};
//具体的车
class WBM5:public Car
{
public:
	WBM5(Engine *engine):Car(engine)
	{

	}
	virtual void installEngine()
	{
		m_engine->InstallEngine();
	}
};
class WBM6:public Car
{
public:
	WBM6(Engine *engine):Car(engine)
	{

	}
	virtual void installEngine()
	{
		m_engine->InstallEngine();
	}
};
void main()
{
	Engine *engine = NULL;
	WBM6 *wbm6 =NULL;

	engine = new Engine4400cc;
	wbm6 = new WBM6(engine);
	wbm6->installEngine();

	delete engine;
	delete wbm6;

	cout << "hello..." << endl;
	system("pause");
	return;
}