#include <iostream>
#include "string"
using namespace std;

class Subject
{
public:
	virtual void sailbook() =0;
};
class RealSubjectBook : public Subject
{
public:
	virtual void sailbook()
	{
		cout << "����" << endl;
	}
};
//����
class dangdangProxy: public Subject
{
public:
	virtual void sailbook()
	{
		RealSubjectBook *rsb = new RealSubjectBook;
		dazhe();
		rsb->sailbook();
	}
	void dazhe()
	{
		cout << "˫ʮһ����" << endl;
	}

};

void main()
{
	Subject *s = new dangdangProxy;
	s->sailbook();
	delete s;
	cout << "hello" << endl;
	system("pause");
	return;
}
