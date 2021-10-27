/*
https://zhaitianbao.blog.csdn.net/article/details/118965352

https://blog.csdn.net/hankern/article/details/90572592?ops_request_misc=&request_id=&biz_id=102&utm_term=string::size_type&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-5-90572592.nonecase&spm=1018.2226.3001.4187
https://blog.csdn.net/sinat_31608641/article/details/107247452?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522163530615616780357273939%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=163530615616780357273939&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-3-107247452.pc_search_ecpm_flag&utm_term=string%3A%3Asize_type&spm=1018.2226.3001.4187
*/
#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;
void SplitString(string& s, vector<string>& v, string c)
{
    string::size_type pos1, pos2;//string抽象意义是字符串， size（）的抽象意义是字符串的尺寸， string::size_type抽象意义是尺寸单位类型
    pos2 = s.find(c);
    pos1 = 0;
    while (string::npos != pos2)//string::npos是一个静态成员常量，表示size_t的最大值（Maximum value for size_t）。该值表示“直到字符串结尾”，作为返回值它通常被用作表明没有匹配。
        
    {
        v.push_back(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())//st.size()表示st中的字符数量，字符数量的统计是由 1 开始累计计算的，所以字符数量正好比字符串的下标索引数（由 0 开始累计计算）大 1 ，这里的index != st.size();的效果等同于index < st.size();
        v.push_back(s.substr(pos1));
}
int main()
{
    string str;
    vector<string> result;
    int x = 0, y = 0;
    getline(cin, str);
    SplitString(str, result, ";");
    for (auto i : result)
    {
        if (i.empty())
        {
            continue;
        }
        string tmp = i.substr(1);
        if (regex_match(tmp, regex("[0-9]*")))
        {
            switch (i[0])
            {
            case'A':x -= stoi(tmp); break;
            case'D':x += stoi(tmp); break;
            case'W':y += stoi(tmp); break;
            case'S':y -= stoi(tmp); break;
            default:break;
            }
        }
    }
    cout <<"("<< x << "," << y <<")"<< endl;

    system("pause");
    system("cls");
    return 0;
}