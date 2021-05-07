/*** 
 * @Author: gjwu
 * @Date: 2021-05-07 14:21:01
 * @Description: Hard - 接雨水
 * @Ref: https://leetcode-cn.com/problems/trapping-rain-water/
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        stack<int> stack;
        int ans = 0;
        for (int i=0; i<height.size(); i++) {
            while(!stack.empty() && height[stack.top()] < height[i]) {
                int tmpIndex = stack.top();
                stack.pop();
                // 栈顶相同元素只留一个
                while (!stack.empty() && height[stack.top()] == height[tmpIndex]) {
                    stack.pop();
                }

                if (!stack.empty()) {
                    int stackTop = stack.top();
                    ans += (min(height[stackTop], height[i]) - height[tmpIndex]) * (i-stackTop-1);
                } 
            }
            stack.push(i);
        }
        return ans;
    }
};