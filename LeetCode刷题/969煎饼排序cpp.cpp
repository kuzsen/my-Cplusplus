#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> rightSort = arr;
        sort(rightSort.begin(), rightSort.end());
        vector<int> res; // 存储k
        int n = arr.size(), numBig = 0; // 第numBig+1大值
        while (arr != rightSort) {
            // while (numBig <= n - 1) {
                // 找到最大值所在的位置
                // vector<int> :: iterator biggest = max_element(begin(arr), arr.end()); // 返回值是迭代器位置
                // 返回最大值索引
            int curMaxIndex = (int)(std::max_element(arr.begin(), arr.end() - numBig) - arr.begin());
            if (curMaxIndex != n - 1 - numBig) { // 当前最大值不在相对末尾
                if (curMaxIndex != 0) {
                    // reverse(arr.begin(), arr.begin() + curMaxIndex); // 先放到头部
                    reverse(arr.begin(), arr.begin() + curMaxIndex + 1); // 反转前curMaxIndex + 1个元素
                    // res.push_back(curMaxIndex); 
                    res.push_back(curMaxIndex + 1); // k - 1
                }
                reverse(arr.begin(), arr.end() - numBig); // 再把当前最大值放在相对末尾
                res.push_back(n - 1 - numBig + 1);
            }
            // else continue; // 如果已经在正确位置上，则继续
            numBig++; // 在0-（n-1-numbig）更小的区间中找第numBig+1大值            
        }
        return res;
    }
};
int main()
{
    vector<int> test = { 3,2,4,1 };
    vector<int> res = Solution().pancakeSort(test);

	system("pause");
	system("cls");
	return 0;
}
