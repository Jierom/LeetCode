/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 15:04:38
 * @Description: Easy - 对称二叉树
 * @Ref: https://leetcode-cn.com/problems/symmetric-tree/
 */

#include <iostream>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* node1, TreeNode* node2) { 
        if (node1 == NULL && node2 == NULL) {
            return true;
        }
        else if (node1 == NULL || node2 == NULL) {
            return false;
        }
        return node1->val == node2->val && helper(node1->right, node2->left) && helper(node1->left, node2->right);
    }
};