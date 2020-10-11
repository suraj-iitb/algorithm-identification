#include<stdio.h>

void insertionSort(int *A,int N);

int main(void){

  int n;
  int a[1000];
  int i;


  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

   insertionSort(a,n);


   return 0;
}

void insertionSort(int *A,int N){

  int i,j,v,k;

   for(k=0;k<N-1;k++)
      printf("%d ",A[k]);
    printf("%d\n",A[N-1]);
    
  for(i=1;i<N;i++){
    v=A[i];
    j=i-1;

    while(j>=0 && A[j]>v){

      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
    for(k=0;k<N-1;k++)
      printf("%d ",A[k]);
    printf("%d\n",A[N-1]);
  }
}

