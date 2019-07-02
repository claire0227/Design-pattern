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
		cout << "卖书" << endl;
	}
};
//代理
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
		cout << "双十一打折" << endl;
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
