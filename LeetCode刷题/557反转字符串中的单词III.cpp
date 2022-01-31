#include<iostream>
using namespace std;
#include <sstream>
class Solution {
public:
    string reverseWords(string s) {
        // https://blog.csdn.net/liuweiyuxiang/article/details/89070296
        // 4.2 stringstream用于空格分割的字符串的切分
        string res;
        stringstream ss(s); // 将s写入stringstream对象ss
        string word;
        while (ss >> word) { // 从右往左分割ss中的字符串，将单词写给word；
            reverse(word.begin(), word.end());
            res += word + ' '; // 每个反转单词后加上一个空格
        }
        return res.substr(0, res.size() - 1); // 去掉最后一个空格
    }
};
int main()
{
    string test = "Let's take LeetCode contest";
    string res = Solution().reverseWords(test);
	system("pause");
	system("cls");
	return 0;
}
