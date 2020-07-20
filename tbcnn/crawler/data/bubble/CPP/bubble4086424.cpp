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
        for(int j=1;j<N-i;j++){
            if(A[j]<A[j-1]){
                B=A[j];
                A[j]=A[j-1];
                A[j-1]=B;
                count++;
            }
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

