#include<bits/stdc++.h>
using namespace std;
int A[2000000],B[2000000];
int n,C[10000];
void CountingSort(int A[],int B[],int k){
    for(int i=0;i<k;i++){
        C[i]=0;
    }
    
    for(int j=1;j<=n;j++){
        C[A[j]]++;
    }
    
    for(int i=1;i<k;i++){
        C[i]+=C[i-1];
    }
    
    for(int j=n;j>0;j--){
        B[C[A[j]]]=A[j];
        C[A[j]]--;
    }
    return ;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>A[i];
    CountingSort(A,B,10000);
    for(int i=1;i<=n;i++){
        cout<<B[i];
        if(i!=n) cout<<" ";
    }
    cout<<endl;
    return 0;
}

