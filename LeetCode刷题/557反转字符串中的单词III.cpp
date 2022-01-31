#include<iostream>
using namespace std;
#include <sstream>
class Solution {
public:
    string reverseWords(string s) {
        // https://blog.csdn.net/liuweiyuxiang/article/details/89070296
        // 4.2 stringstream���ڿո�ָ���ַ������з�
        string res;
        stringstream ss(s); // ��sд��stringstream����ss
        string word;
        while (ss >> word) { // ��������ָ�ss�е��ַ�����������д��word��
            reverse(word.begin(), word.end());
            res += word + ' '; // ÿ����ת���ʺ����һ���ո�
        }
        return res.substr(0, res.size() - 1); // ȥ�����һ���ո�
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
