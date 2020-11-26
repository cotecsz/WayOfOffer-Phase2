//
// Created by dream on 2020/11/26.
//

#include <string>
#include <assert.h>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }

        int record[26] = {0};
        for (auto c : s){
            record[c - 'a']++;
        }

        for (auto c : t ){
            if (record[c - 'a'] == 0){
                return false;
            }
            record[c - 'a']--;
        }
        return true;
    }
};

int main(){
    string s("anagram");
    string t("nagrmaa");

    Solution sol;
    assert(sol.isAnagram(s, t));
    return 0;
}