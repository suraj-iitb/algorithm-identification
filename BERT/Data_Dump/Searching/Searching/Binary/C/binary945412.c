#include<stdio.h>

main(){

  int n,q,i,left,right,mid,c=0;
  int S[100000];
  int T[50000];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  
  for(i=0;i<q;i++){
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(S[mid]==T[i]){
	c++;
	break;
      }
      else if(S[mid]<T[i]){
	left=mid+1;
      }
      else{
	right=mid;
      }
    }
  }
  printf("%d\n",c);
  return 0;
}
