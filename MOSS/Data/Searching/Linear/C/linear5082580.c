#include<stdio.h>

#define N 10000
#define Q 500
#define NOT_FOUND 0;

int LinearSearch(int,int *,int);

int main(){
  int S[N],T[Q];
  int i,j,count=0;
  int n;
  int q;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);

  for(i=0;i<q;i++) count += LinearSearch(n,S,T[i]);
  printf("%d\n",count);

  return 0;
}

int LinearSearch(int n,int A[],int key){
  int i=0;
  A[n] = key;
  while(A[i] != key) i++;
  if(i == n) return NOT_FOUND;
  return 1;
}


