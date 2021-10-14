#pragma once
#include "Identity.h"

class Student : public Identity
{
public:
	//默认构造
	Student();
	
	//有参数构造
	Student(int id, string name, string password);

	//操作菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消我的预约
	void cancelOrder();

	//学生学号
	int m_studentId;

};

