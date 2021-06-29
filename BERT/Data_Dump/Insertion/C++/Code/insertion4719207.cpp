#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)

int main(){
    ll n;
    cin >> n;
    ll a[n] = {};
    rep(i,0,n){
        cin >> a[i];
        cout << a[i];
        if(i != n-1) cout << " ";
        else cout << endl;
    }

    rep(i,1,n){
        ll v = a[i],j = i - 1;

        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        rep(k,0,n){
            cout << a[k];
            if(k != n-1) cout << " ";
            else cout << endl;
        }
    }
    return 0;
}

