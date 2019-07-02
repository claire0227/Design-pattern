#include <iostream>
using namespace std;
#include "string"
class House
{
public:
	void setWindow(string window)
	{
		this->m_window = window;
	}
	void setWall(string wall)
	{
		this->m_wall = wall;
	}
	void setDoor(string door)
	{
		this->m_door = door;
	}
	string getDoor()
	{
		return m_door;
	}
	string getWindow()
	{
		return m_window;
	}
	string getWall()
	{
		return m_wall;
	}
private:
	string m_window;
	string m_wall;
	string m_door;
};

//���̶ӣ�����Ľӿ�
class Builder
{
public:
	virtual void buildwall() =0;
	virtual void builddoor()=0;
	virtual void buildwindow()=0;
	virtual House* getHouse()=0;
};
//��Ԣ���̶�
class FlatBuilder: public Builder
{
	public:
	FlatBuilder()
	{
		m_house = new House;
	}
	virtual void buildwall()
	{
		m_house->setWall("flat wall");
	}
	virtual void builddoor()
	{
		m_house->setDoor("flat door");
	}
	virtual void buildwindow()
	{
		m_house->setWindow("flat Window");
	}
	virtual House* getHouse()
	{
		return m_house;
	}
private:
	House *m_house;
};

//villa���̶�
class VillaBuilder: public Builder
{
	public:
	VillaBuilder()
	{
		m_house = new House;
	}
	virtual void buildwall()
	{
		m_house->setWall("villa wall");
	}
	virtual void builddoor()
	{
		m_house->setDoor("villa door");
	}
	virtual void buildwindow()
	{
		m_house->setWindow("villa Window");
	}
	virtual House* getHouse()
	{
		return m_house;
	}
private:
	House *m_house;
};

//���ʦ�������߼�
//�����Ӹɾ���Ļ�
class Director
{
public:
	Director(Builder * build)
	{
		m_build = build;
	}
	void Construct()
	{
		m_build->buildwall();
		m_build->buildwindow();
		m_build->builddoor();
	}
private:
	Builder* m_build;
};

void main()
{
	House *h = NULL;
	//�빤�̶�
	VillaBuilder *v = new VillaBuilder;
	//���ʦ��֯���̶Ӹɻ�
	Director * d =  new Director(v);
	d->Construct();
	h = v->getHouse();
	cout << h->getDoor() << endl;
	cout << h->getWall() << endl;
	cout << h->getWindow() << endl;
	delete v;
	delete d;

	cout << "hello" << endl;
	system("pause");
	return;
}