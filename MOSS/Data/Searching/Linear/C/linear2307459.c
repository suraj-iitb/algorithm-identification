#include <stdio.h>
#include <stdlib.h>

int linersearch(int[],int,int);

int main(){
  int i, count=0, n, q, *S, *T;
  scanf("%d",&n);
  S = (int *)malloc(sizeof(int) * n);
  for(i=0; i<n; i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  T = (int *)malloc(sizeof(int) * q);
  for(i=0; i<q; i++)
    scanf("%d",&T[i]);

  for(i=0; i<q; i++)
    if(linersearch(S,n,T[i]))
      count++;
  printf("%d\n",count);
  return 0;
}

int linersearch(int A[],int len,int key){
  int i;
  for(i=0; i<len; i++)
    if(A[i] == key)
      return 1;
  return 0;
}
