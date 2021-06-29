#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int ans=0;
    bool flag=true;
    while(flag){
        flag=false;
        for(int i=N-1;i>0;i--){
            if(A[i]<A[i-1]){
                int v=A[i];
                A[i]=A[i-1];
                A[i-1]=v;
                ans++;
                flag=true;
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<A[i];
        if(i==N-1) cout<<endl;
        else cout<<' ';
    }
    cout<<ans<<endl;
}
