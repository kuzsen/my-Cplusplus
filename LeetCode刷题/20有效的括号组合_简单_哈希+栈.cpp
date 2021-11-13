//https://leetcode-cn.com/problems/valid-parentheses/
/*
���룺s = "([)]"
�����false

���룺s = "{[]}"
�����true
s �������� '()[]{}' ���
*/
#include<iostream>
#include<stack>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    unordered_map<char, char> pair = {//��ϣ��ļ�Ϊ�����ţ�ֵΪ��ͬ���͵������š�
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
            if (pair.count(c)) {//cΪ������ʱ���ж����������ջ��ջ��Ԫ���Ƿ�ƥ��
            //����unordered_map������洢�����ظ�����Ԫ�أ����count()���������ϼ��unordered_map���Ƿ���ھ��и�������Ԫ�ء�,���Map�д��ھ��и�������ֵ����˺�������1�����򷵻�0��
                if (lefttemp.size() == 0 || lefttemp.top() != pair[c]) {//���������ջΪ�գ��޷����ʱ��������cƥ�䣻����������ջ��ջ��Ԫ�����ʱ��c����ͬһ�����ͣ�Ҳ�޷�ƥ��
                    return false;
                }
                else {
                    lefttemp.pop();//��ʱc��������ջ����������ͬһ�����ͣ�ƥ��ɹ�������ջ����������ȥ��
                }
            }
            else {//cΪ������
                lefttemp.push(c);//��������������Ҫ�ȱպϣ�������ǿ��Խ���������ŷ���ջ��
            }
        }
        return lefttemp.empty();//������ջΪ�գ�˵��һһƥ��ɹ�������1
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
