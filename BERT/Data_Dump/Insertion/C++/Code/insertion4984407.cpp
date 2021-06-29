#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n){
        cout<<a[i];
        printf("%c", (i==n-1) ? '\n' : ' ');
    }
    for(int i=1;i<n;i++){
        for(int j= i-1;j>=0;j--){
            if(a[j]<=a[j+1]) break;
            swap(a[j+1],a[j]);
        }
        rep(i,n){
            cout<<a[i];
            printf("%c", (i==n-1) ? '\n' : ' ');
        }   
    }
}
