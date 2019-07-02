#include <iostream>
using namespace std;

//抽象类 加上指向自己的属性
//造完车之后 需要将任务进行传递
class CarHandle
{
public:
	virtual void HandleCar() =0;
	CarHandle * setNextHandle(CarHandle *handle)
	{
		m_handle = handle;
	}
protected:
	CarHandle * m_handle;//下一个数据单元
};
//具体的类
class HeadCarHandle : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "造车头" << endl;
		//造完车头以后将任务移交给下一个处理者
		if(m_handle != NULL)
		{
			m_handle->HandleCar();
		}
	}
};
class BodyCarHandle  : public CarHandle
{
public:
	virtual void HandleCar() 
	{
		cout << "造车身" << endl;
		if(m_handle != NULL)
		{
			m_handle->HandleCar();
		}
	}
};
class TailCarHandle  : public CarHandle
{
public:
	virtual void HandleCar() 
	{
		cout << "造车尾" << endl;
		if(m_handle != NULL)
		{
			m_handle->HandleCar();
		}
	}
};
void main()
{
	//业务逻辑被写死到客户端
	CarHandle * h = new HeadCarHandle;
	CarHandle * b = new BodyCarHandle;
	CarHandle * t = new TailCarHandle;

	//任务的处理关系
	//可以任意改变业务逻辑
	h->setNextHandle(b);
	b->setNextHandle(t);
	t->setNextHandle(NULL);

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