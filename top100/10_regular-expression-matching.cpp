/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 13:36:42
 * @Description: 正则表达式匹配
 * @Ref: https://leetcode-cn.com/problems/regular-expression-matching/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        bool** dp = new bool*[m+1];
        for (int i=0; i<m+1; i++) {
            dp[i] = new bool[n+1];
            for (int j=0; j<n+1; j++) {
                dp[i][j] = false;
            }
        }

        // 初始化 "" 和 * 的匹配关系
        dp[0][0] = true;
        for (int j=2; j<=n; j+=2) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }

        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                char sc = s[i-1];
                char pc = p[j-1];
                // 当前字符能够匹配
                if (sc == pc || pc == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (pc == '*') {
                    // 抵消上一个字符
                    if (dp[i][j-2]) {
                        dp[i][j] = true;
                    }
                    // 上一个字符匹配得上
                    else if (sc == p[j-2] || p[j-2] == '.') {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};