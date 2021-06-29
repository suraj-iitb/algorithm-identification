#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,ii,j,jj,n,v;
    cin>>n;
    vector<int>a(n);
    for(i=0;i<n;i++){
        cin>>a.at(i);
    }
    for(i=1;i<n;i++){
        for(j=0;j<n;j++)cout<<a.at(j)<<(j!=n-1?" ":"\n");
        v=a.at(i);
        for(j=i-1;j>=0&&a[j]>v;j--){
            a.at(j+1)=a.at(j);
        }
        a.at(j+1)=v;
    }
    for(j=0;j<n;j++)cout<<a.at(j)<<(j!=n-1?" ":"\n");
    return 0;
}
