#include <stdio.h>
#include <stdlib.h>
int main(){
  int n,i,j,A[1000],s;

  scanf("%d",&n);
  if(n<0 && n>100) exit(0);

  for(i=0;i<n;i++){
    scanf(" %d",&A[i]);
  }
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  
  for(i=1;i<n;i++){
    s = A[i];
    j= i - 1;
    while(j>=0&&A[j]>s){
      A[j+1] = A[j];
      j--;
      A[j+1]=s;
    }
      for(j=0;j<n-1;j++){
	printf("%d ",A[j]);
      }
      printf("%d\n",A[n-1]);
  }
  return 0;
}

