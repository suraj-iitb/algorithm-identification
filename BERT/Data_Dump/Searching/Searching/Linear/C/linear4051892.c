#include <stdio.h>
#include <stdlib.h>
#define N 10000
#define Y 1000000000

int search(int *,int,int);

int main()
{
  int i,n,q,S[N],T,cnt=0;

  scanf("%d",&n);
  if(n>10000) exit(1);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
    if(S[i] > Y) exit(2);
  }
  scanf("%d",&q);
  if(q>500) exit(1);
  for(i=0;i<q;i++){
    scanf("%d",&T);
    if(T > Y) exit(2);
    if(search(&S[0],n,T)) cnt++; //１が返って来たらカウントする
  }

  printf("%d\n",cnt);
  
  return 0;
}

int search(int *S,int n,int T)
{
  int i;

  for(i=0;i<n;i++)
    if(S[i] == T) return 1; 
  return 0;
}

