#include <stdio.h>
#define N 100000
#define T 50000
 
main()
{
 
  int i,j;
  int A[N],B[T];
  int n,t,left,right,mid,key=0,f=0;
   
  scanf("%d",&n);
   
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
 
  scanf("%d",&t);
   
  for(j = 0; j < t; j++){
    scanf("%d",&B[j]);
     
    left = 0;
    right = n;
     
    while(left < right){
      mid = (left + right)/2;
       
      if(B[j] == A[mid]){
    f++;
    break;
      }
       
      if(B[j] > A[mid]){
    left = mid + 1;
      }
       
      else if(B[j] < A[mid]){
    right = mid;
      }
    }
  }
   
   
   
  printf("%d\n",f);
   
  return 0;
   
}
