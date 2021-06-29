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
    bool flag = true;
    for(int i = 0;flag;i++){
        flag = false;
        int j = n;
        while(j > i){
            j--;
            if(a[j-1] > a[j]){
                swap(a[j-1],a[j]);
                cnt++;
                flag = true;
            }
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

