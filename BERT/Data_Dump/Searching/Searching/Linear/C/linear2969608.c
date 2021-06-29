#include <stdio.h>
int check(int ,int *,int );
int main(void){
  int n,q,S[10000],key,i,count;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0,count=0;i<q;i++){
    scanf("%d",&key);
    if(check(key,S,n)==1)count++;
  }
  printf("%d\n",count);
  return 0;
}
int check(int key,int *S,int n){
  int i=0;
  while(S[i]!=key && i<n)i++;
  if(i==n)return 0;
  else return 1;
}
