#include <stdio.h>
#define MAX 100000
int main(){

  int i, count=0;
  int left, right, mid;
  int n, q;
  int S[MAX], T[MAX];

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
    
    while(left<right){
      mid = (left + right)/2;
      if(T[i] == S[mid]){
	count++;
	break;
      }
      if(T[i] > S[mid]){
	left = mid + 1;
      }
      else right = mid;
    }
  }

  printf("%d\n",count);
  
  return 0;
}
