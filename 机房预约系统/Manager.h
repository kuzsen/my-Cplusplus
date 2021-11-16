#pragma once
#include"Identity.h"
#include<vector>
#include"Student.h"
#include"Teacher.h"
#include"ComputerRoom.h"

class Manager : public Identity
{
public:
	
	Manager();//默认构造

	Manager(string name, string password);	//有参构造
	
	virtual void operMenu();//管理员操作界面，子类中实现纯虚函数的实现，的，头文件声明，在Manager.cpp中具体实现
	
	void addPerson();//添加账号（学生or老师）

	void noPerson();  //删除账号
	
	void showPerson();//
	
	void showComputer();//查看机房信息
	
	void cleanFile();//清空预约记录

	/*要去除重复的账号，首先要将学生和教师的账号信息获取到程序中，方可检测
	在manager.h中，添加两个容器，用于存放学生和教师的信息
	添加一个新的成员函数 void initVector()初始化容器*/

	void initVector();

	vector<Student>stu;//学生容器

	vector<Teacher>tea;//老师容器

	//检查学生or老师信息是否有重复,//id为传入的学号or职工号，type为1学生or2老师，返回值true=有重复，false=没有重复，可以添加该账号
	bool checkRepeat(int id, int type);

	//添加机房的容器，用于保存机房信息
	vector<ComputerRoom>CR;

	
};