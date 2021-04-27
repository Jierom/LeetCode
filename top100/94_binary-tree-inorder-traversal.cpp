/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 15:03:00
 * @Description: 
 * @Ref: 
 */


#include <iostream>
#include <vector>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nums;
        inoder(root, nums);
        return nums;
    }

    void inoder(TreeNode* root, vector<int>& nums) {
        if (root) {
            inoder(root->left, nums);
            nums.push_back(root->val);
            inoder(root->right, nums);
        }
    }
};