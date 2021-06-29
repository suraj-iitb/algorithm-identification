#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;


int main(){
    int n;
    cin >>n;
    int a[n];
    rep(i,n) cin >>a[i];
    rep(i,n+1){
        if(i==0)i++;
        int v=a[i];
        int j=i-1;
        rep(k,n) {
            cout << a[k];
            if(k<n-1) cout << " ";
        }
        cout <<endl;
        while(j>=0 && a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1] =v;
        
    }
    return 0;
}
