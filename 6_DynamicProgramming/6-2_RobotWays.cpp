//
// Created by dream on 2020/12/15.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "assert.h"
using namespace std;

class Solution{
public:
    int getWays(int N, int start, int end, int K){
        if (start > N || end > N || N < 2 || K < 1 || start < 1 || end < 1)   return 0;

        return process(N, start, end, K);
    }

private:
    // 可变参数：start K
    int process(int N, int start, int end, int K){

        if (K == 0){
            return start == end ? 1 : 0;
        }

        if (start == 1){
            return process(N, 2, end, K-1);
        }
        if (start == N){
            return process(N, N-1, end, K-1);
        }

        return process(N, start - 1, end, K - 1)
            +  process(N, start + 1, end, K - 1);
    }
};


class SolutionHashMap{
public:
    int getWays(int N, int start, int K, int end){
        if (N < 1 || start < 1 || start > N || end < 1 || end > N || K < 1){
            return 0;
        }

        unordered_map<string, int> mem;
        process(N, start, K, end, mem);

        string key = to_string(start) + "_" + to_string(K);
        return mem[key];
    }

private:
    const int mod = 1e9 + 7;
    int process(int N, int start, int rest, int end, unordered_map<string, int>& mem){
        string key = to_string(start) + "_" + to_string(rest);
        if (mem.find(key) != mem.end()){
            return mem[key];
        }

        int ans = 0;
        if (rest == 0){
            ans = ((start == end) ? 1 : 0);
            mem.insert({key, ans});
            return ans;
        }

        if (start == 1){
            ans = process(N, 2, rest - 1, end, mem) % mod;
            mem.insert({key, ans});
            return ans;
        }

        if (start == N){
            ans = process(N, N-1, rest - 1, end, mem) % mod;
            mem.insert({key, ans});
            return ans;
        }

        ans = (process(N, start-1, rest - 1, end, mem)
                + process(N, start+1, rest - 1, end, mem)) % mod;
        mem.insert({key, ans});
        return ans;
    }
};

class SolutionVec{
public:
    int getWays(int N, int start, int K, int end){
        if (N < 1 || start < 1 || start > N || end < 1 || end > N || K < 1){
            return 0;
        }

        vector<vector<int>> cache(N+1, vector<int>(K+1, -1));

        int res = process(N, start, K, end, cache);
        return res;
    }

private:
    const int mod = 1e9 + 7;
    int process(int N, int cur, int rest, int end, vector<vector<int>>& cache){
        if (cache[cur][rest] != -1){
            return cache[cur][rest] ;
        }

        if (rest == 0){
            cache[cur][rest] = cur == end ? 1 : 0;
            return cache[cur][rest];
        }

        if (cur == 1){
            cache[cur][rest] = process(N, 2, rest - 1, end, cache) % mod;
            return cache[cur][rest];
        }

        if (cur == N){
            cache[cur][rest] = process(N, N - 1, rest - 1, end, cache) % mod;
            return cache[cur][rest];
        }

        cache[cur][rest] = (process(N, cur + 1, rest - 1, end, cache)
                           + process(N, cur - 1, rest - 1, end, cache)) % mod;

        return cache[cur][rest];
    }
};

class SolutionDP{
public:
    int getWays(int N, int start, int K, int end){
        if (N < 1 || start < 1 || start > N || end < 1 || end > N || K < 1){
            return 0;
        }

        const int mod = 1e9 + 7;
        vector<vector<int>> dp(N+1, vector<int>(K+1, 0));

        dp[end][0] = 1;
        for (int rest = 1; rest < K + 1; rest++){
            for (int cur = 1; cur < N + 1; cur++){
                if (cur == 1){
                    dp[cur][rest] = dp[2][rest-1] % mod;
                }
                else if (cur == N){
                    dp[cur][rest] = dp[N-1][rest-1] % mod;
                }
                else{
                    dp[cur][rest] = (dp[cur-1][rest-1] + dp[cur+1][rest-1]) % mod;
                }
            }
        }

        return dp[start][K];
    }
};

/*
    // 7 2 13 5             924
    // 7 4 9 2              0
    // 5 2 3 3              3
    // 5000 4548 5000 1600  602611261
 */
int main(){
    int N, K, start, end;
    cin >> N >>  start >>  K >> end;

//    Solution sol;
//    int res = sol.getWays(N, start, end, K);
//    cout << "res = " << res << endl;

//    SolutionHashMap solHash;
//    int resHash = solHash.getWays(N, start,  K, end);
//    cout << "Hashres = " << resHash << endl;


    SolutionVec solVec;
    int resVec = solVec.getWays(N, start, K, end);
    cout << "resVes = " << resVec << endl;


    SolutionDP solDP;
    int resDP = solDP.getWays(N, start, K, end);
    cout << "resDP = " << resDP << endl;

    return 0;
}
