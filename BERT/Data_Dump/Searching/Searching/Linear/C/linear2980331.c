#include<stdio.h>

int S[10000];
int T[500],n,q;
int linearsearch(int x){
  int i=0;
  S[n]=x;
  while(S[i]!=x){
    i++;
    if(i==n)return 0;
  }
  return 1;
}
     
int main()
{
  int i,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    count+=linearsearch(T[i]);
  }
  printf("%d\n",count);

  return 0;
}

