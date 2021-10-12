#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<unordered_set>
using namespace std;

class lengthofLongestSubstring 
{
public:
    //�ٷ��ⷨ���ƶ�����
    int lengthOfLongestSubstring(string s) {
        // ��ϣ���ϣ���¼ÿ���ַ��Ƿ���ֹ�
        unordered_set<char> occ;
        int n = s.size();
        // ��ָ�룬��ʼֵΪ -1���൱���������ַ�������߽����࣬��û�п�ʼ�ƶ�
        int rk = -1, ans = 0;
        // ö����ָ���λ�ã���ʼֵ���Եر�ʾΪ -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // ��ָ�������ƶ�һ���Ƴ�һ���ַ�
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // ���ϵ��ƶ���ָ��
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // �� i �� rk ���ַ���һ�����������ظ��ַ��Ӵ�
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }

    //����һ��
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
    string s = "abcabde";
    lengthofLongestSubstring test;
    int RESULT = 0;
    //RESULT = test.BaoLi1(s);
    //RESULT = test.HashMap2(s);
   // RESULT = test.Vector3(s);
    RESULT = test.lengthOfLongestSubstring(s);
    cout << "�����ַ���s = " << s << " �����ظ��ַ��Ӵ�����󳤶�Ϊ��" << RESULT << endl; 
    
    system("pause");
    system("cls");
    return 0;
}