/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 15:10:12
 * @Description: Easy - 买卖股票的最佳时机
 * @Ref: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 */

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = prices[0];
        int high = 0;
        for (int i=1; i<prices.size(); i++) {
            low = min(low, prices[i]);
            high = max(high, prices[i] - low);
        }
        return high;
    }
};