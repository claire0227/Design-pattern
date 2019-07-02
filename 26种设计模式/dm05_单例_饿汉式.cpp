#include <iostream>
using namespace std;

//懒汉式
class Singleton
{
private:
	Singleton()
	{
		cout << "Singleton 构造函数执行" << endl;
	}
public:
	static Singleton * getInstance()
	{
		//if(m_psl==NULL)
			//m_psl = new Singleton;
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
Singleton * Singleton::m_psl=new Singleton;//静态变量的初始化放在类的外面,相当于全局变量
void main()
{
	printf("aa");
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();

	//create_thread();不存在线程竞争资源

	if(p1==p2)
	{
		cout << "是同一个对象" << endl;
	}
	else 
	{
	cout << "不是同一个对象" << endl;
	}
	Singleton::FreeInstance();//静态函数可以直接调用
	system("pause");
	return;
}