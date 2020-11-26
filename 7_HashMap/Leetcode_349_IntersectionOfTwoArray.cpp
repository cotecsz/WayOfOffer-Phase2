//
// Created by dream on 2020/11/26.
//


#include <vector>
#include <unordered_set>
#include <assert.h>
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> res_set;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());

        for (auto n : nums2){
            if (nums1_set.find(n) != nums1_set.end()){
                res_set.insert(n);
            }
        }

        vector<int> res(res_set.begin(), res_set.end());
        return res;
    }
};

int main(){
    vector<int> nums1 {1, 2, 3 ,3, 3, 4};
    vector<int> nums2 {2, 2, 2, 3, 3, 3};
    vector<int> res = {3, 2};

    Solution sol;
    assert(sol.intersection(nums1, nums2) == res);

    return 0;
}