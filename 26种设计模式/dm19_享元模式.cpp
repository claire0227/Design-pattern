#include <iostream>
#include "string"
#include "map"
using namespace std;

class Person
{
public:
	Person(string name,int age)
	{
		this->m_name = name;
		this->age = age;
	}
	virtual void printT()=0;
	
protected:
	string m_name;
	int    age;
};
class Teacher : public Person
{
	//���캯�� ���Լ̳�
public:
	Teacher(string name,int age,string id):Person(name,age)
	{
		this->m_id = id;
	}
	void printT()
	{
		cout << "name:" << m_name << "gae" << age << " id" << m_id << endl;
	}
private:
	string m_id;
};

//�����ʦ�ڵ�Ŀ����ȴ洢
//��Ԫ����
class FlyWeightTeacherFactory
{
public:
	//���캯��
	FlyWeightTeacherFactory()
	{
		map1.clear();
	}
	~FlyWeightTeacherFactory()
	{
		while(!map1.empty())
		{
			Person *tmp;
			map<string, Person*>::iterator it = map1.begin();

			tmp = it->second;
			map1.erase(it);//�ѵ�һ���ڵ��������ɾ��
			delete tmp;//ͨ������ָ���ͷſռ�
		}
	}
	Person * GetTeacher(string id)
	{

		map<string, Person*>::iterator it =map1.find(id);
		if(it==map1.end())
		{
			string tmpname;
			cout << "��������ʦ���֣�";
			cin >> tmpname;

			int tmpage;
			cout << "��������ʦ���䣺";
			cin >> tmpage;

			Teacher *tmp = new Teacher(tmpname,tmpage,id);
			map1.insert(pair<string,Person*>(id,tmp));
			return tmp;
		}
		else
			return it->second;
	}
private:
	map<string, Person*> map1;
};
void main()
{
	Person *p1 = NULL;
	Person *p2 = NULL;
	FlyWeightTeacherFactory * fwtf = new FlyWeightTeacherFactory;
	p1= fwtf->GetTeacher("001");
	p1->printT();

	p2= fwtf->GetTeacher("001");
	p2->printT();

	delete fwtf,p1,p2;

	cout << "hello..." << endl;
	system("pause");
	return;
}