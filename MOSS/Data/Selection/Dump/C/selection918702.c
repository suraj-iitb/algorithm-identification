#include <stdio.h>
#define N 100

main()
{
  int n,i,j;
  int temp,count=0,minj;
  int A[N];
  
  scanf("%d",&n);
  
  for( i = 0 ; i < n ; i++ ){

    scanf("%d",&A[i]);

  }
  
  for(i = 0 ; i < n - 1 ; i++){
    minj = i;
    
    for(j = i ; j < n ; j++){
      
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(i != minj){
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    count++;
  }
    
  }
  
  for( i = 0 ; i < n ; i++ ){
    if(i != 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
