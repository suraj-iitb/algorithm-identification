#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=100;

int selectionSort(int A[],int N){
  int i,j,sw=0,tmp,minj;

  for(i=0;i<N-1;i++){
    minj=i;
    for ( j = i; j < N; j++)
    {
      if(A[j]<A[minj]){
        minj=j;
      }  
    }
    tmp=A[i];
    A[i]=A[minj];
    A[minj]=tmp;
    if(i!=minj) sw++;
  }

  return sw;
}


int main(){

  int i,j,sw,N,A[MAX_N]={};

  cin >> N;
  for(i=0;i<N;i++) cin >> A[i];

  sw=selectionSort(A,N);

  for ( i = 0; i < N; i++)
  {
    if (i!=0)
    {
      printf(" ");
    }
    printf("%d",A[i]);
    
  }
  printf("\n");
  printf("%d\n",sw);

  return 0;

}
