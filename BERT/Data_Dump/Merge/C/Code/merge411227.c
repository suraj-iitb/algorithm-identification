#include <stdio.h>
#define X 500000
#define Y 1000000001

void Merge(int *, int, int, int);
void MergeSort(int *, int, int);
void Print(int *);
int count = 0;

main(){
  int i, n;
  int A[X];
  

  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&A[i]);


  MergeSort(A, 0, n);

  for(i = 0; i < n; i++)
    if(i == n - 1)
      printf("%d\n",A[i]);
    else
      printf("%d ",A[i]);
  printf("%d\n",count);
  
  return 0;
}



void Merge(int *A, int B, int C, int D){
  int i, j, k, N1, N2;
  int La[X], Ra[X];
  
  N1=C-B;
  N2=D-C;

  for(i = 0; i < N1; i++){
    La[i] = A[B+i];
  }
  for(i = 0; i < N2; i++){
    Ra[i] = A[C+i];
  }
  
  La[N1] = Y;
  Ra[N2] = Y;
  
  i = 0; 
  j = 0;
  
  for(k = B; k <= D - 1; k++){
    count++;
    if( La[i] <= Ra[j] )
      A[k] = La[i++];
    else
      A[k] = Ra[j++];
  }
  
  
}


void MergeSort(int *A, int B, int D){  
  int C;
  
  if( B+1 < D ){
    C=(B+D) / 2;
    
    MergeSort(A, B, C);
    MergeSort(A, C, D);
    Merge(A, B, C, D);
  }
}
