#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
#define MA 2000001







int main(){
  int i,j,k;
  int C[MAX+1],*A,*B;
 

  scanf("%d",&k);

  

  A = malloc(sizeof(int *) * k+1);
  B = malloc(sizeof(int *) * k+1);

   for(i = 0;i<=MAX;i++){
    C[i] = 0;
  }

  
     
  for(i = 0;i<k;i++){
    scanf("%d",&A[i+1]);
    C[A[i+1]]++;
  }

   for(i =1;i<=MAX;i++){
    C[i] = C[i] + C[i-1];
  }
  for(j = 1;j<=k;j++){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }


  


  for(i = 1;i<=k;i++){
    if(i>1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  
  

  return 0;
}

