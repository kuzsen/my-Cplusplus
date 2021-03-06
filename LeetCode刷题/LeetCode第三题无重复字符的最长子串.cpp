#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<unordered_set>
using namespace std;

class lengthofLongestSubstring 
{
public:
    //官方解法，移动窗口
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }

    //方法一：
    int BaoLi1(string& s)
    {
        int start(0), end(0), length(0), result(0);
        int ssize = int(s.size());
        while (end < ssize)
        {
            char tempchar = s[end];//存放窗口右端
            for (int index =start; index < end; index++)
            {
                if (s[index] == tempchar)
                {
                    start = index + 1;
                    length = end - start;
                    break;
                }
            }
            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }
    //方法二：利用hashmap优化
    int HashMap2(string& s) {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        unordered_map<char, int> hash;
        while (end < sSize)
        {
            char tmpChar = s[end];
            //仅当s[start,end) 中存在s[end]时更新start
            if (hash.find(tmpChar) != hash.end() && hash[tmpChar] >= start)
            {
                start = hash[tmpChar] + 1;
                length = end - start;
            }
            hash[tmpChar] = end;

            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }

    //方法三：利用数组vector存放最长子串
    int Vector3(string& s) {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        //定义一个128位数组,全部初始化为-1
        //等于ASCII码刚好128个,如果'a',则对应下标为97的元素.数组里面保存的都是他在字符串出现的下标,当然初始化为-1,表示遍历之前都没有出现,如果为0,说明它出现在第一个字符....
        vector<int> vec(128, -1);
        while (end < sSize)
        {
            char tmpChar = s[end];
            //仅当s[start,end) 中存在s[end]时更新start
            if (vec[int(tmpChar)] >= start)
            {
                start = vec[int(tmpChar)] + 1;
                length = end - start;
            }
            vec[int(tmpChar)] = end;

            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }
};

int main()
{
    string s = "abcabde";
    lengthofLongestSubstring test;
    int RESULT = 0;
    //RESULT = test.BaoLi1(s);
    //RESULT = test.HashMap2(s);
   // RESULT = test.Vector3(s);
    RESULT = test.lengthOfLongestSubstring(s);
    cout << "输入字符串s = " << s << " 的无重复字符子串的最大长度为：" << RESULT << endl; 
    
    system("pause");
    system("cls");
    return 0;
}