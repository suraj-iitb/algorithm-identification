#include<stdio.h>
#define Max1 100000
#define Max2 50000
main(){
  int i;
  int n, q;
  int S[Max1], T[Max2];
  int left, right, mid, count = 0, key;

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

    key =  T[i];

    while(left<right){

      if((left + right)%2 == 0) mid = (left + right)/2;

      else  mid = ( left + right -1)/2;

      if(key == S[mid]){count++;
        break;
      }

      else if(key < S[mid])right = mid;

      else if(key > S[mid])left = mid+1;
    }
  }
  printf("%d\n", count);

  return 0;

}
