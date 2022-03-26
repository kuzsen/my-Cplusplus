#include <iostream>
#include <vector>
#include <map> // 按k值排序
#include <algorithm>
using namespace std;
int main() {
    int M;
    cin >> M;
    vector<int> ans(M);
    for (int k = 0; k < M; k++) {
        int N;
        cin >> N;
        vector<int> nums(N);
        vector<char> kinds(N);
        // 统计个数
        map<int, int> cnt1;
        // 统计类别
        map<char, int> cnt2;
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            nums[i] = num;
            cnt1[num] += 1;
        }
        for (int i = 0; i < N; i++) {
            char c;
            cin >> c;
            kinds[i] = c;
            cnt2[c] += 1;
        }
        bool islianxu = false; // 连续5张牌
        if (cnt1.size() == 5) {
            /*int pre = 0;
            int end = 0;
            for (map<int, int> :: iterator it = cnt1.begin(); it != cnt1.end(); it++) {
                if (it ==  cnt1.begin()) {
                    pre = it->first;
                }
                end = it->first;
            }
            islianxu = end - pre == 4 ? true : false;**/
            sort(nums.begin(), nums.end());
            islianxu = nums[N - 1] - nums[0] == 4 ? true : false;
        }
        long long res = 1;
        int times_2 = 0, times_3 = 0, times_4 = 0, times_5 = 0;
        for (map<int, int> ::iterator it = cnt1.begin(); it != cnt1.end(); it++) {
            if (it->second == 5) {
                times_5++;
            }
            else if (it->second == 4) {
                times_4++;
            }
            else if (it->second == 3) times_3++;
            else if (it->second == 2) times_2++;
        }
        if (times_5 == 1) res *= 15000;
        else if (times_4 == 1) res *= 150;
        else if (times_2 == 1 && times_3 == 1) res *= 40;
        else if (times_2 == 0 && times_3 == 1) res *= 6;
        else if (times_2 == 2 && times_3 == 0) res *= 4;
        else if (times_2 == 1 && times_3 == 0) res *= 2;
        // if (cnt1.size() == 1 && auto cnt1.begin.second == 5) res * 15000; // 5张相同

        if (islianxu && cnt2.size() == 1) {
            res *= 8000; // 连续且类别相同
        }
        else if (islianxu) {
            res *= 20;
        }
        else if (!islianxu && cnt2.size() == 1 && N == 5) res *= 300;
        // cout << res << endl;
        ans[k] = res;
    }
    for (int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }
    system("pause");
    system("cls");
    return 0;
}