#include <bits/stdc++.h>
using namespace std;

int c=0;

int bubble(int *r, int n){
    int flag=1;
    int tmp;
    while(flag){
        flag=0;
        for(int i=n-1;i>0;i--){
            if(r[i]<r[i-1]){
                tmp=r[i];
                r[i]=r[i-1];
                r[i-1]=tmp;
                flag=1;
                c++;
            }
        }
    }

    for(int k=0;k<n;k++){
        if(k!=n-1) cout<<r[k]<<' ';
        else cout<<r[k]<<endl;
    }
    return 0;

}


int main(){
    int n;
    int r[1000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>r[i];
    }

    bubble(r, n);
    cout<<c<<endl;

}
