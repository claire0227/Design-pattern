#include <iostream>
using namespace std;
//͸���Ŀ��滻�㷨

class Strategy
{
public:
	virtual void crypt() =0;

};
//�ǶԳƼ���
//�ԳƼ���
class AES: public Strategy
{
public:
	virtual void crypt()
	{
		cout << "AES�����㷨" << endl;
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
		cout << "DES�����㷨" << endl;
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