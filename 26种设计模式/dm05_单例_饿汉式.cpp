#include <iostream>
using namespace std;

//����ʽ
class Singleton
{
private:
	Singleton()
	{
		cout << "Singleton ���캯��ִ��" << endl;
	}
public:
	static Singleton * getInstance()
	{
		//if(m_psl==NULL)
			//m_psl = new Singleton;
		return m_psl;
	}
	static Singleton *FreeInstance()//�ͷ��ڴ�ռ��ָ��
	{
		if(m_psl !=NULL)
		{
			delete m_psl;
			m_psl = NULL;
		}
		return m_psl;

	}
private:
	static Singleton *m_psl;//��̬����
};
Singleton * Singleton::m_psl=new Singleton;//��̬�����ĳ�ʼ�������������,�൱��ȫ�ֱ���
void main()
{
	printf("aa");
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();

	//create_thread();�������߳̾�����Դ

	if(p1==p2)
	{
		cout << "��ͬһ������" << endl;
	}
	else 
	{
	cout << "����ͬһ������" << endl;
	}
	Singleton::FreeInstance();//��̬��������ֱ�ӵ���
	system("pause");
	return;
}