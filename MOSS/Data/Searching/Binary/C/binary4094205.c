#include<stdio.h>
#define MAX 100000
int main(){
  int S[MAX],T[MAX],n,q,i,left,right,mid,count=0,j;
  scanf("%d",&n);
  for(i=0; i<n; i++){
     scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }
  for(i=0; i<q; i++){
    left=0;
    right=n;
    while(left<right){
        mid=(left+right)/2;
        if(S[mid]==T[i]){
            count++;
            break;
        }
        else if(T[i]<S[mid])right=mid;
        else left=mid+1;
     }
  }
  printf("%d\n",count);
  return 0;
}

