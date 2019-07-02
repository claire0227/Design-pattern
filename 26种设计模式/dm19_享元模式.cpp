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
	//构造函数 可以继承
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

//完成老师节点的颗粒度存储
//享元工厂
class FlyWeightTeacherFactory
{
public:
	//构造函数
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
			map1.erase(it);//把第一个节点从容器中删除
			delete tmp;//通过父类指针释放空间
		}
	}
	Person * GetTeacher(string id)
	{

		map<string, Person*>::iterator it =map1.find(id);
		if(it==map1.end())
		{
			string tmpname;
			cout << "请输入老师名字：";
			cin >> tmpname;

			int tmpage;
			cout << "请输入老师年龄：";
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