#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //DFS+���仯����https://leetcode-cn.com/problems/loud-and-rich/solution///wei-rao-li-lun-dfsji-yi-hua-sou-suo-ying-xukd/

    vector<vector<int>> g;//��Ŀ����0 <= ai, bi < n
    vector<int> res;
    vector<int> q;

    /*�ҳ����б�ĳ���˸��е���
    �ҳ������������*/
    int dfs(int i) {
        if (res[i] != -1) return res[i];//˵��person���Ϊi������Ľ���Ѿ��������
        res[i] = i;//�Լ�ӵ�е�Ǯ�϶��������Լ��ġ��ȼ�¼�£�������������û�б��Լ���Ǯ����ģ�ͬʱ�ҳ������������
        for (auto& j : g[i]) {//g[i]��һ��vector�������¼���Ǳ��Լ���Ǯ���˵ı��
            dfs(j);//����������ȱ���
            if (q[res[j]] < q[res[i]]) {//�ҳ������������
                res[i] = res[j];
            }
        }
        return res[i];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();//person�ĸ���

        q = quiet;

        //vector<vector<int>> g(n);//��Ŀ����0 <= ai, bi < n
        g = vector<vector<int>>(n);//��Ŀ����0 <= ai, bi < n
        for (auto& r : richer) {
            //r[0]����� �� r[1]�����  ����
            g[r[1]].emplace_back(r[0]);//��¼���б�r[1]����ˣ������е���r[0]
        }

        //vector<int> res(n, -1);//��һ��������ʾĳ����person[i]���ڶ���������ʾ���б�person[i]���е�����������˵ı��
        res = vector<int>(n, -1);
        for (int i = 0; i < n; ++i) {//����ÿ��person,���ı��Ϊi
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
