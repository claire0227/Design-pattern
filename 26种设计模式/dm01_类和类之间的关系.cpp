#include <iostream>
using namespace std;

class Car;//前置声明
class zhang
{
public:
	//依赖关系
	void GoWork(Car *p)//用别人的车
	{

	}
	Car *fix()//修车
	{

	}
protected:
private:
};
class car
{
public:
protected:
private:
};
//关联关系
class AdvZhang
{
public:
	void GoWork()
	{
		//m_car->
	}
protected:
private:
	Car *m_car;//关联关系
};
void main1()
{
	cout << "hello" << endl;
	system("pause");
	return;
}