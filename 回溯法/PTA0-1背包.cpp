#include<iostream>
#define M 200
using namespace std;

/********************************************************
FileName:		PTA练习 0-1背包
Author:        	M12J10
Created:       	2022/11/28
Description:	回溯法练习。
********************************************************/

int w[M], v[M];
bool x[M] = {0};
int i, n, C;
int cw = 0, cv = 0, rp = 0;
int bestv = 0;

int bound(int t){
    for(i = t; i < n; i++)
        rp += v[i];
    return cv + rp;
}

void Backtrack(int t){
    if(t>n){        // 触底记录
        if(cv > bestv)
            bestv = cv;
        return ;
    }
    if(cw + w[t] <= C){       // 满足约束条件
        x[t] = 1;
        cw += w[t];
        cv += v[t];
        Backtrack(t+1);
        cw -= w[t];
        cv -= v[t];
    }
    if(bestv < bound(t+1)){                   // 满足限界条件
        x[t] = 0;
        Backtrack(t+1);
    }
}
void Knapsack(){
    int sum = 0;
    for(i = 0; i < n; i++)
        sum += w[i];
    if(sum <= C){
        for(i = 0; i < n; i++){
            bestv += v[i];
        }
        return ;
    }
    Backtrack(0);
    return ;
}
int main(){
    cin >> n >> C;
    for(i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    Knapsack();
    cout << bestv << endl;
    return 0;
}