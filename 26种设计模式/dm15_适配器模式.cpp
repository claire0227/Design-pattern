#include <iostream>
#include "string"
using namespace std;

//Current18
//Current220
//Adapter
class Current18v
{
public:
	virtual void useCurrent18v()=0;
};

class Current220v
{
public:
	void useCurrent220v()
	{
		cout << "我是220v 欢迎使用" << endl;
	}
};
class Adapter:public Current18v
{
public:
	Adapter(Current220v* c)
	{
		m=c;
	}
	virtual void useCurrent18v()
	{
		cout << "适配220v" << endl;
		m->useCurrent220v();
	}
private:
	Current220v* m;
};
void main()
{
	Current220v  *c220 = new Current220v;
	Adapter * a = new Adapter(c220);
	a->useCurrent18v();

	delete a,c220;
	system("pause");
	return;
}