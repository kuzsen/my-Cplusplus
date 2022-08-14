#include <iostream>
#include <string>
#include <vector>
using namespace std;
// �ָ��ַ�������
// ԭ�����Թٸ���������C����ָ����ʽ��int split(char* in, const char sep, char** out); // �ַ�ָ����һ����Ҫ��ǿ��ϰ
int split(string in, const char sep, vector<string>& res) {
    int ans = 0;
    for (int i = 0; i < in.size();) {
        // cout << i << endl;
        int j = i;
        while (j < in.size() && in[j] != sep) { // ******************����Ҫ��֤j�ķ�Χ�������
            j++;
        }
        string cur;
        if (j < in.size()) {
            ans++;
            // cout << ans << endl;
            cur = in.substr(i, j - i);
            // i = j + 1;
        }
        else {
            cur = in.substr(i, in.size() - i);
            // break; // ********************************************���һ�����ַ�����û����ӵ�res�У�����break
        }
        // cout << cur << endl;
        i = j + 1;
        res.push_back(cur);
    }
    return ans + 1;
}
int main() {
    string in = "a#c#dcd#daa#113";
    cout << in << endl;
    vector<string> res;
    const char sep = '#';
    // ��sep�ַ��ָ��ַ��������طָ������ַ������������÷����ַ����б�
    int num = split(in, sep, res);
    cout << num << endl;
    for (auto s : res) {
        cout << s << endl;
    }
    system("pause");
    system("cls");
    return 0;
}