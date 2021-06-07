#include<stdio.h>


main(){
  int s[100000];
  int t[50000];
  int n,q;
  int count=0;
  int i,j;
  int left,mid,right;
  
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&s[i]);
  }
  
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&t[i]);
  }
  
  for(i=0; i<q; i++){
    right = n;
    left = 0;
    while(left <= right) {
      mid = (left + right) / 2; 
      if (s[mid] == t[i]) {
	count++;
	break;
      } else if (s[mid] < t[i]) {
	left = mid + 1; 
        } else {
	right = mid - 1; 
      }
    }
    
  }

  printf("%d\n",count);
  return 0;
}
