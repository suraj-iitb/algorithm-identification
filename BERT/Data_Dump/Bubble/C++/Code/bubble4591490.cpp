#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int bubbleSort(vector<int> a,int n){
    bool flag=1;
    int cnt=0;
    while(flag){
        flag=0;
        for(int i=n-1;i>0;i--){
            if(a[i]<a[i-1]){
                swap(a[i],a[i-1]);
                flag=1;
                cnt++;
            }
        }
    }
    rep(i,n-1) cout<<a[i]<<' ';
    cout<<a[n-1]<<endl;
    cout<<cnt<<endl;
    
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    
    bubbleSort(a,n);
    
    return 0;
}
