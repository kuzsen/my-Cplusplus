#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //DFS+记忆化搜索https://leetcode-cn.com/problems/loud-and-rich/solution///wei-rao-li-lun-dfsji-yi-hua-sou-suo-ying-xukd/

    vector<vector<int>> g;//题目给的0 <= ai, bi < n
    vector<int> res;
    vector<int> q;

    /*找出所有比某个人富有的人
    找出其中最安静的人*/
    int dfs(int i) {
        if (res[i] != -1) return res[i];//说明person编号为i的这个的结果已经计算过了
        res[i] = i;//自己拥有的钱肯定不少于自己的。先记录下，接下来查找有没有比自己的钱更多的，同时找出其中最安静的人
        for (auto& j : g[i]) {//g[i]是一个vector，里面记录的是比自己有钱的人的编号
            dfs(j);//进行深度优先遍历
            if (q[res[j]] < q[res[i]]) {//找出其中最安静的人
                res[i] = res[j];
            }
        }
        return res[i];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();//person的个数

        q = quiet;

        //vector<vector<int>> g(n);//题目给的0 <= ai, bi < n
        g = vector<vector<int>>(n);//题目给的0 <= ai, bi < n
        for (auto& r : richer) {
            //r[0]这个人 比 r[1]这个人  富有
            g[r[1]].emplace_back(r[0]);//记录所有比r[1]这个人，更富有的人r[0]
        }

        //vector<int> res(n, -1);//第一个参数表示某个人person[i]，第二个参数表示所有比person[i]富有的人中最安静的人的编号
        res = vector<int>(n, -1);
        for (int i = 0; i < n; ++i) {//遍历每个person,他的编号为i
            dfs(i);
        }
        return res;
    }
};
int main() {

	cout << "Hello , Dear LZS !";
	system("pause");
	system("cls");
	return 0;
}
