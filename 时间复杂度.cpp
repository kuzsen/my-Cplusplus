#include<iostream>
#include<vector>
using namespace std;
//ʱ�临�Ӷ�Ϊn^2������ð������

vector<int> bubbleSort(vector<int>& nums)
{
    int N = nums.size();
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
    return nums;
}

//ʱ�临�Ӷ�Ϊָ��2^n������ϸ������
int algorithm1(int N)
{
    if (N <= 0) return 1;
    int count_1 = algorithm1(N - 1);
    int count_2 = algorithm1(N - 1);
    return count_1 + count_2;
}

//ʱ�临�Ӷ�Ϊ�׳� O(N!)��������ѧ�ϵġ� ��ȫ���С� �������� N �������ظ���Ԫ�أ��������п��ܵ����з������򷽰�����Ϊ��
//N��(N?1)��(N?2)��?��2��1 = N!

int algorithm2(int N) {
    if (N <= 0) return 1;
    int count = 0;
    for (int i = 0; i < N; i++) {
        count += algorithm2(N - 1);
    }
    return count;
}



int main() {
    int n = 3;
    int result = algorithm1(n);//=2^3 = 8
    cout << result << endl;

    system("pause");
    system("cls");
    return 0;
}
