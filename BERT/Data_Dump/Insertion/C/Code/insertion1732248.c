#include <stdio.h>
int main()
{
  int i, j, k, work, N, A[1000];
  

  scanf("%d", &N);
  
  for(i=0;i<N;i++){
    scanf("%d", &A[i]);
  }
  
  
  for(i=1;i<=N;i++){

    for(k=0; k<N; k++){
      printf("%d",A[k]);
      if(k<N-1) printf(" ");
    }

    printf("\n");
    work=A[i];  
    j=i-1;
    while(j>=0 && A[j]>work){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=work;
  }
  return 0;
}

  
