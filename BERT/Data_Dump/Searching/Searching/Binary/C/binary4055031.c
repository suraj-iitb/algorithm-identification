#include <stdio.h>
#define N 1000000
int binarysearch(int*,int,int);
int main(){
  int i,n,S[N],q,t,sum=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    if(binarysearch(S,n,t))sum++;
  }

  printf("%d\n",sum);

  return 0;
}
int binarysearch(int*S,int n,int t){
  int left=0,right=n,mid;
  while(left<right){
    mid=(left+right)/2;
    if(t==S[mid])return 1;
    else if(t<S[mid])right=mid;
    else left=mid+1;
  }
  return 0;
}

