#include <bits/stdc++.h>
using namespace std;
#define rep(i,n,x) for(int i=n;i<x;i++)
const int MAX_N = 100;

void trace(vector<int> a, int n){
    rep(i,0,n){
        if(i>0) cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    return;
}

int main() {
    int n; cin>>n;
    vector<int> a(n); rep(i,0,n) cin>>a[i];

    trace(a, n);
    rep(i,1,n){
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v; 
        trace(a, n);
    }

    return 0;
}
