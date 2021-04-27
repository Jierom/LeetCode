/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 15:05:43
 * @Description: 
 * @Ref: 
 */

#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if (!root) {
            return results;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> result;
            int n = q.size();
            while(n--) {
                TreeNode* s = q.front();
                q.pop();
                result.push_back(s->val);
                if(s->left) q.push(s->left);
                if(s->right) q.push(s->right);
            }
            results.push_back(result);
        }
        return results;
    }
};