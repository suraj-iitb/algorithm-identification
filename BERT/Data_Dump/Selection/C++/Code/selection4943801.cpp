#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
const int MOD = 1000000007;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}



int main(){
    int n; cin >> n; int a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    int cnt = 0;
    for(int i = 0;i < n - 1;i++){
        int minNum=a[i],minIndex=i;
        for(int j = i;j < n;j++){
            if(minNum > a[j]){
                minNum = a[j];minIndex = j;
            }
        }
        if(minIndex != i){
            swap(a[i],a[minIndex]);
            cnt++;
        }
    }
    for(int i = 0;i < n;i++){
        if(i != n - 1){
            cout << a[i] << " ";
        }else{
            cout << a[i] << endl;
        }
    }
    cout << cnt << endl;
}

