#include<stdio.h>

int main(){

  int i,j,key,n;
  int A[100];

  scanf("%d",&n);
  for(i=0 ; i<n ; i++) scanf("%d",A+i);
  for(i=0 ; i<n-1 ; i++) printf("%d ",A[i]);
  printf("%d\n",A[i]);

  for(j=1 ; j<n ; j++){
    key = A[j];
    i = j-1;
    while(i>=0 && A[i]>key){
      A[i+1] = A[i];
      i--;
    }

    A[i+1] = key;
    for(i=0 ; i<n-1 ; i++) printf("%d ",A[i]);
    printf("%d\n",A[i]);
  }
  return 0;
}
