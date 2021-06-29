#include <stdio.h>
#include <stdlib.h>

#define N 10000
#define Q 500

int main (){
  int i, j, k, n, q, cnt=0;
  int S[N], T[Q];

  scanf("%d", &n);
  if(n>10000) exit(1);

  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
    if(S[i]>1000000000) exit(2);
  }

  scanf("%d", &q);
  if(q>500) exit(3);

  for(j=0; j<q; j++){
    scanf("%d", &T[j]);
    if(T[j]>1000000000) exit(4);
  }

  for(k=0; k<q; k++){
    for(i=0; i<n; i++){
      if(S[i]==T[k]){
        cnt++;
        break;
      }
    }
  }

  printf("%d\n", cnt);

  return 0;
}

