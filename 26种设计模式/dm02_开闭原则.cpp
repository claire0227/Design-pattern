#include <iostream>
using namespace std;

/*class BankWorker
{
public:
	void save()
	{
		cout << "存款" << endl;
	}
	void move()
	{
		cout << "转账"<< endl;
	}
	void pay()
	{
		cout << "缴费" << endl;
	}
};

void main()
{
	BankWorker *bw = new BankWorker;
	bw->pay();
	delete bw;
	system("pause");
	return;
}*/

//利用虚类实现多态性
class AdBankWorker
{
public:
	virtual void donothing() =0;//等于0什么意思
};
class  SaveBanker : public AdBankWorker
{
public:
	virtual void donothing()
	{
		cout << "存款" << endl;
	}
};
class  MoveBanker : public AdBankWorker
{
public:
	virtual void donothing()
	{
		cout << "转账 "<< endl;
	}
};
/*
//框架函数
void howDo(AdBanker *bw)//可以把子类对象扔给函数也可以父类对象
{
	bw->donothing();//多态
};
void main03()
{
	AdBankWorker *bw = NULL;
	bw = new MoveBanker;
	howDo(bw);
	bw->donothing();//有多态发生
	delete bw;

	bw = new SaveBanker;
	bw->donothing();
	howDo(bw);
	delete bw;
	system("pause");
	return;

}
*/


