#include<stdio.h>
#include<stdlib.h>

int *CountingSort(int *,int *,int,int);

int main(){
  int *A,*B,n,max,i;

  scanf("%d",&n);

  A=(int *)malloc(n*sizeof(int));
  B=(int *)malloc(n*sizeof(int));

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(i==0||max<A[i]){
      max=A[i];
    }
  }

  B=CountingSort(A,B,max,n);

  for(i=0;i<n;i++){
    printf("%d",B[i]);
    if(i!=n-1){
      printf(" ");
  }
  }
  printf("\n");

  free(A);
  free(B);
  return 0;

}

  int *CountingSort(int *A,int *B,int max,int n){
    int *C,i,j,a,b;

  C=(int *)malloc(max*sizeof(int));

  for(i=0;i<=max;i++){
    C[i]=0;
    }
    
    for(j=0;j<n;j++){
      C[A[j]]++;
    }

    for(i=1;i<=max;i++){
      C[i]=C[i-1]+C[i];
    }

    for(j=n-1;j>=0;j--){
      a=A[j];
      b=C[a]-1;
      B[b]=A[j];
      C[a]--;
    }

    free(C);
    return B;
  }


