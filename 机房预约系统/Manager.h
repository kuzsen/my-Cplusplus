#pragma once
#include"Identity.h"

class Manager : public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string password);
	//����Ա��������
	virtual void operMenu();
	//����˺ţ�ѧ��or��ʦ��
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void cleanFile();

};