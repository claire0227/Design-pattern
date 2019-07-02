#include <iostream>
using namespace std;
#include "list"

class Doctor
{
public:
	void treat_eye()
	{
		cout << "ҽ�������ۿƲ�" << endl;
	}

	void treat_nose()
	{
		cout << "ҽ�����ƱǿƲ�" << endl;
	}
};
//���������
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
//�ύ����
	void SubmittedCase()
	{
		command->treat();
	}
private:
	Command * command;
};
//��ʿ��
class HeadNurse
{
public:
	HeadNurse()
	{
		m_list.clear();
	}
//�ύ����
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
	//ҽ��ֱ�ӿ���
	Doctor *doctor = new Doctor;
	doctor->treat_eye();
	doctor->treat_nose();
	delete doctor;

	//ͨ��һ������ִ�п���
	Doctor *doctor1 = new Doctor;
	Command * command = new CommandTreatNose(doctor1);
	command->treat();
	delete doctor1,command;


	//ͨ����ʿ����
	//��ʿ�ύ������ҽ������
	Doctor *doctor2 = new Doctor;
	Command * command1 = new CommandTreatNose(doctor2);
	BeautyNurse * beautynurse = new BeautyNurse(command1);
	beautynurse->SubmittedCase();

	//ͨ����ʿ�������´�����
	//�½���ʿ��
	//�½�ҽ��
	//�½���������
	//���������ύ����ʿ��
	//��ʿ�������´�����

	delete beautynurse,doctor2,command1;

	cout << "hello..." << endl;
	system("pause");
	return;
}