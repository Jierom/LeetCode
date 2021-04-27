

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
    int result = 0;

    int maxPathSum(TreeNode* root) {
        result = root->val;
        dfs(root);
        return result;
    }

    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);
        result = max(root->val+left+right, result);
        return max(root->val+left, root->val+right);
    }
};