/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 15:07:57
 * @Description: 
 * @Ref: 
 */


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

    int max = 0;

    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return max;
    }

    void dfs(TreeNode* node, int k) {
        if (node == nullptr) {
            if (k > max) {
                max = k - 1;
            }
            return;
        }
        k++;
        dfs(node->left, k);
        dfs(node->right, k);
    } 
};