#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    int minj;
    rep(i,n){
        minj = i;
        for(int j = i; j < n; j++){
            if(a[j]<a[minj]) minj = j;
        }
        if(minj != i){
            swap(a[minj],a[i]);
            ans++;
        }
    }
    rep(i,n-1){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    cout << ans << endl;

}
