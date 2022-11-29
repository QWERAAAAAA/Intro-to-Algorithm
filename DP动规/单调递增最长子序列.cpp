#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int i,j,n,r=1;
    int list[100],m[100];
    cin>>n;
    for(i = 1; i <= n; i++){
        cin>>list[i];
        m[i]=1;
    }
    for(i = 1;i <= n; i++){
        for(j = 1;j < i;j++)
            if(list[j]<list[i])
                m[i] = max(m[i],m[j]+1);
        r = max(r, m[i]);
    }
    cout<<r;
    return 0;
}