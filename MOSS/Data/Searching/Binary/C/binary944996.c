#include <stdio.h>
#define N 100000
#define Q 50000
main(){
  int array1[N],array2[Q],i,j,c=0,n,m,left,right,mid;

  scanf("%d%",&n);
  for(i=0;i<n;i++){
    scanf("%d%",&array1[i]);
  }
  
  scanf("%d%",&m);
  for(j=0;j<m;j++){
    scanf("%d%",&array2[j]);
  }
  
  for(j=0;j<m;j++){
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(array2[j]==array1[mid]){
	c++;
	break;
      }
      if(array2[j]>array1[mid]){
	left=mid+1;
      }
      else if(array2[j]<array1[mid]){
	right=mid;
      }
    }
  }
  
  printf("%d\n",c);
  return 0;
}
