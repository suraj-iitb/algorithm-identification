#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >>n;
    int a[n];
    rep(i,n) cin >>a[i];
    int num=0;
    rep(i,n){
        int minij=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minij])
            minij=j;
        }
        if(a[i]>a[minij]){
            swap(a[i],a[minij]);
            num++;
        }
    }
    rep(i,n){
        cout << a[i];
        if(i<n-1) cout << " ";
    }
    cout <<endl<<num<<endl;

    return 0;
}
