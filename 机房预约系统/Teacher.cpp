#include"Teacher.h"
#include"OrderFile.h"
#include<vector>

Teacher::Teacher()
{
}

Teacher::Teacher(int id, string name, string password)
{
	//初始化属性
	this->m_teacherId = id;
	this->m_Name = name;
	this->m_Password = password;

}

void Teacher :: operMenu()
{
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t  ---------------------------------\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            1.查看所有预约      |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            2.审核预约          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            0.注销登录          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t  ---------------------------------\n";
	cout << "请选择您的操作：";
}

void  Teacher:: showAllOrder()
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

void Teacher:: validOrder()
{
	OrderFile of;
	if (of.orderNum == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核————状态=1的预约记录如下：" << endl;

	vector<int> v;//待审核的预约记录，下标0，1，2，。。。
	int index = 0;//v中的第1，2，3.。。条
	for (int i = 0; i < of.orderNum; i++) {
		if (of.m_orderData[i]["status"] == "1") {
			v.push_back(i);
			cout << ++index << "、";
			cout << "预约日期：周" << of.m_orderData[i]["date"];
			cout << " 时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 学生编号：" << of.m_orderData[i]["stuId"];
			cout << " 学生姓名：" << of.m_orderData[i]["stuName"];
			cout << " 机房编号：" << of.m_orderData[i]["roomId"];
			string status = "状态: 审核中";
			cout << status << endl;
		}
	}
	if (v.size() == 0) {
		cout << "没有需要审核的记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入需要审核的预约记录, 0代表返" << endl;
	int select = 0;//接收所有待审核记录中，老师选择审核的第 select 条预约记录
	int ret = 0;//接收老师对该记录的审核结果
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0)
				break;
			else {
				cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cin >> ret;
				if (ret == 1) {
					//通过
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else {
					//不通过
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();//老师审核后，立即更新预约文件中的记录
				cout << "审核完毕" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入!" << endl;
	}
	system("pause");
	system("cls");
}