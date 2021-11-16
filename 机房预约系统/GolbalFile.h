#pragma once
/*
***************该头文件名字拼写错误，不想改了
*/

#include<fstream>
//在同级目录下创建相关.txt文件，文件路径使用绝对路径比较好
//***********   .txt文件保存时，另存为， 编码——》选择  ANSI  格式，否则读取时容易出现乱码


//学生信息文件   下面定义文件名方式，都可以
//#define  student_file  "D:\\Users\\a'd'mia\\source\\repos\\lzs925\\机房预约系统\\student.txt"
constexpr auto student_file = "D:\\MyCode_C++\\myprojects\\机房预约系统\\student.txt";

//教师信息文件
#define  teacher_file  "D:\\MyCode_C++\\myprojects\\机房预约系统\\teacher.txt"

//管理员文件
#define  manager_file  "D:\\MyCode_C++\\myprojects\\机房预约系统\\manager.txt"

//机房信息文件
#define  computer_file  "D:\\MyCode_C++\\myprojects\\机房预约系统\\computer.txt"

//预约信息文件
#define  order_file  "D:\\MyCode_C++\\myprojects\\机房预约系统\\order.txt"