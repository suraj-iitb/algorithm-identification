#include <bits/stdc++.h>
using namespace std;

int bubble(int A[],int n){
    int sw=0;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=i+1;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                sw++;
            }
        }
    }
    return sw;
}

int main(){
    int n,A[1010];cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];
    int sw=bubble(A,n);
    for(int i=0;i<n;i++){
        if(i) cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    cout<<sw<<endl;
}
