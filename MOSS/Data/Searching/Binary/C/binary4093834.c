#include <stdio.h>
#define N 100000
int  main(){
  int n,S[N],q,T[N],i;
  int left,right,mid,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&T[i]);
  for(i=0;i<q;i++){
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(T[i]==S[mid]){
	cnt++;
	break;
      }
      else if(T[i]<S[mid])right=mid;
      else left=mid+1;
    }
  }
  printf("%d\n",cnt);
  return 0;
}
