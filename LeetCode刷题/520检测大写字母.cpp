#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool detectCapitalUse1(string word) {
		//1，不管第一个字符是大写还是小写，后面的字符大小写 必须与第二个字符的大小写保持一致
		//2，若第一个字符是小写，则需要判断第二个字母是否是大写，若是，则返回false，若是小写，判断是否满足规则1
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

	bool detectCapitalUse2(string word) {//统计大写字母个数
		int uppercount = 0;
		for (auto c : word) {
			if ('A' <= c && c <= 'Z') {
				uppercount++;
			}
		}
		if (uppercount == word.size() || uppercount == 0) return true;//全为大写或者全为小写
		else if (uppercount == 1 && 'A' <= word[0] && word[0] <= 'Z') return true;//首字母为大写，其他均为小写
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
