//
// Created by dream on 2020/11/26.
//

#include <unordered_set>
#include <assert.h>
using namespace std;

/*
 * Leetcode202 快乐数
 *
 *    求得快乐数，判断是否等于1，如果不等于1， 判断集合中是否存在sum，如果存在则会循环。不存在则继续求快乐数。
 */
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>  uset;
        while (true){
            int sum = getSum(n);

            if (sum == 1){
                return true;
            }
            if (uset.find(sum) != uset.end()){
                return false;
            }
            else{
                uset.insert(sum);
            }

            n = sum;
        }
    }

private:
    int getSum(int n){
        int sum = 0;
        while (n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};

int main(){
    int n = 19;

    Solution sol;
    assert(sol.isHappy(n));
    return 0;
}