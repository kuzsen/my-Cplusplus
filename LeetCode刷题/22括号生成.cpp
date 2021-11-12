/*
���� n �����������ŵĶ������������һ�������������ܹ��������п��ܵĲ��� ��Ч�� ������ϡ�1 <= n <= 8
���룺n = 3
�����["((()))","(()())","(())()","()(())","()()()"]

https://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode-solution/
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
����һ��������
˼·

���ǿ����������� 2^2n  �� '(' �� ')' �ַ����ɵ����У�Ȼ�����Ǽ��ÿһ���Ƿ���Ч���ɡ�

�㷨

Ϊ�������������У����ǿ���ʹ�õݹ顣����Ϊ n �����о����ڳ���Ϊ n-1 ������ǰ��һ�� '(' �� ')'��

Ϊ�˼�������Ƿ���Ч�����Ǳ���������У���ʹ��һ������ balance ��ʾ�����ŵ�������ȥ�����ŵ�����������ڱ��������� balance ��ֵС���㣬���߽���ʱ balance ��ֵ��Ϊ�㣬��ô�����о�����Ч�ģ�����������Ч�ġ�

���ӣ�https://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode-solution/

*/
class Solution1 {
public:
	bool isvalid_cur(const string& str) {
		int balance = 0;//��ʾ�����ŵĸ���-�����ŵĸ���
		for (auto c : str) {
			if (c == '(') {
				balance++;
			}
			if (c == ')') {
				balance--;
			}
			if (balance < 0) {//����())(������������������Ч�������
				return false;
			}
		}
		return balance == 0;//balance=0,����Ч
	}
	void generateAll(string& cur, int len, vector<string>&res) {//vector<string>&res,����Ҫ�����õķ�ʽ����res����ʱ�β�res��������ʵ��result�ı�������res��������ͬ��result���Բ�����
		//cur����һ��������������ɵ��ַ�����len�������������ַ����ĳ���Ϊ2n
		if (len == cur.size()) {
			if (isvalid_cur(cur)) {
				res.push_back(cur);
			}
			return;
		}
		cur += '(';
		generateAll(cur, len, res);
		cur.pop_back();
		cur += ')';
		generateAll(cur, len, res);
		cur.pop_back();
	}
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		string current;
		generateAll(current, n * 2, result);

		return result;
	}
};
/*
�����������ݷ�����--�����������߽� �����������dfs  
˼·���㷨

����һ���иĽ�����أ����ǿ���ֻ��������Ȼ������Чʱ����� '(' or ')'���������� ����һ ����ÿ����ӡ����ǿ���ͨ�����ٵ�ĿǰΪֹ���õ������ź������ŵ���Ŀ��������һ�㣬

������������������� n�����ǿ��Է�һ�������š��������������С�������ŵ����������ǿ��Է�һ��������
*/
class Solution2 {
	void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {//���ݺ���  ����  �����������dfs ����
		//if (cur.size() == n * 2) {//  Ҳ����
		if(open == n && close == n){
			ans.push_back(cur);
			return;
		}
		if (open < n) {
			cur.push_back('(');
			backtrack(ans, cur, open + 1, close, n);
			cur.pop_back();
		}
		if (close < open) {
			cur.push_back(')');
			backtrack(ans, cur, open, close + 1, n);
			cur.pop_back();
		}
	}
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		string current;
		backtrack(result, current, 0, 0, n);
		return result;
	}
};

int main() {
	vector<string> test;
	//test = Solution1().generateParenthesis(2);//����ʹ��F11��F10���������������
	test = Solution2().generateParenthesis(2);
	for (int i = 0; i < test.size(); i++) {
		/*for (int j = 0; j < 2 * 2; j++) {
			cout << test[i][j];
		}*/
		cout << test[i].substr(0, 2 * 2) << endl;
		
	}
	cout << "Hello , ear LZS !";
	system("pause");
	system("cls");
	return 0;
}
