#include "OrderFile.h"

OrderFile :: OrderFile()
{
	ifstream ifs;
	ifs.open(order_file, ios::in);//打开预约文件，统计其中的预约信息
	string date;//日期
	string interval;//时间段
	string stuId;//学生编号
	string stuName;//学生姓名
	string roomId;//机房编号
	string status;//预约状态

	this->orderNum = 0;//记录条数

	while (ifs >> date && ifs >> interval && ifs >> stuId
		&& ifs >> stuName && ifs >> roomId && ifs >> status) {
		//测试
		//cout << date << endl;
		//cout << interval << endl;
		//cout << stuId << endl;
		//cout << stuName << endl;
		//cout << roomId << endl;
		//cout << status << endl;
		//cout << endl;
		string key;//小容器的key，表示  信息的名称，比如 data，interval
		string value;//小容器的vaule，表示 信息的值，比如 张三（对应key为stuName）
		map<string, string> m;//小容器，表示一条预约记录的所有信息

		//截取时间段，此时从预约文件order_file中读取到的一条预约记录中，string data = "data:1"
		int pos = date.find(":"); // data[4] = ":"
		if (pos != -1) {
			key = date.substr(0, pos);//substr的第一个参数0表示截取字符串的起始下标，第二个参数pos 表示截取字符串长度，此时，key = data；
			value = date.substr(pos + 1, date.size() - pos - 1);//从':'的下一个字符开始截取剩下的字符，此时，val = 1（表示周一）
			m.insert(make_pair(key, value));//把一条预约记录中的部分信息{data，1}，放入小容器中
		}
		//截取间隔
		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//截取学号
		pos = stuId.find(":");
		if (pos != -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//截取姓名
		pos = stuName.find(":");
		if (pos != -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//截取机房号
		pos = roomId.find(":");
		if (pos != -1) {
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		//截取状态
		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		this->orderNum++;//读取到预约记录加一
		//将小map容器放入到大的map容器中
		this->m_orderData.insert(make_pair(this->orderNum++, m));
	}
	ifs.close();
	//测试最大map容器
	//for (map<int, map<string, string>>::iterator it = m_orderData.begin();
	//	it != m_orderData.end(); it++) {
	//	cout << "条数为：" << it->first << " value = " << endl;
	//	for (map<string, string>::iterator mit = (*it).second.begin();
	//		mit != (*it).second.end(); mit++) {
	//		cout << " key = " << mit->first << " value = " << mit->second << " ";
	//	}
	//	cout << endl; 
	//}

}

void OrderFile :: updateOrder ()
{
	if (this->orderNum == 0)
	{
		return;
	}
	ofstream ofs(order_file, ios::out | ios::trunc);//先将预约文件清空
	for (int i = 0; i < this->orderNum; i++) {//重新将预约记录“写出”到预约文件中，完成更新操作
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}
