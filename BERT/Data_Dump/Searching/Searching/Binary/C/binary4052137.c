#include <stdio.h>
#include <stdlib.h>
#define N 100000
#define Y 1000000000

int search(int,int *,int);

int main()
{
  int n,i,S[N],q,T,cnt=0;

  scanf("%d",&n);
  if(n>N) exit(1);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
    if(S[i]>Y) exit(2);
  }
  scanf("%d",&q);
  if(q>50000) exit(3);
  for(i=0;i<q;i++){
    scanf("%d",&T);
    if(T>Y) exit(2);
    if(search(n,&S[0],T)) cnt++; //1が返って来たらカウントする
  }

  printf("%d\n",cnt);
  
  return 0;
}

int search(int n,int *S,int T)
{
  int left=0,right=n,mid;

  while(left<right){
    mid=(left+right)/2;
    if(T==S[mid]) return 1; //一致したら１を返す
    if(T<S[mid]) right=mid; 
    else if(T>S[mid]) left=mid+1;
  }
  return 0;
}

