//
// Created by dream on 2020/12/14.
//

#include <vector>
#include "assert.h"
using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int end = 0;
        int maxPos = 0;

        int res = 0;
        for (int i = 0; i < nums.size()-1; i++){
            maxPos = max(nums[i] + i, maxPos);
            if (end == i){
                end = maxPos;
                res++;
            }
        }

        return res;
    }

};

int main(){
    vector<int> nums {2,3,1,1,4};
    Solution sol;
    assert(sol.jump(nums) == 2);
    return 0;
}