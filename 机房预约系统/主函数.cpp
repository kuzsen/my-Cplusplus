#include<iostream>
#include<string>
using namespace std;
#include"GolbalFile.h"
#include"Identity.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
#include<fstream>//C++文件输入与输出，头文件<fstream>中包含三个文件输入输出类——ifstream/ofstream/fstream，分别由相应的iostream中的类派生而来

//全局函数——进入管理员操作子菜单界面
//****注意，一定要放在全局登录函数LoginIn的上面，因为LoginIn中会调用该函数
//****否则会提示       "managerMenu":找不到标识符
//*****可以先写一个函数声明，如下，这样  函数实现  就可以随意放了
//void managerMenu(Identity*& father);//函数声明


//全局函数——进入学生操作子菜单界面
void studentMenu(Identity*& father) 
{
	while (true)
	{
		//调用学生子菜单,基类中的纯虚函数在学生子类中实现
		father->operMenu();
		//将父类指针father 强制转换为学生子类指针stu ，用于调用子类中的其他函数接口
		Student* stu = (Student*)father;
		//接收学生的选择
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "申请预约" << endl;
			stu->applyOrder();
		}
		else if (select == 2)
		{
			cout << "查看我的预约" << endl;
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			cout << "查看所有预约" << endl;
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			cout << "取消预约" << endl;
			stu->cancelOrder();
		}
		else
		{
			delete father;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;			
		}
	}
}

//全局函数——进入老师操作子菜单界面
void teachrMenu(Identity*& father)
{
	while (true) {
		//教师菜单
		father->operMenu();

		Teacher* tea = (Teacher*)father;
		int select = 0;//接收老师的选择
		cin >> select;
		if (select == 1) {
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2) {
			//审核预约
			tea->validOrder();
		}
		else {
			delete father;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void managerMenu(Identity*& father)//参数father的类型为父类指针
{
	while (true)
	{
		//调用管理员子菜单
		father->operMenu();
		//将父类指针father 强制转换为子类指针man ，用于调用子类中的其他函数接口
		Manager* man = (Manager*)father;

		int select = 0;
		//接受管理员的选项
		cin >> select;
		if (select == 1)
		{
			cout << "添加账号" << endl;//给学生或教师添加新的账号
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			cout << "查看机房信息" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else //除去1/2/3/4
		{
			delete father;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//登录全局函数
void LoginIn(string filename,int type)//fileName — 操作的文件名，type — 登录的身份(1代表学生、 2代表老师、 3代表管理员)
{
	Identity* Father = nullptr;//父类指针   用于指向子类对象

	//读文件              https://blog.csdn.net/weixin_42831199/article/details/82047874
	ifstream ifs;//创建一个读文件对象，用于将文件中的数据输入到内存中
	ifs.open(filename, ios::in);//以读入的方式打开同一目录下文件名为“filename”的文件
	//ifs.open("D:\\Users\\a'd'mia\\source\\repos\\lzs925\\机房预约系统\\student.txt");
	//判断要读的文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	//若文件存在，准备接收用户输入的登录信息
	int id = 0;
	string name;
	string password;

	if (type == 1)//学生身份，需要输入学号
	{
		cout << "请输入您的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)//老师身份，需要输入老师职工号
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> password;

	if (type == 1)//学生身份验证
	{
		//接收从文件中读入的学生信息
		int fid;//从文件中读取的id号
		string fname;//从文件中读取的name
		string fpasssword;//从文件中读取的password

		while (ifs >> fid && ifs >> fname && ifs >> fpasssword)
		{
			//cout<<fid<<fname<<fpasssword<<endl;//验证是否从文件中读取成功
			if (fid == id && fname == name && fpasssword == password)//与用户输入的信息做对比
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");//清屏

				Father = new Student(id, name, password);  //父类指针指向子类对象
				//进入学登录后的子菜单
				studentMenu(Father);
				return;
			}
		}

	}
	else if (type == 2)//老师身份验证
	{
		//接收从文件中读入的老师信息
		int fid;//从文件中读取的id号——职工号
		string fname;//从文件中读取的name
		string fpasssword;//从文件中读取的password

		while (ifs >> fid && ifs >> fname && ifs >> fpasssword)
		{
			//cout<<fid<<fname<<fpasssword<<endl;//验证是否从文件中读取成功
			if (fid == id && fname == name && fpasssword == password)//与用户输入的信息做对比
			{
				cout << "老师验证登录成功！" << endl;
				system("pause");
				system("cls");//清屏

				Father = new Teacher(id, name, password);  //父类指针指向子类对象
				//进入老师身份的子菜单
				teachrMenu(Father);
				return;
			}
		}
	}
	else if(type == 3)//管理员身份验证
	{
		//接收从文件中读入的管理员信息
		//int fid;//从文件中读取的id号
		string fname;//从文件中读取的name
		string fpasssword;//从文件中读取的password

		while (ifs >> fname && ifs >> fpasssword)
		{
			//cout<<fname<<fpasssword<<endl;//验证是否从文件中读取成功
			if (fname == name && fpasssword == password)//与用户输入的信息做对比
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");//清屏

				Father = new Manager(name, password);  //父类指针指向子类对象,此时调用Manager的有参构造函数，即可初始化学生和老师信息容器
				//进入管理员身份的子菜单
				managerMenu(Father);
				return;
			}
		}
	}
	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;
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
			LoginIn(student_file, select);
			break;
		case 2://选择老师身份
			LoginIn(teacher_file, select);
			break;
		case 3://选择管理员身份
			LoginIn(manager_file, select);
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
