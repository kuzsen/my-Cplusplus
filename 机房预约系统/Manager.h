#pragma once
#include"Identity.h"

class Manager : public Identity
{
public:
	//默认构造
	Manager();
	//有参构造
	Manager(string name, string password);
	//管理员操作界面
	virtual void operMenu();
	//添加账号（学生or老师）
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void cleanFile();

};