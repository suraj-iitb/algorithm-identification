#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,A[110],minj,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++)cin>>A[i];
    bool ok;
    for(int i=0;i<n;i++){
        minj=i;
        ok=0;
        for(int j=i+1;j<n;j++){
            if(A[minj]>A[j]){
                minj=j;
                ok=1;
            }
        }
        swap(A[minj],A[i]);
        if(ok)cnt++;
    }
    for(int i=0;i<n;i++){
        cout<<A[i];
        if(i!=n-1)cout<<" ";
    }
    cout<<endl<<cnt<<endl;

    return 0;
}




