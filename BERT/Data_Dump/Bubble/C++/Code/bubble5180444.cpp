#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,ans=0;
    cin>>N;
    vector<int>A(N);
    for (int i = 0; i < N; i++){
        cin>>A[i];
    }

    for (int j = 0; j < N; j++){
         for (int i = N-1; j<i; i--){
        if(A[i-1]>A[i]){
               int v=A[i];
             A[i]=A[i-1];
             A[i-1]=v;
            ans++;
            }
        }   
    }
    
for (int i = 0; i < N; i++){
        if(i<N-1)cout<<A[i]<<" ";
        else cout<<A[i]<<endl;
    }
cout<<ans<<endl;
    
    
    
}
