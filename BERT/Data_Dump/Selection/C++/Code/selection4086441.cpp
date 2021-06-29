#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a.at(i);
    int count=0;

    rep(i,n){
        int minj=i;
        for(int j=i;j<n;j++){
            if(a.at(j)<a.at(minj)) minj=j;
        }
        if(a.at(minj)!=a.at(i)) count++;
        int tmp=a[i];
        a[i]=a[minj];
        a[minj]=tmp;
    }

    rep(i,n){
        cout<<a.at(i);
        if(i==n-1) cout<<endl;
        else cout<<" ";
    }
    cout<<count<<endl;

    
}
int main(){
    solve();
    return 0;
}
