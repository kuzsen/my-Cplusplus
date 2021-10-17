#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//解法一，暴力，时间复杂度是O（m+n），简单，但是耗时占内存
double findmediansortedarrays(vector<int>& nums1, vector<int>& nums2) 
{
    vector<double> twonums;
    double res = 0;
    //twonums.size() = nums1.size() + nums2.size();
    for(int i = 0; i <nums1.size(); i++)
    //for (auto i = nums1.begin(); i != nums1.end(); i++)
    {
        double n = nums1[i];
        twonums.push_back(n);
    }
    for (auto j = 0; j < nums2.size(); j++)
     {
        double n = nums2[j];
        twonums.push_back(n);
    }

   // twonums.sort();
    sort(twonums.begin(), twonums.end()); // 升序排列

    if (nums1.size() != 0 || nums2.size() != 0)
    {
        if (twonums.size() % 2 == 0)
        {
           // double x = twonums.size() / 2;//double类型，防止算术溢出
            int x = twonums.size() / 2;
            //res = (twonums[x] + twonums[x - 1]) / 2;
            res = (twonums[x] + twonums[x - 1]) / 2.0;//2.0防止算术溢出
        }
        else
        {
            res = twonums[twonums.size() / 2];
        }
    }

    if (nums1.size() == 0 && nums2.size() == 0)
    {
        cout << "两个数组均为空！" << endl;
        res = 0;
    }
    //if (nums1.size() == 0 && nums2.size() != 0)
    //{
    //    if (nums2.size() % 2 == 0)
    //    {
    //       // res = (nums2[nums2.size() / 2] + nums2[nums2.size() / 2 + 1]) / 2;
    //        double x = nums2.size() / 2;
    //        res = (nums2[x] + nums2[x - 1]) / 2;
    //    }
    //    else
    //    {
    //        res = nums2[nums2.size() / 2];
    //    }
    //}
    //if (nums1.size() != 0 && nums2.size() == 0)
    //{
    //    if (nums1.size() % 2 == 0)
    //    {
    //       // res = (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 + 1]) / 2;
    //        double x = nums1.size() / 2;//防止算术溢出
    //        res = (nums1[x] + nums1[x - 1]) / 2;
    //    }
    //    else
    //    {
    //        res = nums1[nums1.size() / 2 ];
    //    }
    //}
    return res;
}

//方法二：二分查找法——时间复杂度为O（log（m+n））,https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) 
    {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */

        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;

        while (true) {
            // 边界情况
            if (index1 == m) {//如果一个数组为空，说明该数组中的所有元素都被排除，我们可以直接返回另一个数组中第 kk 小的元素。
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);//如果 A[k/2−1] 或者 B[k/2−1] 越界，
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);//那么我们可以选取对应数组中的最后一个元素。
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;//当newIndex=index1 + k/2 - 1 时，k=k-k/2;    当newIndex=m - 1时，k = k -（m - index1）
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }


int main()
{
    vector<int> n1 = { 1,2,3 };
    vector<int> n2 = { 4,5,6 };
    vector<int> n3 = { 6,4,5 };
    vector<int> n4 = { 1,7};
    vector<int> n5 = {};
    vector<int> n6 = {};
    vector<int> n7 = {2,3};
   // cout << n1[1]<< endl;
    //double middle ;
    /*double x = 3;
    double y = 4;
    cout << (x + y) / 2 << endl;*/
     //findmediansortedarrays(n1, n2);

    //测试方法一
    //cout << findmediansortedarrays(n1, n2) << endl;//3.5
    //cout << findmediansortedarrays(n1, n3) << endl;//3.5
    //cout << findmediansortedarrays(n1, n4) << endl;//2
    //cout << findmediansortedarrays(n1, n5) << endl;//2
    //cout << findmediansortedarrays(n6, n2) << endl;//5
    //cout << findmediansortedarrays(n5, n6) << endl;//0
    //cout << findmediansortedarrays(n4, n6) << endl;//4
    //cout << findmediansortedarrays(n6, n7) << endl;//2.5

    //测试方法二
    cout << findMedianSortedArrays2(n1, n2) << endl;//3.5

    system("pause"); 

	system("cls");	return 0;
}
