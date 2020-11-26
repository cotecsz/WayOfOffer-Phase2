//
// Created by dream on 2020/11/26.
//


#include <vector>
#include <unordered_map>
using namespace std;

/*
 * Leetcode 1 两数之和
 *      基本思路：依次将数及其对应索引 放入 map中，若target - nums[i] 在map中，
 *              说明找到结果，即nums[i] , 与 map.find(target - nums[i])
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++){
            auto iter = umap.find(target - nums[i]);
            if (iter != umap.end()){
                return {iter->second, i};
            }

            umap.insert({nums[i], i});
        }
    }
};

int main(){

    return 0;
}