#include <iostream>
#include"string"
using namespace std;
//������˵���
class Person
{
public:
	Person(string name,int sex,int condi)
	{
		m_name = name;
		m_sex = sex;
		m_condi = condi;
	}
	int getSex()
	{
		return m_sex;
	}
	int getCondi()
	{
		return m_condi;
	}
	string getName()
	{
		return m_name;
	}
	virtual void gerParter(Person * person) =0;
protected:
	string   m_name;
	int		m_sex;
	int		m_condi;
};
class Woman : public Person
{
public:
	Woman(string name,int sex,int condi):Person(name,sex,condi)
	{

	}
	void gerParter(Person * p)
	{

		if(p->getSex()==this->getSex())
		{
			cout << "�Ҳ���ͬ����" << endl;
		}
		else if(p->getCondi()==this->getCondi())
		{
			cout << this->getName() << "��" << p->getName() << endl;
		}
		else
		{
			cout << this->getName() << "����" << p->getName() << endl;
		}

	}
};

class Man : public Person
{
public:
	Man(string name,int sex,int condi):Person(name,sex,condi)
	{

	}
	void gerParter(Person * p)
	{

		if(p->getSex()==this->getSex())
		{
			cout << "�Ҳ���ͬ����" << endl;
		}
		else if(p->getCondi()==this->getCondi())
		{
			cout << this->getName() << "��" << p->getName() << endl;
		}
		else
		{
			cout << this->getName() << "����" << p->getName() << endl;
		}

	}
};
void main()
{
	Person *xiaofang = new Woman("xiaofang",2,5);
	Person *zhangsan = new Man("zhangsan",1,4);
	Person *lisi = new Man("lisi",1,5);


	xiaofang->gerParter(zhangsan);
	xiaofang->gerParter(lisi);

	cout << "hello..." << endl;
	system("pause");
	return;
}