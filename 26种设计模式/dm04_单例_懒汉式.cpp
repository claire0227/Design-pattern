#include <iostream>
using namespace std;

//懒汉式
class Singleton
{
private:
	Singleton()
	{
		cout << "Singleton 构造函数执行begin" << endl;
		//Sleep(1000);
		cout << "Singleton 构造函数执行end" << endl;
	}
public:
	static Singleton * getInstance()
	{
		if(m_psl==NULL)
			m_psl = new Singleton;//调用构造函数
		return m_psl;
	}
	static Singleton *FreeInstance()//释放内存空间和指针
	{
		if(m_psl !=NULL)
		{
			delete m_psl;
			m_psl = NULL;
		}
		return m_psl;

	}
private:
	static Singleton *m_psl;//静态变量
};
Singleton * Singleton::m_psl=NULL;//静态变量的初始化放在类的外面
void main()
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	if(p1==p2)
	{
		cout << "是同一个对象" << endl;
	}
	else 
	{
	cout << "不是同一个对象" << endl;
	}
	Singleton::FreeInstance;//静态函数可以直接调用
	system("pause");
	return;
}