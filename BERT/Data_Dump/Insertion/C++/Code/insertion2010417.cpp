#include<iostream>
#include<stdio.h>
using namespace std;
static const int  MAX=1000;

int main(void){
  int A[MAX];
  int N;
  int v;
  cin>>N;

  for(int i=0;i<N;i++)cin>>A[i];

  for(int i=0;i<N;i++){
    v = A[i];
    int j=i -1;

    while(j>=0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    for(int j=0;j<N-1;j++)
      printf("%d ",A[j]);
    cout<<A[N-1]<<endl;
  }
  
    return 0;
}
