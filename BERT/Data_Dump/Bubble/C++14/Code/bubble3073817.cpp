#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int gv[105];
    cin>>n;
    for(int i=0;i<n;i++) cin>>gv[i];
    int flag=1;
    int cnt=0;
    while(flag){
        flag=0;
        for(int j=n-1;j>0;j--){
            if(gv[j]<gv[j-1]){
                swap(gv[j],gv[j-1]);
                flag=1;
                cnt++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<gv[i];
        if(i!=n-1) cout<<" ";
    }
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}

