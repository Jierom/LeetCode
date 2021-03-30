// 交换排序：冒泡排序，快速排序
// 插入排序：简单插入排序，希尔排序
// 选择排序：简单选择排序，堆排序
// 归并排序：二路归并排序，多路归并排序
// 非比较排序：计数排序，桶排序，基数排序

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// 辅助函数
void swap(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void print_nums(vector<int> nums) {
    for (int i=0; i<nums.size(); i++) {
        cout << nums[i] << ",";
    }
    cout << endl;
}

vector<int> split(vector<int> nums, int from, int to) {
    vector<int> result;
    for (int i=from; i<=to; i++) {
        result.push_back(nums[i]);
    }
    return result;
}

// 冒泡排序
vector<int> bubbleSort(vector<int>& nums) {
    for (int i=0; i<nums.size(); i++) {
        for (int j=0; j<nums.size()-i-1; j++) {
            if (nums[j] > nums[j+1]) {
                swap(nums, j, j+1);
            }
        }
    }
    return nums;
}

// 快速排序
int partition(vector<int>& nums, int left, int right) {
    int pivot = left;
    int index = pivot + 1;
    for (int i=index; i<= right; i++) {
        if (nums[i] < nums[pivot]) {
            swap(nums, i, index);
            index++;
        }
    }
    swap(nums, pivot, index-1);
    return index - 1;
}
vector<int> quickSort(vector<int>& nums, int left, int right) {
    if (left < right) {
        int p = partition(nums, left, right);
        quickSort(nums, left, p-1);
        quickSort(nums, p+1, right);
    }
    return nums;
}

// 简单插入排序
vector<int> insertSort(vector<int>& nums) {
    for (int i=1; i<nums.size(); i++) {
        int current = nums[i];
        int pre = i-1;
        for (; pre>=0 && nums[pre]>current; pre--) {
            nums[pre+1] = nums[pre];
        }
        nums[pre+1] = current;
    }
    return nums;
}

// 希尔排序
vector<int> shellSort(vector<int>& nums) {
    int len = nums.size();
    for (int gap = floor(len/2); gap > 0; gap = floor(gap/2)) {
        for (int i=gap; i<len; i++) {
            int current = nums[i];
            int pre = i-gap;
            for (; pre>=0 && nums[pre]>current; pre-=gap) {
                nums[pre+gap] = nums[pre];
            }
            nums[pre+gap] = current;
        }
    } 
    return nums;
}

// 简单选择排序
vector<int> selectSort(vector<int>& nums) {
    for (int i = 0; i<nums.size(); i++) {
        int min = nums[i];
        int index = i;
        for (int j=i; j<nums.size(); j++) {
            if (nums[j] < min) {
                min = nums[j];
                index = j;
            }
        }
        swap(nums, index, i);
    }
    return nums;
}

// 归并排序
vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> result;
    int i = 0, j = 0;
    while(i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i++]);
        }
        else {
            result.push_back(right[j++]);
        }
    }
    while (i < left.size()) {
        result.push_back(left[i++]);
    }
    while (j < right.size()) {
        result.push_back(right[j++]);
    }
    return result;
}
vector<int> mergeSort(const vector<int> &nums) {
    if (nums.size() < 2) {
        return nums;
    }
    int mid = (nums.size()-1)/2;
    vector<int> left = split(nums, 0, mid);
    vector<int> right = split(nums, mid+1, nums.size()-1);
    return merge(mergeSort(left), mergeSort(right));
}


int main() {
    vector<int> nums = {3,5,2,4,7,9,6,8,1,3};
    // nums = bubbleSort(nums);
    // nums = quickSort(nums, 0, nums.size()-1);
    // nums = insertSort(nums);
    // nums = shellSort(nums);
    // nums = selectSort(nums);
    // nums = mergeSort(nums);
    print_nums(nums);
    return 0;
}
