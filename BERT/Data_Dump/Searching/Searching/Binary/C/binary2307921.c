#include<stdio.h>
#define N 100000
#define Q 50000

int main(){
  int S[N];
  int T[Q];
  int left,right,midlle;
  int i,j,count=0,n,q;
   
  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&S[i]);
   
  scanf("%d",&q);
  for(i=0; i<q; i++) scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    left=0;
    right=n;

    while(left<right){
      midlle=(left+right)/2;
      if(T[i]==S[midlle]){
	count++;
	break;
      }
      if(T[i]<S[midlle]) right=midlle;
      else if(T[i]>S[midlle]) left=midlle+1;
    }
  }
  printf("%d\n",count);
  return 0;
}
