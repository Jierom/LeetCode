/*** 
 * @Author: gjwu
 * @Date: 2021-04-29 15:17:41
 * @Description: Medium - 盛最多水的容器
 * @Ref: https://leetcode-cn.com/problems/container-with-most-water/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int result = 0;
        while (left < right) {
            int r = (right - left) * min(height[left], height[right]);
            result = max(result, r);
            if (height[left] <= height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return result;
    }
};