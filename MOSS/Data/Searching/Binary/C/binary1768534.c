#include <stdio.h>
#include <stdlib.h>

#define N 100000
#define Q 50000
int binarySearch(int);

int n,q,c=0;
int l,m,r;
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
    c += binarySearch(T[i]);
  }

  printf("%d\n",c);

  return 0;
}

int binarySearch(int key){

  int l = 0;
  int r = n;

  while(l<r){
    m = (l + r)/2;
    if(S[m]==key)
      return 1;
    else if(key < S[m])
      r = m;
    else 
      l = m + 1;
  }
  return 0;
}
