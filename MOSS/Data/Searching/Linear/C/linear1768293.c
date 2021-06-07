#include <stdio.h>
#include <stdlib.h>

#define N 10000
#define Q 500
int linearSearch(int);

int n,q,c=0;
int S[N];
int T[Q];

int main()
{
  int i,k;

  scanf("%d",&n);
  if(N<n) exit(1);

  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  if(Q<q) exit(2);

  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }

  for(i=0; i<q; i++){
    c += linearSearch(T[i]);
  }

  printf("%d\n",c);

  return 0;
}

int linearSearch(int key){

  int i=0;

  S[n] = key;
  while(S[i] != key){
    i++;
    if(i==n) return 0;
  }
  return 1;
}
