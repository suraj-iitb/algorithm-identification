#include <stdio.h>

int main(){
  int flag = 1,ct=0,l,i,j,cp,A[100];
  scanf("%d",&l);
  for(i=0; i<l; i++){
    scanf("%d",&A[i]);
  }
  while(flag==1){
    flag = 0;
    for(j=l-1; j>=1; j--){
      if(A[j] < A[j-1]){
        cp = A[j];
        A[j] = A[j-1];
        A[j-1] = cp;
        flag = 1;
        ct++;
      }
    }
  }
  for(i=0; i<l-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d",A[i]);
  printf("\n%d\n",ct);
}

