#include <stdio.h>
int  linearsearch(long int *s,long int key,int n){
  int i=0;
  s[n]=key;
  while(s[i]!=key) i++;
  if(i==n)return 0;
  return 1;
    
}
int main(){
  int i,j;
  int n,q;
  int count=0;
  long int s[10001];
  long int t[500];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&t[i]);
  for(i=0;i<q;i++) count=count+linearsearch(s,t[i],n);
  printf("%d\n",count);
  return 0;
}
