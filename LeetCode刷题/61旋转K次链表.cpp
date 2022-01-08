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
 // 此题解更容易理解 ——————方法一
// class Solution {
// public:
//     ListNode* rotateOnce(ListNode* head) { // 至少有两个节点，找到尾节点last，将其指向head，再将last的上一个指向空
//         ListNode* last = head->next;
//         ListNode* preLast= head; // 维护一个尾节点的上一个，最后将其作为新的尾节点，指向空
//         while (last->next != nullptr) {
//             preLast = last;
//             last = last->next;
//         }
//         // 此时已经找到了原来的尾节点
//         // 将其指向原来的头节点
//         last->next = head;
//         // 将原来为节点的上一个节点的下一个next置为空
//         preLast->next = nullptr;
//         return last; // 返回链表的新头部
//     }

//     ListNode* rotateRight(ListNode* head, int k) {
//         if (head == nullptr || head->next == nullptr || k == 0) return head;
//         // [1,2,3],2000000000 当k过大时，会超时，可以优化旋转的次数，首先计算节点的个数n，用k对n取余数，再去计算旋转的次数会小于节点的个数
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

// 官方题解————闭合为环
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
        // 比如示例1，n = 5，k = 2
        int add = n - k % n; // 3,原来链表的第3个节点作为旋转后的尾节点，k % n 肯定小于等于 n的，若移动k % n = 1次，第4个节点作为新尾节点；若移动k % n = 2次，第3个节点作为新尾节点

        if (add == n) { // 假如k是n的整数倍，不用旋转
            return head;
        }
        iter->next = head; // 将原来尾节点指向原来头节点，连接成环 
        while (add--) {
            iter = iter->next; // 找到返回结果链表的尾节点
        }
        ListNode* ret = iter->next; // 返回链表的头节点
        iter->next = nullptr; // 从新尾节点处断开 环
        return ret;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/rotate-list/solution/xuan-zhuan-lian-biao-by-leetcode-solutio-woq1/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。