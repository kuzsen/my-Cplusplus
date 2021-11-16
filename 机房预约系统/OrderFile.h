#pragma once
#include <iostream>
using namespace std;
#include <map>
#include "GolbalFile.h"

class OrderFile {
public:
	//构造函数
	OrderFile();//构造函数中获取所有信息，并存放在容器m_orderData中

	//更新预约记录
	void updateOrder();

	//记录的容器 key = 记录的条数, value = 每条记录具体的键值对信息，比如{{data, 1},{interval, 2}, .....}
	map<int, map<string, string>> m_orderData;

	//预约记录条数
	int orderNum;
};


