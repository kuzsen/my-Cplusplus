#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // ˼·��̰�ģ���������Ҫ���ַ��������ܵس������Ծ�����ѡ����������ַ���
        string res;
        vector<pair<int, char>> cnt = { {a, 'a'}, {b, 'b'}, {c, 'c'} };

        // ���ѡ���ַ�
        while (1) {
            // ÿ��ѡ��Ҫ���°���ʣ���ַ������Ӵ�С����,��ʣ�������ַ���ʼ�жϱ���ѡ��
            sort(cnt.begin(), cnt.end(), [](const auto& p1, const pair<int, char>& p2) {
                return p1.first > p2.first;
                });

            bool flag = false; // ���ñ����Ƿ�ѡ��ĳ�ַ��������ж��Ƿ���Ϊfalse������ǣ�˵������δѡ����һ�ַ���res�Ѿ��ﵽ�
            // ������ͬ���ַ��������ڣ�
            for (pair<int, char>& cn : cnt) { // ��ǰ�ַ�chʣ��ĸ���num
                int n = res.size();
                if (cn.first <= 0) continue; // �ַ�ch�Ѿ�û��ʣ����
                // ������ϵ�ǰ�ַ�ch���Ѿ��������������ַ���ͬ�����ж�ѡ����һ���ַ�
                if (n >= 2 && res[n - 1] == cn.second && res[n - 2] == cn.second) continue; // �Ƚϵ�ǰ�ַ���res���������ַ��Ƿ����
                res.push_back(cn.second); // ���ˣ�ѡ��ǰ�ַ���ʣ���ַ�����������Ҫ���������ˣ��˳�forѭ����break
                flag = true; // ����ѡ���ַ�ch
                cn.first--; // ��ǰ�ַ�ch��������һ�����÷�ʽ����num     
                break;
            }

            if (flag == false) break;
        }
        return res;
    }
};
int main()
{
    string test = Solution().longestDiverseString(1, 1, 7);
    cout << test << endl;
	system("pause");
	system("cls");
	return 0;
}
