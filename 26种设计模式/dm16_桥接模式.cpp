#include<iostream>
using namespace std;

//����װ������������ķ������������˶���
class Engine
{
public:
	virtual void InstallEngine() =0;
};
//����ķ������������˶���
class Engine4400cc : public Engine//�������ֿ�ͷ
{
public:
	virtual void InstallEngine()
	{
		cout << "����4400cc������ ��װ���" << endl;
	}
};
class Engine4500cc : public Engine
{
public:
	virtual void InstallEngine()
	{
		cout << "����4500cc������ ��װ���" << endl;
	}
};
//����ĳ���
class Car
{
public:
	Car(Engine *engine )
	{
		this->m_engine = engine;
	}
	virtual void installEngine()=0;
protected://�״��
	Engine *m_engine;//Ӧ������Ϊ���б���
};
//����ĳ�
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