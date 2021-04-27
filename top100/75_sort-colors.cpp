/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 15:02:00
 * @Description: 
 * @Ref: 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 三指针交换
        int l = -1;
        int r = nums.size();

        for (int i=0; i<r; i++) {
            if (nums[i] == 0) {
                swap(nums, ++l, i);
            }
            else if (nums[i] == 2) {
                swap(nums, --r, i);
                i--;
            }
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};