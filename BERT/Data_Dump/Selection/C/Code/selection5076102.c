#include<stdio.h>

int SelectionSort(int A[],int N) {
  int i,j,t,sw = 0,min;

  for(i=0;i<N-1;i++){
    min = i;
    for(j=i;j<N;j++){
      if(A[j]<A[min]) min = j;
    }
    t = A[i];
    A[i] = A[min];
    A[min] = t;
    if(i!=min)sw++;
  }
  return sw;
}

int main() {
  int A[100],N,i,sw;

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  sw = SelectionSort(A,N);

  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",sw);

  return 0;
}
