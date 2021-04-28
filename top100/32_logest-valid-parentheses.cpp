/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 14:59:42
 * @Description: Hard - 最长有效括号
 * @Ref: https://leetcode-cn.com/problems/longest-valid-parentheses/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int ans = 0;
        vector<int> dp(s.length(), 0);

        for (int i=1; i<s.length(); i++) {

            if (s[i] == ')') {
                int j = i - dp[i-1] - 1;
                if (j >= 0 && s[j] == '(') {
                    dp[i] = (i-j+1) + (j>=1 ? dp[j-1] : 0);
                }
            }
            ans = ans > dp[i] ? ans : dp[i];
        }
        return ans;
    }
};