#include<iostream>
using namespace std;
#include<vector>
/*
https://leetcode-cn.com/problems/max-increase-to-keep-city-skyline/
̰��+ģ��
*/
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        //̰�ģ������������⣬����
        int n = grid.size();
        vector<int> rowMax(n, 0);
        vector<int> colMax(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMax[i] = max(rowMax[i], grid[i][j]);//��¼��i�е����ֵ
                colMax[j] = max(colMax[j], grid[i][j]);//���µ�i�У�j�ж�Ӧ�����ֵ
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
