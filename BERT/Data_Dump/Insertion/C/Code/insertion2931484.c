#include <stdio.h>
#include <stdlib.h>


int main(){

  int N,i,j,k,v;
  int *A;

 /* Using loop to check input numbers are in constrants or not */
  while(1){  
    scanf("%d", &N);
    if (N<1 && N>100) printf("error!\n");
    else break;
  }

  /* doing dynamic storange allocation */
  A=(int *)malloc(sizeof(int) * N);
 
 for(i=0 ; i<N ; i++){
    scanf("%d", &A[i]);
  }

 /* output the contents of A */
  for(i=0 ; i<N ; i++){
    printf("%d",A[i]); 
    if(i==N-1)printf("\n");
    else printf(" ");
  }

  /* doing insertion sort and output the machineries */
  for(i=1 ; i<=N-1 ; i++){
    v=A[i];
    j=i-1;
    while(j >= 0 && A[j] > v){
      A[j+1]=A[j];
	j--;
	A[j+1]=v;
    }

    for(k=0 ; k<N ; k++){
      printf("%d",A[k]);
      if(k==N-1)printf("\n");
      else printf(" ");
    }
  }
 
  return 0;
}

