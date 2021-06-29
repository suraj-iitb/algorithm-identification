#include<stdio.h>

#define NUM 100

void insertionSort(int *,int);

int main(){
  int a[NUM],num_l,i;

  scanf("%d",&num_l);
  for(i=0; i<num_l; i++){
    scanf("%d",&a[i]);
    }

  for(i=0; i<num_l-1; i++){
    printf("%d ",a[i]);
  }
  printf("%d",a[num_l-1]);
  printf("\n");

  insertionSort(a,num_l);

  return 0;
}

void insertionSort(int *A, int N){
  int i,j,n,v;
  for(i=1; i<=N-1; i++){
    v = A[i];
    j = i-1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    for(n=0; n<N-1; n++) printf("%d ",A[n]);

    printf("%d",A[N-1]);
    printf("\n");
  }
}

