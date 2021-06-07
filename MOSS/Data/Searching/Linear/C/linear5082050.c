#include<stdio.h>

#define N 10000
#define Q 500

int input(int,int);

int S[N],T[Q];

int main(){
  int i,j,n,q,a=0;

  scanf("%d",&n);
  for(i=0 ; i<n ; i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0 ; i<q ; i++)scanf("%d",&T[i]);
  for(i=0 ; i<q ; i++)
    a+=input(i,n);

  printf("%d\n",a);
}

int input(int i,int n){
  int j;
    S[n] = T[i];
    for(j=0 ; S[j]!=T[i] ; j++);
    if(j==n)return 0;
    else return 1;
}
