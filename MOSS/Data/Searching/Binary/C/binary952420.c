#include<stdio.h>
#define N 100000
#define M 50000


int main(void){
  int i, n, q, S[N], T[M], left, mid, right, key, count;
  scanf("%d", &n);
  for(i=0; i<n ;i++) scanf("%d", &S[i]);
  scanf("%d", &q);
  for(i=0; i<q ;i++)  scanf("%d", &T[i]);

  
  for(i=0; i<q; i++){
    left = 0;
    right = n;
    key = T[i];
    while(left < right){
      mid = (left+right)/2;
      if(S[mid] == key) {
	count++;
	break;
      }
      else if(key < S[mid]) right = mid;
   else if (key > S[mid])left = mid+1;
      
    }
  }
  printf("%d\n", count);
  return 0;
}
