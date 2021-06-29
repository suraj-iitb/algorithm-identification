#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,B,count;
    cin>>N;
    count=0;
    vector<int>A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N;i++){
        int J;
        J=i;
        for(int j=i;j<N;j++){
            if(A[j]<A[J]){
                J=j;
            }
        }
        if(i!=J){
            B=A[i];
            A[i]=A[J];
            A[J]=B;
            count++;
        }
    }
    for(int i=0;i<N;i++){
        if(i==N-1){
            cout<<A[i]<<endl;
        }
        else{
            cout<<A[i]<<" ";
        }
    }
    cout<<count<<endl;
}

