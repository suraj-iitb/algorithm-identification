#include<stdio.h>
#define N 100

int main(){
  int len,A[N],i,j,k,key;

  scanf("%d",&len);
  for(i = 0; i < len; i++){
    scanf("%d",&A[i]);
  }
  for(i = 0; i < len; i++){
    key = A[i];
    j = i - 1;

    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    for(k = 0; k < len; k++){
      if(k == len - 1)printf("%d",A[len - 1]);
      else printf("%d ",A[k]);
    }
    printf("\n");
  }
  return 0;
}
