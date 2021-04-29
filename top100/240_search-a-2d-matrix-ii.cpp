/*** 
 * @Author: gjwu
 * @Date: 2021-04-29 17:08:22
 * @Description: Medium - 搜索二维矩阵 II
 * @Ref: https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n-1;
        while (i<=m-1 && j>=0) {
            // 向左收缩
            if (matrix[i][j] > target) {
                j--;
            }
            // 向下收缩
            else if (matrix[i][j] < target) {
                i++;
            }
            else {
                return true;
            }
        }
        return false;
    }
};