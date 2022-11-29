/********************************************************
FileName:		回溯法解决0-1背包问题
Author:        	M12J10
Created:       	2022/11/28
Description:	回溯法应用。
********************************************************/

/*
    重要伪代码分析：

    1. 计算上界
    // cp为已装包的物品总价值

    double Bound(int i){            // 上界函数，也是剪枝函数
        int rp = 0;        
        while(i <= n){      // 剩余物品为第i～n种物品，计算剩余物品的价值上界（都装包）
            rp += v[i];
            i++;
        }
        return cp + rp;     // 返回上界
    }

    2. 按约束条件和限界条件搜索
    // 死结点回溯时，使用限界条件判断（右子树）
    // 向下扩展时，使用约束条件判断（左子树）

    void Backtrack(int t){                  // t表示当前扩展结点在第t层

        if(t > n){                          // 已经到达叶子结点（触底）
            for(j = 1; j <= n; j++){
                bestx[j] = x[j];            // 用bestx[]保存当前最优解{x1,x2,x3,...,xn}
            }
            bestp = cp;                     // 用bestp保存当前最优值cp
            return ;
        }

        if(cw + w[t] <= W){                 // 如果满足约束条件则搜索左子树
            x[t] = 1;
            cw += w[t];
            cp += v[t];
            Backtrack(t+1);
            cw -= w[t];
            cp -= v[t];
        }

        if(Bound(t+1) > bestp){             // 如果满足限界条件则搜索右子树
            x[t] = 0;
            Backtrack(t+1);
        }
    }

    // 这三个if的设置顺序很有讲究的！！！
*/

#include<iostream>
#include<string>
#include<algorithm>
#define M 105
using namespace std;

// 变量定义为全局变量
int i, j, n, W;             // n表示n个物品，W表示购物车的容量
double w[M], v[M];          // w[i]表示第i个物品的重量，v[i]表示第i个物品的价值
bool x[M];                  // x[i]表示第i个物品是否放入购物车
double cw;                  // 当前重量
double cp;                  // 当前价值
double bestp;               // 当前最优价值
bool bestx[M];              // 当前最优解序列

double Bound(int i){
    int rp = 0;
    while(i <= n){
        rp += v[i];
        i++;
    }
    return cp+rp;
}

void Backtrack(int t){          // 回溯法算法
    if(t>n){
        for(j = 1; j <= n; j++)
            bestx[j] = x[j];
        bestp = cp;
        return ;
    }

    if(cw + w[t] <= W){
        x[t] = 1;
        cw += w[t];
        cp +=v[t];
        Backtrack(t + 1);
        cw -= w[t];
        cp -= v[t];
    }

    if(Bound (t+1) > bestp){
        x[t] = 0;
        Backtrack(t+1);
    }
}

void Knapsack(double W, int n){         // 背包算法
    // 初始化
    cw = 0;
    cp = 0;
    bestp = 0;
    double sumw = 0.0;          // 用来统计所有物品的总重量
    double sumv = 0.0;          // 用来统计所有物品的总价值
    for(i = 1; i <= n; i++){
        sumv += v[i];
        sumw += w[i];
    }
    if(sumw <= W){              // 如果总重量小于背包容量
        bestp  = sumv;
        cout << "放入购物车的物品最大价值为： " << bestp << endl;
        cout << "所有的物品均放入购物车。";
        return ;
    }

    Backtrack(1);               // t=1 从第一层开始调用回溯法

    cout << "放入购物车的物品最大价值为：" << bestp << endl;
    cout << "放入购物车的物品序号为：";
    for(i = 1; i <= n; i++){
        if(bestx[i] == 1)
            cout << i << " ";
    }
    cout << endl;
}

int main(){
    cout << "请输入物品的个数n: ";
    cin >> n;
    cout << "请输入购物车的容量W: ";
    cin >> W;
    cout << "请依次输入每个物品的重量w和价值v, 用空格分开: ";
    for(i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    Knapsack(W,n);          // 调用背包算法
    return 0;
}