#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//class Solution { ------------------------�Լ�д�ģ�����
//private:
//    int my_stoi(string num) {
//        int n = num.size();
//        int res = 0;
//        for (int i = 0; i < n; ++i) {
//            res += ((num[i] - '0') * (10 ^ (n - i - 1)));
//        }
//        return res;
//    }
//public:
//    string multiply(string num1, string num2) {
//        string res;
//        int i_num1 = my_stoi(num1), i_num2 = my_stoi(num2);
//        int i_res = i_num1 * i_num2;
//        while (i_res >= 0) {
//            res += char(i_res % 10);
//            i_res = i_res / 10;
//        }
//        reverse(res.begin(), res.end());
//        return res;
//    }
//};
class Solution {
public:
    // �ַ������ + ��λ�˷�
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ans = "0";
        int m = num1.size(), n = num2.size();
        // ��λ�˷�
        for (int i = n - 1; i >= 0; i--) {
            string curr;
            int add = 0;
            for (int j = n - 1; j > i; j--) {
                curr.push_back(0);
            }
            int y = num2.at(i) - '0';
            for (int j = m - 1; j >= 0; j--) {
                int x = num1.at(j) - '0';
                int product = x * y + add;
                curr.push_back(product % 10);
                add = product / 10;
            }
            while (add != 0) {
                curr.push_back(add % 10);
                add /= 10;
            }
            reverse(curr.begin(), curr.end());
            for (auto& c : curr) { // ��һ��һ��Ҫ�У���Ϊ֮ǰ����cur�Ķ��ǣ�-'0'��֮���ASCIIֵ������Ҫ��+'0'������ַ�
                c += '0';
            }
            ans = addStrings(ans, curr);
        }
        return ans;
    }
    // �ַ������
    string addStrings(string& num1, string& num2) {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string ans;
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            int result = x + y + add;
            ans.push_back(result % 10);
            add = result / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        for (auto& c : ans) {
            c += '0';
        }
        return ans;
    }
};

// ���ߣ�LeetCode-Solution
// ���ӣ�https://leetcode-cn.com/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/
// ��Դ�����ۣ�LeetCode��
// ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
int main() {
    string s1 = "15", s2 = "200";
    string res = Solution().multiply(s1, s2);
    cout << "�������= " << res << endl;
	cout << "Hello , Dear LZS !";
	system("pause");
	system("cls");
	return 0;
}
