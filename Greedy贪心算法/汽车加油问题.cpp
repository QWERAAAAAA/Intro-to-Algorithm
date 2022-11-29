#include<iostream>
#include<algorithm>
using namespace std;

struct Area{
    int a,b;
};
bool cmp(Area A1, Area A2){
    return A1.b < A2.b;
}
int main(){
    int n;
    Area ex[1000];
    cin>>n;
    for(int i=0; i<n; i++)
        cin >> ex[i].a>> ex[i].b;
    sort(ex,ex+n,cmp);
    int count=1;
    int c = 0;
    for(int i = 1; i<n;){
        if(ex[c].b >= ex[i].a){
            i++;
        }
        else{
            count++;
            c = i;
        }
    }
    cout << count;
    return 0;
}