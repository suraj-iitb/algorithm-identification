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
    for(int i = 0;i < n;i++){
        if(i != n - 1){
            cout << a[i] << " ";
        }else{
            cout << a[i] << endl;
        }
    }
    for(int i = 1;i < n;i++){
        int z = a[i];
        int j = i-1;
        while(j >= 0 && z < a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = z;
        for(int i = 0;i < n;i++){
            if(i != n - 1){
                cout << a[i] << " ";
            }else{
                cout << a[i] << endl;
            }
        }
    }
}

