//
// Created by dream on 2020/11/27.
//


#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int length = nums.size();
        if (length < 4){
            return res;
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < length; i++){
            // 去重
            if (i > 0 && nums[i] == nums[i - 1])    continue;

            for (int j = i+1; j < length; j++){
                // 去重:
                if (j > i + 1 && nums[j] == nums[j - 1])    continue;

                int L = j + 1;
                int R = length - 1;
                while (L < R){
                    int sum = nums[i] + nums[j] + nums[L] + nums[R];
                    if (sum == target){
                        res.push_back({nums[i], nums[j], nums[L], nums[R]});
                        while (L < R && nums[L] == nums[L + 1])     L++;
                        while (L < R && nums[R] == nums[R - 1])     R--;
                        L++;
                        R--;
                    }
                    else if (sum < target){
                        L++;
                    }
                    else{
                        R--;
                    }
                }
            }
        }

        return res;
    }
};


int main(){
    vector<int> nums {1, 0, -1, 0, -2, 2};
    vector<vector<int>> res {{-2, -1, 1, 2},
                             {-2, 0, 0, 2},
                             {-1, 0, 0, 1}};

    Solution sol;
    assert(sol.fourSum(nums, 0) == res);
    return 0;
}