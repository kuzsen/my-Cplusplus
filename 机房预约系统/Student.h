#pragma once
#include "Identity.h"
#include<vector>
#include"ComputerRoom.h"

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

	//在申请预约时，学生可以看到机房的信息，因此我们需要让学生获取到机房的信息
	//在student.h中添加新的成员变量：
	//机房容器
	vector<ComputerRoom> vCom;

};

