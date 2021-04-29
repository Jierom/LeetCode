/*** 
 * @Author: gjwu
 * @Date: 2021-04-29 15:10:28
 * @Description: Easy - 最大子序和
 * @Ref: https://leetcode-cn.com/problems/maximum-subarray/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int sum = nums[0];
        
        for (int i=1; i<nums.size(); i++) {
            if (sum < 0) {
                sum = nums[i];
            }
            else {
                sum += nums[i];
            }
            res = max(res, sum);
        }
        return res;
    }
};