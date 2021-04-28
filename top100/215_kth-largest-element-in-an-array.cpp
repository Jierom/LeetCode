/*** 
 * @Author: gjwu
 * @Date: 2021-04-28 13:42:02
 * @Description: Medium - 数组中的第K个最大元素
 * @Ref: https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size()-1);
        return nums[nums.size() - k];
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = left;
        int slot = pivot + 1;
        for (int i=left+1; i<=right; i++) {
            if (nums[i] < nums[pivot]) {
                swap(nums, i, slot);
                slot++;
            }
        }
        swap(nums, pivot, slot-1);
        return slot-1;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int p = partition(nums, left, right);
            quickSort(nums, left, p-1);
            quickSort(nums, p+1, right);
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};