#include <iostream>
#include <vector>
using namespace std;
// ��leetcode 1235 ���ƣ�ֻ����Ҫ��������±꼯��
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> tasks(n + 1, vector<int>(3, 0)); // n������tasks[i][0]��ʾ����i��Ȩ�أ�tasks[i][1]��������ʼʱ�䣬tasks[i][2]����ʱ��
	int profile,start, end;
	int maxEnd = 0;
	for (int i = 1; i <= n; i++) {
		cin >> profile >> start >> end;
		tasks[i][0] = profile;
		tasks[i][1] = start;
		tasks[i][2] = end;
		maxEnd = max(maxEnd, end);
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(maxEnd + 1, 0)); // dp[i][j]��ʾѡȡ��i��������ʱ��j��Ϊ��βʱ�����Ȩ�غ�
	for (int i = 1; i <= n; i++) { // ����ÿһ������
		for (int j = 0; j <= maxEnd; j++) { // ����i��ǰ���£���0������������ʱ��
			if (j >= tasks[i][2]) { // ���j���ڵ�ǰ����Ľ���ʱ��
				// �˴��ǵ��͵Ķ�̬�滮��������01�������⣬ѡ���߲�ѡ��ѡ�������/С��
				dp[i][j] = max(dp[i - 1][j], dp[i][tasks[i][1]] + tasks[i][0]); // �ж��Ƿ�ѡȡ��ǰi�����ѡȡi������ʱ��Ϊ��ǰ�������ʼʱ��dp[i][tasks[i][1]] ���� ��ǰ�����Ȩ��
			}
			else {
				dp[i][j] = dp[i - 1][j]; // ��ǰ����i��jʱ�̲�ѡȡ
			}
		}
	}
	int j = maxEnd; // �����Ľ���ʱ�俪ʼ�ң���ʹ���һ��ѡȡ����Ľ���ʱ��jС��maxEnd����ô����Ϊ���һ���������������dp[i][j] ���� dp[i][maxEnd]
	vector<int> res; // ѡȡ���Ȩ�غ͵��±꼯��
	for (int i = n; i >= 1; i--) {
		if (dp[i][j] != dp[i - 1][j]) { // ˵����ǰiѡ���ˣ��������ȣ�˵��dp[i][j]һ������dp[i - 1][j]��ԭ����ǰ��Ķ�̬ת�Ʒ���
			res.push_back(i - 1);
			j = tasks[i][1]; // ����ʱ�����Ϊ��ǰѡ���������ʼʱ��
		}
	}
	reverse(res.begin(), res.end()); // ��ת�����±꣬�����ȿ�ʼִ�еĿ�ʼ

	system("pause");
	system("cls");
	return 0;
}
