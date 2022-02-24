// #include <bits/stdc++.h> // ����ͷ�ļ�
#include<iostream>
#include<set>
#include<vector>

using namespace std;
/*
��set����¼�����ߵĻ�����±꣬����pair��¼��ǰ������������cur��ÿ�������ж�ȡ���Ļ����Ƿ���pair�����ڣ��������ֱ������ǰ׺������������������ڣ�˵�����䱻��֣�����setȡ��������䣬��Ϊ����ĸ�����1������n�����Ը��Ӷ���0(nlogn)

���ߣ�??
���ӣ�https://leetcode-cn.com/leetbook/read/meituan/oh4ykh/?discussion=ZyF8w8
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

void maxWeight(vector<int>& w, vector<int> index) {
    int n = w.size();
    vector<int> preSum(n + 1); // ǰ׺��
    for (int i = 1; i <= n; i++) {
        preSum[i] = preSum[i - 1] + w[i - 1];
    }
    set<int> s; // ����Ѿ�ȡ�߻���ı��
    pair<int, int> cur = make_pair(0, n - 1);
    for (int i = 0; i < n; i++) { // ���ΰ���ȡ��˳��ȡ����Ӧ�Ļ���
        int ind = index[i] - 1;
        s.insert(ind); // �����Ѿ�ȡ���Ļ����ż�����
        if (ind >= cur.first && ind <= cur.second) {
            int curleft = 0;
            int curMax = 0;
            for (auto& right : s) {
                if (curMax < preSum[right] - preSum[curleft]) {
                    curMax = preSum[right] - preSum[curleft];
                    cur.first = curleft;
                    cur.second = right;
                }
                curleft = right + 1;
            }
            if (curMax < preSum[n] - preSum[curleft]) {
                curMax = preSum[n] - preSum[curleft];
                cur.first = curleft;
                cur.second = n;
            }
            cout << curMax << endl;
        }
        else {
            cout << preSum[cur.second] - preSum[cur.first] << endl;
        }
    }
}
int main() {
    int n; // ��������
    cin >> n; // 5
    vector<int> weight(n); // 3 2 4 4 5
    vector<int> index(n); // 4 3 5 2 1   �������1-n��ʵ���±�Ҫ��һ
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
        cin >> index[i];
    }
    maxWeight(weight, index);
    system("pause");
    system("cls");
    return 0;
}