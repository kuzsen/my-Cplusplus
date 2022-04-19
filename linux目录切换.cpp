// ..两个点表示返回上一级目录
// .一个点表示当前目录

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <stack>
string last_str(string str) {
	// /user/your_name/.. 
	// /user/./your_name 
	// stack<string> st;

	stack<string> st;
	string res;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '/') {
			int j = i + 1;
			string cur;
			while (j < str.size() && str[j] != '/') {
				cur += str[j];
			}
			if (cur == "..") {
				st.pop();
			}
			else if (cur == ".") {
				if (st.empty()) {
					res = "/root/";
					return res;
				}
				else {
					continue;
				}
			}
			else {
				st.push(cur);
			}
		}
	}
	// 最后输出栈st中的字符串

	return res;
}
int main()
{
	string str;
	cin >> str;
	cout << last_str(str);

	system("pause");
	system("cls");
	return 0;
}
