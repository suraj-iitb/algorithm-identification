#include<stdio.h>
#define N 1000
int main(){
  int A[N];
  int i,key,j,n,k;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d",A[n-1]);
  printf("\n");
  for(i = 1;i<=n-1;i++){
    key = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > key)
      {
	A[j+1] = A[j];
	j--;
	A[j+1] = key;
      }
    for(k=0;k<n-1;k++){
      printf("%d ",A[k]);
    }
    printf("%d",A[k]);
    printf("\n");
  }
  return 0;
}

