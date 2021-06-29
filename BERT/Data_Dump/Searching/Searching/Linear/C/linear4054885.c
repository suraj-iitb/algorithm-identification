#include <stdio.h>
#define N 10001
int linearserach(int*,int,int);

int main(){
  int i,n,S[N],q,t,sum=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    if(linearserach(S,n,t))sum++;
  }

  printf("%d\n",sum);

  return 0;
}
int linearserach(int* S,int n,int t){
  int i=0;
  S[n]=t;
  while(S[i]!=t){
    i++;
  }
  if (i==n)return 0;
  return 1;
    
}

