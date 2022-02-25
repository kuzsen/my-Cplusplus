// https://mp.weixin.qq.com/s/ilOdw4qdu_EJZNXvybqdag
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	vector<int> find(vector<int> nums) { 
		int n = nums.size();
		vector<int> res;
		vector<int> left_max(n, INT_MIN);
		vector<int> right_min(n, INT_MAX);
		/*从左到右找每个元素左边最大值，从右到左找每个元素右边最大值，再看元素是否被夹在中间～*/
		for (int i = 1; i < n; i++) {
			left_max[i] = max(left_max[i - 1], nums[i - 1]); 
		}
		for (int i = n - 2; i >= 0; i--) {
			right_min[i] = min(right_min[i + 1], nums[i + 1]);
		}
		for (int i = 0; i < n; i++) {
			if (left_max[i] < nums[i] && nums[i] < right_min[i]) {
				res.push_back(i);
			}
		}
		return res;
	}
	vector<int> find2(vector<int> nums) { // 单调栈法
	/*记录左侧最大值，遍历数组，
	如果num[i]大于左侧最大值，更新最大值且把当前index压栈，
	如果num[i]比栈顶小，则出栈，直到栈空，i++进入下次循环*/
		int n = nums.size();
		vector<int> res;
		stack<int> sta;
		int left_max = INT_MIN;
		for (int i = 0; i < n; i++) {
			while (!sta.empty() && nums[i] < nums[sta.top()]) {
				sta.pop();
				// left_max = max(nums[i], nums[sta.top()]);
			}
			if (nums[i] > left_max) {
				left_max = nums[i];
				sta.push(i);
			}
		}
		while (!sta.empty()) {
			res.push_back(sta.top());
			sta.pop();
		}
		return res;
	}
};


int main()
{
	// vector<int> arr = { 2,3,1,8,9,20,12 };
	vector<int> arr2 = { 2,3,1,8,9,20,12,30,51,55 };
	// auto res = Solution().find(arr); // {3,4}
	auto res = Solution().find(arr2); // {3, 4, 7, 8, 9}
	// auto res = Solution().find2(arr2); // {9,8,7,4,3}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	system("pause");
	system("cls");
	return 0;
}
