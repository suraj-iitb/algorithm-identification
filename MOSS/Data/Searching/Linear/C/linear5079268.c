#include <stdio.h>
#define N 10000
#define Q 500

int main(void)
{
  int i, j, k, v, n, q, count, key;
  count = 0;
  key = 0;
  /*in*/
  int S[N];
  scanf("%d", &n);
  for(i = 0; i<n; i++){
    scanf("%d", &S[i]);
  }
  int T[Q];
  scanf("%d", &q);
  for (j=0; j<q; j++){
    scanf("%d", &T[j]);
  }

 for (i=1; i<n; ++i) {
     v =S[i];
     j = i - 1;
     while ( j >= 0 && S[j] > v){
          S[j+1] = S[j];
          j--;
     }
     S[j+1] = v;
  }

  for(j=0; j<q; j++){
    key = T[j];
    for(i=0; i<n; i == i){
      if(i ==0 && S[i] == key){
          count++;
      }
      if(i >0 && S[i] == key && S[i] != S[i-1]){
         count++;
      }
    i++;
    }
  }
  printf("%d\n", count);

}

