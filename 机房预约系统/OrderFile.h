#pragma once
#include <iostream>
using namespace std;
#include <map>
#include "GolbalFile.h"

class OrderFile {
public:
	//���캯��
	OrderFile();//���캯���л�ȡ������Ϣ�������������m_orderData��

	//����ԤԼ��¼
	void updateOrder();

	//��¼������ key = ��¼������, value = ÿ����¼����ļ�ֵ����Ϣ������{{data, 1},{interval, 2}, .....}
	map<int, map<string, string>> m_orderData;

	//ԤԼ��¼����
	int orderNum;
};


