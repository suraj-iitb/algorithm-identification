#include<stdio.h>
#define N 100


int main(){

  int i=0,j,k,n,key,check;
  int A[N];

  scanf("%d",&n);
  while(i < n){
    check = scanf("%d",&A[i]);
    i++;
  }

  for(i = 0;i <= n-1;i++){
      
    key = A[i];
    j = i -1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
      }
    A[j+1] = key;
    for(k = 0;k < n-1;k++){
      printf("%d ",A[k]);
    }
    printf("%d\n",A[n-1]);
  }
  return 0;
}

