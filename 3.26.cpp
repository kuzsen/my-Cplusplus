#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
	int n, k; // 5, 3
	cin >> n >> k;
	// vector<int> nums = { 1, 1, 3 ,2, 1 };
	// vector<int> nums = { 3, 3, 1, 3, 1, 1, 2 ,3, 2 ,2 ,2, 2, 3, 3, 3, 3, 1 };
	// vector<int> nums = { 1, 1, 3, 2, 1};
	vector<int> nums = { 1, 1 };
	int res = 0;
	int win = 0;
	int t = 0;
	unordered_map<int, int> score;
	while (win == 0)
	{
		for (int i = 0; i < n; i++) {
			res++;
			if (!score.count(nums[i])) {
				score.clear();
				score[nums[i]]++;
			}
			else {
				score[nums[i]]++;
				if (score[nums[i]] == k) {
					win = nums[i];
					break;
				}
			}
		}
		// ÿ����һ��nums�󣬱Ƚ�score�������һ��nums�����������score���Ƿ��б仯�����û�У�break��cout << "INF";
	}
	
	if (win == 0) {
		cout << "INF";
	}
	else {
		cout << res << " " << win;
	}
	system("pause");
	system("cls");
	return 0;
}