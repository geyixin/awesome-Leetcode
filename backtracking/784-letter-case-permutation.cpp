/*
 * @Author: Eashin
 * @Date: 2020-06-14 22:19:49
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-14 23:05:25
 * @Description: 
 * @FilePath: /backtracking/784-letter-case-permutation.cpp
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
// 递归
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        helper(S,0,res);
        return res;
    }

    void helper(string s, int index, vector<string>& res) {
        if(index == s.size()) {
            res.push_back(s);
            return;
        }
        helper(s,index+1,res);
        if(isalpha(s[index])) {
            if(islower(s[index])) s[index] = toupper(s[index]);
            else if(isupper(s[index])) s[index] = tolower(s[index]);
            helper(s,index+1,res);
        }
    }

// 非递归【牛人版本。思路不错】
    vector<string> letterCasePermutation_2(string S) {
        vector<string> ans{S};  // S="a1b2", ans = {"asb2"}
        for(int i = 0; i < S.size(); i++){
            if(isalpha(S[i])){
                for(int j = ans.size() - 1; j >= 0; j--){   // key
                    ans.push_back(ans[j]);
                    if(isupper(ans[j][i])) ans[j][i] = tolower(ans[j][i]);
                    else ans[j][i] = toupper(ans[j][i]);
                }
            }
        }
        return ans;
    }
};