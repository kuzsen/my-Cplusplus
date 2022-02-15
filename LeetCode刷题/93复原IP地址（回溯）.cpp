class Solution {
    // ������131.�ָ���Ĵ����ƣ�0-255����Ч����ͬ���Ӵ��ǻ���
private:
    vector<string> res;
    string curIP;
    bool flag = false;
    void backTracing(const string& s, int startIndex, int pointNum) {
        if (pointNum == 3) { // curIP���Ѿ�����3����Ч������
            if (isVaild(s, startIndex, s.size() - 1)) { // ���һ����IPҲ����Ч�ģ�����curIP������res
                curIP += s.substr(startIndex, s.size() - startIndex);
                res.push_back(curIP);
                // flag = true;
                curIP.erase(curIP.size() - 1 - s.size() + startIndex, s.size() - startIndex); // ���ݣ����ող�������һ����Ч����ɾ����
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
                if (pointNum == 3 && flag) { // ��13���Ѿ�������
                    flag = false;
                }
                else { // �ǵ��ĸ���Ч�����Ļ���
                    // curIP -= '.';
                    curIP.erase(curIpSize - 1, 1); // ɾ���ַ����д�����λ��pos��ʼ��len���ַ�
                    curIP.erase(curIpSize - i + startIndex - 2, i - startIndex + 1);
                    // curIP -= s.substr(startIndex, i - startIndex + 1);
                }
                // ����
                pointNum--;

            }
            else break; // ��startIndex��ͷ�����ֲ��Ϸ����˳���ǰѭ��

        }
    }
    bool isVaild(const string& s, int l, int r) {
        // 0-255������Ч��
        if (l > r) return false;
        if (r - l + 1 > 3 || (r - l >= 1 && s[l] == '0')) return false; // ����ǰ��0
        int num = stoi(s.substr(l, r - l + 1)); // stoi()������Χ��飬Ĭ�Ϸ�Χ����int�ķ�Χ�ڵģ����������Χ�Ļ����runtime error���� ��ǰ�ж�num����3λ����false
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