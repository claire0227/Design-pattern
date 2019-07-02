#include <iostream>
#include "string"
using namespace std;

class MementTo//����¼
{
	public:
	MementTo(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	string getName()
	{
		return m_name;
	}
	int getAge()
	{
		return m_age;
	}
	void setName(string name)
	{
		this->m_name = name;
	}
	void setAge(int age)
	{
		this->m_age = age;
	}
	
	//��ԭ
	
private:
	string m_name;
	int	  m_age;

};
class Person
{
public:
	Person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	string getName()
	{
		return m_name;
	}
	int getAge()
	{
		return m_age;
	}
	void setName(string name)
	{
		this->m_name = name;
	}
	void setAge(int age)
	{
		this->m_age = age;
	}
	MementTo* createMementTo()
	{
		return new MementTo(m_name,m_age);
	}
	void setMementTo(MementTo* mento)
	{
		this->m_age = mento->getAge();
		this->m_name = mento->getName();
	}
public:
	void printT()
	{
		cout << "m_name		" << m_name << "m_age	" << m_age << endl;
	}
private:
	string m_name;
	int	  m_age;
};


//������
class Caretaker
{
public:
	Caretaker(MementTo* mento)
	{
		this->mento = mento;
	}
	MementTo* getMemenTo()
	{
		return mento;
	}
	void setMemmTo(MementTo* mento)
	{
		this->mento = mento;
	}
private:
	MementTo* mento;
};

void main26_01()
{
	MementTo *mento = NULL;
	Person *p = new Person("����",33);
	p->printT();
	//����Person�����һ��״̬
	printf("_____________\n");
	mento = p->createMementTo();
	p->setAge(42);
	p->printT();
	printf("��ԭ�ɵ�״̬\n");
	p->setMementTo(mento);
	p->printT();
	delete mento;
	delete p;
	
}

void main26_02()
{
	//MementTo *mento = NULL;
	Caretaker *caretaker = NULL;
	Person *p = new Person("����",33);
	p->printT();
	//����Person�����һ��״̬
	printf("_____________\n");
	//mento = p->createMementTo();
	caretaker = new Caretaker(p->createMementTo());
	p->setAge(42);
	p->printT();
	printf("��ԭ�ɵ�״̬\n");
	//p->setMementTo(mento);
	p->setMementTo(caretaker->getMemenTo());
	p->printT();
	delete caretaker;
	delete p;
}
void main()
{
	main26_02();
	cout << "hello..." << endl;
	system("pause");
	return;
}