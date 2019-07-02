#include <iostream>
using namespace std;

//����ʽ
class Singleton
{
private:
	Singleton()
	{
		cout << "Singleton ���캯��ִ��begin" << endl;
		//Sleep(1000);
		cout << "Singleton ���캯��ִ��end" << endl;
	}
public:
	static Singleton * getInstance()
	{
		if(m_psl==NULL)
			m_psl = new Singleton;//���ù��캯��
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
Singleton * Singleton::m_psl=NULL;//��̬�����ĳ�ʼ�������������
void main()
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	if(p1==p2)
	{
		cout << "��ͬһ������" << endl;
	}
	else 
	{
	cout << "����ͬһ������" << endl;
	}
	Singleton::FreeInstance;//��̬��������ֱ�ӵ���
	system("pause");
	return;
}