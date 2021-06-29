#include<stdio.h>
#include<stdlib.h>
#define N 2000001
#define VMAX 10000

short *A; /*for input*/
short *B; /*for output*/
int C[VMAX+1]; /*for count*/
int n;

void CountingSort(void);

int main(){
  
  int i;
  
  /*input*/
  scanf("%d",&n);

  A=malloc(sizeof(short)*n+1);
  B=malloc(sizeof(short)*n+1);
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  CountingSort();
  
  /*output*/
  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);

  free(A);
  free(B);
  
  return 0;
}

void CountingSort(void){
  
  int i,j;
  
  for(i=0;i<VMAX;i++){
    C[i]=0;
  }
  
  for(j=0;j<n;j++){
    C[A[j]]++;
  }

  for(i=1;i<VMAX;i++){
    C[i]=C[i]+C[i-1];
  }
  
  for(j=n-1;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}

