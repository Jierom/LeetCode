/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 13:31:36
 * @Description: Medium - 三数之和
 * @Ref: https://leetcode-cn.com/problems/regular-expression-matching/
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        nums = quickSort(nums, 0, nums.size()-1);

        for (int i=0; i<nums.size(); i++) {
            if (i==0 || nums[i]!=nums[i-1]) {
                int left = i+1;
                int right = nums.size()-1;

                while (left < right) {
                    if (nums[i] + nums[left] + nums[right] < 0) {
                        left++;
                    }
                    else if (nums[i] + nums[left] + nums[right] > 0) {
                        right--;
                    }
                    else {
                        if (left==i+1 || nums[left] != nums[left-1]) {
                            vector<int> result;
                            result.push_back(nums[i]);
                            result.push_back(nums[left]);
                            result.push_back(nums[right]);
                            results.push_back(result);
                        }
                        left++;
                        right--;
                    }
                }
            }
        }
        return results;
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = left;
        int slot = pivot + 1;
        for (int i=slot; i<=right; i++) {
            if (nums[i] < nums[pivot]) {
                int tmp = nums[i];
                nums[i] = nums[slot];
                nums[slot] = tmp;
                slot++;
            }
        }
        int tmp = nums[pivot];
        nums[pivot] = nums[slot-1];
        nums[slot-1] = tmp;
        return slot-1;
    }

    vector<int> quickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int p = partition(nums, left, right);
            quickSort(nums, left, p-1);
            quickSort(nums, p+1, right);
        }
        return nums;
    }
};