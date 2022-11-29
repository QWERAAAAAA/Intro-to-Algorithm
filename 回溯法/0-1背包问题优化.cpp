// 优化当然是优化剪枝函数啦！

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

double Bound(int i){            // 计算上界（即将剩余物品装满剩余的背包容量时获得的最大价值）
    double cleft = W - cw;      // 剩余容量
    double brp = 0.0;
    while(i <= n && w[i] < cleft){
        cleft -= w[i];
        brp += v[i];
        i++;
    }
    if(i <= n){             // 采用切割的方式装满背包，这里是在求上界，求解时不允许切割
        brp += v[i] / w[i]*cleft;
    }
    return cp+brp;
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
        Backtrack(t+1);
        cw -= w[t];
        cp -= v[t];
    }

    if(Bound (t+1) > bestp){
        x[t] = 0;
        Backtrack(t+1);
    }
}

struct Object{          // 定义物品结构体
    int id;             // 物品序号
    double d;           // 单位价值
};

bool cmp(Object a1, Object a2){     // 按照物品单位价值由大到小排序
    return a1.d > a2.d;
}

void Knapsack(double W, int n){         // 背包算法
    // 初始化
    cw = 0;
    cp = 0;
    bestp = 0;
    double sumw = 0.0;          // 用来统计所有物品的总重量
    double sumv = 0.0;          // 用来统计所有物品的总价值

    Object Q[n];                // 物品结构体数组，用于排序
    double a[n+1], b[n+1];      // 辅助数组，用于把排序后的重量和价值传递给原来的重量价值数组

    for(i = 1; i <= n; i++){
        Q[i-1].id = i;
        Q[i-1].d = 1.0*v[i]/w[i];
        sumv += v[i];
        sumw += w[i];
    }
    if(sumw <= W){              // 如果总重量小于背包容量
        bestp  = sumv;
        cout << "放入购物车的物品最大价值为： " << bestp << endl;
        cout << "所有的物品均放入购物车。";
        return ;
    }
    sort(Q, Q+n, cmp);      // 按单位价值排序
    for(i = 1; i<=n; i++){      // 把排好序的数据传递给辅助数组
        a[i] = w[Q[i-1].id];
        b[i] = v[Q[i-1].id];
    }
    Backtrack(1);               // t=1 从第一层开始调用回溯法

    cout << "放入购物车的物品最大价值为：" << bestp << endl;
    cout << "放入购物车的物品序号为：";
    for(i = 1; i <= n; i++){
        if(bestx[i] == 1)
            cout << Q[i-1].id << " ";
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