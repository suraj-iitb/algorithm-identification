#include <stdio.h>
#define Max 100000
int main(){
  int i,T[Max],S[Max],k,j=0,count=0,n,left,right,mid; 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&T[i]);
  }
  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%d",&S[i]);
  }
  for(i=0;i<k;i++){
    left=0;
    right=n;
    while(left < right){
      mid = (left + right)/2;
      if(T[mid] == S[i]){
      count++;
      break;
      }else if(S[i] < T[mid]){
      right = mid;
      }else{
	left = mid +1;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
