// https://blog.csdn.net/zhaitianbao/article/details/119567773
// ��Ŀ����

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string key, str;
	// getline(cin, key); // ���Ի�ȡһ���е����룬getline�������Զ�ȡ���У�����ǰ����Ƕ��ʽ�Ŀո񣬲�����洢���ַ���������
	// getline(cin, str); // ������ʱ��ֱ��������\n����EOF�������趨���ַ� 'q'�� ����ֹһ���ַ������������
	while (cin >> key >> str) { // cin����һ���ַ���ʱ�������ո񡱡���TAB�������س����ͽ���
		vector<char> comp(26); // ������Կkey��26��Ӣ����ĸ���õ����ܲ���comp
		int i = 0; // ��ͷ��comp��ֵ
		for (int j = 0; j < key.size(); j++) {
			key[j] = tolower(key[j]); // ͳһ��keyת����Сд
			if (key.find(key[j]) == j) { // find()�ַ����е�һ�γ���ĳ�ַ���λ��/�±꣬����key�е��ַ����ȥ�ز������ٸ�ֵ��comp
				comp[i] = key[j];
				i++;
			}
		}
		for (char c = 'a'; c <= 'z'; c++) {
			if (key.find(c) == string::npos) { // 26��ĸ��key�в����ڵ��ַ�c��Ҳ���뵽comp��
				comp[i] = c;
				i++;
			}
		}
		// ���ˣ�comp��Ϊ���ܲ���
		// ����Դ����ܵ��ַ�str���м���
		string res;
		for (char c : str) {
			if (c >= 'a' && c <= 'z') {
				res.push_back(comp[c - 'a']); // �ַ�c��ԭ��26��ĸ��abc...xyz�е�λ�ã��ҵ�������ĸ���λ�õ��ַ�
			}
			else if (c >= 'A' && c <= 'Z') { // ԭ�����ַ�cΪ��д��ĸ������ܺ��Ա��ִ�д
				res.push_back(toupper(comp[c - 'a']));
			}
			else {
				res.push_back(c); // ��26��ĸ�ַ���������
			}
		}
		cout << "��Կkey=" << key << "�ʹ������ַ���str=" << str << "���ܺ�Ϊ��" << res << endl;
	}
	system("pause");
	system("cls");
	return 0;
}
