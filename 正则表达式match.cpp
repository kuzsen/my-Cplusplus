///*
////https://blog.csdn.net/qq_34802416/article/details/79307102��Ҫ�����
//
//C++��ʹ��������ʽ��Ҫע���һ�����⣺ת���ַ�'\'
//match��ȫ��ƥ�䣬��Ҫ�������ַ�������ƥ�����
//
//\d��ƥ��һ�������ַ���
//+ ��ƥ��һ�λ��Σ�
//cout << regex_match("123", regex("\\d")) << endl;		//���Ϊ0
//cout << regex_match("123", regex("\\d+")) << endl;		//���Ϊ1
//������������ֵΪboolֵ����Ҫ����if�������ʽ�С�
//
//�����ʱ������ϣ���ܹ����ƥ�������ַ��������Խ�����в�������ʱ����Ҫ��ƥ�������д洢���������ִ洢��ʽ��
//match_results<string::const_iterator> result;
//smatch result;			//ʹ����������ࡢ���㣬�Ƽ�ʹ�á�
//
//*/

#include<iostream>
#include<regex>//������ʽregular expressionͷ�ļ�
using namespace std;

int main()
{
	string str = "Hello_2018";
	smatch result;
	regex pattern("(.{5})_(\\d{4})");	//ƥ��5�����ⵥ�ַ� + �»��� + 4������

	if (regex_match(str, result, pattern))//��ƥ������У�������()�ķ�ʽ���������ʵ���еĹ������������ţ����Թ����������ݡ�
	{
		cout << result[0] << endl;		//����ƥ������Hello_2018
		cout << result[1] << endl;		//��һ��ƥ������ݣ�Hello
		cout << result[2] << endl;		//�ڶ���ƥ������ݣ�2018
		cout << "�����ʾ��ʽ2" << endl;
		cout << result.str() << endl;	//���������Hello_2018
		cout << result.str(1) << endl;	//��һ��ƥ������ݣ�Hello
		cout << result.str(2) << endl;	//�ڶ���ƥ������ݣ�2018
	}

	//�������
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;
	}

	system("pause");
	system("cls");
	return 0;
}


