#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	int getMoneymount(int n) {
		if (n == 1) {
			return 0;
		}

		//定义状态二维数组（n+1）x（n+1）
		//int dp[n+1][n+1];
		//vector<vector<int>> dp;数组为空，初始化时会发生越界
		vector<vector<int>> dp(n+1,vector<int>(n+1));
		//初始化数组
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j] = INT_MAX;
			}
		}
		//定义基础值dp[i][i] = 0；
		for (int i = 0; i <= n; i++) {
			dp[i][i] = 0;
		}
		//用一个位置左边和下边地数据来计算它本身
		//按照来，从第2列开始
		for (int j = 2; j <= n; j++) {
			//按行，从下往上
			for (int i = j - 1; i >= 1; i--) {//若，i >= j, dp[0][0] = 0 ,所以不管这种情况，用不到; i = j - 1保证i<j
				//算除了两端i和j，的每一个分割点
				for (int k = i + 1; k <= j - 1; k++) {
					dp[i][j] = min(k + max(dp[i][k - 1], dp[k + 1][j]), dp[i][j]);
				}
				//算两端
				dp[i][j] = min(dp[i][j], i + dp[i + 1][j]);
				dp[i][j] = min(j + dp[i][j - 1], dp[i][j]);
			}
		}
		return dp[1][n];
	}
};

int main() {
	int ntest = 3;
	cout << Solution().getMoneymount(ntest) << endl;

	cout << "Hello , Dear LZS !";
	system("pause");
	system("cls");
	return 0;
}
