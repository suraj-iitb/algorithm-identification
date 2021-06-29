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

ll bubbleSort(vector<ll> &a,ll n){
    bool flag=true;
    ll ct=0;
    while(flag){
        flag=false;
        for(int j=n-1;j>0;j--){
            if(a[j]<a[j-1]){
                ll aa=a[j];
                a[j]=a[j-1];
                a[j-1]=aa;
                ct++;
                flag=true;
            }
        }
    }
    return ct;
}

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll k =bubbleSort(a,n);
    rep(i,n){
        if(i==n-1) cout<<a[i]<<endl;
        else cout<<a[i]<<" ";
    }
    cout<<k<<endl;
}

