#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    
    for(int i=0; i<n; i++){
        int v = a[i];
        int j = i-1;
        while(j>=0 && a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        
        rep(i,n){
            if(i) printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
    
    return 0;
}


