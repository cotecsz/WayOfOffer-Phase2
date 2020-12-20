//
// Created by dream on 2020/12/20.
//

#include <vector>
#include <iostream>
using namespace std;


// 组合方法数
class Solution{
public:
    int getWays(vector<int> arr, int aim){
        if (arr.size() == 0 || aim < 0){
            return 0;
        }

        int res = process(arr, 0, aim);
        return res == 0 ? -1 : res;
    }


private:
    int process(vector<int>& arr, int index, int rest){
        if (index == arr.size() ){
            return rest == 0 ? 1 : 0;
        }

        int res = 0;
        for (int i = 0; i * arr[index] <= rest; i++){
            res += process(arr, index + 1, (rest - i * arr[index]));
        }

        return res;
    }
};

class SolutionDP {
public:
    int getWays(vector<int> arr, int aim) {
        if (arr.size() == 0 || aim < 0){
            return 0;
        }

        int N = arr.size();
        vector<vector<int>> dp (N + 1, vector<int>(aim+1, 0));
        dp[N][0] = 1;

        for (int i = N - 1; i >= 0; i--){
            for (int rest = 0; rest <= aim; rest++){
                dp[i][rest] = dp[i+1][rest];
                if (rest - arr[i] >= 0){
                    dp[i][rest] += dp[i][rest - arr[i]];
                }
            }
        }

        return dp[0][aim];
    }
};

int main(){
    int N , aim;
    cin >> N >> aim;
    vector<int> arr(N, 0);

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    Solution sol;
    int res = sol.getWays(arr, aim);
    cout << res << endl;

    SolutionDP solDP;
    int resDP = solDP.getWays(arr, aim);
    cout << resDP << endl;
    return 0;
}