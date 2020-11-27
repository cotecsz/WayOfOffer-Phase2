//
// Created by dream on 2020/11/27.
//

#include <string>
#include <assert.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};

        for (auto c : magazine){
            record[c - 'a']++;
        }

        for (auto c : ransomNote){
            if (record[c - 'a'] == 0){
                return false;
            }
            record[c - 'a']--;
        }

        return true;
    }

};

int main(){
    string magazine {"aab"};
    string ransomNote {"aa"};

    Solution sol;
    assert(sol.canConstruct(ransomNote, magazine));
    return 0;
}