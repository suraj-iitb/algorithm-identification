#include <stdio.h>

int main(){
  int i,n,q,count = 0;
  int right,left,mid;
  int S[100000],T[50000];

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
  }

  for(i = 0; i < q; i++){
    left = 0;
    right = n;
    while(left < right){
      mid = (left + right) / 2;
      if(S[mid] == T[i]){
	count++;
	break;
      }
      else if(T[i] < S[mid]) right = mid;
      else left = mid + 1;
    }
  }

    printf("%d\n",count);
    
  return 0;
}
