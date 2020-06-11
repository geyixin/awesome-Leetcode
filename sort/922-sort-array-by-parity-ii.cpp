/*
 * @Author: Eashin
 * @Date: 2020-06-11 22:32:30
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-11 22:59:37
 * @Description: 
 * @FilePath: /one test a day/922-sort-array-by-parity-ii.cpp
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
// 内存消耗大
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> A1, A2;
        for(int n : A){
            if(n%2==0) A2.push_back(n);
            else A1.push_back(n);
        }
        for(int i=0; i<A1.size(); i++){
            A[2*i] = A2[i];
            A[2*i+1] = A1[i];
        }
        return A;
    }

// 法2
    vector<int> sortArrayByParityII_2(vector<int>& A) {
        int j = 1;
        for(int i=0; i<A.size()-1; ){
            if(A[i]%2==0) {
                i += 2;
                continue;
            }
            else {
                while(1) {
                    if (A[j]%2==0) {
                        swap(A[i],A[j]);
                        i += 2;
                        j += 2;
                        break;
                    }
                    j += 2;
                }
            }
        }
        return A;
    }
};