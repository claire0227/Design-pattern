#include <iostream>
using namespace std;

//������ ����ָ���Լ�������
//���공֮�� ��Ҫ��������д���
class CarHandle
{
public:
	virtual void HandleCar() =0;
	CarHandle * setNextHandle(CarHandle *handle)
	{
		m_handle = handle;
	}
protected:
	CarHandle * m_handle;//��һ�����ݵ�Ԫ
};
//�������
class HeadCarHandle : public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "�쳵ͷ" << endl;
		//���공ͷ�Ժ������ƽ�����һ��������
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
		cout << "�쳵��" << endl;
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
		cout << "�쳵β" << endl;
		if(m_handle != NULL)
		{
			m_handle->HandleCar();
		}
	}
};
void main()
{
	//ҵ���߼���д�����ͻ���
	CarHandle * h = new HeadCarHandle;
	CarHandle * b = new BodyCarHandle;
	CarHandle * t = new TailCarHandle;

	//����Ĵ����ϵ
	//��������ı�ҵ���߼�
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