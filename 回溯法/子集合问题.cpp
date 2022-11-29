// 约束条件：curNum <= c
// 限界条件：无。因为是“存在问题”，只要有一个解就行，无需找最优解。(需要剪枝，剪枝也是根据估值法)
// 解空间：{x1,x2,..., xn}，解空间树结构
// 解分量的显约束：放或不放，即xi取值为0或1
// 

#include<iostream>
#include<string>
#include<algorithm>
#define M 100
using namespace std;

int i, j, n, c;     // n为整数个数，c表示目标值
int S[M];           // S[]表示整数集合
int curNum;         // 当前的整数值
bool x[M];          // 表示第i个整数是否选
int sumNum = 0;

// void Backtrack(int t){
//     flag = 0;
//     if(curNum == c){
//         int k = 1;
//         for(j = 1; j <= n; j++){
//             if(x[j]){
//                 numList[k] = S[j];
//                 k++;
//             }
//         }
//         countN = k;
//         return ;
//     }
//     if(curNum + S[t] < c){
//         x[t] = 1;
//         curNum += S[t];
//         Backtrack(t+1);
//         curNum -= S[t];
//         flag = 1;
//     }
//     if(curNum < c && flag){
//         x[t] = 0;
//         Backtrack(t+1);
//     }
// }

bool Backtrack(int  t){
    if(curNum == c) return true;
    if(t>n) return false;
    sumNum -= S[t];
    if(curNum + S[t] <= c){
        x[t] = 1;
        curNum += S[t];
        if(Backtrack(t+1))
            return true;
        curNum -= S[t];
    }
    if(sumNum+curNum >= c){
        x[t] = 0;
        if(Backtrack(t+1)) return true;
    }
    sumNum += S[t];
    return false;
}
void Knapsack(int c, int n){
    curNum = 0;
    int min = S[1];
    for(i = 0; i < n; i++){
        if(S[i] < min)
            min = S[i];
        if(min > c){
            cout << "No Solution!";
            return ;
        }
        sumNum += S[i];  
    }
    if(sumNum < c){
        cout << "No Solution!";
        return ;
    }
    if(!Backtrack(0))
        cout << "No Solution!";
    else{
        for(i = 0; i < n; i++)
            if(x[i])    cout << S[i] << " ";
    }
}

int main(){
    cin >> n;
    cin >> c;
    for(i = 0; i < n; i++)
        cin >> S[i];
    Knapsack(c,n);
    return 0;
}

#include<iostream>
#include<string>
#include<algorithm>
#define M 1000
using namespace std;

int i, j, n, c;     // n为整数个数，c表示目标值
int S[M];           // S[]表示整数集合
int curNum;         // 当前的整数值
bool x[M];          // 表示第i个整数是否选
int sumNum = 0;

bool Backtrack(int  t){
    if(curNum == c) return true;
    if(t>n) return false;
    sumNum -= S[t];
    if(curNum + S[t] <= c){
        x[t] = 1;
        curNum += S[t];
        if(Backtrack(t+1))
            return true;
        curNum -= S[t];
    }
    if(sumNum+curNum >= c){
        x[t] = 0;
        if(Backtrack(t+1)) return true;
    }
    sumNum += S[t];
    return false;
}
void Knapsack(int c, int n){
    curNum = 0;
    int min = S[0];
    for(i = 0; i < n; i++){
        if(S[i] < min)
            min = S[i];
        if(min > c){
            cout << "No Solution!";
            return ;
        }
        sumNum += S[i];  
    }
    if(sumNum < c){
        cout << "No Solution!";
        return ; 
    }
    if(Backtrack(0) == false)
        cout << "No Solution!";
    else{
        for(i = 0; i < n; i++)
            if(x[i])    cout << S[i] << " ";
    }
}

int main(){
    cin >> n;
    cin >> c;
    for(i = 0; i < n; i++)
        cin >> S[i];
    Knapsack(c,n);
    return 0;
}
