#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int>A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int a=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(i!=0){
                if(A[i]<A[j]){
                    a=A[i];
                    A[i]=A[j];
                    A[j]=a;
                }
            }
        }
        for(int j=0;j<N;j++){
            if(j==N-1){
                cout<<A[j]<<endl;
            }
            else{
                cout<<A[j]<<" ";
            }
        }
    }
}
