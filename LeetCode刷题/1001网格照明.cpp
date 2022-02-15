#include<iostream>
using namespace std;
#include <vector>
#include <map>
const int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} }; // 8个方向
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<vector<int>> grid(n, vector<int>(n, 0)); // grid[x][y]该位置被照亮的次数
        // unordered_map<vector<int>, int> open; // 查找效率高，初始化不成功，unordered_set和unordered_map本质上都是使用hash方法对元素进行存储和查找，而C++没有为vector定义的默认hash方法，故无法通过编译
        map<vector<int>, int> open;
        for (auto& lamp : lamps) {
            open[lamp]++;
            int x = lamp[0], y = lamp[1];
            grid[x][y]++; // 照亮自身
            for (int i = 0; i < n; i++) {
                if (i != lamp[0]) grid[i][lamp[1]]++; // 照亮列
                if (i != lamp[1]) grid[lamp[0]][i]++; // 照亮行
                // 如何照亮两条对角线
                if (i != 0) { // 除去自己
                    if (x + i < n && y + i < n) grid[x + i][y + i]++; // 右下
                    if (x - i >= 0 && y - i >= 0) grid[x - i][y - i]++; // 左上
                    if (x - i >= 0 && y + i < n) grid[x - i][y + i]++; // 右上
                    if (x + i < n && y - i >= 0) grid[x + i][y - i]++; // 左下
                }
            }
        }
        vector<int> res;
        for (auto& query : queries) {
            int x = query[0], y = query[1]; // 当前查询点
            if (grid[x][y] == 0) res.push_back(0);
            else res.push_back(1);
            // 查询后，关闭当前单元格及相邻8个方向上的任何灯
            if (open.count(query) != 0) closeLamp(grid, query, open, n);
            for (int i = 0; i < 8; i++) {
                int newx = x + dir[i][0], newy = y + dir[i][1];
                if (newx >= 0 && newx < n && newy >= 0 && newy < n) {
                    vector<int> near = { newx, newy };
                    if (open.count(near) != 0) closeLamp(grid, near, open, n);
                }
            }
        }
        return res;
    }
    void closeLamp(vector<vector<int>>& grid, vector<int> lamp, map<vector<int>, int>& open, int n) {
        open[lamp]--;
        int x = lamp[0], y = lamp[1];
        grid[x][y]--; // 熄灭自身
        for (int i = 0; i < n; i++) {
            if (i != lamp[0]) grid[i][lamp[1]]--; // 照亮列
            if (i != lamp[1]) grid[lamp[0]][i]--; // 照亮行
            // 如何照亮两条对角线
            if (i != 0) { // 除去自己
                if (x + i < n && y + i < n) grid[x + i][y + i]--; // 右下
                if (x - i >= 0 && y - i >= 0) grid[x - i][y - i]--; // 左上
                if (x - i >= 0 && y + i < n) grid[x - i][y + i]--; // 右上
                if (x + i < n && y - i >= 0) grid[x + i][y - i]--; // 左下
            }
        }
    }
};
int main()
{
    int n = 5;
    vector<vector<int>> lamps = { {0,0},{4,4} };
    vector<vector<int>> queries = { {1,1},{0,0},{2,2} };
    vector<int> res = Solution().gridIllumination(n, lamps, queries);
    
	system("pause");
	system("cls");
	return 0;
}
