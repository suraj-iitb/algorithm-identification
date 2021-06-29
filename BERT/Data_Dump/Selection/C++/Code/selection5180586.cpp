#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,ans=0;
    cin>>N;
    vector<int>A(N),B;
    for (int i = 0; i < N; i++){
        cin>>A[i];
    }
    B =A;
    for(int i=0;i<N;i++){
        int mymin=A[i],kiroku=i;
        for(int j=i;j<N;j++){
            if(mymin>A[j]){
            kiroku=j;
            mymin=A[j];
            }
        		}
            if(i!=kiroku){
                int v=A[i];
                A[i] =mymin;
                A[kiroku]=v;
              ans++;
            }
    }
for (int i = 0; i < N; i++){
        if(i<N-1)cout<<A[i]<<" ";
        else cout<<A[i]<<endl;
    }
cout<<ans<<endl;  
    
}
