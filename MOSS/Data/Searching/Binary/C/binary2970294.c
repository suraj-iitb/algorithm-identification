#include<stdio.h>
int main(){

  int n,q,i,j,count=0;
  int S[1000000];
  int T[1000000];
  int mid,left,right,key;
  
   scanf("%d",&n);
  for(i=0; i<n; i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i=0; i<q; i++)
    scanf("%d",&T[i]);

  for(j=0; j<q; j++){
    key = T[j];
    left = 0;
    right = n;
    
    while(left < right){
      mid = (left + right)/2;
      if(key == S[mid]){
	count++;
	break;
      }
      if(key > S[mid]){
	left = mid+1;
      }
      else if(key < S[mid]){
	right = mid;
      }
    }
  }

  printf("%d\n",count);
  return 0;
}

