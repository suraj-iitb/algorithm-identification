#include <stdio.h>

int linearSearch(int *,int,int);

int main() {
  int i,n,q,S[1000000],T[1000000],ans=0;


  scanf("%d",&n);
  for(i=0;i<n ;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q; i++) scanf("%d",&T[i]);

  for(i=0; i<q; i++){
    ans += linearSearch(S,T[i],n);
  }
  printf("%d\n",ans);

  return 0;
}


int linearSearch(int *A, int key, int n){
  int i=0;
  A[n] = key;
  while(A[i] != key){
    i++;
    if(i == n) return 0;
  }
    return 1;
}
