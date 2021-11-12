/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。1 <= n <= 8
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]

https://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode-solution/
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
方法一：暴力法
思路

我们可以生成所有 2^2n  个 '(' 和 ')' 字符构成的序列，然后我们检查每一个是否有效即可。

算法

为了生成所有序列，我们可以使用递归。长度为 n 的序列就是在长度为 n-1 的序列前加一个 '(' 或 ')'。

为了检查序列是否有效，我们遍历这个序列，并使用一个变量 balance 表示左括号的数量减去右括号的数量。如果在遍历过程中 balance 的值小于零，或者结束时 balance 的值不为零，那么该序列就是无效的，否则它是有效的。

链接：https://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode-solution/

*/
class Solution1 {
public:
	bool isvalid_cur(const string& str) {
		int balance = 0;//表示左括号的个数-右括号的个数
		for (auto c : str) {
			if (c == '(') {
				balance++;
			}
			if (c == ')') {
				balance--;
			}
			if (balance < 0) {//例如())(————————无效括号组合
				return false;
			}
		}
		return balance == 0;//balance=0,则有效
	}
	void generateAll(string& cur, int len, vector<string>&res) {//vector<string>&res,必须要用引用的方式传递res，此时形参res是输出结果实参result的别名，对res操作就如同对result亲自操作，
		//cur代表一个由左右括号组成的字符串，len代表左右括号字符串的长度为2n
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
方法二：回溯法——--————或者叫 深度优先搜索dfs  
思路和算法

方法一还有改进的余地：我们可以只在序列仍然保持有效时才添加 '(' or ')'，而不是像 方法一 那样每次添加。我们可以通过跟踪到目前为止放置的左括号和右括号的数目来做到这一点，

如果左括号数量不大于 n，我们可以放一个左括号。如果右括号数量小于左括号的数量，我们可以放一个右括号
*/
class Solution2 {
	void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {//回溯函数  或者  深度优先搜索dfs 函数
		//if (cur.size() == n * 2) {//  也可以
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
	//test = Solution1().generateParenthesis(2);//可以使用F11，F10，监视器，逐步理解
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
