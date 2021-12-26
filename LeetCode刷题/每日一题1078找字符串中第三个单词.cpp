#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        // 首先先将字符串text中的单词放到数组中
        vector<string> word;
        int start = 0, end = 0;
        /*while (end < text.size()) {
            end = text.find(" ", start);
            word.emplace_back(text.substr(start, end - start));
            start = end + 1;
        }*/
        while (1) {
            end = text.find(" ", start); //第二个参数表示，查找的起始位置，若find没有找到，返回-1
            if (end == -1) {
                break;
            }
            word.emplace_back(text.substr(start, end - start));
            start = end + 1; // 更新起始位置
        }
        word.emplace_back(text.substr(start, text.size() - start)); // 将最后一个单词也放入word数组

        vector<string> res;
        int n = word.size();
        if (n < 3) return res;
        int i = 0;
        while (i < n - 2) {
            if (word[i] == first && word[i + 1] == second) {
                res.emplace_back(word[i + 2]);
            }
            i++;
        }
        return res;
    }
};
int main()
{
    string text = "ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv ypkk";
    string first = "lnlqhmaohv";
    string second = "ypkk";

    vector<string> result = Solution().findOcurrences(text, first, second);
    for (auto str : result) {
        cout << str << endl;
    }
	system("pause");
	system("cls");
	return 0;
}
