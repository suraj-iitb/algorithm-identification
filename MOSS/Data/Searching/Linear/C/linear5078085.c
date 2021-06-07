#include<stdio.h>
#include<stdlib.h>
#define N 10^9

int linerSearch(int,int *,int);

int main(){
  int n,q,*S,*T,i = 0,count = 0;

  scanf("%d",&n);
  S = (int *)malloc(sizeof(int) * n);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  T = (int *)malloc(sizeof(int) * q);
  for(i = 0;i < q;i++){
    scanf("%d",&T[i]);
  }
  for(i = 0;i < q;i++){
    if(linerSearch(n,S,T[i]) == 0)continue;
    else count++;
  }
  printf("%d\n",count);
  return 0;
}

int linerSearch(int n,int A[],int key){
  int i = 0;
  A[n] = key;
  while(A[i] != key)i++;
  if(i == n)return 0;
  return 1;
}

