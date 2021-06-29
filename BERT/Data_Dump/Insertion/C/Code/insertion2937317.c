#include <stdio.h>
#define N 1000
int main(){
  int i, n, key;
  int A[N], j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=1;i<n;i++){
    for(key=0;key<n;key++){
      if(key==n-1){
 printf("%d",A[key]);
 continue;
      }
      printf("%d ",A[key]);
    }
    printf("\n");     
    key=A[i];
    j=i-1;
    while(j>=0&&A[j]>key){
      A[j+1]=A[j];
      j--;
      A[j+1]=key;
    }
  }  
  for(key=0;key<n;key++){
    if(key==n-1){
 printf("%d",A[key]);
 continue;
    }
    printf("%d ",A[key]);
  }
   printf("\n");
  return 0;
}

