#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
// #include <utility>
// ����nԪ��һƿ��ˮ2Ԫ��������ˮƿ��һƿ��ˮ���ĸ�ƿ�ǻ�һƿ��ˮ�������ȼ�ƿ
class solution {
public:
	int maxDrink(int n) {
		int res = 0, bottle = 0, cap = 0; // �����ƿ�ӣ�ƿ��
		int thistimeDrink = n / 2;
		while (thistimeDrink > 0) 
		{
			res += thistimeDrink;
			bottle += thistimeDrink;
			cap = thistimeDrink;
			thistimeDrink = bottle / 2 + cap / 4;
			bottle %= 2;
			cap %= 4;
		}
		return res;
	}
};

// ����һ����target��һ������nums������nums�����е��������ظ�ʹ�ã����������С��target����
// �磺 target 123451235 �� nums = [1, 2, 3, 7]
// ���䣺nums[i]��һ���Ǹ�λ������25��1654
// ans = 1233777777
// ����˼·�����ݣ�ÿ��ѡȡnums[i]����res���ϴ���nums[i]����С10���ݣ��ټ���nums[i],
// ���統ǰres = 25�� ��һ��ѡȡ26��ƴ�ӹ��̣�25*100 + 26 = 2526
class solution2 {
public:
	int res = 0;
	void backTracing(vector<int>& nums, int target, int path) {
		if (path >= target) return;
		else {
			res = max(res, path);
		}
		int tentime;
		for (auto& num : nums) {
			tentime = getTimes(num);
			path *= tentime;
			path += num;
			backTracing(nums, target, path);
			// path -= num; // ��ʵ��һ������ʡ�ԣ���Ϊnum < tentime, ����һ��Ϊ����ȡ��
			path /= tentime;
		}
	}
	int getTimes(int num) { // ע��nums[i]��Ϊ0
		int maxten = 1;
		while (num > 0) 
		{
			maxten *= 10;
			num /= 10;
		}
		return maxten;
	}
	int find(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int path = 0;
		backTracing(nums, target, path);
		return res;
	}


};
int main()
{	
	//int n; // 8
	//cin >> n;
	//int res = solution().maxDrink(n);
	//cout << res << endl; // 4+2+1+1+1

	vector<int> nums = { 1, 2, 3, 7 };
	int target = 123451235;
	int res2 = solution2().find(nums, target);
	cout << res2 << endl; // 1233777777
	system("pause");
	system("cls");
	return 0;
}
