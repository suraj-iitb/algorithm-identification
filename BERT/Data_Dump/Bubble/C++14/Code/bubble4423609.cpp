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
    bool flg=true;
    int count=0;
    int i=0;
    while(flg){
        flg=false;
        for(int j=n-1;j>=i+1;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                flg=true;
                count++;
            }
        }
        i++;
    }
    rep(i,n-1){
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
    cout<<count<<endl;
}
            



