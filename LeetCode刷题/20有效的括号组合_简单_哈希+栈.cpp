//https://leetcode-cn.com/problems/valid-parentheses/
/*
输入：s = "([)]"
输出：false

输入：s = "{[]}"
输出：true
s 仅由括号 '()[]{}' 组成
*/
#include<iostream>
#include<stack>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    unordered_map<char, char> pair = {//哈希表的键为右括号，值为相同类型的左括号。
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    bool isValid(string s) {
        stack<char> lefttemp;
        if ((s.size() % 2) == 1) {
            return false;
        }
        for (auto c : s) {
            if (pair.count(c)) {//c为右括号时，判断其和左括号栈的栈顶元素是否匹配
            //由于unordered_map不允许存储具有重复键的元素，因此count()函数本质上检查unordered_map中是否存在具有给定键的元素。,如果Map中存在具有给定键的值，则此函数返回1，否则返回0。
                if (lefttemp.size() == 0 || lefttemp.top() != pair[c]) {//如果左括号栈为空，无法与此时的右括号c匹配；或者左括号栈的栈顶元素与此时的c不是同一种类型，也无法匹配
                    return false;
                }
                else {
                    lefttemp.pop();//此时c与左括号栈顶左括号是同一种类型，匹配成功，并将栈顶的左括号去除
                }
            }
            else {//c为左括号
                lefttemp.push(c);//后遇到的左括号要先闭合，因此我们可以将这个左括号放入栈顶
            }
        }
        return lefttemp.empty();//左括号栈为空，说明一一匹配成功，返回1
    }
};
int main()
{
    string test = "(){}[]({)[}]";//0
    bool res;
    res = Solution().isValid(test);
    cout << res;

    system("pause");
    system("cls");
    return 0;
}
