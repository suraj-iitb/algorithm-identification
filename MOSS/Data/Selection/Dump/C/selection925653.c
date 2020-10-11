#include<stdio.h>
 int main(){
 
  int A[100];
  int i,j,n,temp,m=0,min;
 
  scanf("%d",&n);
  for(i = 0; i < n; i++)scanf("%d",&A[i]);
 
  for(i = 0; i < n ; i++){
   min = i;
      
   for(j = i; j < n; j++){
	if(A[j] < A[min]){
            min=j;
}
      }
 
      if(min!=i){
          temp = A[i];
          A[i] = A[min];
          A[min] = temp;
          m = m + 1;
        }
    }
 
  for(i = 0 ; i < n-1 ; i++){
   printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",m);
   
  return 0;
}
