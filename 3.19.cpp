//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int tankNum, life, power, base; // ̹�������� �ﱤ����ֵ�� �ﱤÿ�ο���ը������̹�ˣ� �ﱤ����
//    cin >> tankNum >> life >> power >> base;
//    vector<int> lifes(base, life); // �ﱤ����ֵ����
//    int round = 0; // �غ���
//    // ʾ��
//    // 10, 6, 8, 2
//    // 2
//
//    int index = 0; // ָ��ǰʣ���һ���ﱤ
//
//    // ̹�˾������л�����ʣ���������ٵĵﱤ��ÿ�غ�ը�پ�����ĵﱤ������ﱤ�������ͻ�ը��̹��
//    while (tankNum > 0 && index < base) { // ����̹�˿��Թ��� && ��ʣ�µﱤ
//        round++;
//
//        // ̹�˽����ﱤ
//        int curFire = tankNum; // ���غϵĻ���
//        while (curFire > 0 && index < base) {
//            if (curFire >= lifes[index]) { // ��ǰ�������ڵ�ǰָ��ﱤ��ʣ������ֵ
//                curFire -= lifes[index];
//                lifes[index] = 0; // ����index��ǰָ��ĵﱤ����������ֵ��Ϊ0
//                index++; // ָ����һ���ﱤ
//            }
//            else {
//                lifes[index] -= curFire;
//                curFire = 0;
//            }
//        }
//        // �ﱤ����̹��
//        tankNum -= (base - index) * power; 
//    }
//    if (lifes[base - 1] > 0) { // ���һ���ﱤ������ֵ��Ȼ����0��˵��̹�����ս���ʧ����
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
//        int n, v; // n�����ÿ����Բ�ժ������
//        cin >> n >> v;
//        vector<vector<int>> guas(n, vector<int>(3));
//        int endDay = 0; // ���й����е������ժ��ֹʱ��
//        for (int i = 0; i < n; i++) {
//            int k, a, b;
//            cin >> k >> a >> b;
//            endDay = max(endDay, b);
//            guas[i][0] = a;
//            guas[i][1] = b;
//            guas[i][2] = k;
//        }
//        // ���չ���ĳ�����ʼʱ������
//        sort(guas.begin(), guas.end(), comp);
//        int res = 0;
//        int start = guas[0][0]; // ��ʼ��ժ�ϵ�����
//        int i = 0; // �������ĵ�һƬ���￪ʼ��ժ
//        while (start <= endDay)
//        {
//            int fire = v; // ����ɲ�ժ������
//            while (fire > 0 && start >= guas[i][0] && start <= guas[i][1]) { // ��start����Բ�ժ��iƬ����Ĺ�
//                if (fire < guas[i][2]) {
//                    res += fire;
//                    fire = 0;
//                    guas[i][2] -= fire;
//                    // start++;
//                }
//                else { // �ѵ�ǰi����ʣ�µ�ȫ����ժ
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

