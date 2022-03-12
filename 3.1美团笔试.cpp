#include<iostream>
#include <vector>
using namespace std;

int main()
{
    //int n;
    //cin >> n;
    //vector<int> input(n);
    //for (int i = 0; i < n; i++) {
    //    int num;
    //    cin >> num;
    //    input[i] = num;
    //}
    //vector<int> dp(n); // dp[i]表示以input[i]结尾的连续的子序列，序列中的数字乘积为正
    //dp[0] = input[0] == 1 ? 1 : 0;
    //for (int i = 1; i < n; i++) {
    //    int s = input[i];
    //    dp[i] = s == 1 ? 1 : 0;
    //    for (int j = i - 1; j >= 0; j--) {
    //        s *= input[j];
    //        if (s > 0) dp[i]++;
    //        else break;
    //    }
    //}
    //int res = 0;
    //for (int i = 0; i < n; i++) {
    //    res += dp[i];
    //}
    //cout << res;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> wantFood(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        int food1, food2;
        cin >> food1 >> food2;
        wantFood[i][0] = food1;
        wantFood[i][1] = food2;
    }
    int res = 0;
    vector<int> used(m, 0); // used[i] = 0,表示菜品i+1还没被点
    for (int i = 0; i < n; i++) {
        if (used[wantFood[i][0]] == 0 && used[wantFood[i][1]]) {
            res++;
            used[wantFood[i][0]] = 1;
            used[wantFood[i][1]] = 1;
        }   
    }
    cout << res;
    return 0;
}
