/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 // ������������� ����������������һ
// class Solution {
// public:
//     ListNode* rotateOnce(ListNode* head) { // �����������ڵ㣬�ҵ�β�ڵ�last������ָ��head���ٽ�last����һ��ָ���
//         ListNode* last = head->next;
//         ListNode* preLast= head; // ά��һ��β�ڵ����һ�����������Ϊ�µ�β�ڵ㣬ָ���
//         while (last->next != nullptr) {
//             preLast = last;
//             last = last->next;
//         }
//         // ��ʱ�Ѿ��ҵ���ԭ����β�ڵ�
//         // ����ָ��ԭ����ͷ�ڵ�
//         last->next = head;
//         // ��ԭ��Ϊ�ڵ����һ���ڵ����һ��next��Ϊ��
//         preLast->next = nullptr;
//         return last; // �����������ͷ��
//     }

//     ListNode* rotateRight(ListNode* head, int k) {
//         if (head == nullptr || head->next == nullptr || k == 0) return head;
//         // [1,2,3],2000000000 ��k����ʱ���ᳬʱ�������Ż���ת�Ĵ��������ȼ���ڵ�ĸ���n����k��nȡ��������ȥ������ת�Ĵ�����С�ڽڵ�ĸ���
//         ListNode* countHelp = head;
//         int n = 0;
//         while (countHelp != nullptr) {
//             countHelp = countHelp->next;
//             n++;
//         }
//         k %= n;
//         while (k > 0) {
//             ListNode* newHead = rotateOnce(head);
//             head = newHead;
//             k--;
//         }
//         return head;
//     }
// };

// �ٷ���⡪�������պ�Ϊ��
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        int n = 1;
        ListNode* iter = head;
        while (iter->next != nullptr) {
            iter = iter->next;
            n++;
        }
        // ����ʾ��1��n = 5��k = 2
        int add = n - k % n; // 3,ԭ������ĵ�3���ڵ���Ϊ��ת���β�ڵ㣬k % n �϶�С�ڵ��� n�ģ����ƶ�k % n = 1�Σ���4���ڵ���Ϊ��β�ڵ㣻���ƶ�k % n = 2�Σ���3���ڵ���Ϊ��β�ڵ�

        if (add == n) { // ����k��n����������������ת
            return head;
        }
        iter->next = head; // ��ԭ��β�ڵ�ָ��ԭ��ͷ�ڵ㣬���ӳɻ� 
        while (add--) {
            iter = iter->next; // �ҵ����ؽ�������β�ڵ�
        }
        ListNode* ret = iter->next; // ���������ͷ�ڵ�
        iter->next = nullptr; // ����β�ڵ㴦�Ͽ� ��
        return ret;
    }
};

// ���ߣ�LeetCode-Solution
// ���ӣ�https://leetcode-cn.com/problems/rotate-list/solution/xuan-zhuan-lian-biao-by-leetcode-solutio-woq1/
// ��Դ�����ۣ�LeetCode��
// ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������