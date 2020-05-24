/*
 * @Author: Eashin
 * @Date: 2020-05-24 21:41:14
 * @LastEditors: Eashin
 * @LastEditTime: 2020-05-24 22:38:51
 * @Description: 
 * @FilePath: /greedy/874-mo-ni-xing-zou-ji-qi-ren-by-leetcode.cpp
 */ 

#include<iostream>
#include <vector>
#include <set>

using namespace std;

/*
    觉得这题巧点在两处：
        1. 合理构造方向数组；【尝试过不用管方的方式，但C++较为繁琐。Python还是可接受的】
        2. 合理构造阻碍节点。【每前进一步都需要判断阻碍集合中是否存在改点，其实就是find操作，set对find较友好】
*/

class Solution {
public:
    int robotSim(vector<int>& commands, vector< vector<int> >& obstacles) {
        // make direction array: up<0,1>, down<0,-1>, left<-1,0> right<1,0>
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, dir = 0, dis = 0;
        set< pair<int,int> > obstaclesSet;  // 官方是 unordered_set，貌似不成功。可能是现在改动了。
        for(vector<int> obstacle : obstacles) {
            obstaclesSet.insert( make_pair(obstacle[0],obstacle[1]) );
        }
        for (int command : commands) {
            if (command == -2) dir = (dir + 3) % 4;
            else if (command == -1) dir = (dir + 1) % 4;
            else {
                for (int i = 0; i < command; i++) {
                    int tmp_x = x + dx[dir];
                    int tmp_y = y + dy[dir];
                    if (obstaclesSet.find(make_pair(tmp_x,tmp_y)) == obstaclesSet.end()) {
                        x = tmp_x;
                        y = tmp_y;
                        dis = max(dis, x*x+y*y);
                    }
                }
            }
        }
        return dis;
    }
};

int main() {
    int a[3] = {4,-1,3};
    vector<int> commands(a,a+3);
    vector< vector<int> > obstacles;
    Solution so;
    cout << so.robotSim(commands,obstacles);
    return 0;
}