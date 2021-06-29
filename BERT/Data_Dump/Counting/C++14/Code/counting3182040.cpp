#include<bits/stdc++.h>
using namespace std;

#define MAX 2000001
#define VMAX 10000

int C[VMAX];

void CountingSort(int A[],int B[],int n,int k){
  for(int i=0;i<k;i++){
    C[i]=0;
  }
  for(int i=0;i<n;i++){
    C[A[i]]++;
  }
  for(int i=0;i<k;i++){
    C[i]+=C[i-1];
  }
  for(int i=n-1;i>=0;i--){
    B[C[A[i]]-1] = A[i];
    C[A[i]]--;
  }
}

int main(){
  int A[MAX],B[MAX];
  int n,mx=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>A[i];
    mx=max(mx,A[i]);
  }
  CountingSort(A,B,n,VMAX+1);
  for(int i=0;i<n;i++){
    if(i) cout<<" "<<B[i];
    else cout<<B[i];
  }
  cout<<endl;
  return 0;
}
  

