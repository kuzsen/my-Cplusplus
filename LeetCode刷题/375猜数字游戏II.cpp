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

		//����״̬��ά���飨n+1��x��n+1��
		//int dp[n+1][n+1];
		//vector<vector<int>> dp;����Ϊ�գ���ʼ��ʱ�ᷢ��Խ��
		vector<vector<int>> dp(n+1,vector<int>(n+1));
		//��ʼ������
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j] = INT_MAX;
			}
		}
		//�������ֵdp[i][i] = 0��
		for (int i = 0; i <= n; i++) {
			dp[i][i] = 0;
		}
		//��һ��λ����ߺ��±ߵ�����������������
		//���������ӵ�2�п�ʼ
		for (int j = 2; j <= n; j++) {
			//���У���������
			for (int i = j - 1; i >= 1; i--) {//����i >= j, dp[0][0] = 0 ,���Բ�������������ò���; i = j - 1��֤i<j
				//���������i��j����ÿһ���ָ��
				for (int k = i + 1; k <= j - 1; k++) {
					dp[i][j] = min(k + max(dp[i][k - 1], dp[k + 1][j]), dp[i][j]);
				}
				//������
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
