//
// Created by dream on 2020/11/20.
//

#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int eor = 0;
        for (auto n : nums){
            eor ^= n;               // eor = a ^ b
        }

        int rightOne = eor & (~eor + 1);    // 根据最右侧1将数分为两类，a b分别在不同的类别中
        int onlyOne = 0;
        for (auto n : nums){
            if ((rightOne & n) != 0){
                onlyOne ^= n;
            }
        }

        return {onlyOne, eor^onlyOne};
    }
};


int main(){
    vector<int> nums {1, 2, 1, 2, 1, 3, 4, 3, 4, 5};
    vector<int> res {5, 1};
    Solution sol;
    assert(sol.singleNumber(nums) == res);
    return 0;
}