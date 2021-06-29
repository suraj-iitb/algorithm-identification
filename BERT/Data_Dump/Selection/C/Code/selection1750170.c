#include <stdio.h>

void selectionSort(int*, int);
int cnt=0;

int main()
{  
  int i;
  int A[100],N;

  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  selectionSort(A,N);
  for(i=0;i<N;i++){
    printf("%d",A[i]); 
    if(i != N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}

void selectionSort(int *a, int n)
{
  int i,j,minj,temp;

  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(a[j] < a[minj]){
	minj = j;
      }	
    }
    if(minj != i){
    temp = a[i];
    a[i] = a[minj];
    a[minj] = temp;
    cnt++;
    }
  }
}
