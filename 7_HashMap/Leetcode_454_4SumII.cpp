//
// Created by dream on 2020/11/27.
//

#include <vector>
#include <unordered_map>
#include <assert.h>
using namespace std;

/*
 * Leetcode454 四数之和
 *      由于只需计算相加等于0的个数，所以解法与Leetcode1 两数之和异曲同工。
 */
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count = 0;
        unordered_map<int, int> umap;
        for (auto a : A){
            for (auto b : B){
                umap[a+b]++;
            }
        }

        for (auto c : C){
            for (auto d: D){
                if (umap.find(0 - (c + d)) != umap.end()){
                    count+= umap[0-(c+d)];
                }
            }
        }

        return count;
    }
};

int main(){
    vector<int> A {1, 2};
    vector<int> B {-2, -1};
    vector<int> C {-1, 2};
    vector<int> D {0, 2};

    Solution sol;
    assert(sol.fourSumCount(A, B, C, D) == 2);

    return 0;
}