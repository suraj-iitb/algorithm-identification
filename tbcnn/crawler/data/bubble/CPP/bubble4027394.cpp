#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,A[110],v,cnt;
    cin>>n;
    for(int i=0;i<n;i++)cin>>A[i];
    bool ok=1;
    for(int I=0;ok;I++){
        ok=0;
    for(int i=n-1;i>I;i--){
        v=A[i];
        if(A[i]<A[i-1]){
            A[i]=A[i-1];
            A[i-1]=v;
            cnt++;
            ok=1;
        }
    }
    }
    for(int i=0;i<n;i++){
        cout<<A[i];
        if(i!=n-1)cout<<" ";
    }
    cout<<endl<<cnt<<endl;

    return 0;
}




