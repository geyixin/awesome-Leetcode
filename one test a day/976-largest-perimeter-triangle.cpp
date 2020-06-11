/*
 * @Author: Eashin
 * @Date: 2020-06-11 23:06:58
 * @LastEditors: Eashin
 * @LastEditTime: 2020-06-11 23:12:35
 * @Description: 
 * @FilePath: /one test a day/976-largest-perimeter-triangle.cpp
 */ 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Soluton {
public:
    static bool cmp(int a, int b) {
        return a>b;
    }
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end(),cmp);
        for(int i=0; i<A.size()-2; i++) {
            if (A[i] < (A[i+1] + A[i+2])) return A[i]+A[i+1]+A[i+2];
        }
        return 0;
    }    
};
