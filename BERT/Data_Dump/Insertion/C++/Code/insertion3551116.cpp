#include <bits/stdc++.h>
using namespace std;
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FOR1(x,to) for(int x=1;x<(to);x++)
int main()
{
    int n,j;cin>>n;
    int a[n];
    
    FOR(i,n){
        cin>>a[i];
    }
    
    FOR(i,n){
        if(i>0) cout<<" ";
            cout<<a[i];
        }
    cout<<"\n";
        
    for(int i=1;i<n;i++){
        int v=a[i];
        j=i-1;
        while(j>=0 and a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        FOR(i,n){
            if(i>0) cout<<" ";
            cout<<a[i];
        }
        if(i!=(n)){
        cout<<"\n";
        }
    }
}

