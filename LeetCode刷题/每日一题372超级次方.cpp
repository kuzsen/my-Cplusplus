#include<iostream>
#include<vector>
using namespace std;
//
//作者：AC_OIer
//链接：https ://leetcode-cn.com/problems/super-pow/solution/gong-shui-san-xie-di-gui-kuai-su-mi-ying-yx1j/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
    int MOD = 1337;
public:
    int superPow(int a, vector<int>& b) {
        return dfs(a, b, b.size() - 1);
    }
    int dfs(int a, vector<int>& b, int u) {
        if (u == -1) return 1;
        return pow(dfs(a, b, u - 1), 10) * pow(a, b[u]) % MOD;////pow(dfs(a, b, u - 1), 10)表示a^(b/10)   pow(a, b[u])表示a^(b%10)
    }
    int pow(int a, int b) {//求a^b,a累乘b次法
        int ans = 1;
        a %= MOD;////防止底数a本身就大于1337
        while (b-- > 0) ans = ans * a % MOD;////防止a在取a^b次幂过程中大于1337
        return ans;
    }
    int qpow(int a, int b) {//求a^b,快速降幂法,若b=3=0011
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

//递归+快速幂
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

    int qpow(int a, int b) {//求a^b,快速降幂法,若b=3=0011
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
