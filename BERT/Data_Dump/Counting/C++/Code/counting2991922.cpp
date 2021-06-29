#include "bits/stdc++.h"
using namespace std;
#define MAX 2000001
#define VMAX 10000

int C[VMAX];
int n=0;
int k=0;

void countingsort(int A[],int B[],int k){
  for(int i=0;i<=k;i++){
    C[i]=0;
  }
  for(int j=1;j<=n;j++){
    C[A[j]]++;
  }
  for(int i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }
  for(int j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(int i=1;i<=n;i++){
    cout<<B[i];
    if(i!=n)cout<<" ";
    
  }
  printf("\n");
}

int main(){
  int A[MAX]={};
  int B[MAX]={};
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>A[i];
    if(k<A[i])k=A[i];
  }
  countingsort(A,B,k);

  
  return 0;
}

