#include <stdio.h>

int main(){
  int n,q;
  int S[100000], T[50000];
  int count=0;
  int i;
  int mid, left, right;

  scanf("%d", &n );
  //printf("%d\n", n);
  for (i=0 ; i<n; i++ ) {
    scanf("%d", &S[i] );
    //printf("%d ", S[i] );
  }
  //printf("\n");
  scanf("%d", &q );
  for (i=0 ; i<q; i++ ) {
    scanf("%d", &T[i] );
  }

  for(i=0; i<q; i++){
    left=0; right=n;
    while(left<right){
      mid = (left + right)/2;
      if(S[mid]==T[i]){
        count++;
        break;
      }else if(S[mid]>T[i]){
        right = mid;
      }else{
        left = mid+1;
      }
    }
  }
  printf("%d\n", count );
  return 0;
}
