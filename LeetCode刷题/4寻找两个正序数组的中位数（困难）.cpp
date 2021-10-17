#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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
            double x = twonums.size() / 2;//trunc(a) 取a的整数部分
            res = (twonums[x] + twonums[x - 1]) / 2;
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

    //测试
    cout << findmediansortedarrays(n1, n2) << endl;//3.5
    cout << findmediansortedarrays(n1, n3) << endl;//3.5
    cout << findmediansortedarrays(n1, n4) << endl;//2
    cout << findmediansortedarrays(n1, n5) << endl;//2
    cout << findmediansortedarrays(n6, n2) << endl;//5
    cout << findmediansortedarrays(n5, n6) << endl;//0
    cout << findmediansortedarrays(n4, n6) << endl;//4
    cout << findmediansortedarrays(n6, n7) << endl;//2.5
    system("pause");
	system("cls"); 
	return 0;
}
