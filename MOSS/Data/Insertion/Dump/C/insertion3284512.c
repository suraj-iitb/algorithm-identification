#include<stdio.h>

int main(){
  int N,A[1000],i,j,v,h;
  scanf("%d",&N);
  for(i = 0 ; i < N  ; i++)scanf("%d",&A[i]);
  for(i = 0 ; i < N  ; i++){
    v = A[i];
    j = i-1;
    while(j >=0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    for(h = 0 ; h < N  ; h++) {
      if(h==N-1)printf("%d", A[h]);
      else printf("%d ", A[h]);
  }
  
    printf("\n");
  }
  return 0;
}

