/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        //层序遍历————队列，还可以用BFS实现，看官方题解
        if (root->val % 2 == 0) return false;
        queue<TreeNode*> q;
        q.push(root);
        int curCeng = -1;
        while (!q.empty()) {
            curCeng++;
            int size = q.size();
            if (curCeng % 2 == 0) {
                int pre = -1;//偶数层单调递增
                for (int i = 0; i < size; ++i) {
                    TreeNode* node = q.front();
                    if (node->val % 2 == 0 || node->val <= pre) return false;
                    pre = node->val;
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            else {
                int pre = 1e6;// 奇数层单调递减
                for (int i = 0; i < size; ++i) {
                    TreeNode* node = q.front();
                    if (node->val % 2 == 1 || node->val >= pre) return false;
                    pre = node->val;
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
        }
        return true;
    }
};