//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int tankNum, life, power, base; // 坦克数量， 碉堡生命值， 碉堡每次可以炸多少量坦克， 碉堡数量
//    cin >> tankNum >> life >> power >> base;
//    vector<int> lifes(base, life); // 碉堡生命值数组
//    int round = 0; // 回合数
//    // 示例
//    // 10, 6, 8, 2
//    // 2
//
//    int index = 0; // 指向当前剩余第一座碉堡
//
//    // 坦克尽量集中火力打剩余生命最少的碉堡，每回合炸毁尽量多的碉堡，否则碉堡反过来就会炸毁坦克
//    while (tankNum > 0 && index < base) { // 还有坦克可以攻击 && 还剩下碉堡
//        round++;
//
//        // 坦克进攻碉堡
//        int curFire = tankNum; // 本回合的火力
//        while (curFire > 0 && index < base) {
//            if (curFire >= lifes[index]) { // 当前火力大于当前指向碉堡的剩余生命值
//                curFire -= lifes[index];
//                lifes[index] = 0; // 消灭index当前指向的碉堡，将其生命值置为0
//                index++; // 指向下一个碉堡
//            }
//            else {
//                lifes[index] -= curFire;
//                curFire = 0;
//            }
//        }
//        // 碉堡进攻坦克
//        tankNum -= (base - index) * power; 
//    }
//    if (lifes[base - 1] > 0) { // 最后一座碉堡的生命值仍然大于0，说明坦克最终进攻失败了
//        round = -1;
//    }
//    cout << round << endl;
//    system("pause");
//    system("cls");
//    return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <unordered_map>
//#include <vector>
//using namespace std;
//int main() {
//    int n;
//    cin >> n;
//    vector<int> n1(n);
//    vector<int> n2(n);
//    for (int i = 0; i < n; i++) {
//        int a, b;
//        cin >> a >> b;
//        n1[i] = a;
//        n2[i] = b;
//    }
//    sort(n1.begin(), n1.end());
//    sort(n2.begin(), n2.end());
//    int res = 0;
//    for (int i = 0; i < n; i++) {
//        res += ((n1[i] - n2[i]) * (n1[i] - n2[i]));
//    }
//    cout << res;
//    system("pause");
//    system("cls");
//    return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <unordered_map>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool comp(vector<int> g1, vector<int> g2) {
//    if (g1[0] < g2[0]) return true;
//    else if (g1[0] == g2[0]) {
//        return g1[1] < g2[1];
//    }
//    else
//    {
//        return false;
//    }
//}
//int main() {
//    int T;
//    cin >> T;
//    while (T > 0) {
//        int n, v; // n个瓜田，每天可以采摘的数量
//        cin >> n >> v;
//        vector<vector<int>> guas(n, vector<int>(3));
//        int endDay = 0; // 所有瓜田中的最晚采摘终止时间
//        for (int i = 0; i < n; i++) {
//            int k, a, b;
//            cin >> k >> a >> b;
//            endDay = max(endDay, b);
//            guas[i][0] = a;
//            guas[i][1] = b;
//            guas[i][2] = k;
//        }
//        // 按照瓜田的成熟起始时间排序
//        sort(guas.begin(), guas.end(), comp);
//        int res = 0;
//        int start = guas[0][0]; // 开始采摘瓜的天数
//        int i = 0; // 从排序后的第一片瓜田开始采摘
//        while (start <= endDay)
//        {
//            int fire = v; // 当天可采摘的数量
//            while (fire > 0 && start >= guas[i][0] && start <= guas[i][1]) { // 第start天可以采摘第i片瓜田的瓜
//                if (fire < guas[i][2]) {
//                    res += fire;
//                    fire = 0;
//                    guas[i][2] -= fire;
//                    // start++;
//                }
//                else { // 把当前i瓜田剩下的全部采摘
//                    res += guas[i][2];
//                    fire -= guas[i][2];
//                    guas[i][2] = 0;
//                    i++;
//                }
//            }
//            start++;
//        }
//        cout << res;
//        T--;
//    }
//    return 0;
//}

#include <iostream>
#include <vector>
using namespace std;
bool isSelf(int num) {
    int s = 0;
    int temp = num;
    while (temp > 0) {
        s += temp % 10;
        temp /= 10;
    }
    if (num % s == 1) {
        return true;
    }
    else return false;
}
int main() {
    int t;
    cin >> t;
    vector<vector<int>> in(t, vector<int>(2));
    int minNum = 1000000, maxNum = 1;
    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        in[i][0] = l;
        in[i][1] = r;
        minNum = min(minNum, l);
        maxNum = max(maxNum, r);
    }
    vector<int> dp(maxNum + 1, 0);
    for (int i = minNum; i <= maxNum; i++) {
        if (isSelf(i)) {
            dp[i] = dp[i - 1] + 1;
        }
        else dp[i] = dp[i - 1];
    }
    for (int i = 0; i < t; i++) {
        int res_i = dp[in[i][1]] - dp[in[i][0] - 1];
        cout << res_i << endl;
    }
    system("pause");
    system("cls");
    return 0;
}

