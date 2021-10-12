#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class lengthofLongestSubstring 
{
public:
    //����һ�������ⷨ��ʱ�临�Ӷ�ΪO(n*2)
    int BaoLi1(string& s)
    {
        int start(0), end(0), length(0), result(0);
        int ssize = int(s.size());
        while (end < ssize)
        {
            char tempchar = s[end];//��Ŵ����Ҷ�
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
    //������������hashmap�Ż�
    int HashMap2(string& s) {
        //s[start,end) ǰ����� ���治����
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        unordered_map<char, int> hash;
        while (end < sSize)
        {
            char tmpChar = s[end];
            //����s[start,end) �д���s[end]ʱ����start
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

    //����������������vector�����Ӵ�
    int Vector3(string& s) {
        //s[start,end) ǰ����� ���治����
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        //����һ��128λ����,ȫ����ʼ��Ϊ-1
        //����ASCII��պ�128��,���'a',���Ӧ�±�Ϊ97��Ԫ��.�������汣��Ķ��������ַ������ֵ��±�,��Ȼ��ʼ��Ϊ-1,��ʾ����֮ǰ��û�г���,���Ϊ0,˵���������ڵ�һ���ַ�....
        vector<int> vec(128, -1);
        while (end < sSize)
        {
            char tmpChar = s[end];
            //����s[start,end) �д���s[end]ʱ����start
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
    string s = "abcabd";
    lengthofLongestSubstring test;
    int RESULT = 0;
    //RESULT = test.BaoLi1(s);
    //RESULT = test.HashMap2(s);
    RESULT = test.Vector3(s);
    cout << "�����ַ���s = " << s << " �����ظ��ַ��Ӵ�����󳤶�Ϊ��" << RESULT << endl; 
    
    system("pause");
    system("cls");
    return 0;
}