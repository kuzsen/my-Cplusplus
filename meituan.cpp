
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {

    /*
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums[i] = num;
    }
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 0; i < n - 2; i++) {
        // if (i > 0 && nums[i] == nums[i - 1]) continue;
        // int k = n - 1;
        for (int j = i + 1; j < n - 1; j++) {
            // if (j > i+1 && nums[j] == nums[j - 1]) continue;
            int k = n - 1;
            while (j < k && nums[i] + nums[k] > 3 * nums[j]) {
                k--;
            }
            if (j == k) break;
            while (j < k && nums[i] + nums[k] == 3 * nums[j]) {
                res++;
                k--;
            }
            break;
        }
    }
    cout << res << endl;
    */

    map<string, int> m;
    for (int i = 1; i <= 10; i++) {
        m[to_string(i)] = i;
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << endl; // Êä³ö1£¬10£¬2£¬3£¬4£¬5£¬6£¬7£¬8£¬9£¬Ô­Òò°´ÕÕ×ÖµäÐòÅÅÐò2 > 10
    }
    system("pause");
    system("cls");
    return 0;
}

