/*
 * @Author: Eashin
 * @Date: 2020-05-25 19:43:47
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-25 21:01:17
 * @Description: 
 * @FilePath: /dynamic-programming/1025-divisor-game.cpp
 */ 

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
// DP 法
    bool divisorGame(int N) {
        if (N == 1) return false;
        if (N == 2) return true;
        vector<int> dp(N+1, 0);
        dp[2] = 1;
        for (int i=3; i<=N; i++) {
            for (int j=1; j<=i/2; ++j) {
                if (i%j==0 && dp[i-j]==0) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[N];
    }

// 归纳 法
    /*
        Alice要想赢，那必须将2掌握在自己手里。
        如果N为偶数，那Alice每次都选1，那Bob每次只能取奇数（奇数的约数必为奇数）；
        如果N为奇数，那Alice第一次选择之后的值可奇可偶数，如果为偶，则Alice必输，如果为奇，那选不到2，还是输。
        综上，N为偶数，Alice赢，反之Bob赢。
    */
    bool divisorGame2(int N) {
        return (N%2==0);
    }
};