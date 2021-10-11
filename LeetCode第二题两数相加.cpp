#include<iostream>
using namespace std;
#include<vector>

//1��������������
class ListNode {
public:
    int val;//��ǰ���ֵ
    ListNode* next;//ָ����һ���
    ListNode(int x) : val(x), next(NULL) {}
};

//2����������
ListNode* CreatLinkList(vector<int>nums)
{
    ListNode* head = new ListNode(-1);
    auto start = head;
    for (auto num : nums)
    {
        //start->next->val = num;// start->next�ǿ�ָ�룬��Ҫ�����ڴ�ռ�
        start->next = new ListNode(num);
        start = start->next;
    }
    return head->next;
    delete(head);
}

//3����ӡ����
void printLinkList(ListNode* xx) 
{
    ListNode* node = xx;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}
////4���ͷ��ڴ桪����δʵ��
//void freeLinkList(ListNode* yy) 
//{
//
//}

//4���������
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = new ListNode(-1), * current = head;//�����������ͷ���head����ǰ���current
        int carry = 0;//��λ��
        while (l1 || l2)//l1��l2��ǰΪ����Ϊ��
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
        delete(head);//�ͷŽ��ͷ��㣨-1��
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