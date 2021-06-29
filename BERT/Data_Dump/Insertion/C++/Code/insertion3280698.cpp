#include <stdio.h>

int main(){
  int i,j,v,A[1000],a,k;
  scanf("%d",&a);
  for(i=0; i<a; i++){
    scanf("%d",&A[i]);
  }
  for(i=0; i<a-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  for(i=1; i<=a-1; i++){
    v = A[i];
    j = i -1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(k=0; k<a-1; k++){
      printf("%d ",A[k]);
    }
    printf("%d\n",A[k]);
  }
}
