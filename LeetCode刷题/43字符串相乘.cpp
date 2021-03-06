#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//class Solution { ------------------------自己写的，不对
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
    //// 方法一：字符串相加 + 逐位乘法
    //string multiply(string num1, string num2) {
    //    if (num1 == "0" || num2 == "0") {
    //        return "0";
    //    }
    //    string ans = "0";
    //    int m = num1.size(), n = num2.size();
    //    // 逐位乘法
    //    for (int i = n - 1; i >= 0; i--) {
    //        string curr;
    //        int add = 0;
    //        for (int j = n - 1; j > i; j--) {
    //            curr.push_back(0);
    //        }
    //        int y = num2.at(i) - '0';
    //        for (int j = m - 1; j >= 0; j--) {
    //            int x = num1.at(j) - '0';
    //            int product = x * y + add;
    //            curr.push_back(product % 10);
    //            add = product / 10;
    //        }
    //        while (add != 0) {
    //            curr.push_back(add % 10);
    //            add /= 10;
    //        }
    //        reverse(curr.begin(), curr.end());
    //        for (auto& c : curr) { // 这一步一定要有，因为之前插入cur的都是（-'0'）之后的ASCII值，所以要（+'0'）变成字符
    //            c += '0';
    //        }
    //        ans = addStrings(ans, curr);
    //    }
    //    return ans;
    //}
    //// 字符串相加
    //string addStrings(string& num1, string& num2) {
    //    int i = num1.size() - 1, j = num2.size() - 1, add = 0;
    //    string ans;
    //    while (i >= 0 || j >= 0 || add != 0) {
    //        int x = i >= 0 ? num1.at(i) - '0' : 0;
    //        int y = j >= 0 ? num2.at(j) - '0' : 0;
    //        int result = x + y + add;
    //        ans.push_back(result % 10);
    //        add = result / 10;
    //        i--;
    //        j--;
    //    }
    //    reverse(ans.begin(), ans.end());
    //    for (auto& c : ans) {
    //        c += '0';
    //    }
    //    return ans;
    //}
    /*
     方法二：竖式乘法，容易理解，且空间时间复杂度都更好
 */
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size(), n = num2.size(); // 此创建长度为 m+n的数组ansArr 用于存储乘积
        auto ansArr = vector<int>(m + n); // 令 m 和 n 分别表示num1 和num2 的长度，并且它们均不为0，则 num1和num2的乘积的长度为 m+n-1或 m+n。

        for (int i = m - 1; i >= 0; i--) {
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2.at(j) - '0';
                ansArr[i + j + 1] += x * y;  // ansArr[i + j + 1] = num1[i] * num[j] 
            }
        }
        for (int i = m + n - 1; i > 0; i--) { // ansArr[i + j + 1] > 10,将10位加到上一位中去
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        int index = ansArr[0] == 0 ? 1 : 0; // ansArr[0]等于0，说明两数相乘只有m+n-1位，
        string ans;
        while (index < m + n) {
            ans.push_back(ansArr[index]); // 从index=1开始将数组中的数字插入到string ans中
            index++;
        }
        for (auto& c : ans) { // 将c由数值型转变为字符型
            c += '0';
        }
        return ans;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
int main() {
    string s1 = "15", s2 = "200";
    string res = Solution().multiply(s1, s2);
    cout << "两数相乘= " << res << endl;
	cout << "Hello , Dear LZS !";
	system("pause");
	system("cls");
	return 0;
}
