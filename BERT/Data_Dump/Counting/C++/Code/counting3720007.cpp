#include<bits/stdc++.h>
using namespace std;
#define MAX 2000000
#define VMAX 11000
int A[MAX],C[VMAX],B[MAX];
int n;
void countingSort(int *A,int *B,int vmax){
    for(int i=0;i<=vmax;i++){
        C[i]=0;
    }
    for(int i=0;i<n;i++){
        C[A[i]]++;
    }
    for(int i=1;i<=vmax;i++)
        C[i]=C[i]+C[i-1];
    for(int i=n-1;i>=0;i--){
        B[C[A[i]]-1]=A[i];
        C[A[i]]--;
    }
}
int main(){
    cin>>n;
    int vmax=-1;
    for(int i=0;i<n;i++){
         cin>>A[i];
         vmax=max(vmax,A[i]);
    }
    countingSort(A,B,vmax);
    for(int i=0;i<n;i++){
        if(i)
            cout<<" ";
        cout<<B[i];
    }
    cout<<endl;
    return 0; 
}
