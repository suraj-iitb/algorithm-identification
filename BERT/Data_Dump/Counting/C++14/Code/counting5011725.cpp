#include<iostream>
#include<vector>
using namespace std;

void countsort(vector<int> &a,vector<int> &b,int k){
    vector<int> c(k+1,0);
    int n=a.size();
    
    
    for(int i=1;i<n;i++){
        c[a[i]]+=1;
    }
    for(int i=1;i<=k;i++){
        c[i]+=c[i-1];
    }
    for(int i=n;i>=1;i--){
        b[c[a[i]]]=a[i];
        c[a[i]]-=1;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> b(n+1);
    countsort(a,b,10000);
    for(int i=1;i<=n;i++){
        if(i!=1)cout<<' ';
        cout<<b[i];
    }
    cout<<endl;
}
