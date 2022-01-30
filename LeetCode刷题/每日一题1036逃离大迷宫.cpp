#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<map>
class Solution {
public:
    // unordered_map<pair<int,int>, int> block;
    map<pair<int, int>, int> block;
    vector<int> newPositon;
    vector<int> dirX;
    vector<int> dirY;
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for (auto b : blocked) {
            // block[b]++;
            // block[make_pair(b[0], b[1])]++;
            block.insert(make_pair(make_pair(b[0], b[1]), 1));
        }
        newPositon = vector<int>(2, 0);
        // 定义上下左右移动
        // vector<pair<int, int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        dirX = { -1,1,0,0 };
        dirY = { 0,0,-1,1 };
        return dfs(source, target);

    }
    bool dfs(vector<int> source, vector<int>& target) {
        if (source[0] == target[0] && source[1] == target[1]) return true;
        //bool resFlag = false;
        for (int i = 0; i < 4; i++) {
            newPositon[0] = source[0] + dirX[i], newPositon[1] = source[1] + dirY[i];
            if ((i == 0 && source[0] == 0) ||
                (i == 1 && source[0] == 1e6 - 1) ||
                (i == 2 && source[1] == 0) ||
                (i == 3 && source[1] == 1e6 - 1) ||
                //block.count(newPositon)) continue;
                block.count(make_pair(newPositon[0], newPositon[1]))) {
                continue;
            }
            //resFlag = dfs(newPositon);
            if (dfs(newPositon, target)) return true;
        }
        return false;
    }
};
int main()
{
    vector<vector<int>> blocked = { {0,1},{1,0} };
    vector<int> source = {0, 0};
    vector<int> target = {0, 2};
    bool test = Solution().isEscapePossible(blocked, source, target);
    cout << test << endl; // true 

	system("pause");
	system("cls");
	return 0;
}
