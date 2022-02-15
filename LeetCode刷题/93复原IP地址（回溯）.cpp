class Solution {
    // 本题与131.分割回文串类似，0-255才有效，等同于子串是回文
private:
    vector<string> res;
    string curIP;
    bool flag = false;
    void backTracing(const string& s, int startIndex, int pointNum) {
        if (pointNum == 3) { // curIP中已经存在3个有效整数了
            if (isVaild(s, startIndex, s.size() - 1)) { // 最后一个子IP也是有效的，插入curIP，加入res
                curIP += s.substr(startIndex, s.size() - startIndex);
                res.push_back(curIP);
                // flag = true;
                curIP.erase(curIP.size() - 1 - s.size() + startIndex, s.size() - startIndex); // 回溯，将刚刚插入的最后一个有效整数删除掉
                return;
            }
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isVaild(s, startIndex, i)) {
                curIP += s.substr(startIndex, i - startIndex + 1);
                curIP += '.';
                pointNum++;
                backTracing(s, i + 1, pointNum);
                int curIpSize = curIP.size();
                if (pointNum == 3 && flag) { // 第13行已经回溯了
                    flag = false;
                }
                else { // 非第四个有效整数的回溯
                    // curIP -= '.';
                    curIP.erase(curIpSize - 1, 1); // 删除字符串中从索引位置pos开始的len个字符
                    curIP.erase(curIpSize - i + startIndex - 2, i - startIndex + 1);
                    // curIP -= s.substr(startIndex, i - startIndex + 1);
                }
                // 回溯
                pointNum--;

            }
            else break; // 以startIndex开头的数字不合法，退出当前循环

        }
    }
    bool isVaild(const string& s, int l, int r) {
        // 0-255才是有效的
        if (l > r) return false;
        if (r - l + 1 > 3 || (r - l >= 1 && s[l] == '0')) return false; // 含有前导0
        int num = stoi(s.substr(l, r - l + 1)); // stoi()会做范围检查，默认范围是在int的范围内的，如果超出范围的话则会runtime error！， 提前判断num超过3位数，false
        if (num >= 0 && num <= 255) return true;
        else return false;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        curIP.clear();
        backTracing(s, 0, 0);
        return res;

    }
};