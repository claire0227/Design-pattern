#include <iostream>
#include <list>
#include "string"
using namespace std;
//抽象父节点
class IFile
{
public:
	virtual void display()=0;//显示节点的名字
	virtual int add(IFile *ifile)=0;//添加节点
	virtual int remove(IFile *ifile)=0;//删除子节点
	virtual list<IFile*>* getChild()=0;//获取目录
};
//叶子节点，文件节点
class File : public IFile//文件为叶子节点
{
public:
	File(string name)
	{
		m_name = name;
	}
	virtual void display()//显示节点的名字
	{
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile)//添加节点
	{
		return -1;
	}
	virtual int remove(IFile *ifile)//删除子节点
	{
		return -1;
	}
	virtual list<IFile*>* getChild()//获取目录
	{
		return NULL;
	}
private:
	string m_name;
};
//目录节点
class Dir :public IFile
{
public:
	Dir(string name)
	{
		m_name = name;
		m_list = new list<IFile *>;
		m_list->clear();//清空

	}
	virtual void display()//显示节点的名字
	{
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile)//添加节点
	{
		m_list->push_back(ifile);
		return 0;
	}
	virtual int remove(IFile *ifile)//删除子节点
	{
		m_list->remove(ifile);
		return 0;
	}
	virtual list<IFile*>* getChild()//获取目录
	{
		return m_list;
	}
private:
	string m_name;
	list<IFile*> *m_list;
};
//递归地显示树
void showTree(IFile *root, int level)
{
	//1 显示根节点
	//2 若根节点有孩子
		//（孩子是文件，显示名字）
		//若孩子是目录，递归显示子目录
	
	if(root == NULL)
	{
		return;
	}
	for(int i =0;i<level;i++)
	{
		printf("\t");
	}
	//1 显示根节点
	root->display();
	list<IFile*> *mylist = root->getChild();
	if(mylist != NULL)//说明是一个目录
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
	//获取root节点下的孩子集合
	list<IFile*> *list = root->getChild();
	//利用迭代器进行遍历

	for(auto it = list->begin();it!=list->end();it++)
	{
		(*it)->display();
	}
	Dir *dir222 = new Dir("222dir");
	File *bbbfile = new File("bbb.txt");
	dir1->add(dir222);
	dir1->add(bbbfile);

	cout << "通过递归的方式显示root节点下的所有子节点" << endl;

	showTree(root,0);//递归

	cout << "hello..." << endl;
	system("pause");
	return;
}