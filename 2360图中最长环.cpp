#include<iostream>
#include <vector>
#include <unordered_map>
// https://leetcode.cn/problems/longest-cycle-in-a-graph/
// ����vector�ϴ�ʱ���÷����ᳬʱ
using namespace std;
class Solution {
public:
    int longestCycle(vector<int>& e) { // e��ʾedges
        int n = e.size();
        vector<bool> used(n, false); // ���ڱ��ĳ�ڵ��Ƿ���һ���������ڣ�����ڵ㲻����forѭ����Ѱ��һ����ͬ�Ļ� 
        int res = -1;
        for (int i = 0; i < n; i++) {
            if (used[i]) continue; // used[i],��ǰi�Ѿ�������֮ǰ�Ļ���, ������ǰi
            // �ж���iΪ����Ƿ����γɻ�
            unordered_map<int, int> path;
            int d = 0;
            path[i] = 0;
            int start = i;
            while (e[start] != -1 && path.count(e[start]) == 0) { // �ߵ���β����������
                d++;
                path[e[start]] = d;
                start = e[start];
            }
            if (e[start] == -1) continue; // û�л�
            if (e[start] != i) continue; // �γɵĻ�������startΪ���
            if (e[start] == i) { // �����Ե�ǰiΪ���Ļ�
                res = max(res, d + 1); // ����res
                // �Ե�ǰiΪ���Ļ��ĳ��ȣ����ڣ��û��ڣ���������һ�ڵ㣬Ϊ���Ļ��ĳ��ȣ�����������Ľڵ㲻���ٴ�ͷѰ��һ���ˣ�ʹ��vector������һ�¼���
                for (unordered_map<int, int>::iterator it = path.begin(); it != path.end(); it++) {
                    used[it->first] = true;
                }

                if (res == n) break; // ��ǰ�жϴﵽ�������ֵ��break
            }
        }
        return res;
    }
};
int main()
{
    vector<int> edges = { 1,2,0,4,5,6,3,8,9,7 };
    cout << Solution().longestCycle(edges) << endl; 

	system("pause");
	system("cls");
	return 0;
}
