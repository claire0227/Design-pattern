#include <iostream>
using namespace std;

/*class BankWorker
{
public:
	void save()
	{
		cout << "���" << endl;
	}
	void move()
	{
		cout << "ת��"<< endl;
	}
	void pay()
	{
		cout << "�ɷ�" << endl;
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

//��������ʵ�ֶ�̬��
class AdBankWorker
{
public:
	virtual void donothing() =0;//����0ʲô��˼
};
class  SaveBanker : public AdBankWorker
{
public:
	virtual void donothing()
	{
		cout << "���" << endl;
	}
};
class  MoveBanker : public AdBankWorker
{
public:
	virtual void donothing()
	{
		cout << "ת�� "<< endl;
	}
};
/*
//��ܺ���
void howDo(AdBanker *bw)//���԰���������Ӹ�����Ҳ���Ը������
{
	bw->donothing();//��̬
};
void main03()
{
	AdBankWorker *bw = NULL;
	bw = new MoveBanker;
	howDo(bw);
	bw->donothing();//�ж�̬����
	delete bw;

	bw = new SaveBanker;
	bw->donothing();
	howDo(bw);
	delete bw;
	system("pause");
	return;

}
*/


