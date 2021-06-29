#include <stdio.h>
#define M 100

void selectionSort(int[],int);
int count = 0;

int main (){
    int n,i;
    int A[M+1];
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    selectionSort(A,n);
    printf("%d\n",count);

    return 0;

}

void selectionSort(int A[],int N){
  int j,i,mini,temp;

  for (i = 0 ;i<N;i++){
    mini = i;
    for (j= i;j<N;j++){
      if(A[j] < A[mini])mini = j;
    }
    if(mini != i){
      temp = A[mini];
      A[mini] = A[i];
      A[i] = temp;
      count++;
    }
    
  }
  for (i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
    
}

