// https://blog.csdn.net/zhaitianbao/article/details/119567773
// 题目链接

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string key, str;
	// getline(cin, key); // 可以获取一整行的输入，getline函数可以读取整行，包括前导和嵌入式的空格，并将其存储在字符串对象中
	// getline(cin, str); // 在输入时，直至遇到‘\n’或EOF，或者设定的字符 'q'， 才终止一行字符串输入操作。
	while (cin >> key >> str) { // cin接收一个字符串时，遇“空格”、“TAB”、“回车”就结束
		vector<char> comp(26); // 根据密钥key和26个英文字母，得到加密参照comp
		int i = 0; // 从头给comp赋值
		for (int j = 0; j < key.size(); j++) {
			key[j] = tolower(key[j]); // 统一将key转换成小写
			if (key.find(key[j]) == j) { // find()字符串中第一次出现某字符的位置/下标，即对key中的字符完成去重操作后再赋值给comp
				comp[i] = key[j];
				i++;
			}
		}
		for (char c = 'a'; c <= 'z'; c++) {
			if (key.find(c) == string::npos) { // 26子母中key中不存在的字符c，也插入到comp中
				comp[i] = c;
				i++;
			}
		}
		// 至此，comp即为加密参照
		// 下面对待加密的字符str进行加密
		string res;
		for (char c : str) {
			if (c >= 'a' && c <= 'z') {
				res.push_back(comp[c - 'a']); // 字符c在原来26字母表abc...xyz中的位置，找到加密字母表该位置的字符
			}
			else if (c >= 'A' && c <= 'Z') { // 原来的字符c为大写字母，则加密后仍保持大写
				res.push_back(toupper(comp[c - 'a']));
			}
			else {
				res.push_back(c); // 非26字母字符，不加密
			}
		}
		cout << "密钥key=" << key << "和待加密字符串str=" << str << "加密后为：" << res << endl;
	}
	system("pause");
	system("cls");
	return 0;
}
