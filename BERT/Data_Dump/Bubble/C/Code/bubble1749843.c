#include <stdio.h>

void bubbleSort(int*,int);

int cnt=0;

int main()
{
  
  int i;
  int A[100],N;
  
  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  bubbleSort(A,N);
  for(i=0;i<N;i++){
    printf("%d",A[i]); 
    if(i != N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);

  
  return 0;
}

void bubbleSort(int* a,int n)
{
  int i,j,temp; 
  
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(a[j] < a[j-1]){
	temp = a[j];
        a[j] = a[j-1];
	a[j-1] = temp;
	cnt++;
      }
    }
  }
}
