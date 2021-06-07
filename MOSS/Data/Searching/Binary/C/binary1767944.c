#include <stdio.h>

int binarySearch(int *,int,int);

int main() {
  int i,n,q,S[1000000],T[1000000],ans=0;


  scanf("%d",&n);
  for(i=0;i<n ;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q; i++) scanf("%d",&T[i]);

  for(i=0; i<q; i++){
    ans += binarySearch(S,T[i],n);
  }
  printf("%d\n",ans);

  return 0;
}

int binarySearch(int *A, int key, int n){
  int left = 0;
  int right = n;
  int mid;

  while(left < right){
    mid = (left + right) / 2;
    if (A[mid] == key) return 1;
    else if (key < A[mid]) right = mid;
    else left = mid + 1;
  }
  return 0;
}
