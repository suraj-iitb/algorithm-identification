#include<stdio.h>

main(){

  int i, left, right, mid, n, q, count = 0, S[100000], T[50000]\
;

  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i = 0;i < q;i++){
    scanf("%d", &T[i]);
    left = 0;
    right = n;
    while(left < right){
      mid = (left + right) / 2;
      if(T[i] == S[mid]){
        count++;
        break;
      }
      if(T[i] > S[mid]){
        left = mid + 1;
      }
      else if(T[i] < S[mid]){
        right = mid;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
