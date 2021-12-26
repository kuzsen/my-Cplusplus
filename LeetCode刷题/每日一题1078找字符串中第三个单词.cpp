#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        // �����Ƚ��ַ���text�еĵ��ʷŵ�������
        vector<string> word;
        int start = 0, end = 0;
        /*while (end < text.size()) {
            end = text.find(" ", start);
            word.emplace_back(text.substr(start, end - start));
            start = end + 1;
        }*/
        while (1) {
            end = text.find(" ", start); //�ڶ���������ʾ�����ҵ���ʼλ�ã���findû���ҵ�������-1
            if (end == -1) {
                break;
            }
            word.emplace_back(text.substr(start, end - start));
            start = end + 1; // ������ʼλ��
        }
        word.emplace_back(text.substr(start, text.size() - start)); // �����һ������Ҳ����word����

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
