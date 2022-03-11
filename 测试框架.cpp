//#include<iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <map>
//#include <unordered_map>
//
//
//
//
//using namespace std;
//int solution(int a, int b) { // a边形，第b个
//	int res = 1;
//	int d = a - 2; // 公差
//	for (int i = 2; i <= b + 1; i++) {
//		int numi = 1 + (i - 1) * d;
//		res += numi;
//	}
//	return res;
//}
//int main()
//{	
//	int n;
//	cin >> n;
//	int sum = 0;
//	for (int i = 0; i < n; i++) {
//		int A, B;
//		cin >> A >> B;
//		int cur = solution(A, B);
//		cout << cur << endl;
//		sum += cur;
//	}
//	cout << sum << endl;
//	system("pause");
//	system("cls");
//	return 0;
//}
//// 正n边形中等腰锐角三角形的数量，三角形的顶点要在多边形的顶点上
#include<iostream>
#include <vector>
#include <string>
using namespace std;
class lzs {
public:
    int drx[8] = { -1,-1,-1,0,0,1,1,1 }, dry[8] = { -1,0,1,-1,1,-1,0,1 };
    vector<string> res;
    void solution(vector<string>& input) {
        vector<string> res;
        vector<vector<double>> count(4, vector<double>(4, 0)); // 统计每个位置周边未知状态'.'的个数
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (input[i][j] == '.') {
                    int newx = i + drx[i], newy = j + dry[j];
                    if (newx >= 0 && newx <= 4 && newy >= 0 && newy <= 4) {
                        count[newx][newy] += 1.0;
                    }
                }

            }
        }
        vector<vector<double>> maybe(4, vector<double>(4, 0));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (input[i][j] == '.') {
                    continue;
                }
                else if (input[i][j] - 0 > 0 && input[i][j] - 00 <= 8) {
                    int newx = i + drx[i], newy = j + dry[j];
                    if (newx >= 0 && newx <= 4 && newy >= 0 && newy <= 4 && input[newx][newy] == '.') {
                        maybe[newx][newy] += (input[i][j] - 0) / count[i][j]; // 累加贡献
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (maybe[i][j] >= 1.0) {
                    input[i][j] = 'X';
                }
                else if ()
            
            }
        }
    }
}

int main() {
    int n = 4;
    vector<string> input(4);
    for (int i = 0; i < 4; i++) {
        string str;
        cin >> str;
        input[i] = str;
    }
    solution(input);

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> cats(n);
    int sumCat = 0;
    for (int i = 0; i < n; i++) {
        int cat;
        cin >> cat;
        sumCat += cat;
        cats[i] = cat;
    }
    vector<int> last(n);
    for (int i = 0; i < n; i++) {
        last[i] = sumCat - cats[i]; // 剩余猫猫的能力值
    }

    int m;
    cin >> m;
    vector<vector<int>> dogs(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        int b, c;
        cin >> b >> c;
        dogs[i][0] = b;
        dogs[i][1] = c;
    }

    for (int i = 0; i < m; i++) { // 每只🐕发起攻击
        int add = 0;
        bool flag = false;
        for (int j = 0; j < n; j++) { // 遍历猫猫j迎战，最后选择需要增加能力值最小的
            /*if (cats[j] >= dogs[i][0] && last[j] >= dogs[i][1]) {
                cout << 0 << endl; // 不需要增加
                break;
            }*/
            int add1 = cats[j] < dogs[i][0] ? dogs[i][0] - cats[j] : 0;
            int add2 = last[j] < dogs[i][1] ? dogs[i][1] - last[j] : 0;
            if (add == 0 && !flag) {
                add = add1 + add2;
                flag = true;
            }
            else {
                add = min(add, add1 + add2);
                // if (add == 0) break;
            }

        }
        cout << add << endl;
    }
    return 0;
}