#include<stdio.h>

main(){
  int n,q,S[100000],T[50000],i,j,count=0;
  int left,mid,right;

  scanf("%d",&n);
  for(i=0 ; i<n ; i++) scanf("%d",&S[i]);

  scanf("%d",&q);

  for(j=0 ; j<q ; j++){
    scanf("%d",&T[j]);
  }
   
  for(j=0 ; j<q ; j++){ 
  left = 0;
  right = n;
  
    while(left < right){
      mid = (left + right) / 2;
      if(T[j] == S[mid]){
	count++;
	break;
      }
      else if(T[j] < S[mid]){
	right = mid;
      }
      else if(T[j] > S[mid]){
	left = mid + 1;
      }
    }
  }

  printf("%d\n",count);

  return 0;
}
