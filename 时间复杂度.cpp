#include<iostream>
#include<vector>
using namespace std;
//时间复杂度为n^2，比如冒泡排序法

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

//时间复杂度为指数2^n，比如细胞分裂
int algorithm1(int N)
{
    if (N <= 0) return 1;
    int count_1 = algorithm1(N - 1);
    int count_2 = algorithm1(N - 1);
    return count_1 + count_2;
}

//时间复杂度为阶乘 O(N!)，比如数学上的“ “全排列” 。即给定 N 个互不重复的元素，求其所有可能的排列方案，则方案数量为：
//N×(N?1)×(N?2)×?×2×1 = N!

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
