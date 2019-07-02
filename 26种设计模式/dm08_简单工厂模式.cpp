#include <iostream>
using namespace std;

//��������࣬ע����Ҫ�����麯��
class fruit
{
public:
	virtual void getFruit()=0;
};
//��������࣬��д�麯��
class banana : public fruit//��ס�ⲿ�ֵ��﷨
{
public:
	virtual void getFruit()
	{
		cout << " �����㽶������" << endl;
	}
};
class apple : public fruit//��ס�ⲿ�ֵ��﷨
{
public:
	virtual void getFruit()
	{
		cout << " ����ƻ��������" << endl;
	}
};
//������
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
			printf("��֧��\n");
			return NULL;
		}
	}
};
void main()
{
	//����������
	factory *f = new factory;
	fruit *p = NULL;//��������ָ��
	//���������㽶
	p=f->create("banana");//����ָ��ָ���������
	p->getFruit();
	delete p;

	//����ƻ��
	p=NULL;
	p=f->create("apple");//����ָ��ָ���������
	p->getFruit();
	delete p;

	delete f;
	cout << "hello..." << endl;
	system("pause");
	return;
}