#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int gv[105];
    cin>>n;
    for(int i=0;i<n;i++) cin>>gv[i];
    int cnt=0;
    for(int i=0;i<n;i++){
        int minj=i;
        for(int j=i;j<n;j++){
            if(gv[j]<gv[minj]){
                minj=j;
            }
        }
        swap(gv[i],gv[minj]);
        if(i!=minj) cnt++;
    }
    for(int i=0;i<n;i++){
        cout<<gv[i];
        if(i!=n-1) cout<<" ";
    }
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}


