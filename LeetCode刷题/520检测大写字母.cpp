#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool detectCapitalUse1(string word) {
		//1�����ܵ�һ���ַ��Ǵ�д����Сд��������ַ���Сд ������ڶ����ַ��Ĵ�Сд����һ��
		//2������һ���ַ���Сд������Ҫ�жϵڶ�����ĸ�Ƿ��Ǵ�д�����ǣ��򷵻�false������Сд���ж��Ƿ��������1
		if (word.size() >= 2 && islower(word[0]) && isupper(word[1])) {
			return false;
		}
		for (int i = 2; i < word.size(); ++i) {
			if (isupper(word[i]) != isupper(word[1])) {
				return false;
			}
		}
		return true;
	}

	bool detectCapitalUse2(string word) {//ͳ�ƴ�д��ĸ����
		int uppercount = 0;
		for (auto c : word) {
			if ('A' <= c && c <= 'Z') {
				uppercount++;
			}
		}
		if (uppercount == word.size() || uppercount == 0) return true;//ȫΪ��д����ȫΪСд
		else if (uppercount == 1 && 'A' <= word[0] && word[0] <= 'Z') return true;//����ĸΪ��д��������ΪСд
		else return false;
	}
};

int main()
{
	string test;
	bool res1;
	bool res2;
	while (true) {
		getline(cin, test);
		res1 = Solution().detectCapitalUse1(test);
		cout << res1 << endl;
		res2 = Solution().detectCapitalUse2(test);
		cout << res2 << endl;
	}

	system("pause");
	system("cls");
	return 0;
}
