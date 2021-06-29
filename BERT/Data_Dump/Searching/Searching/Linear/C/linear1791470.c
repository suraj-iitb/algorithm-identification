#include<stdio.h>
#include<stdlib.h>

int linearSearch(int * ,int, int);

int main(){

  int i,cnt=0;
  int n,*S,q,*T;

  //入力
  scanf("%d",&n);
  S=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  T=(int *)malloc(sizeof(int)*q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);


  //search
  for(i=0;i<q;i++)  cnt+=linearSearch(S,T[i],n);

  //表示
  printf("%d\n",cnt);

  return 0;
}
int linearSearch(int *A,int key,int n){

  int i=0;
  A[n]=key;
  while(A[i]!=key){
    i++;
    if(i==n) return 0;
  }

  return 1;
}
