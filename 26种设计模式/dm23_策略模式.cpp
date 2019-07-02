#include <iostream>
using namespace std;
//透明的可替换算法

class Strategy
{
public:
	virtual void crypt() =0;

};
//非对称加密
//对称加密
class AES: public Strategy
{
public:
	virtual void crypt()
	{
		cout << "AES加密算法" << endl;
	}

};

class Context
{
public:
	void setStratedy(Strategy *strategy)
	{
		this->strategy = strategy;
	}
		void myoperator()
	{
		strategy->crypt();
	}
private:
	Strategy *strategy;
};
class DES: public Strategy
{
public:
	virtual void crypt()
	{
		cout << "DES加密算法" << endl;
	}


};
void main()
{
	Strategy *strategy = NULL;
	strategy = new DES;
	Context * context = new Context;
	context->setStratedy(strategy);
	context->myoperator();

	delete strategy;
	delete context;

	cout << "hello..." << endl;
	system("pause");
	return;
}