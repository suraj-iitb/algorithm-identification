#include <stdio.h>
#define N 10000
#define Q 500

int linersearch(int,int *,int);

int main(){

  int i,n,q,key,S[N],T[Q],cnt=0;

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&S[i]);

  scanf("%d",&q);

  for(i=0;i<q;i++) scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    if(linersearch(n,S,T[i])==1)cnt++;
  }

  printf("%d\n",cnt);

  return 0;
}

int linersearch(int n,int A[],int key){
  int i=0;

  A[n]=key;
  while(A[i]!=key){
    i++;
    if(i == n)return 0;
  }

  return 1;
}

