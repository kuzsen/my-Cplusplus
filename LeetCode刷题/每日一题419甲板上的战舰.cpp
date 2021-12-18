class Solution {
public:
    // 自己画张图，更容易理解，很简单，遍历起点就可以了
    int countBattleships(vector<vector<char>>& board) {
        // 一个战舰可能有多个连续的X组成，当board[i][j] = ‘X’时，判断其左边和上边，都不为'X'，才是一条战舰
        int m = board.size(), n = board[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.')) { // 上方是空位或边界
                    res++;
                }
            }
        }
        return res;
    }
};