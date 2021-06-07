#include <stdio.h>

int linearSeach(int *,int,int);

int main(){
  int S[100000];
  int T[100000];
  int N,q,i;
  int cnt=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
    if( linearSearch(S,N,T[i]) )cnt++;
  }

  printf("%d\n",cnt);

  return 0;
}

int linearSearch(int A[],int N,int key){
  int i=0;

  A[N]=key;

  while(A[i] != key){
    i++;
  }
   return i != N;
}

