#include "stdio.h"

int linearSearch(int [], int [], int i, int n);


main(){

  int i, c=0, n, q, s, t, S[10001], T[10001];

  scanf("%d", &n);

  for(i=0 ; i<n ; i++){

    scanf("%d", &s);
    S[i] = s;
  }

  scanf("%d", &q);

  for(i=0 ; i<q ; i++){

    scanf("%d", &t);
    T[i] = t;
  }

  for(i=0 ; i<q ; i++){
    c += linearSearch(S,T,i,n);
  }

  printf("%d\n", c);

  return 0;
}


int linearSearch(int S[], int T[], int i, int n)
{
int j = 0;
  S[n] = T[i];

  while(S[j] != S[n]){
    j++;
  }

  if(j == n){
    return 0;
  }
  return 1;
}
