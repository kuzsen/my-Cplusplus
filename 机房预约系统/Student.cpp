#include "Student.h"
#include "GolbalFile.h"
#include "OrderFile.h"
#include<cstdlib>//在此添加是为了解决Student.cpp中system("pause");system("cls");  提示system不明确问题
//在C里就是stdlib.h，在c++里就是cstdlib，里面封装了许多函数，

Student::Student()
{

}

Student :: Student(int id, string name, string password)//Student类的有参构造函数中
{
	//初始化学生信息
	this->m_studentId = id;
	this->m_Name = name;
	this->m_Password = password;
	//获取机房信息
	ifstream ifs;
	ifs.open(computer_file, ios::in);

	ComputerRoom cr;
	while (ifs >> cr.CR_id && ifs >> cr.CR_max)
	{
		this->vCom.push_back(cr);
	}
	ifs.close();
}

void Student :: operMenu()
{
	cout << "欢迎学生代表：" << this->m_Name << "登录" << endl;
	cout << "\t\t  ---------------------------------\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            1.申请预约          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            2.查看我的预约      |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            3.查看所有预约      |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            4.取消预约          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            0.注销登录          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t  ---------------------------------\n";
	cout << "请输入您的操作：";
}
void Student :: applyOrder()
{
	cout << "机房开放时间为周一至周五" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	int date = 0;//周几
	int interval = 0;//上午or下午，时间段
	int room = 0;//申请机房号
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		cout << "输入有误，请重新输入";
	}
	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请选择机房：" << endl;
	cout << "1号机房容量：" << vCom[0].CR_max << endl;
	cout << "2号机房容量：" << vCom[1].CR_max << endl;
	cout << "3号机房容量：" << vCom[2].CR_max << endl;

	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功！审核中" << endl;
	ofstream ofs(order_file, ios::app);//将该学生的个人信息以及预约信息，写到预约文件中记录下来
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_studentId << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;//表示预约的状态，1 = 审核中

	ofs.close();
	system("pause");
	system("cls");
}

void Student :: showMyOrder()
{
	/*
	显示预约记录时，需要从文件中获取到所有记录，用来显示，创建预约的类来管理记录以及更新
	在头文件以及源文件下分别创建OrderFile.h和OrderFile.cpp文件
	*/

	OrderFile of;//创建预约文件的对象，调用了构造函数，已经将order_file中的信息读入到m_orderData大容器中对预约文件order_file进行读写，更新，获取预约条数等操作
	if (of.orderNum == 0) {
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	int orderMyself = 0;//所有自身预约记录,若遍历完预约文件的大容器后，vMyself.size() == 0，则没有该学生的预约记录
	for (int i = 0; i < of.orderNum; i++) {
		//string 转 int
		//string 利用 .c_str() 转 const char*
		//利用 atoi(const char*) 转 int
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_studentId) {
			orderMyself++;//检测到自身预约记录加一
			cout << "预约日期: 周" << of.m_orderData[i]["date"];
			cout << " 时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房号：" << of.m_orderData[i]["roomId"];
			string status = "状态：";
			//1 审核中 2 已预约 -1 预约失败 0 取消预约
			if (of.m_orderData[i]["status"] == "1") {
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1") {
				status += "预约失败，审核未通过";
			}
			else {
				status += "预约已取消";
			}
			cout << " " << status;
			cout << endl;
		}

	}
	if (orderMyself == 0) {
		cout << "预约文件中没有您的预约记录!" << endl;
	}
	system("pause");
	system("cls");

}


void  Student :: showAllOrder()
{
	OrderFile of;
	if (of.orderNum == 0) {
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.orderNum; i++) {
		cout << i + 1 << "、";

		cout << "预约日期: 周" << of.m_orderData[i]["date"];
		cout << " 时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号：" << of.m_orderData[i]["stuId"];
		cout << " 姓名：" << of.m_orderData[i]["stuName"];
		cout << " 机房：" << of.m_orderData[i]["roomId"];
		string status = "状态：";
		//1 审核中 2 已预约 -1 预约失败 0 取消预约
		if (of.m_orderData[i]["status"] == "1") {
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "预约失败，审核未通过";
		}
		else {
			status += "预约已取消";
		}
		cout << " " << status;
		cout << endl;
	}
	system("pause");
	system("cls");
}

void  Student :: cancelOrder()
{ 
	OrderFile of;
	if (of.orderNum == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或以预约成功的记录可以取消，请输入取消的记录" << endl;

	vector<int> v;//储存自身所有  审核中或以预约成功  的记录
	int index = 1;//v中的第index条记录
	for (int i = 0; i < of.orderNum; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_studentId) {
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				v.push_back(i);//将检测到的————自身所有  审核中或以预约成功  的记录————插入到容器中
				cout << index++ << "、 ";
				cout << "预约日期：周" << of.m_orderData[i]["date"];
				cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房：" << of.m_orderData[i]["roomId"];
				string status = " 状态：";
				if (of.m_orderData[i]["status"] == "1") {
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2") {
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	if (v.size() == 0) {
		cout << "预约文件中没有您可以取消的记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或以预约成功的记录可以取消，请输入取消的记录" << endl;
	cout << "请输入自身所有“审核中或以预约成功” 的记录容器v中，需要取消的第select条记录，0代表返回" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();//状态改变后，立即更新预约文件
				cout << "已取消预约" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
}
