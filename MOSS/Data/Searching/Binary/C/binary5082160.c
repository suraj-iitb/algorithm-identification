#include <stdio.h>
#define N 100000
#define Q 50000

int main(void)
{
  int i, j, v, n, m, q;

  /*in*/
  int S[N];
  scanf("%d", &n);
  for(i = 0; i<n; i++){
    scanf("%d", &S[i]);
  }
  int T[Q];
  scanf("%d", &q);
  Q == q;
  for (j=0; j<q; j++){
    scanf("%d", &T[j]);
  }
 /*sort*/
 for (i=1; i<n; ++i) {
     v =S[i];
     j = i - 1;
     while ( j >= 0 && S[j] > v){
          S[j+1] = S[j];
          j--;
     }
     S[j+1] = v;
  }

  m = n+1;
  int U[m];
  j = 0;
  for(i=0; i<n; ++i){
    if(i == 0){
      U[j] = S[i];
      j++;
    }
    if(i>0 && S[i] != S[i-1]){
      U[j] = S[i];
      j++;
    }
    if(S[i] == S[i-1]){
      m--;
    }
  }
  j = 0;

 /*serch*/
  int left, right, mid, key, count, t;
  key = 0;
  mid = 0;
  count = 0;
  left = 0;

  for(i=0; i<q; i++){
    key = T[i];
    left = 0;
    right = m;

    while (left < right){
      mid = (left + right) / 2;

      if(U[mid] == key){
        count++;
        break;
      }else{
        if(key < U[mid]){
          right = mid;
        }else{
          left = mid+1;
         }
       }
    }
  }
  printf("%d\n", count);

}

