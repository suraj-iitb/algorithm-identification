#include<stdio.h>

int main(){
  int i;
  int j;
  int k;
  int key;
  int n;
  
  scanf("%d",&n);
  
  int  A[n];
  
  for(i=0; i<n; i++)
    scanf("%d",&A[i]);
  for(k=0; k<n-1; k++)
      printf("%d ",A[k]);
    printf("%d\n",A[k]);
  
  for(i = 1; i<n; i++){
    key = A[i];
    j = i-1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    for(k=0; k<n-1; k++)
      printf("%d ",A[k]);
    printf("%d\n",A[k]);
  }
      
  return 0;
}

