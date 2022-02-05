#include<iostream>
using namespace std;
#include<unordered_map>
class Solution {
public:
    int my(int fen, int sec, int startAt, int moveCost, int pushCost, int targetSeconds) {
        // unordered_map<int, int> m;
        vector<int> fen_sec;
        int wei = 0;
        if (fen >= 10) wei = 4;
        else if (fen < 10 && fen > 0) wei = 3;
        else if (fen == 0 && sec >= 10) wei = 2;
        else if (fen == 0 && sec < 10) wei = 1;
        if (fen >= 10) {
            // m[fen/10]++;
            // m[fen%10]++;
            fen_sec.push_back(fen / 10);
            fen_sec.push_back(fen % 10);
        }
        else if (fen < 10 && fen > 0) {
            // m[fen]++;
            fen_sec.push_back(fen);
        }

        if (sec >= 10) {
            // m[sec/10]++;
            // m[sec%10]++;
            fen_sec.push_back(sec / 10);
            fen_sec.push_back(sec % 10);
        }
        // else if (sec < 10 && sec > 0) {
        else if (sec < 10) { // sec==0也可，插入两个0位
            if (fen_sec.size() != 0) { // 说明分不为0
                // m[0]++; //秒的10位=0，也要按一次
                fen_sec.push_back(0);
            }
            // m[sec]++;
            fen_sec.push_back(sec);
        }
        //int sametimes = 0;
        // 93 94,起始为0，从左到右，需要移动4次，不能连续按2次9
        // if (m.count(startAt)) sametimes = m[startAt];
        // int movetimes = sametimes == 0 ? m.size() : m.size() - 1;
        int movetimes = 0;
        for (int i = 0; i < fen_sec.size(); i++) {
            if (startAt != fen_sec[i]) movetimes++;
            startAt = fen_sec[i];
        }
        return moveCost * movetimes + pushCost * wei;
    }
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        // int res = INT_MAX;
        // 分+秒
        int fen = targetSeconds / 60, sec = targetSeconds % 60;
        int res = INT_MAX;
        if (fen < 100) {
            res = min(res, my(fen, sec, startAt, moveCost, pushCost, targetSeconds));
        }

        if (fen > 0 && sec <= 39) {
            res = min(res, my(fen - 1, sec + 60, startAt, moveCost, pushCost, targetSeconds));
        }

        return res;
    }
};
int main()
{

    int res = Solution().minCostSetTime(1, 1, 5603, 900);
	system("pause");
	system("cls");
	return 0;
}
