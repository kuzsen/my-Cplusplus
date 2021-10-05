//密码强度等级
//https://blog.csdn.net/zhaitianbao/article/details/120489623?spm=1001.2014.3001.5501

#include <iostream>    
#include <string>
using namespace std;

string SecurityLevel(string password)
{
    int sum = 0;
    int size = password.size();
    // 密码长度
    if (size <= 4)
        sum += 5;
    else if (size > 4 && size <= 7)
        sum += 10;
    else
        sum += 25;
    // 遍历
    bool noletter = true;
    bool haveupper = false;
    bool haveLower = false;
    bool havenumber = false;
    bool havesymbol = false;
    int numsize = 0;
    int symbolsize = 0;
    for (int i = 0; i < size; ++i)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            numsize++;
            havenumber = true;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            noletter = false;
            haveLower = true;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            noletter = false;
            haveupper = true;
        }
        else {
            symbolsize++;
            havesymbol = true;
        }
    }
    // 字母
    if (haveupper && haveLower)
        sum += 20;
    else if ((haveupper && !haveLower) || (!haveupper && haveLower))
        sum += 10;
    // 数字
    if (numsize > 1)
        sum += 20;
    else if (numsize == 1)
        sum += 10;
    // 数字
    if (symbolsize > 1)
        sum += 25;
    else if (symbolsize == 1)
        sum += 10;
    // 奖励
    if (haveupper && haveLower && havenumber && havesymbol)
        sum += 5;
    else if (!noletter && havenumber && havesymbol)
        sum += 3;
    else if (!noletter && havenumber)
        sum += 2;
    //结果
    if (sum >= 90)
        return "VERY_SECURE";
    else if (sum >= 80)
        return "SECURE";
    else if (sum >= 70)
        return "VERY_STRONG";
    else if (sum >= 60)
        return "STRONG";
    else if (sum >= 50)
        return "AVERAGE";
    else if (sum >= 25)
        return "WEAK";
    else
        return "VERY_WEAK";
}

int main()
{
    string password;
    while (getline(cin, password))
    {
        cout <<"你输入的密码强度等级为："<< SecurityLevel(password) << endl;
    }
    system("pause");
    system("cls");
    return 0;
}
