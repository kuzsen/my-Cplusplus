#include<iostream>
using namespace std;
#include<vector>
/*
https://leetcode-cn.com/problems/max-increase-to-keep-city-skyline/
贪心+模拟
*/
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        //贪心，看题解容易理解，不难
        int n = grid.size();
        vector<int> rowMax(n, 0);
        vector<int> colMax(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMax[i] = max(rowMax[i], grid[i][j]);//记录第i行的最大值
                colMax[j] = max(colMax[j], grid[i][j]);//更新第i行，j列对应的最大值
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res += min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }
        return res;
    }
};
int main()
{

	system("pause");
	system("cls");
	return 0;
}
