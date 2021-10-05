#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int getone(int num)
{
    bitset<8> t(num);
    string s = t.to_string();
        cout << "你输入数字的二进制字符串长度为："<<s.size() << endl;

    int max = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        int len = 0;
        while (s[i] == '1')
        {
            len++;
            i++;
        }
        if (len > max)
            max = len;
    }
    return max;
}

int main()
{
    int num;
    while (cin >> num)
    {
        cout << getone(num) << endl;
    }
    return 0;
}