#include<iostream>
#include <stdlib.h>
using namespace std;

#define MAX 2000001
#define N 10000

int main(){
  unsigned  short *A,*B;
int C[N+1];
int n;

cin >> n;

A=(unsigned short*)malloc(sizeof(int)*n+1);
B=(unsigned short*)malloc(sizeof(int)*n+1);

for(int i=0;i<=N;i++) C[i]=0;

for(int i=0;i<n;i++){
  cin >> A[i+1];
  C[A[i+1]]++;
}

for(int i=1;i<=N;i++)C[i]=C[i]+C[i-1];

for(int j=1;j<=n;j++){
  B[C[A[j]]]=A[j];
  C[A[j]]--;
}

for(int i=1;i<=n;i++){
  if(i>1) cout << " ";
  cout << B[i];
}
cout << endl;
  return 0;
}

