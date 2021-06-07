#include<stdio.h>

int main(){
  int i, j, n, q, c=0, left, right, mid;
  int S[100001], T[50001];

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }
  
  for(i=0; i<q; i++){
    left = 0;
    right = n;
    while(left < right){
      mid = (left + right)/2;
	  if(S[mid] == T[i]){
	    c++;
	    break;
	  }
	  else if(S[mid] < T[i]) left = mid+1;
	  else  right = mid;
    }
  }
  printf("%d\n",c);
  return 0;
}
