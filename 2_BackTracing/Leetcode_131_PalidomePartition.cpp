//
// Created by dream on 2020/11/18.
//

#include <string>
#include <vector>
#include <assert.h>

using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        path.clear();
        res.clear();
        if (s.empty())      return res;

        backtracing(s, 0);
        return res;
    }

private:
    vector<string> path;
    vector<vector<string>> res;

    void backtracing(string& s, int startIndex){
        // 分割到字符串大小时，说明已分割出回文串，保存结果
        if (startIndex >= s.size()){
            res.push_back(path);
            return ;
        }

        for (int i = startIndex; i < s.size(); i++){
            // 切割完，双指针判断是否是回文串
            if (isPalidrome(s, startIndex, i)){
                string str = s.substr(startIndex, i-startIndex+1);
                path.push_back(str);
            }
            else{
                continue;
            }

            backtracing(s, i+1);
            path.pop_back();
        }
    }

    bool isPalidrome(string& s, int start, int end){
        for (int i=start, j = end; i < j; i++, j--){
            if (s[i] != s[j]){
                return false;
            }
        }

        return true;
    }
};

int main(){
    string s{"aab"};

    Solution sol;
    vector<vector<string>> res{{"a", "a", "b"},
                            {"aa", "b"}};

    assert(sol.partition(s) == res);
    return 0;
}