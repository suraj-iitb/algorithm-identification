#include <stdio.h>
#include <stdlib.h>
#define N 2000001
#define V 10000
int main(){
  int n,i,j,cnt[V+1];
  unsigned short *ans,*A;
  scanf("%d",&n);
  A = malloc(sizeof(short)*n+1);
  ans = malloc(sizeof(short)*n+1);
  for(i=0;i<V+1;i++)cnt[i]=0;
  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
    cnt[A[i+1]]++;
  }
  for(i=1;i<V+1;i++)cnt[i]=cnt[i]+cnt[i-1];
  for(i=1;i<=n;i++){
    ans[cnt[A[i]]]=A[i];
    cnt[A[i]]--;
  }
  for(i=1;i<n+1;i++){
    if(i==n)printf("%d\n",ans[i]);
    else printf("%d ",ans[i]);
  }
  return 0;
}

