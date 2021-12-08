#include<iostream>
#include<vector>
using namespace std;
//
//���ߣ�AC_OIer
//���ӣ�https ://leetcode-cn.com/problems/super-pow/solution/gong-shui-san-xie-di-gui-kuai-su-mi-ying-yx1j/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
class Solution {
    int MOD = 1337;
public:
    int superPow(int a, vector<int>& b) {
        return dfs(a, b, b.size() - 1);
    }
    int dfs(int a, vector<int>& b, int u) {
        if (u == -1) return 1;
        return pow(dfs(a, b, u - 1), 10) * pow(a, b[u]) % MOD;////pow(dfs(a, b, u - 1), 10)��ʾa^(b/10)   pow(a, b[u])��ʾa^(b%10)
    }
    int pow(int a, int b) {//��a^b,a�۳�b�η�
        int ans = 1;
        a %= MOD;////��ֹ����a����ʹ���1337
        while (b-- > 0) ans = ans * a % MOD;////��ֹa��ȡa^b���ݹ����д���1337
        return ans;
    }
    int qpow(int a, int b) {//��a^b,���ٽ��ݷ�,��b=3=0011
        int ans = 1;
        a %= MOD;
        while (b != 0) {
            if ((b & 1) != 0)
            {
                ans = ans * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }
};

//�ݹ�+������
class Solution2 {
public:
    int superPow(int a, vector<int>& b) {
        a %= 1337; int n = b.size();
        if (a == 0 || a == 1)    return a;
        if (n == 0)     return 1;
        int r = qpow(a, b[n - 1]);
        b.pop_back();
        int l = pow(superPow(a, b), 10);
        return (l * r) % 1337;
    }

    int qpow(int a, int b) {//��a^b,���ٽ��ݷ�,��b=3=0011
        int ans = 1;
        while (b != 0) {
            if ((b & 1) != 0)
            {
                ans = ans * a % 1337;
            }
            a = a * a % 1337;
            b >>= 1;
        }
        return ans;
    }
};
int main()
{
    /*int a = 99;
    vector<int> b = { 2,3,4,5 };*/
    int a = 2;
    vector<int> b = {1,0};
    int res = 0;
    res = Solution().superPow(a, b);
    //res = Solution().superPow(a, b);
    cout << res;

	system("pause");
	system("cls");
	return 0;
}
