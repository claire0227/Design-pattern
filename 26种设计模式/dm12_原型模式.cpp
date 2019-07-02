#define _CRT_SECURE_NO_WARNINGS//���Ǻ����
#include <iostream>
#include "string"
using namespace std;


//������
class Person
{
public:
	virtual Person* clone()=0;//�ӿں���
	virtual void printT()=0;
};
//������
class CPlusPlusProgrammer : public Person
{
public:
	CPlusPlusProgrammer(string name,int age)
	{
	 m_name = name;
	 m_age = age;
	 m_resume = NULL;
	}
	CPlusPlusProgrammer()
	{
	 m_name = "";
	 m_age = 0;
	 m_resume = NULL;
	}
	void setResume(char *p)
	{
		if(m_resume!=NULL)
		{
			delete m_resume;
			
		}
		m_resume = new char[strlen(p)+1];
		strcpy(m_resume,p);
	}
	virtual Person* clone()
	{
		CPlusPlusProgrammer* tmp = new CPlusPlusProgrammer;
		//tmp->m_age=this->m_age;
		*tmp = *this;
		return tmp;

	}
	virtual void printT()
	{
		cout << m_name << m_age << endl;
	}

private:
	string m_name;
	int  m_age;
	//���ǳ����
	char * m_resume;
};
void main()
{
	Person * c1 = new CPlusPlusProgrammer("����",32);//ע��ʹ�û���ָ��
	c1->printT();
	Person * c2 = c1->clone();
	c2->printT();
	delete c1,c2;
	cout << "hello" << endl;
	system("pause");
	return;
}