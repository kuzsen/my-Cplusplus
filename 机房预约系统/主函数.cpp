#include<iostream>
#include<string>
using namespace std;
#include"GolbalFile.h"
#include"Identity.h"



//��¼ȫ�ֺ���
void LoginIn(string filename,string type)//fileName �� �������ļ�����type �� ��¼�����(1����ѧ���� 2������ʦ�� 3�������Ա)
{
	Identity* person = nullptr;//����ָ��   ����ָ���������

	//���ļ�

}
int main()
{
	int select = 0;
	while (true) {

		cout << endl << "�������������" << endl;//         \t��ʾ��4��\n��ʾ����
		cout << "\t\t  ---------------------------------\n";
		cout << "\t\t |                                |\n";
		cout << "\t\t |            1.ѧ������          |\n";
		cout << "\t\t |                                |\n";
		cout << "\t\t |            2.��    ʦ          |\n";
		cout << "\t\t |                                |\n";
		cout << "\t\t |            3.�� �� Ա          |\n";
		cout << "\t\t |                                |\n";
		cout << "\t\t |            0.��    ��          |\n";
		cout << "\t\t |                                |\n";
		cout << "\t\t  ---------------------------------\n";
		cout << "����������ѡ��";

		cin >> select;//�����û�ѡ��

		switch (select)
		{
		case 1://ѡ��ѧ�����
			break;
		case 2://ѡ����ʦ���
			break;
		case 3://ѡ�����Ա���
			break;
		case 0://�˳�ϵͳ
			cout << "���˳�����ӭ�´�ʹ��!" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	
	}
	
	system("pause");
	system("cls");
	return 0;
}