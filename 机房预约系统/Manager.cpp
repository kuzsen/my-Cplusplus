#include"Manager.h"
#include<fstream>
#include"GolbalFile.h"
#include<algorithm>
//#include"Student.h"
//#include"Teacher.h"
#include"ComputerRoom.h"


Manager::Manager()
{
	
}

Manager::Manager(string name, string password)
{
	this->m_Name = name;//在管理员构造函数中，初始化管理员信息——姓名和密码
	this->m_Password = password;

	//在管理员有参构造函数中，调用初始化容器函数，初始化学生和老师信息容器
	this->initVector();

	//初始化机房信息，//将每一机房的信息从机房文件中读出来，再导入到管理员类中的机房容器CR中
	ifstream ifs;
	ifs.open(computer_file, ios::in);
	if (!ifs.is_open())
	{
		cout << "机房文件打开失败" << endl;
	}
	ComputerRoom cr;
	while (ifs >> cr.CR_id && ifs >> cr.CR_max)
	{
		CR.push_back(cr);
	}
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
	string errortip;//提示管理员添加账号的id，学生or老师文件中已经存在了
	int select = 0;
	cin >> select;//接收管理员输入的选项
	if (select == 1)
	{
		//添加的是学生账号
		filename = student_file;
		tip = "请输入学生学号";
		errortip = "输入学号已存在，请重新输入";
	}
	if (select == 2)
	{
		//添加的是老师账号
		filename = teacher_file;
		tip = "请输入老师职工号";
		errortip = "输入职工号已存在，请重新输入";
	}

	//利用追加的方式 写文件
	ofs.open(filename, ios::out | ios::app);
	int id;//管理员添加的id/name/password
	string name;
	string password;

	cout << tip << endl;

	//判断输入id是否有重复
	while (true)
	{
		cin >> id;
		int ret = checkRepeat(id, select);
		if (ret) //输入id有重复
		{
			cout << errortip << endl;
		}
		else
			break;
	}

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> password;

	//向文件中添加数据
	ofs << id << " " << name << " " << password << " " << endl;//注意添加空格
	cout << "账号添加成功" << endl;
	system("pause");
	system("cls");
	ofs.close();//关闭文件

	//bug描述：刚刚添加的账号（学生号或者职工号）由于没有更新到容器中，在3管理员界面，继续选择1添加账号时，依然会重复，因为学生or老师容器还未更新
	//解决方案：在每次添加新账号后，重新初始化容器，即把刚刚添加的账号，加到学生or老师容器中
	this->initVector();

	return;
}

void Manager::noPerson() //待完成
{

}

//打印某一学生的信息，在查看账号showPerson()函数中，会调用此函数
void printStudent(Student& s)
{
	cout << "学号：" << s.m_studentId << " " << " 姓名：" << s.m_Name << " " << " 密码：" << s.m_Password << endl;
}
//打印某一老师的信息，在查看账号showPerson()函数中，会调用此函数
void printTeacher(Teacher& t)
{
	cout << "职工号：" << t.m_teacherId << " " << "姓名：" << t.m_Name << " " << "密码：" << t.m_Password << endl;
}
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有的学生" << endl;
	cout << "2、查看所有的老师" << endl;

	int select = 0;//接受用户选择
	cin >> select;
	if (select == 1)//查看学生
	{
		cout << "所有学生信息如下：" << endl;
		for_each(stu.begin(), stu.end(), printStudent);// // perform function for each element [_First, _Last)
		//遍历学生容器，逐个打印出学生信息//for_each需要包含算法头文件#include<algorithm>
	}
	else //查看老师
	{
		cout << "所有老师信息如下：" << endl;
		for_each(tea.begin(), tea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	if (CR.size() == 0)
	{
		cout << "机房文件为空" << endl;
		system("pause");
		system("cls");
		return ;
	}
	cout << "机房信息如下：" << endl;
	for (auto i = CR.begin(); i != CR.end(); i++)
	{
		cout << "机房编号：" << i->CR_id << " " << "该机房最大容量：" << i->CR_max << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()//将预约文件order_file清空
{
	ofstream ofs;//创建 往文件中 “写入” 的操作对象
	ofs.open(order_file, ios::trunc);  //ios::trunc——将先前的文件内容移除（Remove)

	ofs.close();
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector() 
{
	//确保学生和老师是容器清空状态
	stu.clear();
	tea.clear();
	//读取学生信息
	ifstream ifs;
	ifs.open(student_file, ios::in);
	if (!ifs.is_open())
	{
		cout << "学生信息文件读取失败" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_studentId && ifs >> s.m_Name && ifs >> s.m_Password)
	{
		stu.push_back(s);
	}
	//测试是否读取到  学生容器stu中
	cout << "当前学生数量为：" << stu.size() << endl;
	//关闭学生文件
	ifs.close();

	//读取老师信息
	ifs.open(teacher_file, ios::in);
	if (!ifs.is_open()) 
	{
		cout << "老师信息文件读取失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_teacherId && ifs >>t.m_Name  && ifs >>t.m_Password) 
	{
		tea.push_back(t);
	}
	//测试
	cout << "当前老师数量为：" << tea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)//判断学生容器stu中，是否已经存在学号为id的学生
	{
		for (auto i = stu.begin(); i != stu.end(); i++)//遍历学生容器
		{
			if (i->m_studentId == id)
			{
				cout << "输入的学号" << id << "与学生文件中的重复" << endl;
				return true;
			}
		}
	}
	else//判断老师容器tea中，是否已经存在职工号为id的老师
	{
		for (auto i = tea.begin(); i != tea.end(); i++)//遍历老师容器
		{
			if (i->m_teacherId== id)
			{
				cout << "输入的职工号" << id << "与老师文件中的重复" << endl;
				return true;
			}
		}
	}
	return false;
}


