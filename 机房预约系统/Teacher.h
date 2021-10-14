#pragma once
#include"Identity.h"

#include <iostream>
using namespace std;

class Teacher : public Identity
{
public:
	//默认构造
	Teacher();
	//有参构造
	Teacher(int id, string name, string password);
	//教师操作界面
	virtual void operMenu();
	//查看所有预约
	void showAllOrder();
	//审核预约
	void validOrder();
	//教师职工号
	int m_teacherId;
};