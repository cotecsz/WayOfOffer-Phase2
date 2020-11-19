//
// Created by dream on 2020/11/19.
//

#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        res.clear();

        backtracing(nums, 0);
        return res;
    }

private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracing(vector<int>& nums, int startIndex){
        if (path.size() > 1){
            res.push_back(path);
            // 不用return, 继续深搜
        }

        // 去重：使用set
        unordered_set<int> uset;
        for(int i = startIndex; i < nums.size(); i++){
            if (!path.empty() && nums[i] < path.back()
                ||  uset.find(nums[i]) != uset.end()){        // 选取的数比path中最后一个数小（非递增）
                continue;                                     // unset 中是否已经使用过unset
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracing(nums, i+1);
            path.pop_back();
        }
    }
};


int main(){
    vector<int> nums {4, 6, 7, 7};
    vector<vector<int>> res = {{4, 6},
                               {4, 6, 7},
                               {4, 6, 7, 7},
                               {4, 7},
                               {4,7,7},
                               {6, 7},
                               {6, 7, 7},
                               {7,7}
    };

    Solution sol;
    vector<vector<int>> res = sol.findSubsequences(nums);
    return 0;
}