#include"Manager.h"
#include<fstream>
#include"GolbalFile.h"


Manager::Manager()
{
	
}

Manager::Manager(string name, string password)
{
	this->m_Name = name;//�ڹ���Ա���캯���У���ʼ������Ա��Ϣ
	this->m_Password = password;
}

void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼" << endl;
	cout << "\t\t  ---------------------------------\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            1.����˺�          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            2.�鿴�˺�          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            3.�鿴����          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            4.���ԤԼ          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            0.ע����¼          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t  ---------------------------------\n";
	cout << "�װ��Ĺ���Ա��������������һ��������";
}

void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string filename;//����˺Ų�������Ҫ���� ��д���� ���ļ���

	ofstream ofs;//�ļ���д����   ��������
	string tip;//��ʾ����Ա���룬��Ҫ��ӵġ�ѧ��ѧ�š�/����ʦְ���š�
	int select = 0;
	cin >> select;//���չ���Ա�����ѡ��
	if (select == 1)
	{
		//��ӵ���ѧ���˺�
		filename = student_file;
		tip = "������ѧ��ѧ��";
	}
	if (select == 2)
	{
		//��ӵ�����ʦ�˺�
		filename = teacher_file;
		tip = "��������ʦְ����";
	}

	//����׷�ӵķ�ʽ д�ļ�
	ofs.open(filename, ios::out | ios::app);
	int id;//����Ա��ӵ�id/name/password
	string name;
	string password;

	cout << tip << endl;
	cin >> id;

	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> password;

	//���ļ����������
	ofs << id << " " << name << " " << password << " " << endl;
	cout << "�˺���ӳɹ�" << endl;
	system("pause");
	system("cls");

	ofs.close();//�ر��ļ�
	return;
}

void Manager::showPerson()
{

}

void Manager::showComputer()
{

}

void Manager::cleanFile()
{

}
