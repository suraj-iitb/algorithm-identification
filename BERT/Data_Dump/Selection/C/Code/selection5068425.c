#include <stdio.h>

void selection_Sort(int *,int);
void swap(int *,int *);
int cnt=0;

int main(){
int A[100], N, i;

scanf("%d",&N);

for(i=0;i<N;i++){
scanf("%d",&A[i]);
}
selection_Sort(A,N);

for(i=0;i<N;i++){

    printf("%d",A[i]);
    if (i != N - 1)
            printf(" ");
}
printf("\n");
printf("%d\n",cnt);

    return 0;
}

void selection_Sort (int A[], int N) {
  int i, j, min;

  for (i = 0; i < N-1; i++) {

    min = i;

    for (j = i + 1; j < N; j++) {

      if (A[j] < A[min])

      min = j;

  }
  if(i!=min){

  swap(&A[min], &A[i]);

  cnt++;
  }

}

}

void swap (int *x, int *y) {
  int r;

  r = *x;

  *x = *y;

  *y = r;
}
