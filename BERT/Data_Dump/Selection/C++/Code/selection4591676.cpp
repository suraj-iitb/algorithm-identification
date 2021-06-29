#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int selectionSort(vector<int>& a,int n){
    int minj;
    int cnt=0;
    for(int i=0;i<n-1;i++){
        minj=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        swap(a[i],a[minj]);
        if(minj!=i){
            cnt++;
        }
    }
    
    return cnt;
}

int main(){
    int n,cnt;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    
    cnt=selectionSort(a,n);
    
    rep(i,n-1) cout<<a[i]<<' ';
    cout<<a[n-1]<<endl;
    cout<<cnt<<endl;
    
    return 0;
}
