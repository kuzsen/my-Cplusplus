#include<iostream>
using namespace std;
#include <vector>
#include <map>
const int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} }; // 8������
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<vector<int>> grid(n, vector<int>(n, 0)); // grid[x][y]��λ�ñ������Ĵ���
        // unordered_map<vector<int>, int> open; // ����Ч�ʸߣ���ʼ�����ɹ���unordered_set��unordered_map�����϶���ʹ��hash������Ԫ�ؽ��д洢�Ͳ��ң���C++û��Ϊvector�����Ĭ��hash���������޷�ͨ������
        map<vector<int>, int> open;
        for (auto& lamp : lamps) {
            open[lamp]++;
            int x = lamp[0], y = lamp[1];
            grid[x][y]++; // ��������
            for (int i = 0; i < n; i++) {
                if (i != lamp[0]) grid[i][lamp[1]]++; // ������
                if (i != lamp[1]) grid[lamp[0]][i]++; // ������
                // ������������Խ���
                if (i != 0) { // ��ȥ�Լ�
                    if (x + i < n && y + i < n) grid[x + i][y + i]++; // ����
                    if (x - i >= 0 && y - i >= 0) grid[x - i][y - i]++; // ����
                    if (x - i >= 0 && y + i < n) grid[x - i][y + i]++; // ����
                    if (x + i < n && y - i >= 0) grid[x + i][y - i]++; // ����
                }
            }
        }
        vector<int> res;
        for (auto& query : queries) {
            int x = query[0], y = query[1]; // ��ǰ��ѯ��
            if (grid[x][y] == 0) res.push_back(0);
            else res.push_back(1);
            // ��ѯ�󣬹رյ�ǰ��Ԫ������8�������ϵ��κε�
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
        grid[x][y]--; // Ϩ������
        for (int i = 0; i < n; i++) {
            if (i != lamp[0]) grid[i][lamp[1]]--; // ������
            if (i != lamp[1]) grid[lamp[0]][i]--; // ������
            // ������������Խ���
            if (i != 0) { // ��ȥ�Լ�
                if (x + i < n && y + i < n) grid[x + i][y + i]--; // ����
                if (x - i >= 0 && y - i >= 0) grid[x - i][y - i]--; // ����
                if (x - i >= 0 && y + i < n) grid[x - i][y + i]--; // ����
                if (x + i < n && y - i >= 0) grid[x + i][y - i]--; // ����
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
