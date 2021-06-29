#include <stdio.h>

int main(){

  int i,n,S[100000],q,T[50000],count = 0;
  int left,right,mid;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

 scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    left = 0;
    right = n;
    while(left < right){
      mid = (left + right)/2;
      if(S[mid] == T[i]){
	count++;
	break;
      }
      else if(T[i] < S[mid]){
	right = mid;
      }
      else{
	left = mid +1;
      }
    }
  }

  printf("%d\n",count);

  return 0;
}
