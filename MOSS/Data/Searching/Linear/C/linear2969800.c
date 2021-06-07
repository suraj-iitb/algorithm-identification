#include <stdio.h>
#define N 10000

int LinerSearch(int S[],int n,int flag){
  int i=0;
  S[n]=flag;
  while(S[i]!=flag)i++;
  return i!=n;
}

int main(){
  int i,n,q,S[N],sum=0,flag;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&flag);
    if(LinerSearch(S,n,flag)!=0)sum++;
  }
  printf("%d\n",sum);

  return 0;
}
  

