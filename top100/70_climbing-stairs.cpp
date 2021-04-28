/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 14:59:42
 * @Description: Easy - 爬楼梯
 * @Ref: https://leetcode-cn.com/problems/climbing-stairs/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n==1) {
            return 1;
        }
        if (n==2) {
            return 2;
        }
        int* dp = new int[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i=3; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};