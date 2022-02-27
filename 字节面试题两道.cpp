#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
// #include <utility>
// 你有n元，一瓶汽水2元，两个汽水瓶换一瓶汽水，四个瓶盖换一瓶汽水，问最多喝几瓶
class solution {
public:
	int maxDrink(int n) {
		int res = 0, bottle = 0, cap = 0; // 结果，瓶子，瓶盖
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

// 给你一个数target，一个数组nums，求用nums数组中的数（可重复使用）构造出最大的小于target的数
// 如： target 123451235 ， nums = [1, 2, 3, 7]
// 补充：nums[i]不一定是个位数，如25，1654
// ans = 1233777777
// 解题思路：回溯，每次选取nums[i]，将res乘上大于nums[i]的最小10的幂，再加上nums[i],
// 比如当前res = 25， 下一次选取26，拼接过程：25*100 + 26 = 2526
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
			// path -= num; // 其实这一步可以省略，因为num < tentime, 且下一行为向下取整
			path /= tentime;
		}
	}
	int getTimes(int num) { // 注意nums[i]不为0
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
