#include<iostream>
using namespace std;
class Solution {
public:
    int hash(string& sub, int& p, int& m, int& k) {
        int res = 0;
        for (int i = 0; i < k; i++) {
            int varVal = sub[i] - 'a' + 1;
            int aa = p ^ i;
            res += varVal * aa;
        }
        return res % m;
    }
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        string res;
        for (int i = 0; i < s.size() - k; i++) {
            string sub = s.substr(i, k);
            if (hash(sub, power, modulo, k) == hashValue) {
                return sub;
            }
        }
        return res;
        //return res;
    }
};
int main()
{
    string s = "leetcode";
    int power = 7, modulo = 20, k = 2, hashValue = 0;
    string res = Solution().subStrHash(s, power, modulo, k, hashValue);
    cout << res << endl;
	system("pause");
	system("cls");
	return 0;
}
