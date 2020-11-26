//
// Created by dream on 2020/11/26.
//

#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

/*
 * Leetcode15 三数之和
 *
 * 基本思路：
 *      使用双指针法，对数组排序，遍历数组中每个数，再使用双指针依次遍历，除去当前数的右侧数组。
 *
 *
 * 注意：
 *     一剪枝两去重：
 *     1. 当前数大于0时，直接剪枝（数组有序）
 *     2. 当前数 nums[i] 等于 下一个数num[i+1] 时，去重 （当前数nums[i[]）
 *     3. 当找到一组和为0时，去除等于左右边界数   （左右边界）
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        int length = nums.size();
        if (length == 0 || length < 3){
            return res;
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            // 剪枝
            if (nums[i] > 0)    continue;
            // 去重
            if (i > 0 && nums[i] == nums[i-1])  continue;

            int L = i + 1;
            int R = length - 1;
            while (L < R){
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0){
                    res.push_back({nums[i], nums[L], nums[R]});
                    // 去重
                    while (L < R && nums[L] == nums[L+1])   L++;
                    while (L < R && nums[R] == nums[R-1])   R--;
                    L++;
                    R--;
                }
                else if (sum < 0){
                   L++;
                }
                else{
                    R--;
                }
            }
        }
        return res;
    }
};


int main(){
    vector<int> nums {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = {{-1, -1, 2},
                       {-1, 0, 1}};

    Solution sol;
    assert(sol.threeSum(nums) == res);
    return 0;
}
