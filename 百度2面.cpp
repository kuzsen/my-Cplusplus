#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 分割字符串函数
// 原本面试官给定参数是C语言指针形式，int split(char* in, const char sep, char** out); // 字符指针这一块需要加强练习
int split(string in, const char sep, vector<string>& res) {
    int ans = 0;
    for (int i = 0; i < in.size();) {
        // cout << i << endl;
        int j = i;
        while (j < in.size() && in[j] != sep) { // ******************这里要保证j的范围不能溢出
            j++;
        }
        string cur;
        if (j < in.size()) {
            ans++;
            // cout << ans << endl;
            cur = in.substr(i, j - i);
            // i = j + 1;
        }
        else {
            cur = in.substr(i, in.size() - i);
            // break; // ********************************************最后一个子字符串还没有添加到res中，不能break
        }
        // cout << cur << endl;
        i = j + 1;
        res.push_back(cur);
    }
    return ans + 1;
}
int main() {
    string in = "a#c#dcd#daa#113";
    cout << in << endl;
    vector<string> res;
    const char sep = '#';
    // 用sep字符分割字符串，返回分割后的子字符串个数，引用返回字符串列表
    int num = split(in, sep, res);
    cout << num << endl;
    for (auto s : res) {
        cout << s << endl;
    }
    system("pause");
    system("cls");
    return 0;
}