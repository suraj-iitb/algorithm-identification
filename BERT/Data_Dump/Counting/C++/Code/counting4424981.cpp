#include <iostream>
using namespace std;
void countingsort(int A[],int B[],int k,int n){
    int C[k+1];
    for(int i=0;i<=k;i++){
        C[i]=0;
    }
    for(int j=1;j<=n;j++){
        C[A[j]]=C[A[j]]+1;
    }
    for(int i=1;i<=k;i++){
        C[i]=C[i]+C[i-1];
    }
    for(int j=n;j>=1;j--){
        B[C[A[j]]]=A[j];
        C[A[j]]=C[A[j]]-1;
    }
}
int main(){
    int A[2000000]={},B[2000000]={};
    int n,k=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
        if(k<A[i]){
            k=A[i];
        }
    }
    countingsort(A,B,k,n);
    for(int i=1;i<n;i++){
        cout<<B[i]<<" ";
    }
    cout<<B[n]<<endl;
    return 0;
}
