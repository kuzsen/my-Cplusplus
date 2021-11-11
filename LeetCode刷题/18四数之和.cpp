//https://leetcode-cn.com/problems/4sum/solution/shuang-zhi-zhen-jie-fa-can-zhao-san-shu-zhi-he-ge-/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;//�����ظ�
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;//�����ظ�
                }
                int k = j + 1;
                int w = n - 1;
                while (k < w) {
                    if (nums[i] + nums[j] == target - nums[k] - nums[w]) {
                        res.push_back({ nums[i],nums[j],nums[k],nums[w] });
                        k++;//�ɹ��б�һ��󣬼����ƽ��м�
                        while (k < w && nums[k] == nums[k - 1]) {
                            k++;
                        }
                        w--;
                        while (k < w && nums[w] == nums[w + 1]) {
                            w--;//�ɹ��б�һ��󣬼����ƽ��м�
                        }
                    }
                    else if (nums[i] + nums[j] < target - nums[k] - nums[w]) {
                        k++;
                    }
                    else {
                        w--;
                    }
                }
            }
        }
        return res;
    }
};
int main() {

    vector<int>test = { 1,0,-1,0,-2,2 };
    int targrtnum = 0;
    vector<vector<int>> result;
    result = Solution().fourSum(test, targrtnum);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << ",";
        }
        cout << endl;
    }
       
	system("pause");
	system("cls");
	return 0;
}
