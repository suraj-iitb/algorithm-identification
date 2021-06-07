#include<stdio.h>
#include<stdlib.h>

int Binarysearch(int[],int,int);

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
    if(Binarysearch(S,n,T[i]))
      count++;
  printf("%d\n",count);
  free(S);
  free(T);
  return 0;
}

int Binarysearch(int A[],int n,int key){
  int l=0, r=n, m;
  while(l<r){
    m = (l + r) / 2;
    if(A[m] == key)
      return 1;
    else if(A[m] > key)
      r = m;
    else if(A[m] < key)
      l = m + 1;
  }
  return 0;
}
