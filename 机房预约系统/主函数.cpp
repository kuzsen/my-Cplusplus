#include<iostream>
#include<string>
using namespace std;
#include"GolbalFile.h"
#include"Identity.h"



//登录全局函数
void LoginIn(string filename,string type)//fileName — 操作的文件名，type — 登录的身份(1代表学生、 2代表老师、 3代表管理员)
{
	Identity* person = nullptr;//父类指针   用于指向子类对象

	//读文件

}
int main()
{
	int select = 0;
	while (true) {

		cout << endl << "请输入您的身份" << endl;//         \t表示空4格，\n表示换行
		cout << "\t\t  ---------------------------------\n";
		cout << "\t\t |                                |\n";
		cout << "\t\t |            1.学生代表          |\n";
		cout << "\t\t |                                |\n";
		cout << "\t\t |            2.老    师          |\n";
		cout << "\t\t |                                |\n";
		cout << "\t\t |            3.管 理 员          |\n";
		cout << "\t\t |                                |\n";
		cout << "\t\t |            0.退    出          |\n";
		cout << "\t\t |                                |\n";
		cout << "\t\t  ---------------------------------\n";
		cout << "请输入您的选择：";

		cin >> select;//接收用户选择

		switch (select)
		{
		case 1://选择学生身份
			break;
		case 2://选择老师身份
			break;
		case 3://选择管理员身份
			break;
		case 0://退出系统
			cout << "已退出，欢迎下次使用!" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	
	}
	
	system("pause");
	system("cls");
	return 0;
}