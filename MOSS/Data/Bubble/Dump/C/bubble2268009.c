#include <stdio.h>
int main(){
  int n, i, j, flag = 1, tmp, count = 0;
  int A[100];

  scanf("%d", &n);

  for ( i = 1; i <= n; i++ ){
    scanf("%d", &A[i]);
  }

  while(flag!=0){

    flag = 0;
    
    for(j = n ;1 < j ;j--){
      
      if(A[j] < A[j-1]){
	tmp = A[j];
	A[j] = A[j-1]; 
	A[j-1] = tmp;

	flag = 1;
	count++;
      }
      
    }
  }
  
  for(i=1;i<n;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n]);
  printf("%d\n",count);

  return 0;
}
