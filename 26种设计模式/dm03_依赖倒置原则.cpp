#include <iostream>
using namespace std;

//让电脑的框架与具体的厂商解耦合

class HardDisk
{
public:
	virtual void work()=0;
};
class Memory
{
public:
	virtual void work()=0;
};
class cpu
{
public:
	virtual void work()=0;
};
class Computer
{
public:
	Computer(HardDisk * harddisk,Memory *memory,cpu *cpu)
	{
	m_harddisk =harddisk;
	m_memory = memory;
	m_cpu = cpu ;
	}
public:
	void work()
	{
	m_harddisk->work();
	m_memory->work();
	m_cpu->work();
	}
private:
	HardDisk * m_harddisk;
	Memory *m_memory;
	cpu *m_cpu;

};
class InterCpu:public cpu
{
public:
	void work()
	{
		cout << "我是intel cpu我工作良好" << endl;
	}
};
class XSDisk:public HardDisk
{
public:
	void work()
	{
		cout << "我是西数硬盘" << endl;
	}
};
class JSDMem:public Memory
{
public:
	void work()
	{
		cout << "我是JSD硬盘" << endl;
	}
};

void main4()
{
	HardDisk * harddisk = NULL;
	Memory *memory= NULL;
	cpu *cpu= NULL;//抽象类

	memory = new JSDMem;
	harddisk = new XSDisk;
	cpu = new InterCpu;

	Computer *mcomputer = new Computer(harddisk,memory,cpu);

	mcomputer->work();

	delete mcomputer;
	delete memory;
	delete harddisk;
	delete cpu;

	cout << "hello" << endl;
	system("pause");
	return;
}

//组合实现类的功能扩展,对一个类进行功能增强
class A
{
public:
	void doA()
	{

	}
};

class C
{
public:
	C(A *a)
	{

	}
	void setA(A *a)
	{
		this->a = a;
	}

private:
	A *a;
};