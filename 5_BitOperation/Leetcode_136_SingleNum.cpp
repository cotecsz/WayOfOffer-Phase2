//
// Created by dream on 2020/11/20.
//

#include <vector>
#include <assert.h>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int eor = 0;
        for (auto n : nums){
            eor ^= n;
        }

        return eor;
    }
};

int main(){
    vector<int> nums = {4, 1, 2, 1, 2};

    Solution sol;
    assert(sol.singleNumber(nums) == 4);
    return 0;
}