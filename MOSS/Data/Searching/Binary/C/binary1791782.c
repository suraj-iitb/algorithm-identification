#include <stdio.h>
#define N 100000
#define Q 50000

int main(){
  int S[N], T[Q], C = 0;
  int left, right, mid, key;
  int n, q, i;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }

  for(i = 0; i < q; i++){
    key = T[i];
    left = 0;
    right = n;

    while(left < right){
      mid = (left + right) / 2;
      if(S[mid] == key){
        C++;
        break;
      }
      else if (key < S[mid]){
        right = mid;
      }
      else left = mid + 1;
    }
  }

  printf("%d\n", C);

  return 0;
}
