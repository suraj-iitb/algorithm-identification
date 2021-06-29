#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[100];
    rep(i,n){
        cin>>a[i];
    }
    int count=0;
    rep(i,n){
        int minj=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        swap(a[i],a[minj]);
        if(a[i]!=a[minj])count++;
    }
    rep(i,n-1){
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
    cout<<count<<endl;
    return 0;
}
