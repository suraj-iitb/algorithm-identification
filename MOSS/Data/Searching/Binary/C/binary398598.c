/* Search II */
#include<stdio.h>
int main(){
  int n,q; /* n: S, q: T */
  int S[100001],T[50001]; /* n<=100000, q<=50000 */
  int i,j,counter=0;
  int left, mid, right;

  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for(i=0;i<q;i++){
    scanf("%d", &T[i]);
  }

  /* Binary Search */
  /* S:A, T:key */
  for(i=0;i<q;i++){
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(S[mid]==T[i]){
        counter++;
        break;
      }else if(S[mid]<T[i]){
        left=mid+1;
      }else{
        right=mid;
      }
    }
  }
  printf("%d\n",counter);
  return 0;
}
