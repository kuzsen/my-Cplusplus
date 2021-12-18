class Solution {
public:
    // �Լ�����ͼ����������⣬�ܼ򵥣��������Ϳ�����
    int countBattleships(vector<vector<char>>& board) {
        // һ��ս�������ж��������X��ɣ���board[i][j] = ��X��ʱ���ж�����ߺ��ϱߣ�����Ϊ'X'������һ��ս��
        int m = board.size(), n = board[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.')) { // �Ϸ��ǿ�λ��߽�
                    res++;
                }
            }
        }
        return res;
    }
};