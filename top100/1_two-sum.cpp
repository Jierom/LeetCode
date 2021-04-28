/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 14:53:03
 * @Description: Easy - 两数之和
 * @Ref: https://leetcode-cn.com/problems/two-sum/
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        bool hasFind = false;
        vector<int> results(2);

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int val1 = nums[i];
                int val2 = nums[j];
                int sum = val1 + val2;
                if (sum == target) {
                    hasFind = true;
                    results[0] = i;
                    results[1] = j;
                    break;
                }
            }
            if (hasFind == true) {
                break;
            }
        }
        return results;
    }
};