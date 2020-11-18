//
// Created by dream on 2020/11/18.
//

#include <vector>
#include <string>
#include <assert.h>
using namespace std;


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if (s.empty())  return res;

        backtracing(s, 0, 0);
        return res;
    }

private:
    vector<string> res;
    void backtracing(string& s, int startIndex, int pointNum){
        if (pointNum == 3){
            if (isValid(s, startIndex, s.size()-1)){
                res.push_back(s);
            }
            return ;
        }

        for (int i = startIndex; i < s.size(); i++){
            if (isValid(s, startIndex, i)){
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backtracing(s, i+2, pointNum);          // i+2, 插入. 所以后移两位
                pointNum--;
                s.erase(s.begin() + i + 1);
            }
            else{
                break;
            }
        }
    }

    bool isValid(string& s, int start, int end){
         if (start > end)    return false;      // "1111"

        // 以0开头的地址不合法，首尾都为0，即0合法
        if (s[start] == '0' && start != end)    return false;

        int num = 0;
        for (int i = start; i <= end; i++){
            if (s[i] < '0' || s[i] > '9'){
                return false;
            }

            num = num * 10 + (s[i] - '0');
            if (num > 255){
                return false;
            }
        }

        return true;
    }
};


int main(){
    string s{"25525511135"};
    string s2{"1111"};

    vector<string> res = {"255.255.11.135",
                          "255.255.111.35"};

    Solution sol;
    res = sol.restoreIpAddresses(s2);
    assert(sol.restoreIpAddresses(s) == res);

    return 0;
}