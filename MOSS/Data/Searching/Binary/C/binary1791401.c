#include <stdio.h>
#define N 100000
#define Q 50000

int main(){
  int n, q, i, count = 0, left, right, mid, S[N], T[Q];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }

  for(i = 0; i < q; i++){
    left = 0;
    right = n;
    while(left < right){
      mid = (left + right) / 2;
      //printf("left = %d, right = %d, mid = %d, count = %d\n", left, right, mid, count);
      if(T[i] == S[mid]){
	count++;
	break;
      }
      else if(T[i] > S[mid]) left = mid + 1;
      else right = mid;
    }
  }

  printf("%d\n", count);

  return 0;
}
