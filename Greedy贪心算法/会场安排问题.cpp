#include<iostream>
#include<algorithm>
using namespace std;

struct Act{
    int begin, end;
};
bool cmp(Act a, Act b){
    if(a.begin == b.begin)
        return a.end < b.end;
    return a.begin < b.begin;
}

int main(){
    int k, place = 1;
    int i, j;
    cin >> k;
    Act activity[100], temp[100];
    for(int i = 0; i < k; i++)
        cin >> activity[i].begin >> activity[i].end;
    sort(activity, activity+k, cmp);
    temp[0] = activity[0];
    for(i = 1; i < k; i++){
        for(j = 0; j < place; j++){
            if(activity[i].begin >= temp[j].end){
                temp[j] = activity[i];
                break;
            }
        }
        if(j == place){
            temp[place++] = activity[i];
        }
    }
    cout << place;
    return 0;
}