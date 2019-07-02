#include <iostream>
using namespace std;
//��ϵͳ
class SubSystemA
{
public:
	void doThing()
	{
		cout << "SubSystemA run" << endl;
	}

};

class SubSystemB
{
public:
	void doThing()
	{
		cout << "SubSystemB run" << endl;
	}

};

class SubSystemC
{
public:
	void doThing()
	{
		cout << "SubSystemC run" << endl;
	}

};

//���ģʽ
class Facade
{
public:
	Facade()
	{
	SubSystemA *sysA = new SubSystemA;
	SubSystemB *sysB = new SubSystemB;
	SubSystemC *sysC = new SubSystemC;
	}
	~Facade()
	{
		delete sysA;
		delete sysB;
		delete sysC;
	}
public:
	void doThing()
	{
		sysA->doThing();
		sysB->doThing();
		sysC->doThing();
	}
private:
	SubSystemA *sysA;
	SubSystemB *sysB;
	SubSystemC *sysC;

};
void main()
{
	Facade *f = new Facade;
	f->doThing();
	delete f;

	cout << "hello..." << endl;
	return;
}