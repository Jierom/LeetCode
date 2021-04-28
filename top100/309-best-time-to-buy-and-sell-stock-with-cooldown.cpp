/*** 
 * @Author: gjwu
 * @Date: 2021-04-28 13:44:38
 * @Description: Medium - 最佳买卖股票时机含冷冻期
 * @Ref: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int* sell = new int[prices.size()];
        int* buy = new int[prices.size()];
        int* cool = new int[prices.size()];

        sell[0] = 0;
        buy[0] = -prices[0];
        cool[0] = 0;
        for (int i=1; i<prices.size(); i++) {
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
            buy[i] = max(buy[i-1], cool[i-1] - prices[i]);
            cool[i] = max(cool[i-1], buy[i-1]);
            cool[i] = max(cool[i], sell[i-1]);
        }
        return sell[prices.size()-1];
    }
};