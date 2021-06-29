#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
// #include <C:\include\boost\multiprecision\cpp_int.hpp>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define divup(a,b) ( ( (a) + ( (b) - 1u) ) / (b) ) // a/b の余り切り上げ
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
// using namespace boost::multiprecision;
ll mod = 1000000007;

ll selectionSort(vector<ll> &a,ll n){
    ll ct=0;
    for(int i=0;i<n;i++){
        ll minj=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj =j;
            }
        }
        if(a[i]!=a[minj]){
            swap(a[i],a[minj]);
            ct++;
        }
    }
    return ct;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll k =selectionSort(a,n);
    rep(i,n){
        if(i==n-1) cout<<a[i]<<endl;
        else cout<<a[i]<<" ";
    }
    cout<<k<<endl;
}

