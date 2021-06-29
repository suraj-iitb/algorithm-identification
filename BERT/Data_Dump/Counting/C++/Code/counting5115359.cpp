#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    //cの長さ
    int max_ = 0;
    rep(i,n){
        cin>>a[i];
        max_ = max(a[i],max_);
    }
    max_++;
    //c[x] represents the number of values less than valuable x
    vector<int> c(max_,0);
    rep(i,n){
        c[a[i]]++;
    }
    for(int i=1;i<max_;i++){
        c[i] = c[i-1]+c[i];
    }
    //for output
    vector<int> b(n);
    rep(i,n){
        b[c[a[i]]-1] = a[i];
        c[a[i]]--;
    }
    rep(i,n){
        cout<<b[i];
        printf("%c",i==n-1?'\n':' ');
    }
    return 0;
}
