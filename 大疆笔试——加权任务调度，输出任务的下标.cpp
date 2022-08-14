#include <iostream>
#include <vector>
using namespace std;
// 与leetcode 1235 类似，只不过要输出任务下标集合
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> tasks(n + 1, vector<int>(3, 0)); // n个任务，tasks[i][0]表示任务i的权重，tasks[i][1]该任务起始时间，tasks[i][2]结束时间
	int profile,start, end;
	int maxEnd = 0;
	for (int i = 1; i <= n; i++) {
		cin >> profile >> start >> end;
		tasks[i][0] = profile;
		tasks[i][1] = start;
		tasks[i][2] = end;
		maxEnd = max(maxEnd, end);
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(maxEnd + 1, 0)); // dp[i][j]表示选取第i个任务，以时刻j作为结尾时的最大权重和
	for (int i = 1; i <= n; i++) { // 遍历每一个任务
		for (int j = 0; j <= maxEnd; j++) { // 再在i的前提下，从0遍历到最大截至时间
			if (j >= tasks[i][2]) { // 如果j大于当前任务的截至时间
				// 此处是典型的动态规划————01背包问题，选或者不选，选其中最大/小的
				dp[i][j] = max(dp[i - 1][j], dp[i][tasks[i][1]] + tasks[i][0]); // 判断是否选取当前i，如果选取i，截至时间为当前任务的起始时间dp[i][tasks[i][1]] 加上 当前任务的权重
			}
			else {
				dp[i][j] = dp[i - 1][j]; // 当前任务i在j时刻不选取
			}
		}
	}
	int j = maxEnd; // 从最后的截至时间开始找，即使最后一个选取任务的截至时间j小于maxEnd，那么它作为最后一个任务，再往后遍历dp[i][j] 等于 dp[i][maxEnd]
	vector<int> res; // 选取最大权重和的下标集合
	for (int i = n; i >= 1; i--) {
		if (dp[i][j] != dp[i - 1][j]) { // 说明当前i选区了，如果不相等，说明dp[i][j]一定大于dp[i - 1][j]，原因是前面的动态转移方程
			res.push_back(i - 1);
			j = tasks[i][1]; // 截至时间更新为当前选区任务的起始时间
		}
	}
	reverse(res.begin(), res.end()); // 翻转任务下标，从最先开始执行的开始

	system("pause");
	system("cls");
	return 0;
}
