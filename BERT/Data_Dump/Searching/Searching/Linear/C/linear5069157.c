#include <stdio.h>

int LinearSearch(int *,int *,int,int);

int main(){
  int S[10001],T[501],n,q,i,j;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
  }

  printf("%d\n",LinearSearch(S,T,n,q));
  
  return 0;
}

int LinearSearch(int *A,int *B,int n,int q){
  int i,j,cnt = 0;
  for(j = 0; j < q; j++){
    i = 0;
    A[n] = B[j];
    while(A[i] != B[j]){
      i++;
    }
    if(i == n)continue;
    cnt++;
  }
  return cnt;
}
  

