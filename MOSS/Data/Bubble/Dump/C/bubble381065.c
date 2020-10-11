#include <stdio.h>

main(){

  int i,j;
  int A[101];
  int len, tmp, count=0;

  scanf("%d",&len);

  for(i=1; i<=len; i++){
    scanf("%d",&A[i]);
  }

  for(i=1; i<=len-1; i++){

    for(j=len; j >=i+1; j--){

      if(A[j] < A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	count++;
      }

    }

  }
  for(i=1; i<=len; i++){
    printf("%d",A[i]);
    if(i!=len){
      printf(" ");
    }
  }
  printf("\n%d\n",count);

return 0;

}
