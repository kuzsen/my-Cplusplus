#include"Manager.h"
#include<fstream>
#include"GolbalFile.h"


Manager::Manager()
{
	
}

Manager::Manager(string name, string password)
{
	this->m_Name = name;//在管理员构造函数中，初始化管理员信息
	this->m_Password = password;
}

void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录" << endl;
	cout << "\t\t  ---------------------------------\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            1.添加账号          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            2.查看账号          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            3.查看机房          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            4.清空预约          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t |            0.注销登录          |\n";
	cout << "\t\t |                                |\n";
	cout << "\t\t  ---------------------------------\n";
	cout << "亲爱的管理员，请输入您的下一步操作：";
}

void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string filename;//添加账号操作，需要进行 “写出” 的文件名

	ofstream ofs;//文件“写出”   操作对象
	string tip;//提示管理员输入，需要添加的“学生学号”/“老师职工号”
	int select = 0;
	cin >> select;//接收管理员输入的选项
	if (select == 1)
	{
		//添加的是学生账号
		filename = student_file;
		tip = "请输入学生学号";
	}
	if (select == 2)
	{
		//添加的是老师账号
		filename = teacher_file;
		tip = "请输入老师职工号";
	}

	//利用追加的方式 写文件
	ofs.open(filename, ios::out | ios::app);
	int id;//管理员添加的id/name/password
	string name;
	string password;

	cout << tip << endl;
	cin >> id;

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> password;

	//向文件中添加数据
	ofs << id << " " << name << " " << password << " " << endl;
	cout << "账号添加成功" << endl;
	system("pause");
	system("cls");

	ofs.close();//关闭文件
	return;
}

void Manager::showPerson()
{

}

void Manager::showComputer()
{

}

void Manager::cleanFile()
{

}
