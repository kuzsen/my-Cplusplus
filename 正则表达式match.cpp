///*
////https://blog.csdn.net/qq_34802416/article/details/79307102主要看这个
//
//C++中使用正则表达式需要注意的一个问题：转义字符'\'
//match是全文匹配，即要求整个字符串符合匹配规则。
//
//\d：匹配一个数字字符；
//+ ：匹配一次或多次；
//cout << regex_match("123", regex("\\d")) << endl;		//结果为0
//cout << regex_match("123", regex("\\d+")) << endl;		//结果为1
//上述方法返回值为bool值，主要用于if条件表达式中。
//
//更多的时候我们希望能够获得匹配结果（字符串），对结果进行操作。这时就需要对匹配结果进行存储，共有两种存储方式。
//match_results<string::const_iterator> result;
//smatch result;			//使用起来更简洁、方便，推荐使用。
//
//*/

#include<iostream>
#include<regex>//正则表达式regular expression头文件
using namespace std;

int main()
{
	string str = "Hello_2018";
	smatch result;
	regex pattern("(.{5})_(\\d{4})");	//匹配5个任意单字符 + 下划线 + 4个数字

	if (regex_match(str, result, pattern))//在匹配规则中，以括号()的方式来划分组别，实例中的规则共有两个括号，所以共有两组数据。
	{
		cout << result[0] << endl;		//完整匹配结果，Hello_2018
		cout << result[1] << endl;		//第一组匹配的数据，Hello
		cout << result[2] << endl;		//第二组匹配的数据，2018
		cout << "结果显示形式2" << endl;
		cout << result.str() << endl;	//完整结果，Hello_2018
		cout << result.str(1) << endl;	//第一组匹配的数据，Hello
		cout << result.str(2) << endl;	//第二组匹配的数据，2018
	}

	//遍历结果
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}

	system("pause");
	system("cls");
	return 0;
}


