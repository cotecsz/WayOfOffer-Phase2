//
// Created by dream on 2020/11/18.
//

#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        path.clear();
        res.clear();

        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracing(nums, 0, used);
        return res;
    }

private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracing(vector<int>& nums, int startIndex, vector<bool>& used){
        res.push_back(path);
        if (startIndex >= nums.size()){
            return ;
        }

        for (int i = startIndex; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false){
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracing(nums, i+1, used);
            used[i] = false;
            path.pop_back();
        }
    }
};

int main(){
    vector<int> nums{1, 2, 2};
    vector<vector<int>> res = {{},
                               {1},
                               {1, 2},
                               {1, 2, 2},
                               {2},
                               {2, 2}};
    Solution sol;
    assert(sol.subsetsWithDup(nums) == res);
    return 0;
}