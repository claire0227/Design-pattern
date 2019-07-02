#include <iostream>
#include <list>
#include "string"
using namespace std;
//���󸸽ڵ�
class IFile
{
public:
	virtual void display()=0;//��ʾ�ڵ������
	virtual int add(IFile *ifile)=0;//��ӽڵ�
	virtual int remove(IFile *ifile)=0;//ɾ���ӽڵ�
	virtual list<IFile*>* getChild()=0;//��ȡĿ¼
};
//Ҷ�ӽڵ㣬�ļ��ڵ�
class File : public IFile//�ļ�ΪҶ�ӽڵ�
{
public:
	File(string name)
	{
		m_name = name;
	}
	virtual void display()//��ʾ�ڵ������
	{
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile)//��ӽڵ�
	{
		return -1;
	}
	virtual int remove(IFile *ifile)//ɾ���ӽڵ�
	{
		return -1;
	}
	virtual list<IFile*>* getChild()//��ȡĿ¼
	{
		return NULL;
	}
private:
	string m_name;
};
//Ŀ¼�ڵ�
class Dir :public IFile
{
public:
	Dir(string name)
	{
		m_name = name;
		m_list = new list<IFile *>;
		m_list->clear();//���

	}
	virtual void display()//��ʾ�ڵ������
	{
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile)//��ӽڵ�
	{
		m_list->push_back(ifile);
		return 0;
	}
	virtual int remove(IFile *ifile)//ɾ���ӽڵ�
	{
		m_list->remove(ifile);
		return 0;
	}
	virtual list<IFile*>* getChild()//��ȡĿ¼
	{
		return m_list;
	}
private:
	string m_name;
	list<IFile*> *m_list;
};
//�ݹ����ʾ��
void showTree(IFile *root, int level)
{
	//1 ��ʾ���ڵ�
	//2 �����ڵ��к���
		//���������ļ�����ʾ���֣�
		//��������Ŀ¼���ݹ���ʾ��Ŀ¼
	
	if(root == NULL)
	{
		return;
	}
	for(int i =0;i<level;i++)
	{
		printf("\t");
	}
	//1 ��ʾ���ڵ�
	root->display();
	list<IFile*> *mylist = root->getChild();
	if(mylist != NULL)//˵����һ��Ŀ¼
	{
		for(auto it = mylist->begin();it!=mylist->end();it++)
	{
		if((*it)->getChild()==NULL)
		{
			for(int i =0;i<level+1;i++)
			{
				printf("\t");
			}
			(*it)->display();
			
		}
			
		else
		{
			showTree((*it),level+1);
		}
	}
	}

}
void main()
{
	Dir *root = new Dir("C");
	//root->display();
	Dir *dir1 = new Dir("111dir");
	File *file1 = new File("aaa.txt");

	root->add(dir1);
	root->add(file1);
	root->display();
	//��ȡroot�ڵ��µĺ��Ӽ���
	list<IFile*> *list = root->getChild();
	//���õ��������б���

	for(auto it = list->begin();it!=list->end();it++)
	{
		(*it)->display();
	}
	Dir *dir222 = new Dir("222dir");
	File *bbbfile = new File("bbb.txt");
	dir1->add(dir222);
	dir1->add(bbbfile);

	cout << "ͨ���ݹ�ķ�ʽ��ʾroot�ڵ��µ������ӽڵ�" << endl;

	showTree(root,0);//�ݹ�

	cout << "hello..." << endl;
	system("pause");
	return;
}