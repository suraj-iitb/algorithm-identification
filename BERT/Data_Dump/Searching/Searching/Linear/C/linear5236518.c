#include<stdio.h>

int linerSearch(int a[],int key,int n)
{
  int i=0;
  a[n]=key;
  while(a[i]!=key){
    i++;
    if(i==n){return n+1;}
  }
  return i;
}

int main(void){
  int n,s[10000],q,t[500],count=0,judge;
  int i=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }

  for(i=0;i<q;i++){
    judge=linerSearch(s,t[i],n);
    if(judge!=n+1){count++;}
  }

  printf("%d\n",count);
  return 0;
}
