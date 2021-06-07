#include<stdio.h>
#define SMAX 100000
#define TMAX 50000

main(){

  int i,j,n,q,count = 0;
  int S[SMAX],T[TMAX];
  int left,right,mid;
  
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j = 0; j < q;j++){
    scanf("%d",&T[j]);
    left = 0;
    right = n;
    while(left < right){
      mid = (left + right)/2;
      if(T[j] == S[mid]){
	count++;
	break;
      }
      if(T[j] > S[mid]) left = mid + 1;
      else if(T[j] < S[mid]) right = mid;
      }
  }
  
  printf("%d\n",count);

  return 0;
}
