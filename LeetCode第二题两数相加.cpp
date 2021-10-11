#include<iostream>
using namespace std;
#include<vector>

//1、创建链表结点类
class ListNode {
public:
    int val;//当前结点值
    ListNode* next;//指向下一结点
    ListNode(int x) : val(x), next(NULL) {}
};

//2、创建链表
ListNode* CreatLinkList(vector<int>nums)
{
    ListNode* head = new ListNode(-1);
    auto start = head;
    for (auto num : nums)
    {
        //start->next->val = num;// start->next是空指针，需要开辟内存空间
        start->next = new ListNode(num);
        start = start->next;
    }
    return head->next;
    delete(head);
}

//3、打印链表
void printLinkList(ListNode* xx) 
{
    ListNode* node = xx;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}
////4、释放内存——还未实现
//void freeLinkList(ListNode* yy) 
//{
//
//}

//4、两数相加
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = new ListNode(-1), * current = head;//创建结果链表头结点head，当前结点current
        int carry = 0;//进位数
        while (l1 || l2)//l1和l2当前为均不为空
        {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int temp_sum = x + y + carry;

            carry = temp_sum / 10;
            current->next = new ListNode(temp_sum % 10);
            current = current->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if(carry)
            current->next = new ListNode(carry);
        return head->next;
        delete(head);//释放结果头结点（-1）
    }
};


int main()
{
    auto l1 = CreatLinkList({ 1,2,3 });
    auto l2 = CreatLinkList({ 4,9,6 });
    printLinkList(l1);
    printLinkList(l2);

    Solution test;
    ListNode* testhead;
    testhead = test.addTwoNumbers(l1, l2);
    printLinkList(testhead);

    system("pause");
    system("cls");
    return 0;
}