//
// Created by dream on 2020/12/14.
//
#include <vector>
#include "assert.h"
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1)   return true;
        for (int i = 0; i <= cover; i++){
            cover = max(nums[i] + i, cover);
            if (cover >= nums.size() - 1)    return true;
        }
        return false;
    }
};


int main(){
    vector<int> nums {2,3,1,1,4};

    Solution sol;
    assert(sol.canJump(nums));
    return 0;
} 