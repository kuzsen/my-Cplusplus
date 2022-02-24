// #include <bits/stdc++.h> // 万能头文件
#include<iostream>
#include<set>
#include<vector>

using namespace std;
/*
用set来记录被拿走的货物的下标，并用pair记录当前重量最大的区间cur，每次首先判断取出的货物是否在pair区间内，如果不是直接利用前缀和输出最大，如果在区间内，说明区间被拆分，遍历set取得最大区间，因为区间的个数从1增长到n，所以复杂度是0(nlogn)

作者：??
链接：https://leetcode-cn.com/leetbook/read/meituan/oh4ykh/?discussion=ZyF8w8
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

void maxWeight(vector<int>& w, vector<int> index) {
    int n = w.size();
    vector<int> preSum(n + 1); // 前缀和
    for (int i = 1; i <= n; i++) {
        preSum[i] = preSum[i - 1] + w[i - 1];
    }
    set<int> s; // 存放已经取走货物的编号
    pair<int, int> cur = make_pair(0, n - 1);
    for (int i = 0; i < n; i++) { // 依次按照取出顺序取出相应的货物
        int ind = index[i] - 1;
        s.insert(ind); // 放入已经取出的货物编号集合中
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
    int n; // 货物数量
    cin >> n; // 5
    vector<int> weight(n); // 3 2 4 4 5
    vector<int> index(n); // 4 3 5 2 1   输入的是1-n，实际下标要减一
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
        cin >> index[i];
    }
    maxWeight(weight, index);
    system("pause");
    system("cls");
    return 0;
}