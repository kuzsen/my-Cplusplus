// 手撕算法：
// 1、实现哈希表的查找和插入，不会写，接下来补充
// 2、实现二叉查找树的插入功能，写出来了
// C++从代码到可执行程序的过程：预编译、编译、汇编、链接、还讲了静态与动态链接的区别
// map与unordered_map的区别
// 为什么map底层用红黑树？回答了红黑树与平衡二叉树的区别

// 然后就结束了？可能是第一个算法不会写？或者是八股文背的太明显？


#include <iostream>
#include <vector>
using namespace std;

struct treeNode {
    int val;
    treeNode* left;
    treeNode* right;
    treeNode() : val(0), left(nullptr), right(nullptr) {};
    treeNode(int v) : val(v), left(nullptr), right(nullptr) {};
    treeNode(int v, treeNode* _l, treeNode* _r) : val(v), left(_l), right(_r) {};
};
treeNode* findTree(treeNode* root, treeNode* inNode) {
    if (root == nullptr) return inNode;
    if (root->left == nullptr && root->right == nullptr) {
        if (root->val < inNode->val) root->right = inNode;
        else root->left = inNode;
        return root;
    }
    if (root->left && root->right == nullptr) {
        if (root->val < inNode->val) {
            root->right = inNode;
            return root;
        }
        else {
            return findTree(root->left, inNode);
        }
    }
    if (root->left == nullptr && root->right) {
        if (root->val < inNode->val) {
            return findTree(root->right, inNode);
        }
        else {
            root->left = inNode;
            return root;
        }
    }
    if (root->val < inNode->val) {
        return findTree(root->right, inNode);
    }
    else {
        return findTree(root->left, inNode);
    }
}
int main() {
    //int a;
    //cin >> a;
    cout << "Hello World!" << endl;
}