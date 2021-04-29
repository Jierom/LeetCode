/*** 
 * @Author: gjwu
 * @Date: 2021-04-29 16:56:07
 * @Description: Medium - 括号生成
 * @Ref: https://leetcode-cn.com/problems/generate-parentheses/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> result;

    vector<string> generateParenthesis(int n) {
        dfs(n, n, "");
        return result;
    }

    void dfs(int left, int right, string str) {
        if (left == 0 && right == 0) {
            result.push_back(str);
            return;
        }

        if (left > 0) {
            dfs(left-1, right, str+"(");
        }
        if (right > left) {
            dfs(left, right-1, str+")");
        }
    }
};