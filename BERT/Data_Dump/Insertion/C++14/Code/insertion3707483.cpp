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

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    rep(i,n){
        if(i==n-1) cout<<a[i]<<endl;
        else cout<<a[i]<<" ";
    }
    for(int i=1;i<n;i++){
        int v=a[i];
        int j=i-1;
        while(j>=0 && a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        rep(i,n){
            if(i==n-1) cout<<a[i]<<endl;
            else cout<<a[i]<<" ";
        }
    }
}

