#include <stdio.h>
#define MAX 100

int main(void){
  
  int len,key,i,j,f;
  int A[MAX];
  
  scanf("%d",&len);
  for(i=0;i<len;i++)
    scanf("%d",&A[i]);
  
  for(i=1;i<len;i++)
    printf("%d ",A[i-1]);
  printf("%d\n",A[i-1]);
  
  for(j=1;j<len;j++){
    key = A[j];
    i = j - 1;
    while(i >= 0 && A[i] > key){
      A[i+1] = A[i];
      i = i - 1;
      A[i+1] = key;
    }
    for(f=1;f<len;f++)
      printf("%d ",A[f-1]);
    printf("%d\n",A[f-1]);
  }
  return 0;
}
