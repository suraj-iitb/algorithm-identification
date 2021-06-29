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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n){
        cout << a[i];
        if(i < n-1) cout << " ";
    }
    cout << endl;

    rep2(i,n){
        ll v = a[i];
        ll j = i - 1;
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
            a[j+1] = v;
        }
        rep(j,n){
            cout << a[j];
            if(j < n-1) cout << " ";
        }
        cout << endl;
    }
}
