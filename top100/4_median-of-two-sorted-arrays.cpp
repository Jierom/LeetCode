/*** 
 * @Author: gjwu
 * @Date: 2021-05-07 13:09:56
 * @Description: Hard - 寻找两个正序数组的中位数
 * @Ref: https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 */

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int M = nums1.size();
        int N = nums2.size();

        // 保证 nums1 长度小于 nums2
        if (M > N) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int k = (M + N + 1) / 2;
        int l = 0, r = M;
        int m1 = 0, m2 = 0;
        while (l < r) {
            m1 = (r+l) / 2;     // nums1位置
            m2 = k - m1;        // nums2位置
            if (nums1[m1] < nums2[m2-1]) {
                l = m1 + 1;
            } else {
                r = m1;
            }
        }
        m1 = l;
        m2 = k - l;

        double ans;
        // 偶数个
        if ((M+N)%2 == 0) {
            double c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
                            m2 <= 0 ? INT_MIN : nums2[m2 - 1]);
            double c2 = min(m1 >= M ? INT_MAX : nums1[m1],
                            m2 >= N ? INT_MAX : nums2[m2]);
            ans = (c1 + c2) / 2;
        } 
        // 奇数个
        else {
            double c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
                m2 <= 0 ? INT_MIN : nums2[m2 - 1]);
            ans = c1;
        }
        return ans;
    }
};