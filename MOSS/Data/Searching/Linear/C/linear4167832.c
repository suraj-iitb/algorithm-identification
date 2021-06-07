#include <stdio.h>

int linear(int A[],int n,int key){
  int i=0;
  A[n]=key;
  while(A[i]!=key){
    i++;
  }
  if(i!=n)
    return 1;
  return 0;
}

int main(){
  int i,n,q,key,S[10001],sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
  if(linear(S,n,key)==1)
    sum++;
  }
  printf("%d\n",sum);
  return 0;
}

