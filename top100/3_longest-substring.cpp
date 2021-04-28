/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 14:56:22
 * @Description: Medium - 无重复字符的最长子串
 * @Ref: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int length = 0;
        for (; right < s.size(); right++) {
            int p = find_repeat(s, left, right);
            if (p != -1) {
                left = p + 1;
            }
            length = max(length, right-left+1);
        }
        return length;
    }

    int find_repeat(string s, int left, int right) {
        int repeat = -1;
        for (int i=left; i<right; i++) {
            if (s[i] == s[right]) {
                repeat = i;
                return repeat;
            }
        }
        return repeat;
    }
};