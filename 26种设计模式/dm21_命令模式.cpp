#include <iostream>
using namespace std;
#include "list"

class Doctor
{
public:
	void treat_eye()
	{
		cout << "医生治疗眼科病" << endl;
	}

	void treat_nose()
	{
		cout << "医生治疗鼻科病" << endl;
	}
};
//抽象控制类
class Command
{
public:
	virtual void treat() =0;
};

class CommandTreatEye : public Command
{
public:
	CommandTreatEye(Doctor *doctor)
	{
		m_doctor = doctor;
	}
	void treat()
	{
		m_doctor->treat_eye();
	}
private:
	Doctor *m_doctor;
};

class CommandTreatNose : public Command
{
public:
	CommandTreatNose(Doctor *doctor)
	{
		m_doctor = doctor;
	}
	void treat()
	{
		m_doctor->treat_nose();
	}
private:
	Doctor *m_doctor;
};

class BeautyNurse
{
public:
	BeautyNurse(Command * command)
	{
		this->command = command;
	}
//提交命令
	void SubmittedCase()
	{
		command->treat();
	}
private:
	Command * command;
};
//护士长
class HeadNurse
{
public:
	HeadNurse()
	{
		m_list.clear();
	}
//提交命令
	void setCommand(Command * command)
	{
		m_list.push_back(command);
	}
	void SubmittedCase()
	{
		for(auto it = m_list.begin();it != m_list.end();it++)
		{
			(*it)->treat();
		}
	}
private:
	list<Command*> m_list;
};
void main()
{
	//医生直接看病
	Doctor *doctor = new Doctor;
	doctor->treat_eye();
	doctor->treat_nose();
	delete doctor;

	//通过一个命令执行看病
	Doctor *doctor1 = new Doctor;
	Command * command = new CommandTreatNose(doctor1);
	command->treat();
	delete doctor1,command;


	//通过护士调用
	//护士提交简历，医生看病
	Doctor *doctor2 = new Doctor;
	Command * command1 = new CommandTreatNose(doctor2);
	BeautyNurse * beautynurse = new BeautyNurse(command1);
	beautynurse->SubmittedCase();

	//通过护士长批量下达命令
	//新建护士长
	//新建医生
	//新建两个命令
	//将命令类提交给护士长
	//护士长批量下达命令

	delete beautynurse,doctor2,command1;

	cout << "hello..." << endl;
	system("pause");
	return;
}