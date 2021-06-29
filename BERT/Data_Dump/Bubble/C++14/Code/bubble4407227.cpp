#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >>n;
    int a[n];
    rep(i,n) cin>>a[i];

    int flag = 1,num=0;
    while(flag){
        flag = 0;
        for(int j=n-1;j>0;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                num++;
                flag=1;
            }
        }
    }
    rep(i,n){
        cout << a[i];
        if(i<n-1) cout << " ";
    }
    cout << endl << num <<endl;
    return 0;
}
