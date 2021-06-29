#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,tmp,a,bsd_signal;
    int k,g;
    int r[10000];
    cin>>n;
    for(int i=0;i<n;i++) cin>>r[i];
    for(g=0;g<n;g++){
            if(g<n-1) cout<<r[g]<<' ';
            else cout<<r[g]<<endl;
        }

    for(int j=1;j<n;j++){
        a=r[j];
        for(k=j-1;k>=0;k--){
            if(a<r[k]){
                r[k+1]=r[k];
            }
            else break;
        }
        r[k+1]=a;
        for(g=0;g<n;g++){
            if(g<n-1) cout<<r[g]<<' ';
            else cout<<r[g]<<endl;
        }
    }


}
